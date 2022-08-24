#include <iostream>
#include <string>
#include <deque>
#if USE_STD
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include <set.hpp>
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>
#include <tester_utils.hpp>

// #define MAX_RAM 4294967296
#define MAX_RAM 42949672
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

void line() { std::cout << "-----------------------------------------\n"; };
void nline() { std::cout << "\n-----------------------------------------\n"; };
static void testVector(void);
static void testMap(void);
static void testStack(void);
static void testSet(void);
static void testSubject(int argc, char** argv);

int main(int argc, char** argv) {

	testSubject(argc, argv);


	if (TIME_TRACK) {
		time_tracker("Vector", &testVector);
		time_tracker("Map", &testMap);
		time_tracker("Stack", &testStack);
		time_tracker("Set", &testSet);
	} else {
		testVector();
		testMap();
		testStack();
		testSet();
	}

	return (0);
}

static void testSubject(int argc, char** argv)
{
	std::cout << "=========================================\n";
	std::cout << "              SUBJECT TESTS				\n";
	std::cout << "=========================================\n";

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return ;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	nline();
	std::cout << std::endl << std::endl;
}

static void testVector(void)
{
	int N, i;

	// tests reference: pcunha https://github.com/PCC19/ft_containers/blob/master/main.cpp

	std::cout << "=========================================\n";
	std::cout << "              VECTOR TESTS				\n";
	std::cout << "=========================================\n";

	ft::vector<int> vector_int;

	nline(); std::cout << "\t1.0 Default constructor:\n";line();
		ft::vector<int> vector_1;
		std::cout << "Vector constructed with default constructor\n";
		print_vector(vector_1);

	nline(); std::cout << "\t2.0 Fill constructor:\n";line();
		ft::vector<int> vector_2(5,10);
		std::cout << "Vector_2(5,10) (fill constructror)\n";
		print_vector(vector_2);

	nline(); std::cout << "\t3.0 Range  constructor:\n";line();
		ft::vector<int> vector_3;
		for (int i = 2; i <= 32; i*=2)
			vector_3.push_back(i);
		ft::vector<int> vector_range(vector_3.begin(), vector_3.end());
		print_vector(vector_3);
		std::cout << "Vector Range\n";
		print_vector(vector_range);

	nline(); std::cout << "\t4.0 Iterators\n";line();
		ft::vector<int>::iterator it1;
		std::cout << "iterating on vector_2: \n";
		print_vector(vector_2);
		for (it1 = vector_2.begin(); it1 != vector_2.end(); it1++)
			std::cout << *it1 << " , ";
		std::cout << std::endl;

	nline(); std::cout << "\t4.1 Const Iterators\n";line();
		ft::vector<int>::const_iterator const_it1;
		std::cout << "iterating on vector_2: \n";
		print_vector(vector_2);
		for (const_it1 = vector_2.begin(); const_it1 != vector_2.end(); const_it1++)
			std::cout << *const_it1 << " , ";
		std::cout << std::endl;

	nline(); std::cout << "\t5.0 Reverse Iterators\n"; line();
		ft::vector<int>::reverse_iterator it2;
		std::cout << "iterating on vector_3: \n";
		print_vector(vector_3);
		for (it2 = vector_3.rbegin(); it2 != vector_3.rend(); it2++)
			std::cout << *it2 << " , ";
		std::cout << std::endl;

	nline(); std::cout << "\t5.1 Const Reverse Iterators\n"; line();
		ft::vector<int>::const_reverse_iterator const_it2;
		std::cout << "iterating on vector_3: \n";
		print_vector(vector_3);
		for (const_it2 = vector_3.rbegin(); const_it2 != vector_3.rend(); const_it2++)
			std::cout << *const_it2 << " , ";
		std::cout << std::endl;

	nline(); std::cout << "\t6.0 Size, max_size & Capacity\n";line();
		print_vector(vector_3);
		std::cout << "Vector_3 size: " << vector_3.size() << std::endl;
		std::cout << "Vector_3 max_size: " << vector_3.max_size() << std::endl;
		std::cout << "Vector_3 capacity: " << vector_3.capacity() << std::endl;

	nline(); std::cout << "\t7.0 Resize\n"; line();
		std::cout << "Vector_3: resize(10,3)\n";
		vector_3.resize(10,3);
		print_vector(vector_3);
		print_vector(vector_3);
		std::cout << "Vector_3: resize(4,11)\n";
		vector_3.resize(4,11);
		print_vector(vector_3);

	nline(); std::cout << "\t8.0 Reserve\n";line();
		std::cout << "vector_2:\n";
		print_vector(vector_2);
		std::cout << "Reserve 20:\n";
		vector_2.reserve(20);
		print_vector(vector_2);

	nline(); std::cout << "\t9.0 Empty\n:"; line();
		std::cout << "is vector_2 empty ?\n";
		std::cout << vector_2.empty() << std::endl;
		std::cout << "is vector_1 empty ?\n";
		std::cout << vector_1.empty() << std::endl;

	nline(); std::cout << "\t10.0 Operator []\n";line();
		print_vector(vector_3);
		std::cout << "vector_3[2]: " << vector_3[2] << std::endl;
		std::cout << "vector_3[3]: " << vector_3[3] << std::endl;
		std::cout << "vector_3[1]: " << vector_3[1] << std::endl;
		std::cout << "vector_3[100]: " << vector_3[100] << std::endl;

	nline(); std::cout << "\t11.0 at\n";line();
		print_vector(vector_3);
		std::cout << "vector_3.at(2): " << vector_3.at(2) << std::endl;
		std::cout << "vector_3.at(3): " << vector_3.at(3) << std::endl;
		std::cout << "vector_3.at(1): " << vector_3.at(1) << std::endl;
		try {
			std::cout << "vector_3.at(100): " << vector_3.at(100) << std::endl;
		} catch (std::exception& err) {
			std::cout << "Catched expected error at vector_3.at(100)" << std::endl;
		}

	nline(); std::cout << "\t12.0 front & back\n";line();
		print_vector(vector_3);
		std::cout << "Vector_3 front: " << vector_3.front() << std::endl;
		std::cout << "Vector_3 back : " << vector_3.back() << std::endl;

	nline(); std::cout << "\t13.0 Assign\n";line();
		vector_3.push_back(10);
		vector_3.push_back(20);
		vector_3.push_back(30);
		vector_3.push_back(40);
		vector_3.push_back(50);
		ft::vector<int>::iterator it3, it4;
		it3 = vector_3.begin();
		it3++;
		it3++;
		it4 = vector_3.end();
		it4--;
		it4--;
		ft::vector<int> vector_4;
		vector_4.assign(it3, it4);
		print_vector(vector_3);
		std::cout << "assign from it3: " << *it3 << " to it4: " << *it4 << std::endl;
		print_vector(vector_4);

	nline(); std::cout << "\t13.1 Number Assign\n";line();
		ft::vector<int> vector_assign;
		std::cout << "assign 12, 42 at vector_assign: " << std::endl;
		vector_assign.assign(12, 42);
		print_vector(vector_assign);

	nline(); std::cout << "\t14.0 push_back\n"; line();
		std::cout << "push_back(1):\n"; vector_4.push_back(1); print_vector(vector_4);;
		std::cout << "push_back(2):\n"; vector_4.push_back(2); print_vector(vector_4);;
		std::cout << "push_back(3):\n"; vector_4.push_back(3); print_vector(vector_4);;
		ft::vector<int> vector_push_back;
		std::cout << "vector_push_back: push_back(3):\n"; vector_push_back.push_back(3); print_vector(vector_push_back);;

	nline(); std::cout << "\t15.0 pop_back\n";line();
		std::cout << "pop_back !\n"; vector_4.pop_back(); print_vector(vector_4);
		std::cout << "pop_back !\n"; vector_4.pop_back(); print_vector(vector_4);
		std::cout << "pop_back !\n"; vector_4.pop_back(); print_vector(vector_4);
		ft::vector<int> vector_pop_back;
		std::cout << "vector_pop_back: pop_back(3):\n"; vector_pop_back.pop_back(); print_vector(vector_pop_back);;

	nline(); std::cout << "\t16.0 insert_single\n"; line();
		std::cout << "Insert 2,15\n";
		it3 = vector_4.begin();
		it3++; it3++;
		vector_4.insert(it3,15);
		print_vector(vector_4);

	nline(); std::cout << "\t17.0 insert fill\n";line();
		std::cout << "Insert 2, 3, 33:\n";
		vector_4.insert(it3, 5, 33);
		print_vector(vector_4);

	nline(); std::cout << "\t18.0 insert range\n";line();
		ft::vector<int> vector_r;
		vector_r.push_back(1000);
		vector_r.push_back(2000);
		vector_r.push_back(3000);
		vector_r.push_back(4000);

		ft::vector<int>::iterator it5 = vector_4.begin();
		ft::vector<int>::iterator it6 = vector_r.begin();
		ft::vector<int>::iterator it7 = vector_r.end();
		it7--;
		print_vector(vector_r);
		print_vector(vector_4);
		it5++;
		std::cout << "starting from it5 : " << *(it5 );
		(void) it6;
		std::cout << " insert from it6: " << *it6 << " to it7: " << *(it7) << std::endl;
		vector_4.insert(it5 , it6, it7);
		print_vector(vector_4);

	nline(); std::cout << "\t19.0 erase position\n";line();
		ft::vector<int>::iterator it8 = vector_4.begin();
		it8 = it8 + 2;
		print_vector(vector_4);
		std::cout << " erase begin + 2\n";
		vector_4.erase(it8);
		print_vector(vector_4);

	nline(); std::cout << "\t20.0 erase first/last\n";line();
		std::cout << " erase begin + 2 to end - 2\n";
		print_vector(vector_4);
		it8 = vector_4.begin();
		it8 = it8 + 2;
		ft::vector<int>::iterator it9 = vector_4.end();
		it9 = it9 - 2;
		vector_4.erase(it8, it9);
		print_vector(vector_4);

	nline(); std::cout << "\t21.0 swap\n";line();
		ft::vector<int> my_vector;
		N = 5;
		for (i = 0; i < N; i++)
		{
			my_vector.push_back(i * 10);
		}
		ft::vector<int>::iterator first_va, first_vb;
		first_va = my_vector.begin();
		first_va++;
		std::cout << "My Vector:\n";
		print_vector(my_vector);
		std::cout << "first_va: " << *first_va << std::endl;
		ft::vector<int>::const_iterator const_va;
		const_va = my_vector.begin();
		const_va++;
		std::cout << "const_va: " << *const_va << std::endl;
		std::cout << "equals ?: " << (first_va == const_va) << std::endl;

		ft::vector<int> other_vector;
		N = 17;
		for (i = 0; i < N; i++)
		{
			other_vector.push_back(i * (-10));
		}
		first_vb = other_vector.begin();
		std::cout << "Other Vector:\n";
		print_vector(other_vector);
		std::cout << "first_vb: " << *first_vb << std::endl;
		my_vector.swap(other_vector);
		std::cout << "After swap !!\n";
		std::cout << "My Vector:\n"; print_vector(my_vector);
		std::cout << "first_va: " << *first_va << std::endl;
		std::cout << "first_va++: " << *(++first_va) << std::endl;
		std::cout << "Other Vector:\n"; print_vector(other_vector);
		std::cout << "first_vb: " << *first_vb << std::endl;
		std::cout << "first_vb++: " << *(++first_vb) << std::endl;

	nline(); std::cout << "\t22.0 clear\n";line();
		std::cout << "Vector 2:\n";
		print_vector(vector_2);
		std::cout << "Clear !\n:";
		vector_2.clear();
		print_vector(vector_2);

	nline(); std::cout << "\t23.0 Non-Member Functions\n"; line();
		ft::vector<int> v1, v2;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v2 = v1;
		std::cout << "v1:\n"; print_vector(v1);
		std::cout << "v2:\n"; print_vector(v2);
		std::cout << "v1 == v2 ? : " << (v1 == v2) << std::endl;
		v1.push_back(4);
		std::cout << "v1.push_back(4)\n";
		std::cout << "v1:\n"; print_vector(v1);
		std::cout << "v2:\n"; print_vector(v2);
		std::cout << "v1 == v2 ? : " << (v1 == v2) << std::endl;
		std::cout << "v1 != v2 ? : " << (v1 != v2) << std::endl;
		v1.pop_back();
		std::cout << "v1.pop_back()\n";
		std::cout << "v1:\n"; print_vector(v1);
		std::cout << "v2:\n"; print_vector(v2);
		std::cout << "v1 <  v2 ? : " << (v1 < v2) << std::endl;
		std::cout << "v1 <= v2 ? : " << (v1 <= v2) << std::endl;
		std::cout << "v1 >  v2 ? : " << (v1 > v2) << std::endl;
		std::cout << "v1 >= v2 ? : " << (v1 >= v2) << std::endl;
		v1.push_back(5);
		std::cout << "v1.push_back(5)\n";
		std::cout << "v1:\n"; print_vector(v1);
		std::cout << "v2:\n"; print_vector(v2);
		std::cout << "v1 <  v2 ? : " << (v1 < v2) << std::endl;
		std::cout << "v1 <= v2 ? : " << (v1 <= v2) << std::endl;
		std::cout << "v1 >  v2 ? : " << (v1 > v2) << std::endl;
		std::cout << "v1 >= v2 ? : " << (v1 >= v2) << std::endl;

	nline(); std::cout << "\t24.0 Deep Copy\n"; line();
		ft::vector<int> v3 = v2;
		ft::vector<int> v4(v3);
		std::cout << "v2:\n"; print_vector(v2);
		std::cout << "v3:\n"; print_vector(v3);
		std::cout << "v4:\n"; print_vector(v4);

		std::cout << "clear v2:\n";
		v2.clear();
		std::cout << "v2:\n"; print_vector(v2);
		std::cout << "v3:\n"; print_vector(v3);
		std::cout << "v4:\n"; print_vector(v4);

		std::cout << "clear v3:\n";
		v3.clear();
		std::cout << "v3:\n"; print_vector(v3);
		std::cout << "v4:\n"; print_vector(v4);

		line();
		std::cout << std::endl;
		std::cout << std::endl;
};

