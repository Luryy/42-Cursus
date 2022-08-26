#ifndef TREEE_HPP
#define TREEE_HPP

#include <string>
#include <rb_tree_iterator.hpp>
#include <typeinfo>
#include <utils.hpp>

namespace ft {
	template <class T, class Compare = ft::less<T>,  class Alloc = std::allocator<Rb_tree_node<T> > >
	class rb_tree {
		public:
			typedef T data_type;
			typedef Alloc allocator_type;
  			typedef size_t size_type;
			typedef data_type* pointer;
			typedef const data_type* const_pointer;
			typedef Rb_tree_node<data_type> node;
			typedef Rb_tree_node<data_type>* node_ptr;
			typedef rb_tree_iterator<pointer> iterator;
			typedef rb_tree_iterator<const_pointer> const_iterator;
  			typedef Compare key_compare;

		private:
			node_ptr _root;
			node_ptr _end;
			size_type _size;
			allocator_type _alloc;
			key_compare _comp;


		public:
			rb_tree(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
				: _root(NULL), _size(0), _alloc(alloc), _comp(comp)
			{
				_end = create_node();
				_end->parent = _root;
				_end->right = _root;
				_end->left = _root;
			};

			~rb_tree(void)
			{
				clear();
				free_node(_end);
			};

			rb_tree &operator=(const rb_tree &src) {
				if (this != &src) {
					_alloc = src._alloc;
					_comp = src._comp;
					clear();
					const_iterator it = src.begin();
					for (; it != src.end(); it++)
						insert(*it);
				}
				return *this;
			}

			iterator begin()
			{
				if (!_root)
					return end();
				return iterator(minimum(_root));
			};
			const_iterator begin() const
			{
				if (!_root)
					return end();
				return const_iterator(minimum(_root));
			}

			iterator end() { return iterator(_end); }
  			const_iterator end() const { return const_iterator(_end); }

			bool empty() const { return (_size == 0); }
			size_type size() const { return _size; }
			size_type max_size() const { return _alloc.max_size(); }
			node_ptr get_root() { return this->_root; }

			void swap(rb_tree &target)
			{
				node_ptr node_tmp = _root;
				size_type size_tmp = _size;
				node_ptr end_tmp = _end;
				key_compare comp_tmp = _comp;
				allocator_type alloc_tmp = _alloc;

				_root = target._root;
				_size = target._size;
				_end = target._end;
				_comp = target._comp;
				_alloc = target._alloc;

				target._root = node_tmp;
				target._size = size_tmp;
				target._end = end_tmp;
				target._comp = comp_tmp;
				target._alloc = alloc_tmp;
			}

			node_ptr search(data_type key) const {
				node_ptr found = node_searcher(this->_root, key);
				if (!found)
					return _end;
				return found;
			}

			pair<iterator, bool> insert(const data_type &key, const node_ptr hint = NULL) {
				node_ptr node = create_node(key, NULL, NULL, NULL, RED);

				node_ptr x = _root;
				bool retry_if_not_find_hint = true;
				if (hint)
					x = hint;
				node_ptr y = NULL;

				while (x != NULL)
				{
					y = x;
					if (_comp(node->data, x->data)) {
						x = x->left;
					} else if (_comp(x->data, node->data)) {
						x = x->right;
					} else {
						free_node(node);
						return (pair<iterator, bool>(iterator(x), false));
					}
					if (x == NULL && hint && retry_if_not_find_hint)
					{
						x = _root;
						retry_if_not_find_hint = false;
					}
				}

				_size++;
				node->parent = y;
				if (y == NULL)
					set_root(node);
				else if (_comp(node->data, y->data))
					y->left = node;
				else
					y->right = node;

				if (node->parent == _end)
				{
					node->color = BLACK;
					return (pair<iterator, bool>(iterator(node), true));
				}

				if (node->parent->parent == _end) {
					return (pair<iterator, bool>(iterator(node), true));
				}

				insert_fix(node);
				return (pair<iterator, bool>(iterator(node), true));
			}

			bool remove(data_type data) {
				node_ptr z = node_searcher(_root, data);
				node_ptr x, y;

				if (z == _end || z == NULL)
					return false;

				_size--;
				y = z;
				int y_original_color = y->color;
				if (z->left == NULL)
				{
					x = z->right;
					transplant(z, z->right);
				} else if (z->right == NULL)
				{
					x = z->left;
					transplant(z, z->left);
				} else
				{
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;

					if (y != z->right)
					{
						transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					else if (x)
						x->parent = y;
					transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				free_node(z);
				if (x && y_original_color == BLACK)
					delete_fix(x);
				return true;
			}

			void clear() { clear_all(_root); }

			key_compare key_comp() const { return _comp; }

			iterator lower_bound(const data_type& k) {
				node_ptr x = _root;
				node_ptr y = _end;

				while (x != NULL)
				if (!_comp(x->data, k))
					y = x, x = x->left;
				else
					x = x->right;

				return (iterator(y));
			}

			const_iterator lower_bound(const data_type& k) const {
				node_ptr x = _root;
				node_ptr y = _end;

				while (x != NULL)
				if (!_comp(x->data, k))
					y = x, x = x->left;
				else
					x = x->right;

				return (const_iterator(y));
			}

			iterator upper_bound(const data_type& k) {
				node_ptr x = _root;
				node_ptr y = _end;

				while (x != NULL)
				if (_comp(k, x->data))
					y = x, x = x->left;
				else
					x = x->right;

				return (iterator(y));
			}

			const_iterator upper_bound(const data_type& k) const {
				node_ptr x = _root;
				node_ptr y = _end;

				while (x != NULL)
				if (_comp(k, x->data))
					y = x, x = x->left;
				else
					x = x->right;

				return (const_iterator(y));
			}

		private:
			void free_node(node_ptr nd) {
				_alloc.destroy(nd);
				_alloc.deallocate(nd, 1);
				nd = NULL;
			}

			void set_root(node_ptr new_root)
			{
				_root = new_root;
				_root->parent = _end;
				_end->right = _root;
				_end->left = _root;
				_end->parent = _root;
			}

			node_ptr create_node(data_type data = data_type(), node_ptr parent = NULL,
							node_ptr left = NULL, node_ptr right = NULL, Rb_tree_color color = BLACK)
			{
				node_ptr new_node;
				new_node = _alloc.allocate(1);
				_alloc.construct(new_node, node(data, parent, left, right, color));
				return new_node;
			}

			void clear_all(node_ptr &current_node)
			{
				if (!current_node) return;

				clear_all(current_node->left);
				clear_all(current_node->right);
				free_node(current_node);
				_size--;
				current_node = NULL;
			}

			void left_rotate(node_ptr x) {
				node_ptr y = x->right;

				x->right = y->left;

				if (y->left != NULL)
					y->left->parent = x;

				y->parent = x->parent;

				if (x->parent == _end)
					set_root(y);
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void right_rotate(node_ptr x) {
				node_ptr y = x->left;

				x->left = y->right;

				if (y->right != NULL)
					y->right->parent = x;

				y->parent = x->parent;

				if (x->parent == _end)
					set_root(y);
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			node_ptr node_searcher(node_ptr node, data_type key) const {
				if (node == NULL)
					return node;
				if (_comp(key, node->data))
					return node_searcher(node->left, key);
				else if (_comp(node->data, key))
					return node_searcher(node->right, key);
				return node;
			}

			void transplant(node_ptr u, node_ptr v)
			{
				if (u->parent == _end) {
					_root = v;
					if (_root)
						set_root(v);
				} else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				if (v) v->parent = u->parent;
			}

			void insert_fix(node_ptr z) {
				node_ptr y;

				while (z->parent->color == RED) {
					if (z->parent == z->parent->parent->left)
					{
						y = z->parent->parent->right;
						if (y && y->color == RED)
						{
							y->color = BLACK;
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							z = z->parent->parent;
						} else {
							if (z == z->parent->right)
							{
								z = z->parent;
								left_rotate(z);
							}
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							right_rotate(z->parent->parent);
						}
					} else
					{
						y = z->parent->parent->left;

						if (y && y->color == RED)
						{
							y->color = BLACK;
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							z = z->parent->parent;
						} else
						{
							if (z == z->parent->left)
							{
								z = z->parent;
								right_rotate(z);
							}
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							left_rotate(z->parent->parent);
						}
					}
					if (z == _root)
						break;
				}
				_root->color = BLACK;
				_alloc.destroy(_end);
				_alloc.construct(_end, node(maximum(_root)->data, _root, _root, _root, BLACK));
			}

			void delete_fix(node_ptr x) {
				node_ptr w;

				while (x != _root && x->color == BLACK) {
					if (x == x->parent->left)
					{
						w = x->parent->right;
						if (w->color == RED)
						{
							w->color = BLACK;
							x->parent->color = RED;
							left_rotate(x->parent);
							w = x->parent->right;
						}

						if ((w->left->color == BLACK) &&
							(w->right->color == BLACK))
						{
							w->color = RED;
							x = x->parent;
						} else
						{
							if (w->right->color == BLACK)
							{
								w->left->color = BLACK;
								w->color = RED;
								right_rotate(w);
								w = x->parent->right;
							}

							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							left_rotate(x->parent);
							x = _root;
						}
					} else
					{
						w = x->parent->left;
						if (w->color == RED)
						{
							w->color = BLACK;
							x->parent->color = RED;
							right_rotate(x->parent);
							w = x->parent->left;
						}

						if (!w->right || w->right->color == BLACK)
						{
							w->color = RED;
							x = x->parent;
						} else
						{
							if (w->left->color == BLACK)
							{
								w->right->color = BLACK;
								w->color = RED;
								left_rotate(w);
								w = x->parent->left;
							}

							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							right_rotate(x->parent);
							x = _root;
						}
					}
				}
				if (x) x->color = BLACK;
				_alloc.destroy(_end);
				data_type data = (_root ? maximum(_root)->data : data_type());
				_alloc.construct(_end, node(data, _root, _root, _root, BLACK));
			}
	};
}

#endif
