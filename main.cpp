#include <iostream>
#include <map>
#include "map.hpp"
#include <cstdlib>
#include <ctime>
#include "reverse_iterator.hpp"

using namespace std;

void eval_reverse(){
	map<int, int> a;
	ft::map<int, int> b;

	for (int i = 0; i < 10; i++){
		int r = rand() % 100;
		cout << r << ' ';
		a.insert(make_pair(r, r));
		b.insert(ft::make_pair(r, r));
	}
	cout << endl;

	int pos = rand() % a.size();

	map<int, int>::iterator i;
	ft::map<int, int>::iterator i1;

	i = a.begin();
	i1 = b.begin();

	for (int j = 0; j < pos; j++){
		i++;
		i1++;
	}

	a.erase(i);
	b.erase(i1);

	i = a.begin();
	i1 = b.begin();

	while (i != a.end()){
		cout << (*i).first << ' ';
		i++;
	}
	cout << endl;
}

void eval_erase(){
    map<int, int> a;
	ft::map<int, int> b;

    for (int i = 0; i < 10; i++){
        int r = rand() % 100;
        cout << r << ' ';
        a.insert(make_pair(r, r));
        b.insert(ft::make_pair(r, r));
    }
    cout << endl;

    int pos = rand() % a.size();

    map<int, int>::iterator i;
    ft::map<int, int>::iterator i1;

    i = a.begin();
    i1 = b.begin();

    for (int j = 0; j < pos; j++){
        i++;
        i1++;
    }

    a.erase(i);
    b.erase(i1);

    i = a.begin();
    i1 = b.begin();

    while (i != a.end()){
        cout << (*i).first << ' ';
        i++;
    }
    cout << endl;

     while (i1 != b.end()){
        cout << (*i1).first << ' ';
        i1++;
    }
    cout << endl;
}

void eval_begin_end(){
    map<int, int> a;
	ft::map<int, int> b;

    for (int i = 0; i < 10; i++){
        int r = rand() % 100;
        cout << r << ' ';
        a.insert(make_pair(r, r));
        b.insert(ft::make_pair(r, r));
    }
    cout << endl;
    map<int, int>::iterator i;
    ft::map<int, int>::iterator i1;

    i = a.begin();
    i1 = b.begin();

    while (i != a.end()){
        cout << (*i).first << ' ';
        i++;
    }
    cout << endl;

     while (i1 != b.end()){
        cout << (*i1).first << ' ';
        i1++;
    }
    cout << endl;
}

void eval_rbegin_rend(){
	map<int, int> a;
	ft::map<int, int> b;

	for (int i = 0; i < 10; i++){
		int r = rand() % 100;
		cout << r << ' ';
		a.insert(make_pair(r, r));
		b.insert(ft::make_pair(r, r));
	}
	cout << endl;
	map<int, int>::reverse_iterator i;
	ft::map<int, int>::reverse_iterator i1;

	i = a.rend();
	i1 = b.rend();
	
	while (i != a.rbegin()){
		cout << (*i).first << ' ';
		i++;
	}
	cout << endl;

	while (i1 != b.rbegin()++){
		cout << (*i1).first << ' ';
		i1++;
	}
	cout << endl;
}

int main()
{
//    srand(time(NULL));
//	map<int, int> a;
//	ft::map<int, int> b;
//	ft::map<int, int>::iterator i;
//	 ft::map<int, int>::iterator i1;
//	 ft::map<int, int>::iterator i2;
//
//	 i1 = b.insert(ft::make_pair(3, 3)).first;
//	a.insert(make_pair(2, 2));
//	i = b.insert(ft::make_pair(2, 2)).first;
//	i2 = b.begin();
	//	pair<map<int, int>::iterator, bool> b = a.insert(pair<int, int>(1, 2));
	//	cout << b.first << ' ' << b.second << endl;
//	cout << (*i).first << endl;
//	 cout << (*i1).first << endl;
//	 ++i1;
//	 cout << (*i2).first << endl;
//	 i2++;
//	 cout << (*i2).first << endl;
//    cout << b.size() << endl;
//	cout << a[2] << endl;
    eval_rbegin_rend();

}
