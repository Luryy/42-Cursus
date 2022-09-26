#ifndef RB_TREE_NODE
#define RB_TREE_NODE

namespace ft {
	enum Rb_tree_color {
		RED = true,
		BLACK = false
	};

	template <class T>
	struct Rb_tree_node {
		T data;
		Rb_tree_node *parent;
		Rb_tree_node *left;
		Rb_tree_node *right;
		bool color;

		explicit Rb_tree_node(T _data, Rb_tree_node *_parent, Rb_tree_node *_left,
			Rb_tree_node *_right, Rb_tree_color _color = BLACK):
			data(_data),
			parent(_parent),
			left(_left),
			right(_right),
			color(_color) {}
	};

	template <class T>
	Rb_tree_node<T> *minimum(Rb_tree_node<T> *node)
	{
		while (node && node->left != NULL)
			node = node->left;
		return node;
	}

	template <class T>
	Rb_tree_node<T> *maximum(Rb_tree_node<T> *node)
	{
		while (node && node->right != NULL)
			node = node->right;
		return node;
	}

	template <class T>
	Rb_tree_node<T> *predecessor(Rb_tree_node<T> *node)
	{
		if (node->left)
			return maximum(node->left);
		Rb_tree_node<T>* y = node->parent;
		while (y && node == y->left)
		{
			node = y;
			y = y->parent;
		}
		if (is_end(node))
			return node;
		return y;
	}

	template <class T>
	Rb_tree_node<T> *sucessor(Rb_tree_node<T> *node)
	{
		if (is_end(node))
			return maximum(node);
		if (node->right)
			return minimum(node->right);
		Rb_tree_node<T>* y = node->parent;
		while (y && node == y->right)
		{
			node = y;
			y = y->parent;
		}
		if (is_end(node))
			return node;
		return y;
	}

	template <class T>
	bool is_end(Rb_tree_node<T> *node)
	{
		if (node->parent->parent == node && node->right == node->left)
			return true;
		return false;
	}
}
#endif
