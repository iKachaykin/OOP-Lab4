#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>

#include "Fibonacci.h"
template <class T> class ConstFibIter;

//template <class T>
//ConstFibIter<T> operator+(int, const ConstFibIter<T>&);

template<class T>
class ConstFibIter :
	public std::iterator<std::random_access_iterator_tag, T> {
private:
	int position;
	T current, next;
public:
	//friend ConstFibIter<T> operator+(int, const ConstFibIter<T>&);
	ConstFibIter();
	ConstFibIter(const Fibonacci<T>&);
	ConstFibIter(const T&, const T&, int);
	ConstFibIter(const ConstFibIter<T>&);
	ConstFibIter<T>& operator=(const ConstFibIter<T>&);
	bool operator==(const ConstFibIter<T>&) const;
	bool operator!=(const ConstFibIter<T>&) const;
	T operator*();
	T* operator->();
	ConstFibIter<T>& operator++(); //prefix
	ConstFibIter<T> operator++(int); //postfix
	ConstFibIter<T>& operator--(); //prefix
	ConstFibIter<T> operator--(int); //postfix
	ConstFibIter<T> operator+(int);
	ConstFibIter<T> operator-(int);
	int operator-(const ConstFibIter<T>&) const;
	bool operator<(const ConstFibIter<T>&) const;
	bool operator>(const ConstFibIter<T>&) const;
	bool operator<=(const ConstFibIter<T>&) const;
	bool operator>=(const ConstFibIter<T>&) const;
	ConstFibIter<T>& operator+=(int);
	ConstFibIter<T>& operator-=(int);
	T operator[](int) const;
	//static void swap(ConstFibIter<T>&, ConstFibIter<T>&);
};

template<class T>
inline ConstFibIter<T>::ConstFibIter() {
	Fibonacci<T> tmp_fib;
	position = 0;
	current = tmp_fib.first_default_val;
	next = tmp_fib.second_default_val;
}


template<>
ConstFibIter<char*>::ConstFibIter() {
	Fibonacci<char*> tmp_fib(2);
	position = 0;
	current = new char[1];
	next = new char[1];
	strcpy(current, tmp_fib.first_default_val);
	strcpy(next, tmp_fib.second_default_val);
}

template<class T>
inline ConstFibIter<T>::ConstFibIter(const Fibonacci<T>& tmp_fib)
{
	position = 0;
	current = tmp_fib.first_default_val;
	next = tmp_fib.second_default_val;
}

template<>
inline ConstFibIter<char*>::ConstFibIter(const Fibonacci<char*>& tmp_fib)
{
	position = 0;
	current = new char[strlen(tmp_fib.first_default_val)];
	next = new char[strlen(tmp_fib.second_default_val)];
	strcpy(current, tmp_fib.first_default_val);
	strcpy(next, tmp_fib.second_default_val);
}

template<class T>
inline ConstFibIter<T>::ConstFibIter(const T& current, const T& next, int position) {
	if (position < 0)
		throw 1;
	this->position = position;
	this->current = current;
	this->next = next;
}

//template<>
//inline ConstFibIter<char*>::ConstFibIter(const char*& current, const char*& next, int position) {
//	if (position < 0)
//		throw 1;
//	this->position = position;
//	this->current = current;
//	this->next = next;
//}

template<class T>
inline ConstFibIter<T>::ConstFibIter(const ConstFibIter<T>& other) {
	position = other.position;
	current = other.current;
	next = other.next;
}

template<>
inline ConstFibIter<char*>::ConstFibIter(const ConstFibIter<char*>& other) {
	position = other.position;
	current = new char[strlen(other.current)];
	next = new char[strlen(other.next)];
	strcpy(current, other.current);
	strcpy(next, other.next);
}

template <class T>
inline ConstFibIter<T>& ConstFibIter<T>::operator=(const ConstFibIter<T>& other) {
	position = other.position;
	current = other.current;
	next = other.next;
	return *this;
}

template<>
inline ConstFibIter<char*>& ConstFibIter<char*>::operator=(const ConstFibIter<char*>& other) {
	delete[] current, next;
	position = other.position;
	current = new char[strlen(other.current)];
	next = new char[strlen(other.next)];
	strcpy(current, other.current);
	strcpy(next, other.next);
	return *this;
}

template<class T>
inline bool ConstFibIter<T>::operator==(const ConstFibIter<T>& other) const {
	return current == other.current && next == other.next && position == other.position;
}

template<>
inline bool ConstFibIter<char*>::operator==(const ConstFibIter<char*>& other) const {
	return !strcmp(current, other.current) && !strcmp(next, other.next) && position == other.position;
}

template<>
inline bool ConstFibIter<std::string>::operator==(const ConstFibIter<std::string>& other) const {
	return !current.compare(other.current) && !next.compare(other.next) && position == other.position;
}

template<class T>
inline bool ConstFibIter<T>::operator!=(const ConstFibIter<T>& other) const {
	return current != other.current || next != other.next || position != other.position;
}

template<>
inline bool ConstFibIter<char*>::operator!=(const ConstFibIter<char*>& other) const {
	return strcmp(current, other.current) || strcmp(next, other.next) || position != other.position;
}

template<>
inline bool ConstFibIter<std::string>::operator!=(const ConstFibIter<std::string>& other) const {
	return current.compare(other.current) || next.compare(other.next) || position != other.position;
}

