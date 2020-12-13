
// COS30008, Problem Set 5, 2019

#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

template<class T> 
class List
{
private:
	// auxiliary definition to simplify node usage
	typedef DoublyLinkedNode<T> Node;

	Node* fFirst;		    // the first element in the list
	Node* fLast;	        // the last element in the list
	unsigned int fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    typedef DoublyLinkedNodeIterator<T> Iterator;

#ifdef A
    
    List()                          // default constructor - creates empty list
    {
		fFirst = &Node::NIL;
		fLast = &Node::NIL;
		fCount = 0;
    }
    
#endif
    
    ~List()                         // destructor - frees all nodes
    {
        while ( fFirst != &Node::NIL )
        {
            Node* temp = (Node *)&fFirst->getNext();    // get next node (to become top)
            fFirst->remove();                           // move first node
            delete fFirst;                              // free node memory
            fFirst = temp;                              // make temp the new top
        }
    }
    
    bool isEmpty() const    // Is list empty?
    {
		return (fFirst == &Node::NIL) && (fCount == 0);
    }
    
    int size() const        // list size
    {
        return fCount;
    }
    
    void push_front( const T& aElement )  // adds a node initialized with aElement at front
    {
        Node* lNewElement = new Node( aElement );   // create a new node
        
        if ( fFirst == &Node::NIL )                 // Is this the first node?
        {
            fFirst = lNewElement;                   // make lNewNode first node
            fLast = lNewElement;                    // make lNewNode last node as well
        }
        else
        {
            fFirst->push_front( *lNewElement );     // make lNewElement previous of top
            fFirst = lNewElement;                   // make lNewNode first node
        }
        
        fCount++;                                   // increment count
    }
    
#ifdef B
    
    void push_back( const T& aElement ) // adds a node initialized with aElement at back
    {
		Node* lNewElement = new Node(aElement);   // create a new node

		if (fLast == &Node::NIL)                 // Is this the last node?
		{
			fFirst = lNewElement;                   // make lNewNode first node
			fLast = lNewElement;                    // make lNewNode last node as well
		}
		else
		{
			fLast->push_back(*lNewElement);     // make lNewElement previous of top
			fLast = lNewElement;                   // make lNewNode first node
		}

		fCount++;                                   // increment count
    }
    
#endif
    
#ifdef C
    
    void remove( const T& aElement )        // remove node that matches aElement from list
    {
		Node* temp = fFirst;        // get a copy of the node that can call remove()
		
		
		for (unsigned int i= 0; i < fCount; i++) // 
		{
			if (temp->getValue() == aElement)
			{
				break;
			}
			temp = (Node *)&temp->getNext();
		}

		if (temp == fFirst)
		{
			fFirst = (Node *)&temp->getNext();
		}

		if (temp == fLast)
		{
			fLast = (Node *)&temp->getPrevious();
		}

		temp->remove();  // we have one less node now
		delete temp;
		fCount--;
    }
    
#endif
    
#ifdef D
    
    const T& operator[]( unsigned int aIndex ) const    // list indexer
    {
		if (aIndex < 0 || aIndex > fCount)
		{
			throw std::out_of_range("Out of range exception");
		}
		else
		{
			Iterator myIter = begin();                  // Create a new iterator
			for (unsigned int i = 0; i <= aIndex; i++)  // incremenet the iterator aIndex no. of times
			{
				myIter++;
			}
			return *myIter;         // get the value of the current node
		}
	}
    
#endif
    
#ifdef A
    
    Iterator begin() const          // return a forward iterator
    {
		return --(rend());
	}
    
    Iterator end() const            // return a forward end iterator
    {
		return ++(rbegin());
    }
    
    Iterator rbegin() const         // return a backwards iterator
    {
		Iterator* temp = new Iterator(*fLast);
		return temp->rbegin();
    }
    
    Iterator rend() const            // return a backwards end iterator
    {
		Iterator* temp = new Iterator(*fFirst);
		return temp->rend();
    }
    
#endif

};
