#include "vector.hpp"
#include <iostream>
#include <vector>
#include "stack.hpp"


using namespace std;

void eval_push_pop(){
	std::cout << "<<<<<<<<<<<PUSH,POP>>>>>>>>>>>>" << "\n";
	ft::vector<int> vec;
	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i * 3);
		vec1.push_back(i * 3);
	}

	cout << "STD:\n";
	cout << "push:\n";
	for (int i = 0; i < 10; i++)
	{
		cout << vec1[i] << " ";
	}
	cout << "\npop:\n";
	for (int i = 0; i < 10; i++)
	{
		vec1.pop_back();
		cout << vec1.size() << " ";
	}

	cout << "\nFT:\n";
	cout << "push:\n";
	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << " ";
	}
	cout << "\npop:\n";
	for (int i = 0; i < 10; i++)
	{
		vec.pop_back();
		cout << vec.size() << " ";
	}
	cout << "\n";
}

void eval_front_back_at(){
	std::cout << "<<<<<<<<FRONT,BACK,AT>>>>>>>>>" << "\n";
	ft::vector<int> vec;
	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		vec1.push_back(i);
	}
	cout << "STD:\n";
	cout << "front: " << vec1.front() << endl;
	cout << "back: " << vec1.back() << endl;
	cout << "at: " << vec1.at(6) << endl;
	try {
		cout << "error at: " << vec1.at(13) << endl;}
	catch (std::exception &e) {
		cout << " Out of Range error" << endl;
	}

	cout << "FT:\n";
	cout << "front: " << vec.front() << endl;
	cout << "back: " << vec.back() << endl;
	cout << "at: " << vec.at(6) << endl;
	try {
		cout << "error at: " << vec.at(13) << endl;}
	catch (std::exception &e) {
		cout << " Out of Range error" << endl;
	}
}

void eval_size(){
	std::cout << "<<<<<<<<SIZE,MAX_SIZE>>>>>>>>>>" << "\n";
	ft::vector<int> vec;
	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		vec1.push_back(i);
	}

	cout << "STD:\n";
	cout << "size: " << vec1.size() << endl;
	cout << "max_size: " << vec1.max_size() << endl;
	cout << "capacity: " << vec1.capacity() << endl;
	cout << "empty: " << vec1.empty() << endl;

	cout << "FT:\n";
	cout << "size: " << vec.size() << endl;
	cout << "max_size: " << vec.max_size() << endl;
	cout << "capacity: " << vec.capacity() << endl;
	cout << "empty: " << vec.empty() << endl;
}

void eval_resize(){
	std::cout << "<<<<<<<<<<RESIZE>>>>>>>>>>>>" << "\n";
	ft::vector<int> vec;
	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		vec1.push_back(i);
	}
	cout << "STD:\n";
	vec1.resize(5);
	cout << "size1: " << vec1.size() << endl;
	vec1.resize(8,100);
	cout << "size2: " << vec1.size() << endl;
	vec1.resize(12);
	cout << "size3: " << vec1.size() << endl;

	cout << "FT:\n";
	vec.resize(5);
	cout << "size1: " << vec.size() << endl;
	vec.resize(8,100);
	cout << "size2: " << vec.size() << endl;
	vec.resize(12);
	cout << "size3: " << vec.size() << endl;
}


void eval_end_begin()
{
	std::cout << "<<<<<<<<<BEGIN,END>>>>>>>>>>>" << "\n";
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::iterator t = vec.begin();
	cout << "STD:\n";
	while (t != vec.end())
	{
		cout << *t << " ";
		t++;
	}
	ft::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	cout << "\nFT:\n";
	ft::vector<int>::iterator k = vec1.begin();
	while (k != vec1.end())
	{
		cout << *k << " ";
		k++;
	}
	cout << "\n";
}


void eval_rend_rbegin()
{
	std::cout << "<<<<<<<<RBEGIN,REND>>>>>>>>>>" << "\n";
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::reverse_iterator t = vec.rbegin();
	cout << "STD:\n";
	while (t != vec.rend())
	{
		cout << *t << " ";
		t++;
	}
	ft::vector<int> vec1;
	cout << "\nFT:\n";
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	ft::vector<int>::reverse_iterator k = vec1.rbegin();
	while (k != vec1.rend())
	{
		cout << *k << " ";
		k++;
	}
	cout << "\n";
}

void eval_const_rend_rbegin()
{
	std::cout << "<<<<<<RBEGIN,REND,CONST>>>>>>>>" << "\n";
	cout << "STD:\n";
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::const_reverse_iterator t = vec.rbegin();
	while (t != vec.rend())
	{
		cout << *t << " ";
		t++;
	}
	cout << "\nFT:\n";
	ft::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	ft::vector<int>::const_reverse_iterator k = vec1.rbegin();
	while (k != vec1.rend())
	{
		cout << *k << " ";
		k++;
	}
	cout << "\n";
}