static void testMap(void)
{
	std::cout << "=========================================\n";
	std::cout << "                 MAP TESTS				\n";
	std::cout << "=========================================\n";

	line(); std::cout << "\t0.0 Pair & Make_Pair:\n"; line();
		ft::pair<int, char>	par1(12, 'a');
		ft::pair<int, std::string> par2(0, "Paulo");
		std::cout << "pairs: \n";
		print_pair(par1);
		print_pair(par2);
		line();
		ft::pair<int, int> par3, par4;
		par3 = ft::make_pair(10,100);
		par4 = ft::make_pair(10,100);
		std::cout << "10 100 | 10 100\n";
		std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
		std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
		std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
		std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
		line();
		par3 = ft::make_pair(10,100);
		par4 = ft::make_pair(10,200);
		std::cout << "10 100 | 10 200\n";
		std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
		std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
		std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
		std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
		line();
		par3 = ft::make_pair(1,100);
		par4 = ft::make_pair(10,100);
		std::cout << "1 100 | 10 100\n";
		std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
		std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
		std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
		std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
		line();
		par3 = ft::make_pair(20,100);
		par4 = ft::make_pair(10,100);
		std::cout << "20 100 | 10 100\n";
		std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
		std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
		std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
		std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
		line();
		ft::pair<char, std::string> par;
		std::cout << "make_pair: \n";
		par = ft::make_pair('o', "paulo");
		print_pair(par);
		line();

	line(); std::cout << "1.0 Empty constructor:\n"; line();
		std::cout << "Initializing empty map mapa:\n:";
		ft::map<int, int> mapa;
		print_map(mapa);
		std::cout << "Adding some elements: \n";
		mapa[70] = 700;
		mapa[50] = 500;
		mapa[20] = 200;
		mapa[10] = 100;
		mapa[80] = 800;
		mapa[40] = 400;
		mapa[60] = 600;
		mapa[30] = 300;
		mapa[30] = 3000;
		print_map(mapa);
		std::cout << "Iterating: \n";
		ft::map<int, int>::iterator itm;
		itm = mapa.begin();
		while (itm != mapa.end())
		{
			std::cout << itm->first << " ";;
			itm++;
		}
		std::cout << std::endl;

	line(); std::cout << "\t2.0 Range constructor:\n"; line();
		ft::map<int, int>::iterator i1, i2;
		i1 = mapa.begin();
		i2 = mapa.end();
		i1++;
		i2--; i2--;
		ft::map<int,int> mapa_1(i1, i2);
		std::cout << "Mapa: \n";
		print_map(mapa);
		std::cout << "Range constructor from " << i1->first << " to " << i2->first << "(exclusive)" << std::endl;
		std::cout << "Mapa_1: \n";
		print_map(mapa_1);
		line();

	line(); std::cout << "\t3.0 Copy  constructor:\n"; line();
		ft::map<int,int> mapa_2(mapa_1);
		std::cout << "Mapa_1: \n";
		print_map(mapa_1);
		std::cout << "Mapa_2: \n";
		print_map(mapa_2);

	line(); std::cout << "4.0 Iterators\n"; line();
		ft::map<int,int>::iterator i3;
		std::cout << "Iterating over mapa_2\n";
		for (i3 = mapa_2.begin(); i3 != mapa_2.end(); i3++)
			std::cout << "f: " << i3->first << " s: " << i3->second << std::endl;
		line();

	line(); std::cout << "4.1 Const Iterators\n"; line();
		ft::map<int,int>::const_iterator const_i3;
		std::cout << "Iterating over mapa_2\n";
		for (const_i3 = mapa_2.begin(); const_i3 != mapa_2.end(); const_i3++)
			std::cout << "f: " << const_i3->first << " s: " << const_i3->second << std::endl;
		line();

	line(); std::cout << "5.0 Reverse Iterators\n"; line();
		ft::map<int,int>::reverse_iterator i4;
		std::cout << "Reverse Iterating over mapa_2\n";
		for (i4 = mapa_2.rbegin(); i4 != mapa_2.rend(); i4++)
			std::cout << "f: " << i4->first << " s: " << i4->second << std::endl;
		line();

	line(); std::cout << "5.1 Const Reverse Iterators\n"; line();
		ft::map<int,int>::reverse_iterator const_i4;
		std::cout << "Reverse Iterating over mapa_2\n";
		for (const_i4 = mapa_2.rbegin(); const_i4 != mapa_2.rend(); const_i4++)
			std::cout << "f: " << const_i4->first << " s: " << const_i4->second << std::endl;
		line();

	line(); std::cout << "6.0 Size, max_size & Empty\n"; line();
		std::cout << "Mapa_1: \n";
		print_map(mapa_1);
		std::cout << "Size: " << mapa_1.size() << std::endl;
		std::cout << "Max_size: " << mapa_1.max_size() << std::endl;
		std::cout << "Empty ? " << mapa_1.empty() << std::endl;
		line();
		std::cout << "Mapa_2: \n";
		print_map(mapa_2);
		std::cout << "Size: " << mapa_2.size() << std::endl;
		std::cout << "Max_size: " << mapa_2.max_size() << std::endl;
		std::cout << "Empty ? " << mapa_2.empty() << std::endl;
		line();

	line(); std::cout << "7.0 Operator []\n"; line();
		std::cout << "mapa_2[30] = 500;\n";
		mapa_2[30] = 500;
		print_map(mapa_2);
		std::cout << "mapa_2[35] = 350;\n";
		mapa_2[35] = 0;
		mapa_2[35] = 350;
		print_map(mapa_2);
		line();

	line(); std::cout << "\t8.0 insert_single\n"; line();
		ft::pair<int, int>	par_a;
		ft::map<int, int>::iterator it;
		par_a = ft::make_pair(15,150);
		print_pair(par_a);
		std::cout << "inserting pair(15,150) in mapa_2:\n";
		mapa_2.insert(par_a);
		print_map(mapa_2);
		std::cout << "Iterating ... \n";
		for (it = mapa_2.begin(); it != mapa_2.end(); it++)
			std::cout << it->first << ", :";
		std::cout << std::endl;
		std::cout << "inserting pair(5,50) in mapa_2 with make_pair:\n";
		mapa_2.insert(ft::make_pair(5,50));
		print_map(mapa_2);
		std::cout << "Iterating ... \n";
		for (it = mapa_2.begin(); it != mapa_2.end(); it++)
			std::cout << it->first << ", ";
		std::cout << std::endl;
		std::cout << "inserting again pair(15,150) in mapa_2 (can't repeat):\n";
		mapa_2.insert(par_a);
		print_map(mapa_2);
		std::cout << " Itens are always ordered by key\n";
		line();

	line(); std::cout << "\t9.0 insert hint\n"; line();
		ft::map<int,int>::iterator i5;
		i5 = mapa_2.begin();
		i5++; i5++;
		std::cout << "Hint begin() + 2. Inserting pair(80, 800) in mapa_2 with make_pair:\n";
		mapa_2.insert(i5, ft::make_pair(80, 800));
		print_map(mapa_2);
		line();

	line(); std::cout << "\t10.0 insert range\n"; line();
		ft::map<int, int>::iterator i6, i7;
		i6 = mapa_2.begin();
		i7 = mapa_2.end();
		i6++;
		i7--; i7--;
		ft::map<int,int> mapa_3;
		std::cout << "Mapa_2: \n";
		print_map(mapa_2);
		std::cout << "Insert range from " << i6->first << " to " << i7->first << " (exclusive)" << std::endl;
		mapa_3.insert(i6,i7);
		std::cout << "Mapa_3: \n";
		print_map(mapa_3);
		line();

	line(); std::cout << "\t11.0 erase key\n"; line();
		std::cout << "Erasing key 35: \n";
		size_t already_exists = mapa_2.erase(35);
		std::cout << "Key 35 already exists:" << already_exists << "\n";
		already_exists = mapa_2.erase(35);
		std::cout << "Key 35 already exists:" << already_exists << "\n";
		print_map(mapa_2);
		line();

	line(); std::cout << "\t12.0 erase position\n"; line();
		ft::map<int, int>::iterator i8;
		std::cout << "Erasing position begin() + 2 : \n";
		i8 = mapa_2.begin();
		i8++; i8++;
		mapa_2.erase(i8);
		print_map(mapa_2);
		line();

	line(); std::cout << "\t13.0 erase range\n"; line();
		ft::map<int, int>::iterator i9, i10;
		i9 = mapa_3.begin();
		i10 = mapa_3.end();
		i9++;
		i10--; i10--;
		print_map(mapa_3);
		std::cout << "Erasing mapa_3 from " << i9->first << " to " << i10->first << " (exclusive)" << std::endl;
		mapa_3.erase(i9, i10);
		print_map(mapa_3);
		line();

	line(); std::cout << "\t14.0 swap\n"; line();
		ft::map<int,int> mapa_a(mapa_2), mapa_b(mapa_3);
		ft::map<int,int>::iterator first_a, first_b;
		first_a = mapa_a.begin();
		first_b = mapa_b.begin();
		std::cout << "mapa_a: \n"; print_map(mapa_a);
		std::cout << "first_a: " << first_a->first << std::endl;
		std::cout << "mapa_b: \n"; print_map(mapa_b);
		std::cout << "first_b: " << first_b->first << std::endl;
		mapa_a.swap(mapa_b);
		std::cout << "Apos Swap: \n";
		std::cout << "mapa_a: \n"; print_map(mapa_a);
		std::cout << "first_a: " << first_a->first << std::endl;
		std::cout << "first_a++: " << (++first_a)->first << std::endl;
		std::cout << "mapa_b: \n"; print_map(mapa_b);
		std::cout << "first_b: " << first_b->first << std::endl;
		std::cout << "first_b++: " << (++first_b)->first << std::endl;
		line();

	line(); std::cout << "\t15.1 Iterator vs Const Iterator\n"; line();
		ft::map<int, int>::iterator it_normal = mapa_a.begin();
		ft::map<int, int>::const_iterator it_const = mapa_a.begin();
		std::cout << "it_normal: " << it_normal->first << std::endl;
		std::cout << "it_const: " << it_const->first << std::endl;
		std::cout << "Iguais ? " << (it_normal == it_const) << std::endl;
		line();

	line(); std::cout << "16.0 clear\n"; line();
		std::cout << "mapa_a.clear(): \n";
		mapa_a.clear();
		print_map(mapa_a);
		line();

	line(); std::cout << "17.0 find\n"; line();
		ft::map<int,int>::iterator i11;
		print_map(mapa_2);
		std::cout << "find 30 in mapa_2: \n";
		i11 = mapa_2.find(30);
		if (i11 != mapa_2.end())
			std::cout << "f: " << i11->first << " s: " << i11->second << std::endl;
		else
			std::cout << "Nao achou !\n";
		std::cout << "find 90 in mapa_3: \n";
		i11 = mapa_2.find(90);
		if (i11 != mapa_2.end())
			std::cout << "f: " << i11->first << " s: " << i11->second << std::endl;
		else
			std::cout << "Nao achou !\n";
		line();

	line(); std::cout << "\t18.0 count\n"; line();
		std::cout << "Mapa_2.count(30) :" << mapa_2.count(30) << std::endl;
		std::cout << "Mapa_2.count(90) :" << mapa_2.count(90) << std::endl;
		line();

	line(); std::cout << "\t 19.0 lower bound, upper bound\n"; line();
		print_map(mapa_2);
		ft::map<int, int>::iterator itm_bound;
		int numero = 1;
		itm_bound = mapa_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		numero = 20;
		itm_bound = mapa_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		numero = 40;
		itm_bound = mapa_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		numero = 200;
		itm_bound = mapa_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		numero = 1;
		itm_bound = mapa_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		numero = 20;
		itm_bound = mapa_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		numero = 40;
		itm_bound = mapa_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		numero = 200;
		itm_bound = mapa_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == mapa_2.end()) std::cout << "end !\n";
		else
			 std::cout << itm_bound->first << std::endl;
		line();

		line(); std::cout << "\t20.0 equal range\n"; line();
			ft::pair<ft::map<int,int>::iterator , ft::map<int,int>::iterator > ie;
			print_map(mapa_2);
			std::cout << "equal range_40: \n";
			ie = mapa_2.equal_range(40);
			std::cout << "ie->first: " << ie.first->first;
			std::cout << " ie->second: " << ie.second->first;
			std::cout << std::endl;
			line();
			std::cout << "equal range_45: \n";
			ie = mapa_2.equal_range(45);
			std::cout << "ie->first: " << ie.first->first;
			std::cout << " ie->second: " << ie.second->first;
			std::cout << std::endl;
			line();

		line(); std::cout << "\t21.0 Non-Member Functions\n"; line();
			ft::map<int,int> m1(mapa_2);
			ft::map<int,int> m2(mapa_2);
			std::cout << "m1:  \n"; print_map(m1);
			std::cout << "m2:  \n"; print_map(m2);
			std::cout << "m1 ==  m2 ? : " << (m1 == m2) << std::endl;
			std::cout << "m1 !=  m2 ? : " << (m1 != m2) << std::endl;
			std::cout << "m1 <  m2 ? : " << (m1 < m2) << std::endl;
			std::cout << "m1 <= m2 ? : " << (m1 <= m2) << std::endl;
			std::cout << "m1 >  m2 ? : " << (m1 > m2) << std::endl;
			std::cout << "m1 >= m2 ? : " << (m1 >= m2) << std::endl;
			std::cout << std::endl;
			m1.insert(ft::make_pair(22,222));
			std::cout << "m1:  \n"; print_map(m1);
			std::cout << "m2:  \n"; print_map(m2);
			std::cout << "m1 ==  m2 ? : " << (m1 == m2) << std::endl;
			std::cout << "m1 !=  m2 ? : " << (m1 != m2) << std::endl;
			std::cout << "m1 <  m2 ? : " << (m1 < m2) << std::endl;
			std::cout << "m1 <= m2 ? : " << (m1 <= m2) << std::endl;
			std::cout << "m1 >  m2 ? : " << (m1 > m2) << std::endl;
			std::cout << "m1 >= m2 ? : " << (m1 >= m2) << std::endl;
			line();

		line(); std::cout << "\tBIG SIZE TEST\n"; line();
			size_t NUM = 100000;
			size_t j;

			ft::vector<int>		v;
			v.reserve(NUM);
			for (j = 0; j < NUM; j++)
				v.push_back(j);
			std::cout << "v.size: " << v.size() << "\n";
			v.clear();
			ft::map<int,int>	m;
			for (j = 0; j < NUM; j++)
				m.insert(ft::make_pair(j,j));
			std::cout << "m.size: " << m.size() << "\n";
			m.clear();
			line();
			std::cout << std::endl;
			std::cout << std::endl;
}

