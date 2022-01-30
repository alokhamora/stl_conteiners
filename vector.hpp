#ifndef VECTOR
#define VECTOR
#include <memory>
#include <stdexcept>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "reverse_iterator.hpp"

namespace ft {
	template<class T, class Alloc = std::allocator <T> >
	class vector;

	template<class T>
	class iter_vector;

	template<class T>
	class const_iter : public iterator<std::random_access_iterator_tag, T>
	{
		T *ptr;
		friend class vector<T>;

	public:
		const_iter()
		{
			ptr = NULL;
		}

		const_iter(const const_iter &arg)
		{
			ptr = arg.ptr;
		}

		const_iter(const iter_vector<T> &arg)
		{
			ptr = arg.ptr;
		}

		const const_iter &operator=(const const_iter &a)
		{
			ptr = a.ptr;
			return *this;
		}

		~const_iter()
		{}

		bool operator==(const const_iter &b)
		{
			return ptr == b.ptr;
		}

		bool operator!=(const const_iter &b)
		{
			return ptr != b.ptr;
		}

		const T &operator*()
		{
			return *ptr;
		}

		const T *operator->()
		{
			return ptr;
		}

		const T *operator++()
		{
			ptr++;
			return ptr;
		}

		const T *operator++(int)
		{
			T *prev = ptr;
			++ptr;
			return prev;
		}

		const T *operator--()
		{
			ptr--;
			return *ptr;
		}

		const T *operator--(int)
		{
			T *prev = ptr;
			--ptr;
			return prev;
		}

		const_iter operator+(ptrdiff_t a)
		{
			const_iter b = *this;
			b.ptr += a;
			return b;
		}

		const_iter operator-(ptrdiff_t a)
		{
			const_iter b = *this;
			b.ptr -= a;
			return b;
		}

		bool operator<(const_iter a)
		{
			return ptr < a.ptr;
		}

		bool operator>(const_iter a)
		{
			return ptr > a.ptr;
		}

		bool operator<=(const_iter a)
		{
			return ptr <= a.ptr;
		}

		bool operator>=(const_iter a)
		{
			return ptr >= a.ptr;
		}

		const_iter &operator+=(ptrdiff_t a)
		{
			ptr += a;
			return *this;
		}

		const_iter *operator-=(ptrdiff_t a)
		{
			ptr -= a;
			return *this;
		}

		const T &operator[](ptrdiff_t a)
		{
			return ptr[a];
		}
	};

	template<class T>
	class iter_vector : public iterator<std::random_access_iterator_tag, T>
	{
		T *ptr;
		friend class const_iter<T>;
		friend class vector<T>;

	public:
		iter_vector()
		{
			ptr = NULL;
		}

		iter_vector(const iter_vector &arg)
		{
			ptr = arg.ptr;
		}

		const iter_vector &operator=(const iter_vector &a)
		{
			ptr = a.ptr;
			return *this;
		}

		~iter_vector()
		{}

		bool operator==(const iter_vector &b)
		{
			return ptr == b.ptr;
		}

		bool operator!=(const iter_vector &b)
		{
			return ptr != b.ptr;
		}

		T &operator*()
		{
			return *ptr;
		}

		T *operator->()
		{
			return ptr;
		}

		T *operator++()
		{
			ptr++;
			return ptr;
		}

		T *operator++(int)
		{
			T *prev = ptr;
			++ptr;
			return prev;
		}

		T *operator--()
		{
			ptr--;
			return *ptr;
		}

		T *operator--(int)
		{
			T *prev = ptr;
			--ptr;
			return prev;
		}

		iter_vector operator+(ptrdiff_t a)
		{
			iter_vector b = *this;
			b.ptr += a;
			return b;
		}

		iter_vector operator-(ptrdiff_t a)
		{
			iter_vector b = *this;
			b.ptr -= a;
			return b;
		}

		bool operator<(iter_vector a)
		{
			return ptr < a.ptr;
		}

		bool operator>(iter_vector a)
		{
			return ptr > a.ptr;
		}

		bool operator<=(iter_vector a)
		{
			return ptr <= a.ptr;
		}

		bool operator>=(iter_vector a)
		{
			return ptr >= a.ptr;
		}

		iter_vector &operator+=(ptrdiff_t a)
		{
			ptr += a;
			return *this;
		}

		iter_vector *operator-=(ptrdiff_t a)
		{
			ptr -= a;
			return *this;
		}

		T &operator[](ptrdiff_t a)
		{
			return ptr[a];
		}
	};

	template<class T, class Alloc >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef iter_vector<T> iterator;
		typedef const_iter<T> const_iterator;
		typedef ptrdiff_t difference_type;
		typedef reverse_iterator<const_iter<T> > const_reverse_iterator;
		typedef reverse_iterator<iter_vector<T> > reverse_iterator;
		typedef size_t size_type;
	private:
		T *ptr;
		size_type size_i;
		size_type cpct;
		Alloc alloc;

		void increase()
		{
			if (!cpct)
			{
				ptr = alloc.allocate(2);
				cpct = 2;
				return;
			}
			T *ptrn = alloc.allocate(cpct * 2);
			for (size_t i = 0; i < size_i; i++)
			{
				ptrn[i] = ptr[i];
			}
			alloc.deallocate(ptr, cpct);
			cpct *= 2;
			ptr = ptrn;
		}

