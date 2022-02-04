#include <iostream>
#include <stack>
#include "stack.hpp"

using namespace std;

void eval_push(){
	cout << "!=!=!=!=!=PUSH!=!=!=!=!=\n";
	cout << "STD:\n";
	std::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << "\nFT:\n";

	ft::stack<int> mystack1;

	for (int i=0; i<5; ++i) mystack1.push(i);

	std::cout << "Popping out elements...";
	while (!mystack1.empty())
	{
		std::cout << ' ' << mystack1.top();
		mystack1.pop();
	}
	std::cout << '\n';

}

void eval_size(){
	cout << "!=!=!=!=!=SIZE!=!=!=!=!=\n";
	cout << "STD:\n";
	std::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

	cout << "FT:\n";
	ft::stack<int> myints1;
	std::cout << "0. size: " << myints1.size() << '\n';

	for (int i=0; i<5; i++) myints1.push(i);
	std::cout << "1. size: " << myints1.size() << '\n';

	myints1.pop();
	std::cout << "2. size: " << myints1.size() << '\n';
}

void eval_top(){
	cout << "!=!=!=!=!=TOP!=!=!=!=!=\n";
	cout << "STD:\n";
	std::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "std::mystack.top() is now " << mystack.top() << '\n';

	cout << "FT:\n";
	ft::stack<int> mystack1;

	mystack1.push(10);
	mystack1.push(20);

	mystack1.top() -= 5;

	std::cout << "ft::mystack.top() is now " << mystack1.top() << '\n';
}

void eval_pop(){
	cout << "!=!=!=!=!=POP!=!=!=!=!=\n";
	cout << "STD:\n";
	std::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

	cout << "FT:\n";
	ft::stack<int> mystack1;

	for (int i=0; i<5; ++i) mystack1.push(i);

	std::cout << "Popping out elements...";
	while (!mystack1.empty())
	{
		std::cout << ' ' << mystack1.top();
		mystack1.pop();
	}
	std::cout << '\n';
}

int main(){
	cout << "==========STACK==========\n\n";
	eval_push();
	eval_size();
	eval_top();
	eval_pop();
};