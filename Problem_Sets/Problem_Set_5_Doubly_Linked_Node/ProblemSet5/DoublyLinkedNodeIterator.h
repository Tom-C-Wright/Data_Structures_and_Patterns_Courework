
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

	DoublyLinkedNodeIterator( const Node& aList ) // given
    {
        // set leftmost element
        fLeftmost = &aList;
        
        while ( &fLeftmost->getPrevious() != &Node::NIL )
        {
            fLeftmost = &fLeftmost->getPrevious();
        }
        
        // set rightmost element
        fRightmost = &aList;
        
        while ( &fRightmost->getNext() != &Node::NIL )
        {
            fRightmost = &fRightmost->getNext();
        }
        
        // set current to first
        fCurrent = fLeftmost;
        
        if ( fCurrent != &Node::NIL )
            fState = DATA;
        else
            fState = AFTER;
    }
	
	const DataType& operator*() const	// dereference
    {
        return fCurrent->getValue();
    }

    Iterator& operator++()				// prefix increment
    {
        // state-based analysis, given
        switch ( fState )
        {
        case BEFORE:
            fCurrent = fLeftmost;
            if ( fCurrent == &Node::NIL )
            {
                fState = AFTER;
            }
            else
            {
                fState = DATA;
            }
            break;
                
        case DATA:
            fCurrent = &fCurrent->getNext();
            if ( fCurrent == &Node::NIL )
            {
                fState = AFTER;
            }
            break;
                
        default: ;
        }
        
        return *this;
    }

    Iterator operator++(int)			// postfix increment
    {
        Iterator temp = *this;
        
        ++(*this);
        
        return temp;
    }

    Iterator& operator--()				// prefix decrement
    {
        switch ( fState )
        {
        case AFTER:
            fCurrent = fRightmost;
            if ( fCurrent == &Node::NIL )
            {
                fState = BEFORE;
            }
            else
            {
                fState = DATA;
            }
            break;
                
        case DATA:
            fCurrent = &fCurrent->getPrevious();
            if ( fCurrent == &Node::NIL )
            {
                fState = BEFORE;
            }
            break;
                
        default: ;
        }
        
        return *this;
    }
    
	Iterator operator--(int)			// postfix decrement
    {
        Iterator temp = *this;
        
        --(*this);
        
        return temp;
    }
    
    bool operator==( const Iterator& aOtherIter ) const
    {
        return
            fLeftmost == aOtherIter.fLeftmost &&
            fRightmost == aOtherIter.fRightmost &&
            fCurrent == aOtherIter.fCurrent &&
            fState == aOtherIter.fState;
    }
    
    bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
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
