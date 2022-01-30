#ifndef REVERSE
#define REVERSE
#include "iterator.hpp"

namespace ft{
	template<class Iter>
			class reverse_iterator : public
					iterator<typename Iter::iterator_category,
					typename Iter::value_type> {
					typedef	typename Iter::difference_type difference_type;
					typedef typename Iter::value_type value_type;
					typedef typename Iter::pointer pointer;
					typedef typename Iter::reference reference;
					typedef typename Iter::iterator_category iterator_category;
					typedef Iter iterator_type;
						Iter i;
					public:

						reverse_iterator(){
						};
						explicit reverse_iterator (iterator_type it){
							i = it;
						};
						template <class T>
						reverse_iterator (const reverse_iterator<T>& rev_it){
							i = rev_it.base();
						};
						reverse_iterator operator++(){
							i--;
							return *this;
						}
						reverse_iterator operator++(int){
							reverse_iterator a(i);
							i--;
							return a;
						}
						reverse_iterator operator--(){
							i++;
							return *this;
						}
						reverse_iterator operator--(int){
							reverse_iterator a = i;
							i++;
							return a;
						}
						const reverse_iterator &operator=(const
								reverse_iterator &a){
							i = a.i;
							return *this;
						}
						bool operator!=(const reverse_iterator &b){
							return i != b.i;
						}
						bool operator==(const reverse_iterator &b){
							return i == b.i;
						}
						const value_type operator*(){
							return i.operator*();
						}
						pointer operator->(){
							return i.operator->();
						}
						reverse_iterator operator+(ptrdiff_t a){
							reverse_iterator b = *this;
							b.i -= a;
							return b;
						}
						reverse_iterator operator-(ptrdiff_t a){
							reverse_iterator b = *this;
							b.i += a;
							return b;
						}
						bool operator<(reverse_iterator a){
							return i > a.i;
						}
						bool operator>(reverse_iterator a){
							return i < a.i;
						}
						bool operator<=(reverse_iterator a){
							return i >= a.i;
						}
						bool operator>=(reverse_iterator a){
							return i <= a.i;
						}
						reverse_iterator operator+=(ptrdiff_t a){
							i -= a;
							return *this;
						}
						reverse_iterator operator-=(ptrdiff_t a){
							i += a;
							return *this;
						}
						Iter base() const{
							return i;
						}
//						reference *operator[](ptrdiff_t a){
//							return i[a];
//						}
			};
}

#endif