static void testStack(void)
{
	std::cout << "=========================================\n";
	std::cout << "              STACK TESTS					\n";
	std::cout << "=========================================\n";

	nline(); std::cout << "\t1.0 Default constructor:\n";line();
		ft::stack<int> stack_1;
		std::cout << "Stack constructed with default constructor\n";
		print_stack(stack_1);

	nline(); std::cout << "\t2.0 Push:\n";line();
		ft::stack<int> stack_2;
		ft::stack<int> stack_3;
		std::cout << "s2: " << std::endl; print_stack(stack_2);
		std::cout << "s3: " << std::endl; print_stack(stack_3);
		stack_2.push(1);
		stack_3.push(343);
		std::cout << "s2: " << std::endl; print_stack(stack_2);
		std::cout << "s3: " << std::endl; print_stack(stack_3);
		stack_2.push(41);
		stack_3.push(33);
		std::cout << "s2: " << std::endl; print_stack(stack_2);
		std::cout << "s3: " << std::endl; print_stack(stack_3);
		stack_2.push(41);
		stack_3.push(33);
		stack_2.push(4156);
		stack_3.push(33345);
		stack_2.push(4165);
		stack_3.push(42);
		std::cout << "s2: " << std::endl; print_stack(stack_2);
		std::cout << "s3: " << std::endl; print_stack(stack_3);

	nline(); std::cout << "\t3.0 Pop:\n";line();
		stack_2.pop();
		stack_3.pop();
		std::cout << "s2: " << std::endl; print_stack(stack_2);
		std::cout << "s3: " << std::endl; print_stack(stack_3);
		stack_2.pop();
		stack_3.pop();
		std::cout << "s2: " << std::endl; print_stack(stack_2);
		std::cout << "s3: " << std::endl; print_stack(stack_3);
		stack_2.pop();
		stack_3.pop();
		stack_2.pop();
		stack_3.pop();
		stack_2.pop();
		stack_3.pop();
		std::cout << "s2: " << std::endl; print_stack(stack_2);
		std::cout << "s3: " << std::endl; print_stack(stack_3);

	nline(); std::cout << "\t4.0 Size, empty and top:\n";line();
		ft::stack<int> stack_4;
		std::cout << "s4 size: " << stack_4.size() << " | s4 empty: " << stack_4.size() << std::endl;
		stack_4.push(1243);
		std::cout << "s4 size: " << stack_4.size() << " | s4 empty: " << stack_4.size() << " | s4 top: " << stack_4.top() << std::endl;
		stack_4.push(-989);
		std::cout << "s4 size: " << stack_4.size() << " | s4 empty: " << stack_4.size() << " | s4 top: " << stack_4.top() << std::endl;
		stack_4.push(453989);
		stack_4.push(7656);
		stack_4.push(453565989);
		stack_4.push(489);
		std::cout << "s4 size: " << stack_4.size() << " | s4 empty: " << stack_4.size() << " | s4 top: " << stack_4.top() << std::endl;
		stack_4.pop();
		std::cout << "s4 size: " << stack_4.size() << " | s4 empty: " << stack_4.size() << " | s4 top: " << stack_4.top() << std::endl;
		stack_4.pop();
		stack_4.pop();
		stack_4.pop();
		stack_4.pop();
		std::cout << "s4 size: " << stack_4.size() << " | s4 empty: " << stack_4.size() << " | s4 top: " << stack_4.top() << std::endl;
		stack_4.pop();
		std::cout << "s4 size: " << stack_4.size() << " | s4 empty: " << stack_4.size() << std::endl;

	line(); std::cout << "\t21.0 Non-Member Functions\n"; line();
		ft::stack<int> s5;
		ft::stack<int> s6;
		std::cout << "s5 ==  s6 ? : " << (s5 == s6) << std::endl;
		std::cout << "s5 !=  s6 ? : " << (s5 != s6) << std::endl;
		std::cout << "s5 <  s6 ? : " << (s5 < s6) << std::endl;
		std::cout << "s5 <= s6 ? : " << (s5 <= s6) << std::endl;
		std::cout << "s5 >  s6 ? : " << (s5 > s6) << std::endl;
		std::cout << "s5 >= s6 ? : " << (s5 >= s6) << std::endl;
		std::cout << std::endl;

		s5.push(12); std::cout << "push 12 in s5" << std::endl;
		s6.push(12); std::cout << "push 12 in s6" << std::endl;
		std::cout << "s5 ==  s6 ? : " << (s5 == s6) << std::endl;
		std::cout << "s5 !=  s6 ? : " << (s5 != s6) << std::endl;
		std::cout << "s5 <  s6 ? : " << (s5 < s6) << std::endl;
		std::cout << "s5 <= s6 ? : " << (s5 <= s6) << std::endl;
		std::cout << "s5 >  s6 ? : " << (s5 > s6) << std::endl;
		std::cout << "s5 >= s6 ? : " << (s5 >= s6) << std::endl;
		std::cout << std::endl;

		s6.push(125); std::cout << "push 125 in s6" << std::endl;
		std::cout << "s5 ==  s6 ? : " << (s5 == s6) << std::endl;
		std::cout << "s5 !=  s6 ? : " << (s5 != s6) << std::endl;
		std::cout << "s5 <  s6 ? : " << (s5 < s6) << std::endl;
		std::cout << "s5 <= s6 ? : " << (s5 <= s6) << std::endl;
		std::cout << "s5 >  s6 ? : " << (s5 > s6) << std::endl;
		std::cout << "s5 >= s6 ? : " << (s5 >= s6) << std::endl;
		std::cout << std::endl;

		line();
		std::cout << std::endl;
		std::cout << std::endl;
}

