
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

	List()							            // default constructor - creates empty list
    {
        fFirst = &Node::NIL;
        fLast = &Node::NIL;
        fCount = 0;
    }

    ~List() 						                    // destructor - frees all nodes
    {
        while ( fFirst != &Node::NIL )
        {
            Node* temp = (Node *)&fFirst->getNext();    // get next node (to become top)
            fFirst->remove();                           // move first node
            delete fFirst;                              // free node memory
            fFirst = temp;                              // make temp the new top
        }
    }

#ifdef CopyControl
    
	List(const List& aOther)
	{
		fFirst = &Node::NIL;
		fLast = &Node::NIL;
		fCount = 0;

		for (int i = 0; i < aOther.size(); i++)
		{
			push_back(aOther[i]);
		}
	}
    
	List& operator=(const List& aOther)
	{
		if (this != &aOther)
		{
			while (fFirst != &Node::NIL)
			{
				remove(fFirst->getValue());
			}

			for (int i = 0; i < aOther.size(); i++)
			{
				push_back(aOther[i]);
			}
		}
		else
		{
			throw std::domain_error("Cant asign values from different list");
		}

		return *this;
	}

    
#endif
    
	bool isEmpty() const	// Is list empty?
    {
        return fFirst == &Node::NIL;  // or: return fCount == 0;
    }

    int size() const		// list size
    {
        return fCount;
    }

	void push_front( const T& aElement )	// adds a node initialized with aElement at front
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

	void push_back( const T& aElement )	    // adds a node initialized with aElement at back
    {
        Node* lNewElement = new Node( aElement );   // create a new node
        
        if ( fFirst == &Node::NIL )                 // Is this the first node?
        {
            fFirst = lNewElement;                   // make lNewNode first node
            fLast = lNewElement;                    // make lNewNode last node as well
        }
        else
        {
            fLast->push_back( *lNewElement );       // make lNewElement next of last
            fLast = lNewElement;                    // make lNewNode last node
        }
        
        fCount++;                                   // increment count
    }

	void remove( const T& aElement )	    // remove node that matches aElement from list
    {
        Node* lNode = fFirst;                           // start from the top
        
        while ( lNode != &Node::NIL )           // Are there still nodes available?
        {
            if ( lNode->getValue() == aElement )        // Have we found the node?
                break;                                  // stop the search
            lNode = (Node *)&lNode->getNext();          // move to next node
        }
        
        // At this point we have either reached the end or found the node.
        if ( lNode != &Node::NIL )                      // We have found the node.
        {
            if ( lNode == fFirst )                      // Was it the first node?
            {
                fFirst = (Node *)&lNode->getNext();     // set top to next of node
            }
            if ( lNode == fLast )                       // Was it the last node?
            {
                fLast = (Node *)&lNode->getPrevious();  // set last to previous of node
            }
            
            lNode->remove();                            // isolate node
            delete lNode;                               // release node's memory
            fCount--;                                   // decrement count
        }
    }

	const T& operator[]( unsigned int aIndex ) const	// list indexer
    {
        if ( aIndex < fCount )                          // Is index within bounds?
        {
            Node* lNode = fFirst;                       // start from the top
            while ( aIndex )                            // Have we reached the index?
            {
                // No
                aIndex--;                               // decrement index
                lNode = (Node*)&lNode->getNext();       // move to next node
            }
            // Yes
            return lNode->getValue();                   // return node value
        }
        else
        {
            throw std::range_error( "Index out of bounds." );   // signal error
        }

	}

    Iterator begin() const          // return a forward iterator
    {
        return Iterator( *fFirst );
    }
    
    Iterator end() const            // return a forward end iterator
    {
        return begin().end();
    }
    
    Iterator rbegin() const         // return a backwards iterator
    {
        return begin().rbegin();
    }
    
	Iterator rend() const	        // return a backwards end iterator
    {
        return begin().rend();
    }
};