template<class T>
inline T ConstFibIter<T>::operator*() {
	return current;
}

template<class T>
inline T* ConstFibIter<T>::operator->() {
	return &current;
}

template<class T>
inline ConstFibIter<T>& ConstFibIter<T>::operator++() {
	T tmp = current;
	current = next;
	next += tmp;
	++position;
	return *this;
}

template<>
inline ConstFibIter<char*>& ConstFibIter<char*>::operator++() {
	char* tmp = new char[strlen(current)];
	strcpy(tmp, current);
	strcpy(current, next);
	strcat(next, tmp);
	++position;
	delete[] tmp;
	return *this;
}

template<class T>
inline ConstFibIter<T> ConstFibIter<T>::operator++(int) {
	T tmp = current;
	current = next;
	next += tmp;
	position++;
	return *this;
}

template<>
inline ConstFibIter<char*> ConstFibIter<char*>::operator++(int) {
	char* tmp = new char[strlen(current)];
	strcpy(tmp, current);
	strcpy(current, next);
	strcat(next, tmp);
	position++;
	delete[] tmp;
	return *this;
}

template<class T>
inline ConstFibIter<T>& ConstFibIter<T>::operator--() {
	if (position == 0)
		throw 1;
	T tmp = next;
	next = current;
	current = tmp - current;
	--position;
	return *this;
}

template<>
inline ConstFibIter<char*>& ConstFibIter<char*>::operator--() {
	if (position == 0)
		throw 1;
	char * tmp_str = new char[strlen(next) - strlen(current)];
	strcpy(tmp_str, next + strlen(next));
	strcpy(next, current);
	strcpy(current, tmp_str);
	--position;
	delete[] tmp_str;
	return *this;
}

template<>
inline ConstFibIter<std::string>& ConstFibIter<std::string>::operator--() {
	if (position == 0)
		throw 1;
	std::string tmp_str(next, current.size());
	next = current;
	current = tmp_str;
	--position;
	return *this;
}

template<class T>
inline ConstFibIter<T> ConstFibIter<T>::operator--(int) {
	if (position == 0)
		throw 1;
	T tmp = next;
	next = current;
	current = tmp - current;
	position--;
	return *this;
}

template<>
inline ConstFibIter<char*> ConstFibIter<char*>::operator--(int) {
	if (position == 0)
		throw 1;
	char * tmp_str = new char[strlen(next) - strlen(current)];
	strcpy(tmp_str, next + strlen(next));
	strcpy(next, current);
	strcpy(current, tmp_str);
	position--;
	delete[] tmp_str;
	return *this;
}

template<>
inline ConstFibIter<std::string> ConstFibIter<std::string>::operator--(int) {
	if (position == 0)
		throw 1;
	std::string tmp_str(next, current.size());
	next = current;
	current = tmp_str;
	--position;
	return *this;
}

template<class T>
inline ConstFibIter<T> ConstFibIter<T>::operator+(int number) {
	ConstFibIter<T> result(*this);
	result += number;
	return result;
}

//template<class T>
//inline ConstFibIter<T> operator+(int number, const ConstFibIter<T>& right_iter) {
//	ConstFibIter<T> result(right_iter);
//	result += number;
//	return result;
//}

template<class T>
inline ConstFibIter<T> ConstFibIter<T>::operator-(int number) {
	ConstFibIter<T> result(*this);
	result -= number;
	return result;
}

template<class T>
inline int ConstFibIter<T>::operator-(const ConstFibIter<T>& other) const {
	return position - other.position;
}

template<class T>
inline bool ConstFibIter<T>::operator<(const ConstFibIter<T>& other) const {
	return position < other.position;
}

template<class T>
inline bool ConstFibIter<T>::operator>(const ConstFibIter<T>& other) const {
	return position > other.position;
}

template<class T>
inline bool ConstFibIter<T>::operator<=(const ConstFibIter<T>& other) const {
	return *this < other || *this == other;
}

template<class T>
inline bool ConstFibIter<T>::operator>=(const ConstFibIter<T>& other) const {
	return *this > other || *this == other;
}

template<class T>
inline ConstFibIter<T>& ConstFibIter<T>::operator+=(int number) {
	if (number > 0)
		for (int i = 0; i < number; i++)
			(*this)++;
	else
		for (int i = 0; i > number; i--)
			(*this)--;
	return *this;
}

template<class T>
inline ConstFibIter<T>& ConstFibIter<T>::operator-=(int number) {
	if (number > 0)
		for (int i = 0; i < number; i++)
			(*this)--;
	else
		for (int i = 0; i > number; i--)
			(*this)++;
	return *this;
}

template<class T>
inline T ConstFibIter<T>::operator[](int index) const {
	ConstFibIter<T> tmp;
	tmp += index;
	return *tmp;
}

//template<class T>
//inline static void ConstFibIter<T>::swap(ConstFibIter<T>& left, ConstFibIter<T>& right) {
//	T tmp_T = left.current;
//	left.current = right.current;
//	right.current = tmp_T;
//	tmp_T = left.next;
//	left.next = right.next;
//	right.next = tmp_T;
//	int tmp_int = left.position;
//	left.position = right.position;
//	right.position = tmp_int;
//}


