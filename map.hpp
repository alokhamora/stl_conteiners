#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "reverse_iterator.hpp"

namespace ft
{

	template <class T1, class T2>
	struct pair
	{
		T1 first;
		T2 second;
		pair() {}
		template <class U, class V>
		pair(const pair<U, V> &pr)
		{
			first = pr.first;
			second = pr.second;
		}
		pair(const T1 &a, const T2 &b)
		{
			first = a;
			second = b;
		}
		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

	template <class pointer>
	struct tree
	{
		pointer *pair;
		tree *prev;
		tree *left;
		tree *right;
		tree(){
			pair = NULL;
			prev = NULL;
			left = NULL;
			right = NULL;
		}
	};
	template <class T>
	struct less : std::binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const { return x < y; }
	};

    template <class Key,
			  class T,
			  class Compare,
			  class Alloc >
	class map;
	template <class T>
	class const_map_iterator : public
			iterator<std::bidirectional_iterator_tag, T> {
		tree<T> *ptr;

	private:
		const_map_iterator predcessor(){
			tree<T> *t;
			if (ptr->left != NULL)
			{
				t = ptr->left;
				while (t->right != NULL)
					t = t->right;
				ptr = t;
				return *this;
			}
			t = ptr->prev;
			while (t != NULL && ptr != t->right)
			{
				ptr = t;
				t = t->prev;
			}
			ptr = t;
			return *this;
		}
		const_map_iterator successor()
		{
			tree<T> *t;
			if (ptr->right != NULL)
			{
				t = ptr->right;
				while (t->left != NULL)
					t = t->left;
				ptr = t;
				return *this;
			}
			t = ptr->prev;
			while (t != NULL && ptr != t->left)
			{
				ptr = t;
				t = t->prev;
			}
			ptr = t;
			return *this;
		};

	public:
		tree<T> *get_ptr(){
			return ptr;
		}
		const_map_iterator()
		{
			ptr = NULL;
		}
		const_map_iterator(tree<T> *t)
		{
			ptr = t;
		};
		const const_map_iterator &operator=(const const_map_iterator &a)
		{
			ptr = a.ptr;
			return *this;
		}
			const const_map_iterator &operator++()
		{
			*this = successor();
			return *this;
		}
		const const_map_iterator &operator++(int)
		{
			*this = successor();
			return *this;
		}
		const T &operator*()
		{
			return *(ptr->pair);
		}
		bool operator!=(const_map_iterator b)
		{
			return ptr != b.ptr;
		}
		const const_map_iterator &operator--()
		{
			*this = predcessor();
			return *this;
		}
		const const_map_iterator &operator--(int)
		{
			*this = predcessor();
			return *this;
		}
	};
	template <class T>
	class map_iterator : public  iterator<std::bidirectional_iterator_tag, T>
	{
		tree<T> *ptr;

	private:
		map_iterator predcessor(){
			tree<T> *t;
			if (ptr->left != NULL)
			{
				t = ptr->left;
				while (t->right != NULL)
					t = t->right;
				ptr = t;
				return *this;
			}
			t = ptr->prev;
			while (t != NULL && ptr != t->right)
			{
				ptr = t;
				t = t->prev;
			}
			ptr = t;
			return *this;
		}
		map_iterator successor()
		{
			tree<T> *t;
			if (ptr->right != NULL)
			{
				t = ptr->right;
				while (t->left != NULL)
					t = t->left;
				ptr = t;
				return *this;
			}
			t = ptr->prev;
			while (t != NULL && ptr != t->left)
			{
				ptr = t;
				t = t->prev;
			}
			ptr = t;
			return *this;
		};

	public:
	    tree<T> *get_ptr(){
	        return ptr;
	    }
		map_iterator()
		{
		    ptr = NULL;
		}
		map_iterator(tree<T> *t)
		{
			ptr = t;
		};

		const map_iterator &operator++()
		{
			*this = successor();
			return *this;
		}
		const map_iterator &operator++(int)
		{
			*this = successor();
			return *this;
		}
		const map_iterator &operator--()
		{
			*this = predcessor();
			return *this;
		}
		const map_iterator &operator--(int)
		{
			*this = predcessor();
			return *this;
		}
		T &operator*()
		{
			return *(ptr->pair);
		}
		bool operator!=(map_iterator b)
		{
		    return ptr != b.ptr;
		}
		const map_iterator &operator=(const map_iterator &a)
		{
			ptr = a.ptr;
			return *this;
		}
	};