void eval_const_end_begin()
{
	std::cout << "<<<<<<<BEGIN,END,CONST>>>>>>>>>" << "\n";
	cout << "STD:\n";
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << " ";
		t++;
	}
	cout << "\nFT:\n";
	ft::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	ft::vector<int>::const_iterator k = vec1.begin();
	while (k != vec1.end())
	{
		cout << *k << " ";
		k++;
	}
	cout << "\n";
}

void eval_reserve(){
	std::cout << "<<<<<<<<<<<RESERVE>>>>>>>>>>>>" << "\n";
	cout << "STD:\n";

	unsigned long sz1;

	vector<int> foo1;
	sz1 = foo1.capacity();
	cout << "making foo grow:\n";
	foo1.push_back(sz1);
	for (int i=0; i<100; ++i) {
		foo1.push_back(i);
		if (sz1!=foo1.capacity()) {
			sz1 = foo1.capacity();
			cout << "capacity changed: " << sz1 << '\n';
		}
	}

	vector<int> bar1;
	sz1 = bar1.capacity();
	bar1.reserve(100);   // this is the only difference with foo above
	cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar1.push_back(i);
		if (sz1!=bar1.capacity()) {
			sz1 = bar1.capacity();
			cout << "capacity changed: " << sz1 << '\n';
		}
	}

	cout << "FT:\n";

	unsigned long sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void eval_assign(){
	std::cout << "<<<<<<<<<<<ASSIGN>>>>>>>>>>>>" << "\n";
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	cout << "STD:\n";
	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first


	std::cout << "Size of std first: " << int (first.size()) << '\n';
	std::cout << "Size of std second: " << int (second.size()) << '\n';
	std::cout << "Size of std third: " << int (third.size()) << '\n';


	ft::vector<int> first1;
	ft::vector<int> second1;
	ft::vector<int> third1;
	cout << "FT:\n";
	first1.assign (7,100);             // 7 ints with a value of 100
	ft::vector<int>::iterator it1;
	it1=first1.begin()+1;

	second1.assign(it1,first1.end()-1); // the 5 central values of first


	std::cout << "Size of ft first: " << int (first1.size()) << '\n';
	std::cout << "Size of ft second: " << int (second1.size()) << '\n';
	std::cout << "Size of ft third: " << int (third1.size()) << '\n';

}

void eval_insert(){
	std::cout << "<<<<<<<<<<<INSERT>>>>>>>>>>>>" << "\n";
	cout << "STD:\n";
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.insert(it, 666);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << " ";
		t++;
	}
	cout << "\nFT:\n";
	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.insert(it1,  666);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << " ";
		t1++;
	}
	cout << "\n";

}


void eval_insert2(){
	cout << "\nSTD:\n";
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.insert(it, 3, 666);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << " ";
		t++;
	}
	cout << "\nFT:\n";
	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.insert(it1, 3, 666);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << " ";
		t1++;
	}
	cout << "\n";

}

void eval_insert3(){
	cout << "\nSTD:\n";
	vector<int> vec3;
	std::vector<int>::iterator it3;
	for (int i = 0; i < 10; i++)
		vec3.push_back(i);
	it3 = vec3.begin();

	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.insert(it, it3, it3 + 3);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << " ";
		t++;
	}
	cout << "\nFT:\n";
	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.insert(it1, it3, it3 + 3);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << " ";
		t1++;
	}
	cout << "\n";

}

void eval_erase(){
	std::cout << "<<<<<<<<<<<ERASE>>>>>>>>>>>>" << "\n";
	cout << "STD:\n";
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.erase(it);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << " ";
		t++;
	}
	cout << "\nFT:\n";
	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.erase(it1);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << " ";
		t1++;
	}
	cout << "\n";
}

void eval_erase1(){
	cout << "\nSTD:\n";
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.erase(it, it + 5);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << " ";
		t++;
	}
	cout << "\nFT:\n";
	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.erase(it1, it1 + 5);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << " ";
		t1++;
	}
	cout << "\n";
}

int main()
{
	cout << ">>>>>>>>>>>>VECTOR<<<<<<<<<<<<\n\n";
	eval_push_pop();
	eval_front_back_at();
	eval_size();
	eval_resize();
	eval_end_begin();
	eval_rend_rbegin();
	eval_const_end_begin();
	eval_const_rend_rbegin();
	eval_reserve();
	eval_assign();
	eval_insert();
	eval_insert2();
	eval_insert3();
	eval_erase();
	eval_erase1();
}
