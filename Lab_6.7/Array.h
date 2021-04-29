#pragma once

#include <iostream>


class Array {		//числовий контейнер змінної довжини
public:
	//Синоніми до певних типів даних
	typedef unsigned int UINT;
	typedef int value_type;
	typedef int* iterator;
	typedef const int* const_iterator;
	typedef int& reference;
	typedef const int& const_reference;
	typedef std::size_t size_type;
private:
	static const size_type minsize = 10;	//мінімальний розмір масиву
	size_type size;							//виділено пам’яті для елементів
	size_type count;						//кількість елементів в масиві
	size_type first;						//значення індексу першого елемента в масиві
	value_type* elems;						//вказівник на дані
public:
	//конструктор для створення контейнера(масива) за його параметром - розміром
	Array(const size_type& n = minsize)
		throw(std::bad_alloc, std::invalid_argument);	//специфікація винятків

	//конструктор для створення контейнера(масива) за його параметрами - first і last
	Array(const iterator first, const iterator last)
		throw(std::bad_alloc, std::invalid_argument);	//специфікація винятків

	//конструктор для створення контейнера(масива) за його параметрами - first і last
	Array(const size_type first, const size_type last)
		throw(std::bad_alloc, std::invalid_argument);	//специфікація винятків

	//конструктор копіювання(від одного контейнера до іншого)
	Array(const Array&)
		throw(std::bad_alloc);		//специфікація винятків

	~Array();	//деструктор - для звільнення пам'яті, яка виділеня для контейнера(масива)

	Array& operator=(const Array&);		//перевантаження операції присвоєння

	iterator Begin() { return elems; }	//ітератор - який вказує на початок контейнера(масива)
	const_iterator Begin() const { return elems; }	// ітератор "const" - який вказує на початок контейнера(масива)

	iterator End() { return elems + count; }	//ітератор - який вказує на кінець контейнера(масива)
	const_iterator End() const { return elems + count; }	// ітератор "const" - який вказує на кінець контейнера(масива)

	size_type Size() const;			//виділено пам’яті для елементів(розмір)
	size_type Capacity() const;		//кількість елементів в контейнері(масиві)

	bool Empty() const;				//перевірка на наявність елементів в контейнері(масиві)
	void Resize(size_type newsize)	//змінити розмір контейнера(масива)
		throw(std::bad_alloc);		//специфікація винятків

	//доступ до елементів контейнера(масива) --- прямий(тобто індексація)
	reference operator[](size_type) throw(std::out_of_range);
	//"conts" доступ до елементів контейнера(масива) --- прямий(тобто індексація)
	const_reference operator[](size_type) const throw(std::out_of_range);

	reference Front() { return elems[0]; }
	const_reference Front() const { return elems[0]; }

	reference Back() { return elems[Size() - 1]; }
	const_reference Back() const { return elems[Size() - 1]; }

	void Push_back(const value_type& v);	//добавити елемент в кінець
	void Pop_back();						//видалити останній елемент
	void clear() { count = 0; }				//очистити масив
	void Swap(Array& other);				//поміняти з другим масивом

	//дружня функція виводу даних в стандартний потік виводу
	friend std::ostream& operator <<(std::ostream& out, const Array& a);
	//дружня функція ввід даних в стандартний потік вводу
	friend std::istream& operator >>(std::istream& in, Array& a);
};