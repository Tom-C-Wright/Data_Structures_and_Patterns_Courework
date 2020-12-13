
// COS30008, tutorial 9, 2019

#pragma once

#include "DoublyLinkedNode.h"

template<class DataType> 
class DoublyLinkedNodeIterator
{
private:
	enum IteratorStates { BEFORE, DATA , AFTER }; 
	
	IteratorStates fState;

	typedef DoublyLinkedNode<DataType> Node;

	const Node* fLeftmost; 
	const Node* fRightmost; 
	const Node* fCurrent;
    
public:
	typedef DoublyLinkedNodeIterator<DataType> Iterator;

	DoublyLinkedNodeIterator(const Node& aList)
	{

		fLeftmost = &aList;
		while (&fLeftmost->getPrevious() != &Node::NIL)
		{
			fLeftmost = &fLeftmost->getPrevious();
		}
		fCurrent = fLeftmost;

		fRightmost = &aList;

		while (&fRightmost->getNext() != &Node::NIL)
		{
			fRightmost = &fRightmost->getNext();
		}
	}
	
	const DataType& operator*() const	// dereference
	{
		return fCurrent->getValue();
	}
	
	Iterator& operator++()            // prefix increment
	{

	}

	Iterator operator++(int)			// postfix increment
	{
		Iterator temp = *this;
		++(*this);
		return temp;
	}
	
	Iterator& operator--() 				// prefix decrement
	{
		
	}

	Iterator operator--(int)			// postfix decrement
	{
		Iterator temp = *this;
		--(*this);
		return temp;
	}

	bool operator==(const Iterator& aOtherIter) const
	{
		return (this == &aOtherIter) && (&this->fCurrent == &aOtherIter.fCurrent);
	}

	bool operator!=(const Iterator& aOtherIter) const
	{
		return (this != &aOtherIter) && (&this->fCurrent != &aOtherIter.fCurrent);
	}

	Iterator begin() const
	{
		return ++(rend());
	}
    Iterator end() const
	{
		Iterator temp = *this;
		temp.fCurrent = &Node::NIL;
		temp.fState = AFTER;
		return temp;
	}
    Iterator rbegin() const
	{
		return --(end());
	}
    Iterator rend() const
	{
		Iterator temp = *this;
		temp.fCurrent = &Node::NIL;
		temp.fState = BEFORE;
		return temp;
	}
};