	template <class Key,
			  class T,
			  class Compare = less<Key>,
			  class Alloc = std::allocator<ft::pair<Key, T> > >
	class map
	{
	private:
		tree<ft::pair<Key, T> > *tr;
		Alloc alloc;
		Compare comp;
		size_t _size;

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef map_iterator<value_type> iterator;
		typedef const_map_iterator<value_type> const_iterator;
		typedef ft::reverse_iterator<map_iterator<value_type> >
		        reverse_iterator;
		typedef ft::reverse_iterator<const_map_iterator<value_type> >
				const_reverse_iterator;
		private:
		     tree<value_type> *tree_min(tree<value_type> *tre){
		        while (tre->left != NULL){
		            tre = tre->left;
		            }
		        return tre;
		     };
		     void tree_transplant(tree<value_type> *tr1, tree<value_type> *tr2){
		        if (tr1->prev == NULL)
		            tr = tr2;
		        else if (tr1 == tr1->prev->left)
		            tr1->prev->left = tr2;
		        else
		            tr1->prev->right = tr2;
		        if (tr2 != NULL)
		            tr2->prev = tr1->prev;
		     }
		public:
		class value_compare;
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			this->comp = comp;
			this->alloc = alloc;
			tr = NULL;
			_size = 0;
		}
		template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
            this->comp = comp;
			this->alloc = alloc;
			tr = NULL;
			_size = 0;
			while (first != last){
                insert(*first);
                first++;
            }
        };
        map (const map& x){
            this->comp = comp;
			this->alloc = alloc;
			tr = NULL;
			_size = 0;
			iterator i = x.begin();
			while (i != x.end){
			    insert(*i);
			    i++;
			}
        };
		iterator begin(){
		    tree<ft::pair<Key, T> > *tmp;
		    tmp = tr;
		    while (tmp->left != NULL)
		        tmp = tmp->left;
		    return iterator(tmp);
		};
		iterator end(){
		    return iterator(NULL);
		};
		const_iterator end() const{
			return const_iterator(NULL);
		};
		~map(){
			clear();
		};

		void swap (map& x){
			tree<ft::pair<Key, T> > *tr1 = x.tr;
			Alloc alloc1 = x.alloc;
			Compare comp1 = x.comp;
			size_t _size1 = x._size;

			x.tr = tr;
			x.alloc = alloc;
			x.comp = comp;
			x._size = _size;

			tr = tr1;
			alloc = alloc1;
			comp = comp1;
			_size = _size1;
		};

		const_iterator find (const key_type& k) const{
			tree<ft::pair<Key, T> > *tmp;
			tmp = tr;
			while (tmp != NULL && tmp->pair->first != k){
				if (comp(tmp->pair->first, k))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			return const_iterator(tmp);
		};

		reverse_iterator rend(){
			return reverse_iterator(begin());
		};
		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin());
		};

		void clear(){
            pure(tr);
            tr = NULL;
            _size = 0;

		};

        void pure(tree<ft::pair<Key, T> > *p){

			if (!p)
                return ;
			pure(p->left);
			pure(p->right);
			alloc.deallocate(p->pair, 1);
			p = NULL;
        }

		size_t count (const key_type& k) const{
            const_iterator result = find(k);
            if (result != this->end())
                return 1;
            return 0;
		};

		key_compare key_comp() const{
            return comp;
		};
		value_compare value_comp() const{
            return value_compare(comp);
		};
		iterator lower_bound (const key_type& k){
            iterator it = begin();
            while (it != end()){
                if (!comp(it.get_ptr()->pair->first, k))
                    break;
                ++it;
            }
            return it;
		};
		const_iterator lower_bound (const key_type& k) const{
            const_iterator it = begin();
            while (it != end()){
                if (!comp(it->first, k))
                    break;
                ++it;
            }
            return it;
		};
		iterator upper_bound (const key_type& k){
            iterator it = begin();
            while (it != end()){
                if (comp(k, it.get_ptr()->pair->first))
                    break;
                ++it;
            }
            return it;
		};
		const_iterator upper_bound (const key_type& k) const{
            const_iterator it = begin();
            while (it != end()){
                if (comp(k, it->first))
                    break;
                ++it;
            }
            return it;
		};
		pair<const_iterator,iterator> equal_range (const key_type& k)
		const{
            iterator it = upper_bound(k);
            if (it != begin()){
                --it;
                if (comp(it->first, k) || comp(k, it->first))
                    ++it;
            }
            iterator next(it);
            if (it != end())
                ++next;
            return make_pair<iterator, iterator>(it, next);
		};
		pair<iterator, const_iterator> equal_range (const key_type& k){
            const_iterator it = upper_bound(k);
            if (it != begin()){
                --it;
                if (comp(it->first, k) || comp(k, it->first))
                    ++it;
            }
            iterator next(it);
            if (it != end())
                ++next;
            return make_pair<iterator, const_iterator>(it, next);
		};
		const_iterator begin() const{
			tree<ft::pair<Key, T> > *tmp;
			tmp = tr;
			while (tmp->left != NULL)
				tmp = tmp->left;
			return const_iterator(tmp);
		};
		reverse_iterator rbegin(){
			tree<ft::pair<Key, T> > *tmp;
			tmp = tr;
			while (tmp->right != NULL)
				tmp = tmp->right;
			return reverse_iterator(tmp);
		};
		const_reverse_iterator rbegin() const{
			tree<ft::pair<Key, T> > *tmp;
			tmp = tr;
			while (tmp->right != NULL)
				tmp = tmp->right;
			return const_reverse_iterator(tmp);
		};
		iterator find (const key_type& k){
			tree<ft::pair<Key, T> > *tmp;
			tmp = tr;
			while (tmp != NULL && tmp->pair->first != k){
				if (comp(tmp->pair->first, k))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			return iterator(tmp);
		};
		mapped_type& operator[](const key_type& k){
			return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
		};
		bool empty() const
		{
			if (tr == NULL)
				return true;
			return false;
		}
		size_t size() const
		{
			return _size;
		}
		size_t max_size() const
		{
			return alloc.max_size();
		}
		allocator_type get_allocator() const
		{
			return alloc;
		}
		iterator insert (iterator position, const value_type& val){
			position.get_ptr();
		    return insert(val).first;
		};
		template <class InputIterator>
        void insert (InputIterator first, InputIterator last){
            while (first != last){
                insert(*first);
                first++;
                }
        };
		pair<iterator, bool> insert(const value_type &val)
		{
			if (tr == NULL)
			{
				tr = new (tree<value_type>);
				tr->pair = alloc.allocate(1);
				*(tr->pair) = val;
				iterator iter(tr);
				_size = 1;
				return make_pair(iter, true);
			}
			tree<value_type> *ptr = tr;
			tree<value_type> *prev;
			while (ptr != NULL)
			{
				prev = ptr;
				if (ptr->pair->first == val.first)
				{
					iterator iter(ptr);
					return make_pair(iter, false);
				}
				if (comp(ptr->pair->first, val.first)){
					ptr = ptr->right;
				}
				else{
					ptr = ptr->left;
				}
			}
			tree<value_type> *n = new (tree<value_type>);
			n->pair = alloc.allocate(1);
			*(n->pair) = val;
			if (comp(prev->pair->first, val.first))
				prev->right = n;
			else
				prev->left = n;
			n->prev = prev;
			iterator iter(n);
			_size++;
			return make_pair(iter, true);
		}
		void erase (iterator position){
		    tree<value_type> *tre;
		    tre = position.get_ptr();
            if (tre->left == NULL)
                tree_transplant(tre, tre->right);
            else if (tre->right == NULL)
                tree_transplant(tre, tre->left);
            else {
                tree<value_type> *y;
                y = tree_min(tre->right);
                if (y->prev != tre){
                    tree_transplant(y, y->right);
                    y->right = tre->right;
                    y->right->prev = y;
                }
                tree_transplant(tre, y);
                y->left = tre->left;
                y->left->prev = y;
            }
            _size--;
		};
		size_t erase (const key_type& k){
		    iterator i;
		    i = this->find(k);
		    if (i != this->end())
		    {
		        this->erase(i);
		        return 1;
		    }
		    return 0;
		};
		void erase (iterator first, iterator last){
		    iterator tmp;
		    while( first != last){
		        tmp = first;
		        tmp++;
		        this->erase(first);
		        first = tmp;
		    }
		};
	};
	template <class Key, class T, class Compare, class Alloc>
	class map<Key, T, Compare, Alloc>::value_compare
	{
		friend class map;

	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator()(const value_type &x, const value_type &y) const
		{
			return comp(x.first, y.first);
		}
	};
}

#endif
