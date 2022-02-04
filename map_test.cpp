#include <iostream>
#include <map>
#include "map.hpp"
#include <cstdlib>
#include <ctime>
#include "reverse_iterator.hpp"

using namespace std;

void eval_reverse(){
	std::cout << "+++++++++++REVERSE+++++++++++" << "\n";
	map<int, int> a;
	ft::map<int, int> b;

	for (int i = 0; i < 10; i++){
		int r = rand() % 100;
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
	cout << "STD:\n";
	while (i != a.end()){
		cout << (*i).first << ' ';
		i++;
	}
	cout << endl;
	cout << "FT:\n";
	while (i1 != b.end()){
		cout << (*i1).first << ' ';
		i1++;
	}
	cout << endl;
}

void eval_erase(){
	std::cout << "+++++++++++ERASE+++++++++++" << "\n";
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
	cout << "STD:\n";
    while (i != a.end()){
        cout << (*i).first << ' ';
        i++;
    }
    cout << endl;
	cout << "FT:\n";
     while (i1 != b.end()){
        cout << (*i1).first << ' ';
        i1++;
    }
    cout << endl;
}

void eval_begin_end(){
	std::cout << "+++++++++++BEGIN,END+++++++++++" << "\n";
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
	cout << "STD:\n";
    while (i != a.end()){
        cout << (*i).first << ' ';
        i++;
    }
    cout << endl;
	cout << "FT:\n";
     while (i1 != b.end()){
        cout << (*i1).first << ' ';
        i1++;
    }
    cout << endl;
}

void eval_rbegin_rend(){
	std::cout << "+++++++++++RBEGIN,REND+++++++++++" << "\n";
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
	cout << "STD:\n";
	while (i != a.rbegin()){
		cout << (*i).first << ' ';
		i++;
	}
	cout << endl;
	cout << "FT:\n";
	while (i1 != b.rbegin()++){
		cout << (*i1).first << ' ';
		i1++;
	}
	cout << endl;
}

//void eval_clear(){
//
//    map<int, int> a;
//    ft::map<int, int> b;
//
//    for (int i = 0; i < 10; i++){
//        int r = rand() % 100;
//        a.insert(make_pair(r, r));
//        b.insert(ft::make_pair(r, r));
//    }
//	i = a.begin();
//	i1 = b.begin();
//	cout << "STD:\n";
//	cout << "mymap contains:\n"
//	while (i != a.end()){
//		cout << (*i).first << ' ';
//		i++;
//	}
//	cout << "Clear\n";
//    a.clear();
//
//    b.clear();
//
//}


void eval_count()
{
	std::cout << "+++++++++++COUNT+++++++++++" << "\n";
    map<int, int> a;
    ft::map<int, int> b;
    int r;
    for (int i = 0; i < 10; i++){
        r = rand() % 100;
        a.insert(make_pair(r, r));
        b[r] = r;
    }
    std::cout << a.count(5) << "\n";
    std::cout << b.count(5) << "\n";
    std::cout << a.count(r) << "\n";
    std::cout << b.count(r) << "\n";

}

//void eval_size(){
//	std::cout << "+++++++++++SIZE+++++++++++" << "\n";
//	map<int, int> a;
//	ft::map<int, int> b;
//	int r;
//	for (int i = 0; i < 10; i++){
//		r = rand() % 100;
//		a.insert(make_pair(r, r));
//		b.insert(ft::make_pair(r, r));
//	}
//	cout << "STD:\n";
//	std::cout << "mymap.size() is " << a.size() << '\n';
//	cout << "FT:\n";
//	std::cout << "mymap.size() is " << b.size() << '\n';
//}

//void eval_find(){
//	std::cout << "+++++++++++FIND+++++++++++" << "\n";
//	cout << "STD:\n";
//	std::map<char,int> mymap;
//	std::map<char,int>::iterator it;
//
//	mymap['a']=50;
//	mymap['b']=100;
//	mymap['c']=150;
//	mymap['d']=200;
//
//	it = mymap.find('b');
//	if (it != mymap.end())
//		mymap.erase (it);
//
//	// print content:
//	std::cout << "elements in mymap:" << '\n';
//	std::cout << "a => " << mymap.find('a')->second << '\n';
//	std::cout << "c => " << mymap.find('c')->second << '\n';
//	std::cout << "d => " << mymap.find('d')->second << '\n';
//
//
//	cout << "FT:\n";
//	ft::map<char,int> mymap1;
//	ft::map<char,int>::iterator it1;
//
//	mymap1['a']=50;
//	mymap1['b']=100;
//	mymap1['c']=150;
//	mymap1['d']=200;
//
//	it1 = mymap1.find('b');
//	if (it1 != mymap1.end())
//		mymap1.erase (it1);
//
//	// print content:
//	std::cout << "elements in mymap:" << '\n';
//	std::cout << "a => " << mymap1.find('a').get_ptr()->pair->second << '\n';
//	std::cout << "c => " << mymap1.find('c').get_ptr()->pair->second << '\n';
//	std::cout << "d => " << mymap1.find('d').get_ptr()->pair->second << '\n';
//
//}

//void eval_bound(){
//	std::map<char,int> mymap;
//	std::map<char,int>::iterator itlow,itup;
//
//	mymap['a']=20;
//	mymap['b']=40;
//	mymap['c']=60;
//	mymap['d']=80;
//	mymap['e']=100;
//
//	itlow=mymap.lower_bound ('b');  // itlow points to b
//	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
//
//	mymap.erase(itlow,itup);        // erases [itlow,itup)
//
//	// print content:
//	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//
//	ft::map<char,int> mymap1;
//	ft::map<char,int>::iterator itlow1,itup1;
//
//	mymap1['a']=20;
//	mymap1['b']=40;
//	mymap1['c']=60;
//	mymap1['d']=80;
//	mymap1['e']=100;
//
//	itlow1=mymap1.lower_bound ('b');  // itlow points to b
//	itup1=mymap1.upper_bound ('d');   // itup points to e (not d!)
//
//	mymap1.erase(itlow1, itup1);        // erases [itlow,itup)
//
//	// print content:
//	for (ft::map<char,int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
//		std::cout << (*it).first << " => " << (*it).second << '\n';
//
//	}

int main()
{
	cout << "-------------MAP-------------\n\n";
	srand(time(NULL));
    eval_count();

}