	public:
		explicit vector(const allocator_type &alloc = allocator_type())
		{
			ptr = NULL;
			cpct = 0;
			size_i = 0;
		}

		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
		{
			cpct = 0;
			ptr = NULL;
			size_i = 0;
			for (size_type i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		template<class InputIterator,
				enable_if<is_integral<InputIterator>::value == false> >

		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type())
		{
			ptr = NULL;
			cpct = 0;
			size_i = 0;
			while (first < last)
			{
				push_back(*first);
				first++;
			}
		}

		vector(const vector &x)
		{
			*this = x;
		}

		iterator begin()
		{
			iterator ret;
			ret.ptr = ptr;
			return ret;
		}

		const_iterator begin() const
		{
			const_iterator ret;
			ret.ptr = ptr;
			return ret;
		}

		iterator end()
		{
			iterator ret;
			ret.ptr = ptr + size_i;
			return ret;
		}

		const_iterator end() const
		{
			const_iterator ret;
			ret.ptr = ptr + size_i;
			return ret;
		}

		reverse_iterator rbegin(){
			reverse_iterator a(end() - 1);
			return a;
		}
		const_reverse_iterator rbegin() const {
			reverse_iterator a(end() - 1);
			return a;
		}
		reverse_iterator rend(){
			reverse_iterator a(begin() - 1);
			return a;
		}
		const_reverse_iterator rend() const {
			reverse_iterator a(begin() - 1);
			return a;
		}
		void clear()
		{
			for (size_t i = 0; i < size_i; i++)
				alloc.destroy(ptr + i);
			alloc.deallocate(ptr, cpct);
			size_i = 0;
			cpct = 0;
			ptr = NULL;
		}
		~vector()
		{
			clear();
		}
		vector &operator=(const vector &x)
		{
			clear();
			ptr = alloc.allocate(x.cpct);
			cpct = x.cpct;
			for (size_t i = 0; i < x.size_i; i++)
			{
				ptr[i] = x.ptr[i];
			}
			size_i = x.size_i;
		}

		size_type size() const
		{
			return size_i;
		}

		size_type max_size() const
		{
			return alloc.max_size();
		}

		void resize(size_type n, value_type val = value_type())
		{
			for (size_type i = size_i; i < n; i++)
			{
				push_back(val);
			}
			for (size_type i = size_i; i > n; i--)
			{
				pop_back();
			}
			size_i = n;
			cpct = n;
		}

		size_type capacity() const
		{
			return cpct;
		}

		bool empty() const
		{
			if (!size_i)
				return true;
			return false;
		}

		void reserve(size_type n)
		{
			if (cpct < n)
			{
				T *nptr = alloc.allocate(n);
				for (size_t i = 0; i < size_i; i++)
				{
					nptr[i] = ptr[i];
				}
				for (size_t i = 0; i < size_i; i++)
					alloc.destroy(ptr + i);
				alloc.deallocate(ptr, cpct);
				ptr = nptr;
				cpct = n;
			}
		}

		void push_back(const value_type &val)
		{
			if (size_i == cpct)
				increase();
			ptr[size_i] = val;
			size_i++;
		}

		void pop_back()
		{
			size_i--;
			alloc.destroy(ptr + size_i);
		}

		reference operator[](size_type n)
		{
			return ptr[n];
		}

		const_reference operator[](size_type n) const
		{
			return ptr[n];
		}

		reference at(size_type n)
		{
			if (n >= size_i)
				throw std::out_of_range("Out of Range error");
			return ptr[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= size_i)
				throw std::out_of_range("Out of Range error");
			return ptr[n];
		}

		reference front()
		{
			return ptr[0];
		}

		const_reference front() const
		{
			return ptr[0];
		}

		reference back()
		{
			return ptr[size_i - 1];
		}

		const_reference back() const
		{
			return ptr[size_i - 1];
		}


		template< class InputIterator>
		typename enable_if<is_integral<InputIterator>::value == false,
		void>::type
		assign
		(InputIterator first, InputIterator last)
		{
			this->clear();
			ptr = NULL;
			cpct = 0;
			size_i = 0;
			while (first < last)
			{
				push_back(*first);
				first++;
			}
		}

		void assign(size_type n, const value_type & val){
			this->clear();
			ptr = NULL;
			cpct = 0;
			size_i = 0;
			int i = 0;
			while (i < n) {
				push_back(val);
				i++;
			}
			size_i = n;
		}

		iterator insert (iterator position, const value_type& val){
			size_t pos = position.ptr - ptr;
			push_back(value_type());
			for(size_t i = size_i - 1; i > pos; i--){
				ptr[i] = ptr[i - 1];
			}
			ptr[pos] = val;
			iterator result;
			result.ptr = this->ptr + pos;
			return  result;
		};

		void insert (iterator position, size_type n, const value_type& val){
			for (size_t i = 0; i < n; i++){
				position = insert(position, val);
			}
		};

		template< class InputIterator>
		typename enable_if<is_integral<InputIterator>::value == false,
		void>::type insert (iterator position, InputIterator first,
							InputIterator last){
			while (first != last){
				position = insert(position, *first);
				first++;
				position++;
			}
		};

		iterator erase (iterator position){
			alloc.destroy(position.ptr);
			iterator result = position;
			while (position != this->end()){
				*position = *(position + 1);
				position++;
			}
			size_i--;
			return result;
		};


		iterator erase (iterator first, iterator last){
			while(first != last){
				erase(first);
				last--;
			}
			return first;
		};

		void swap (vector& x){
			T *ptr1 = x.ptr;
			size_type size_i1 = x.size_i;
			size_type cpct1 = x.cpct;
			Alloc alloc1 = x.alloc;

			x.ptr = ptr;
			x.size_i = size_i;
			x.cpct = cpct;
			x.alloc = alloc;

			ptr = ptr1;
			size_i = size_i1;
			cpct = cpct1;
			alloc = alloc1;
		};

		allocator_type get_allocator() const{
			return alloc;
		};
	};
};

#endif