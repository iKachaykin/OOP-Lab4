#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>

template <class T>
class Fibonacci {
private:
	char STR_CONST_F_DEFAULT_VAL = 'a', STR_CONST_S_DEFAULT_VAL = 'b';
	int CONST_SIZE = 16, NUM_CONST_F_DEFAULT_VAL = 0, NUM_CONST_S_DEFAULT_VAL = 1;
	T first_default_val, second_default_val;
	int size_var;
public:
	class const_iterator : public std::iterator<std::random_access_iterator_tag, T> {
	private:
		int position;
		T current, next;
	public:
		const_iterator() {
			position = 0;
			current = first_default_val;
			next = second_default_val;
		}

		const_iterator(const T& current, const T& next, int position) {
			this->position = position;
			this->current = current;
			this->next = next;
		}

		const_iterator(const const_iterator& other) {
			position = other.position;
			current = other.current;
			next = other.next;
		}

		const_iterator& operator=(const const_iterator& other) {
			positon = other.position;
			current = other.current;
			next = other.next;
			return *this;
		}

		bool operator==(const const_iterator& other) const {
			return current == other.current && next == other.next && position == other.position;
		}

		bool operator!=(const const_iterator& other) const {
			return current != other.current || next != other.next || position != other.position;
		}

		T& operator*(){
			return current;
		}

		const_iterator& const_iterator::operator++() {
			T tmp = current;
			current = next;
			next += tmp;
			++position;
			return *this;
		}

		const_iterator operator++(int) {
			T tmp = current;
			current = next;
			next += tmp;
			position++;
			return *this;
		}

		const_iterator& operator--() {
			T tmp = next;
			next = current;
			current = tmp - current;
			--position;
			return *this;
		}

		const_iterator operator--(int) {
			T tmp = next;
			next = current;
			current = tmp - current;
			position--;
			return *this;
		}

		const_iterator& operator+(int number) const {
			const_iterator result(*this);
			if (number > 0)
				for (int i = 0; i < number; i++)
					result++;
			else
				for (int i = 0; i > number; i--)
					result--;
			return result;
		}

		const_iterator& operator-(int number) const {
			const_iterator result(*this);
			if (number > 0)
				for (int i = 0; i < number; i++)
					result--;
			else
				for (int i = 0; i > number; i--)
					result++;
			return result;
		}

		int operator-(const const_iterator& other) const {
			return position - other.position;
		}

		bool operator<(const const_iterator& other) const {
			return position < other.position;
		}

		bool operator>(const const_iterator& other) const {
			return position > other.position;
		}

		bool operator<=(const const_iterator& other) const {
			return *this < other || *this == other;
		}

		bool operator>=(const const_iterator& other) const {
			return *this > other || *this == other;
		}
		const_iterator& operator+=(int number) {
			if (number > 0)
				for (int i = 0; i < number; i++)
					(*this)++;
			else
				for (int i = 0; i > number; i--)
					(*this)--;
			return *this;
		}
		const_iterator& operator-=(int number) {
			if (number > 0)
				for (int i = 0; i < number; i++)
					(*this)--;
			else
				for (int i = 0; i > number; i--)
					(*this)++;
			return *this;
		}
		T& operator[](int number) const {
			return *(*this + number);
		}
		void swap(const_iterator &other) {
			T tmp = current;
			current = other.current;
			other.current = tmp;
			tmp = next;
			next = other.next;
			other.next = tmp;
			tmp = position;
			position = other.position;
			other.position = tmp;
		}
	};
	Fibonacci();
	Fibonacci(int);
	Fibonacci(int, const T&, const T&);
	const_iterator cbegin() const {
		return const_iterator(first_default_val, second_default_val, 0);
	}
	const_iterator cend() const {
		const_iterator result(first_default_val, second_default_val, 0);
		result += size() - 1;
		return result;

	}
	T& at(int index) const {
		if (index >= size() || index < 0)
			throw 1;
		const_iterator it = cbegin();
		it += index;
		return *it;
	}
	void resize(int);
	int size() const;
	~Fibonacci();
};

template<class T>
Fibonacci<T>::Fibonacci(int size_var, const T& first_default_val, const T& second_default_val) {
	this->size_var = size_var;
	this->first_default_val = first_default_val;
	this->second_default_val = second_default_val;
}

template<class T>
void Fibonacci<T>::resize(int size_var) {
	this->size_var = size_var;
}

template<class T>
int Fibonacci<T>::size() const {
	return this->size_var;
}

template<>
Fibonacci<int>::Fibonacci() {
	size_var = CONST_SIZE;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<int>::Fibonacci(int size_var) {
	this->size_var = size_var;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<long int>::Fibonacci() {
	size_var = CONST_SIZE;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<long int>::Fibonacci(int size_var) {
	this->size_var = size_var;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<float>::Fibonacci() {
	size_var = CONST_SIZE;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<float>::Fibonacci(int size_var) {
	this->size_var = size_var;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<double>::Fibonacci() {
	size_var = CONST_SIZE;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<double>::Fibonacci(int size_var) {
	this->size_var = size_var;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<char*>::Fibonacci() {
	size_var = CONST_SIZE;
	first_default_val = new char[1];
	second_default_val = new char[1];
	*first_default_val = STR_CONST_F_DEFAULT_VAL;
	*second_default_val = STR_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<char*>::Fibonacci(int size_var) {
	this->size_var = size_var;
	first_default_val = new char[1];
	second_default_val = new char[1];
	*first_default_val = STR_CONST_F_DEFAULT_VAL;
	*second_default_val = STR_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<std::string>::Fibonacci() {
	size_var = CONST_SIZE;
	first_default_val.append(&STR_CONST_F_DEFAULT_VAL);
	second_default_val.append(&STR_CONST_S_DEFAULT_VAL);
}

template<>
Fibonacci<std::string>::Fibonacci(int size_var) {
	this->size_var = size_var;
	first_default_val.append(&STR_CONST_F_DEFAULT_VAL);
	second_default_val.append(&STR_CONST_S_DEFAULT_VAL);
}

template<class T>
Fibonacci<T>::~Fibonacci() {}

template<>
Fibonacci<char*>::~Fibonacci() {
	delete[] first_default_val, second_default_val;
}

