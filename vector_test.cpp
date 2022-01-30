#include "vector.hpp"
#include <iostream>
#include <vector>
#include "stack.hpp"


using namespace std;

void eval_push_pop(){
	ft::vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i * 3);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << endl;
	}
	for (int i = 0; i < 11; i++)
	{
		vec.pop_back();
		cout << vec.size() << endl;
	}
}

void eval_front_back_at(){
	ft::vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
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
	ft::vector<int> vec;
	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	cout << "size: " << vec.size() << endl;
	cout << "max_size: " << vec.max_size() << endl;
	cout << "max_size1: " << vec1.max_size() << endl;
	cout << "capacity: " << vec.capacity() << endl;
	cout << "empty: " << vec.empty() << endl;
}

void eval_resize(){
	ft::vector<int> vec;
//	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	vec.resize(5);
	cout << "capacity1: " << vec.capacity() << endl;
	vec.resize(8,100);
	cout << "capacity2: " << vec.capacity() << endl;
	vec.resize(12);
	cout << "capacity3: " << vec.capacity() << endl;
}


void eval_end_begin()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << endl;
		t++;
	}
	ft::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	ft::vector<int>::iterator k = vec1.begin();
	while (k != vec1.end())
	{
		cout << *k << endl;
		k++;
	}
}


void eval_rend_rbegin()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::reverse_iterator t = vec.rbegin();
	while (t != vec.rend())
	{
		cout << *t << endl;
		t++;
	}
	ft::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	ft::vector<int>::reverse_iterator k = vec1.rbegin();
	while (k != vec1.rend())
	{
		cout << *k << endl;
		k++;
	}
}

void eval_const_rend_rbegin()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::const_reverse_iterator t = vec.rbegin();
	while (t != vec.rend())
	{
		cout << *t << endl;
		t++;
	}
	ft::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	ft::vector<int>::const_reverse_iterator k = vec1.rbegin();
	while (k != vec1.rend())
	{
		cout << *k << endl;
		k++;
	}
}

void eval_const_end_begin()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << endl;
		t++;
	}
	ft::vector<int> vec1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	ft::vector<int>::const_iterator k = vec1.begin();
	while (k != vec1.end())
	{
		cout << *k << endl;
		k++;
	}
}

void eval_reserve(){
	int sz;

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
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of std first: " << int (first.size()) << '\n';
	std::cout << "Size of std second: " << int (second.size()) << '\n';
	std::cout << "Size of std third: " << int (third.size()) << '\n';


	ft::vector<int> first1;
	ft::vector<int> second1;
	ft::vector<int> third1;

	first1.assign (7,100);             // 7 ints with a value of 100
	ft::vector<int>::iterator it1;
	it1=first1.begin()+1;

	second1.assign(it1,first1.end()-1); // the 5 central values of first

	int myints1[] = {1776,7,4};
	third1.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of ft first: " << int (first1.size()) << '\n';
	std::cout << "Size of ft second: " << int (second1.size()) << '\n';
	std::cout << "Size of ft third: " << int (third1.size()) << '\n';

}

void eval_insert(){
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.insert(it, 666);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << endl;
		t++;
	}

	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.insert(it1,  666);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << endl;
		t1++;
	}

}


void eval_insert2(){
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.insert(it, 3, 666);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << endl;
		t++;
	}

	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.insert(it1, 3, 666);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << endl;
		t1++;
	}

}

void eval_insert3(){
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
		cout << *t << endl;
		t++;
	}

	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.insert(it1, it3, it3 + 3);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << endl;
		t1++;
	}

}

void eval_erase(){
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.erase(it);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << endl;
		t++;
	}

	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.erase(it1);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << endl;
		t1++;
	}
}

void eval_erase1(){
	vector<int> vec;
	std::vector<int>::iterator it;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	it = vec.begin();
	vec.erase(it, it + 5);
	vector<int>::const_iterator t = vec.begin();
	while (t != vec.end())
	{
		cout << *t << endl;
		t++;
	}

	ft::vector<int> vec1;
	ft::vector<int>::iterator it1;
	for (int i = 0; i < 10; i++)
		vec1.push_back(i);
	it1 = vec1.begin();
	vec1.erase(it1, it1 + 5);
	ft::vector<int>::const_iterator t1 = vec1.begin();
	while (t1 != vec1.end())
	{
		cout << *t1 << endl;
		t1++;
	}
}

int main()
{
	eval_erase1();

}