static void testSet(void)
{
	std::cout << "=========================================\n";
	std::cout << "              SET TESTS					\n";
	std::cout << "=========================================\n";

	line(); std::cout << "1.0 Empty constructor:\n"; line();
		std::cout << "Initializing empty set:\n:";
		ft::set<int> setter;
		print_set(setter);
		std::cout << "Adding some elements: \n";
		setter.insert(70);
		setter.insert(50);
		setter.insert(20);
		setter.insert(10);
		setter.insert(80);
		setter.insert(40);
		setter.insert(60);
		setter.insert(30);
		setter.insert(30);
		print_set(setter);
		std::cout << "Iterating: \n";
		ft::set<int>::iterator itm;
		itm = setter.begin();
		while (itm != setter.end())
		{
			std::cout << *itm << " ";;
			itm++;
		}
		std::cout << std::endl;

	line(); std::cout << "\t2.0 Range constructor:\n"; line();
		ft::set<int>::iterator i1, i2;
		i1 = setter.begin();
		i2 = setter.end();
		i1++;
		i2--; i2--;
		ft::set<int> setter_1(i1, i2);
		std::cout << "Setter: \n";
		print_set(setter);
		std::cout << "Range constructor from " << *i1 << " to " << *i2 << "(exclusive)" << std::endl;
		std::cout << "Setter_1: \n";
		print_set(setter_1);
		line();

	line(); std::cout << "\t3.0 Copy  constructor:\n"; line();
		ft::set<int> setter_2(setter_1);
		std::cout << "Setter_1: \n";
		print_set(setter_1);
		std::cout << "Setter_2: \n";
		print_set(setter_2);

	line(); std::cout << "4.0 Iterators\n"; line();
		ft::set<int>::iterator i3;
		std::cout << "Iterating over setter_2\n";
		for (i3 = setter_2.begin(); i3 != setter_2.end(); i3++)
			std::cout << "iterator: " << *i3 << std::endl;
		line();

	line(); std::cout << "4.1 Const Iterators\n"; line();
		ft::set<int>::const_iterator const_i3;
		std::cout << "Const Iterating over setter_2\n";
		for (const_i3 = setter_2.begin(); const_i3 != setter_2.end(); const_i3++)
			std::cout << "iterator: " << *const_i3 << std::endl;
		line();

	line(); std::cout << "5.0 Reverse Iterators\n"; line();
		ft::set<int>::reverse_iterator i4;
		std::cout << "Reverse Iterating over setter_2\n";
		for (i4 = setter_2.rbegin(); i4 != setter_2.rend(); i4++)
			std::cout << "iterator: " << *i4 << std::endl;
		line();

	line(); std::cout << "5.1 Const Reverse Iterators\n"; line();
		ft::set<int>::reverse_iterator const_i4;
		std::cout << "Reverse Const Iterating over setter_2\n";
		for (const_i4 = setter_2.rbegin(); const_i4 != setter_2.rend(); const_i4++)
			std::cout << "iterator: " << *const_i4 << std::endl;
		line();

	line(); std::cout << "6.0 Size, max_size & Empty\n"; line();
		std::cout << "Setter_1: \n";
		print_set(setter_1);
		std::cout << "Size: " << setter_1.size() << std::endl;
		std::cout << "Max_size: " << setter_1.max_size() << std::endl;
		std::cout << "Empty ? " << setter_1.empty() << std::endl;
		line();
		std::cout << "Setter_2: \n";
		print_set(setter_2);
		std::cout << "Size: " << setter_2.size() << std::endl;
		std::cout << "Max_size: " << setter_2.max_size() << std::endl;
		std::cout << "Empty ? " << setter_2.empty() << std::endl;
		line();

	line(); std::cout << "\t7.0 insert_single\n"; line();
		ft::set<int>::iterator it;
		std::cout << "inserting 345345 in setter_2:\n";
		setter_2.insert(345345);
		print_set(setter_2);
		std::cout << "Iterating ... \n";
		for (it = setter_2.begin(); it != setter_2.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
		std::cout << "inserting -12314 in setter_2:\n";
		setter_2.insert(-12314);
		print_set(setter_2);
		std::cout << "Iterating ... \n";
		for (it = setter_2.begin(); it != setter_2.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
		std::cout << "inserting again 345345 in setter_2 (can't repeat):\n";
		setter_2.insert(345345);
		print_set(setter_2);
		std::cout << " Itens are always ordered by key\n";
		line();

	line(); std::cout << "\t8.0 insert hint\n"; line();
		ft::set<int>::iterator i5;
		i5 = setter_2.begin();
		i5++; i5++;
		std::cout << "Hint begin() + 2. Inserting 58 in setter_2:\n";
		setter_2.insert(i5, 58);
		print_set(setter_2);
		line();

	line(); std::cout << "\t9.0 insert range\n"; line();
		ft::set<int>::iterator i6, i7;
		i6 = setter_2.begin();
		i7 = setter_2.end();
		i6++;
		i7--; i7--;
		ft::set<int> setter_3;
		std::cout << "Setter_2: \n";
		print_set(setter_2);
		std::cout << "Insert range from " << *i6 << " to " << *i7 << " (exclusive)" << std::endl;
		setter_3.insert(i6,i7);
		std::cout << "Setter_3: \n";
		print_set(setter_3);
		line();

	line(); std::cout << "\t10.0 erase key\n"; line();
		std::cout << "Erasing key 30: \n";
		size_t already_exists = setter_2.erase(30);
		std::cout << "Key 30 already exists:" << already_exists << "\n";
		already_exists = setter_2.erase(30);
		std::cout << "Key 30 already exists:" << already_exists << "\n";
		print_set(setter_2);
		line();

	line(); std::cout << "\t11.0 erase position\n"; line();
		ft::set<int>::iterator i8;
		std::cout << "Erasing position begin() + 2 : \n";
		i8 = setter_2.begin();
		i8++; i8++;
		setter_2.erase(i8);
		print_set(setter_2);
		line();

	line(); std::cout << "\t12.0 erase range\n"; line();
		ft::set<int>::iterator i9, i10;
		i9 = setter_3.begin();
		i10 = setter_3.end();
		i9++;
		i10--; i10--;
		print_set(setter_3);
		std::cout << "Erasing setter_3 from " << *i9 << " to " << *i10 << " (exclusive)" << std::endl;
		setter_3.erase(i9, i10);
		print_set(setter_3);
		line();

	line(); std::cout << "\t13.0 swap\n"; line();
		ft::set<int> setter_a(setter_2), setter_b(setter_3);
		ft::set<int>::iterator first_a, first_b;
		first_a = setter_a.begin();
		first_b = setter_b.begin();
		std::cout << "setter_a: \n"; print_set(setter_a);
		std::cout << "first_a: " << *first_a << std::endl;
		std::cout << "setter_b: \n"; print_set(setter_b);
		std::cout << "first_b: " << *first_b << std::endl;
		setter_a.swap(setter_b);
		std::cout << "Apos Swap: \n";
		std::cout << "setter_a: \n"; print_set(setter_a);
		std::cout << "first_a: " << *first_a << std::endl;
		std::cout << "first_a++: " << *(++first_a) << std::endl;
		std::cout << "setter_b: \n"; print_set(setter_b);
		std::cout << "first_b: " << *first_b << std::endl;
		std::cout << "first_b++: " << *(++first_b) << std::endl;
		line();

	line(); std::cout << "\t14.1 Iterator vs Const Iterator\n"; line();
		ft::set<int>::iterator it_normal = setter_a.begin();
		ft::set<int>::const_iterator it_const = setter_a.begin();
		std::cout << "it_normal: " << *it_normal << std::endl;
		std::cout << "it_const: " << *it_const << std::endl;
		std::cout << "Iguais ? " << (it_normal == it_const) << std::endl;
		line();

	line(); std::cout << "15.0 clear\n"; line();
		std::cout << "setter_a.clear(): \n";
		setter_a.clear();
		print_set(setter_a);
		line();

	line(); std::cout << "16.0 find\n"; line();
		ft::set<int>::iterator i11;
		print_set(setter_2);
		std::cout << "find 30 in setter_2: \n";
		i11 = setter_2.find(30);
		if (i11 != setter_2.end())
			std::cout << "value: " << *i11 << std::endl;
		else
			std::cout << "Nao achou !\n";
		std::cout << "find 60 in seta_3: \n";
		i11 = setter_2.find(60);
		if (i11 != setter_2.end())
			std::cout << "value: " << *i11 << std::endl;
		else
			std::cout << "Nao achou !\n";
		line();

	line(); std::cout << "\t17.0 count\n"; line();
		std::cout << "Setter_2.count(30) :" << setter_2.count(30) << std::endl;
		std::cout << "Setter_2.count(60) :" << setter_2.count(60) << std::endl;
		line();

	line(); std::cout << "\t 18.0 lower bound, upper bound\n"; line();
		print_set(setter_2);
		ft::set<int>::iterator itm_bound;
		int numero = 1;
		itm_bound = setter_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		numero = 20;
		itm_bound = setter_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		numero = 40;
		itm_bound = setter_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		numero = 200;
		itm_bound = setter_2.lower_bound(numero);
		std::cout << "lb: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		numero = 1;
		itm_bound = setter_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		numero = 20;
		itm_bound = setter_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		numero = 40;
		itm_bound = setter_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		numero = 200;
		itm_bound = setter_2.upper_bound(numero);
		std::cout << "ub: " << numero <<  "---> ";
		if (itm_bound == setter_2.end()) std::cout << "end !\n";
		else
			 std::cout << *itm_bound << std::endl;
		line();

		line(); std::cout << "\t19.0 equal range\n"; line();
			ft::pair<ft::set<int>::iterator , ft::set<int>::iterator > ie;
			print_set(setter_2);
			std::cout << "equal range_50: \n";
			ie = setter_2.equal_range(50);
			std::cout << "ie->first: " << *(ie.first);
			std::cout << " ie->second: " << *(ie.second);
			std::cout << std::endl;
			line();
			std::cout << "equal range_61: \n";
			ie = setter_2.equal_range(61);
			std::cout << "ie->first: " << *(ie.first);
			std::cout << " ie->second: " << *(ie.second);
			std::cout << std::endl;
			line();

		line(); std::cout << "\t20.0 Non-Member Functions\n"; line();
			ft::set<int> s1(setter_2);
			ft::set<int> s2(setter_2);
			std::cout << "s1:  \n"; print_set(s1);
			std::cout << "s2:  \n"; print_set(s2);
			std::cout << "s1 ==  s2 ? : " << (s1 == s2) << std::endl;
			std::cout << "s1 !=  s2 ? : " << (s1 != s2) << std::endl;
			std::cout << "s1 <  s2 ? : " << (s1 < s2) << std::endl;
			std::cout << "s1 <= s2 ? : " << (s1 <= s2) << std::endl;
			std::cout << "s1 >  s2 ? : " << (s1 > s2) << std::endl;
			std::cout << "s1 >= s2 ? : " << (s1 >= s2) << std::endl;
			std::cout << std::endl;
			s1.insert(4242);
			std::cout << "s1:  \n"; print_set(s1);
			std::cout << "s2:  \n"; print_set(s2);
			std::cout << "s1 ==  s2 ? : " << (s1 == s2) << std::endl;
			std::cout << "s1 !=  s2 ? : " << (s1 != s2) << std::endl;
			std::cout << "s1 <  s2 ? : " << (s1 < s2) << std::endl;
			std::cout << "s1 <= s2 ? : " << (s1 <= s2) << std::endl;
			std::cout << "s1 >  s2 ? : " << (s1 > s2) << std::endl;
			std::cout << "s1 >= s2 ? : " << (s1 >= s2) << std::endl;
			line();

		line(); std::cout << "\tBIG SIZE TEST\n"; line();
			size_t NUM = 100000;
			size_t j;

			ft::set<int>	s;
			for (j = 0; j < NUM; j++)
				s.insert(j);
			std::cout << "s.size: " << s.size() << "\n";
			s.clear();
}
