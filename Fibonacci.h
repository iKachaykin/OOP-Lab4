#pragma once
#include <iostream>

template <class T> class ConstFibIter;

template <class T>
class Fibonacci {
private:
	const char STR_CONST_F_DEFAULT_VAL = 'a', STR_CONST_S_DEFAULT_VAL = 'b';
	const int CONST_SIZE = 16, NUM_CONST_F_DEFAULT_VAL = 0, NUM_CONST_S_DEFAULT_VAL = 1;
	T first_default_val, second_default_val;
	int size_var;
public:
	friend ConstFibIter<T>;
	typedef ConstFibIter<T> const_iterator;
	Fibonacci();
	Fibonacci(int);
	Fibonacci(int, const T&, const T&);
	const_iterator cbegin() const;
	const_iterator cend() const;
	T at(int) const;
	void resize(int);
	int size() const;
	~Fibonacci();
};

template<class T>
Fibonacci<T>::Fibonacci(int size_var, const T& first_default_val, const T& second_default_val) {
	if (size_var <= 0)
		throw 1;
	this->size_var = size_var;
	this->first_default_val = first_default_val;
	this->second_default_val = second_default_val;
}

template<class T>
void Fibonacci<T>::resize(int size_var) {
	if (size_var <= 0)
		throw 1;
	this->size_var = size_var;
}

template<class T>
int Fibonacci<T>::size() const {
	return this->size_var;
}

template<class T>
Fibonacci<T>::Fibonacci(){
	size_var = CONST_SIZE;
	first_default_val = NUM_CONST_F_DEFAULT_VAL;
	second_default_val = NUM_CONST_S_DEFAULT_VAL;
}

template<class T> 
Fibonacci<T>::Fibonacci(int size_var) {
	if (size_var <= 0)
		throw 1;
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
	if (size_var <= 0)
		throw 1;
	this->size_var = size_var;
	first_default_val = new char[1];
	second_default_val = new char[1];
	*first_default_val = STR_CONST_F_DEFAULT_VAL;
	*second_default_val = STR_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<std::string>::Fibonacci() {
	size_var = CONST_SIZE;
	first_default_val += STR_CONST_F_DEFAULT_VAL;
	second_default_val += STR_CONST_S_DEFAULT_VAL;
}

template<>
Fibonacci<std::string>::Fibonacci(int size_var) {
	if (size_var <= 0)
		throw 1;
	this->size_var = size_var;
	first_default_val += STR_CONST_F_DEFAULT_VAL;
	second_default_val += STR_CONST_S_DEFAULT_VAL;
}

template<class T>
Fibonacci<T>::~Fibonacci() {}

template<>
Fibonacci<char*>::~Fibonacci() {
	delete[] first_default_val, second_default_val;
}

#include "const_iterator.h"

template<class T>
inline typename Fibonacci<T>::const_iterator Fibonacci<T>::cbegin() const {
	return const_iterator(first_default_val, second_default_val, 0);
}

template<class T>
inline typename Fibonacci<T>::const_iterator Fibonacci<T>::cend() const {
	return const_iterator(first_default_val, second_default_val, 0) + size() - 1;
}

template<class T>
inline T Fibonacci<T>::at(int index) const {
	if (index >= size() || index < 0)
		throw 1;
	const_iterator v = cbegin() + index;
	return *(cbegin() + index);
}
