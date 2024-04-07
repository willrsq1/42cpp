#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	CLASS("Constructor", "Array");
	this->_Tab = new T[0];
	this->_Size = new unsigned int(0);
}

template<typename T>
Array<T>::Array(unsigned int size)
{
	if (size > 1000)
	{
		size = 1000;
		std::cerr << "Too big size input. Reduced to 1000 for memory protecetion." << std::endl;
	}
	CLASS("Constructor with UNSIGNED INT param", "Array");
	this->_Tab = new T[size];
	this->_Size = new unsigned int(size);
}

template<typename T>
Array<T>::~Array()
{
	CLASS("Destructor", "Array");
	delete[] this->_Tab;
	delete this->_Size;
}

template<typename T>
Array<T>::Array(const Array& other)
{
	CLASS("Constructor by copy", "Array");
	if (this == &other)
		return ;
	this->_Tab = new T[*other._Size];
	this->_Size = new unsigned int(*other._Size);
	for (size_t i = 0; i < *_Size; i++)
	{
		_Tab[i] = other._Tab[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator= (const Array& other)
{
	CLASS("Operand = Constructor", "Array");
	if (this == &other)
		return (*this);
	if (_Tab)
		delete[] this->_Tab;
	if (*_Size)
		delete this->_Size;
	this->_Tab = new T[*other._Size];
	this->_Size = new unsigned int(*other._Size);
	for (size_t i = 0; i < *_Size; i++)
	{
		_Tab[i] = other._Tab[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[] (size_t i)
{
	if (i >= this->getSize())
		throw Array<T>::IndexOutOfBounds();
	return (this->_Tab[i]);
}

template<typename T>
T const & Array<T>::operator[](size_t i) const
{
    if (i >= this->getSize())
        throw Array<T>::IndexOutOfBounds();
    return (this->_Tab[i]);
}

template<typename T>
const char * Array<T>::IndexOutOfBounds::what() const throw()
{
	return ("The index is out of bounds");
}
#endif