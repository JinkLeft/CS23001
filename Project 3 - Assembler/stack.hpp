#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    10/2019
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>
//P3M1 COMPLETE
////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class Node {
public:
	Node(): data(), next(0) {};						// Default constructor for node
	Node(const T& item): data(item), next(0) {};	// Node constructor for element with data
	T data;											// Data container for node
	Node<T> *next;									// Node's pointer to the next element
	
};

////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T>
class stack {
public:
              stack     ();
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>);
	bool      operator== (const stack<T>& ) const;
	int getLength(void) const { return length; };
	bool      empty     () const { return (tos == 0); };
	bool      full      () const;
	T         top       () const { return tos->data; };
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
	int length;
};

template <typename T>
stack<T>::stack()
{
	tos = 0;
	length = 0;
}

template <typename T>
stack<T>::stack(const stack<T>& rhs)
{
	Node<T> *bottom, *temptos, *tempNode;

	temptos = rhs.tos;

	tos = 0;
	length = rhs.length;

	while (temptos != 0) {
		tempNode = new Node<T>(temptos->data);

		if (tos == 0) {
			tos = tempNode;
		} else {
			bottom->next = tempNode;
		}

		bottom = tempNode;
		temptos = temptos->next;
	}
}

template <typename T>
stack<T>::~stack()
{
	while (tos != 0) {
		Node<T> *temp = tos;
		tos = tos->next;
		delete temp;
	}

	length = 0;
}

template <typename T>
void stack<T>::swap(stack<T>& rhs)
{

	Node<T> *temp = tos;
	int tempLength = length;

	tos = rhs.tos;
	length = rhs.length;

	rhs.tos = temp;
	rhs.length = tempLength;
}

template <typename T>
stack<T>& stack<T>::operator= (stack<T> rhs)
{
	swap(rhs);
	return *this;
}

template <typename T>
bool stack<T>::operator== (const stack<T>& rhs) const
{
	if (length != rhs.length) {
		return false;
	}

	stack<T> left(*this); 
	stack<T> right(rhs);

	while (!left.empty() && !right.empty()) {
		if (left.pop() != right.pop()) {
			return false;
		}
	}

	return true;
}

template <typename T>
bool stack<T>::full() const
{
	Node<T> *temp = new(std::nothrow) Node<T> ();

	if (temp == 0) {
		return true;
	}

	delete temp;
	return false;
}

template <typename T>
T stack<T>::pop()
{
	assert(tos != 0);

	Node<T> *temp = tos;

	T result = tos->data;

	tos = tos->next;
	--length;

	delete temp;
	return result;
}

template <typename T>
void stack<T>::push(const T& item)
{
	assert(!full());

	Node<T> *temp = new Node<T>(item);

	temp->next = tos;

	tos = temp;
	++length;
}
#endif

