
#pragma once

template<class DataType>


class DoublyLinkedNode
{
public:
	typedef DoublyLinkedNode<DataType> Node;
private:
	DataType fValue;
	Node* fNext;
	Node* fPrevious;
	DoublyLinkedNode()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}
public:
	static Node NIL;

	DoublyLinkedNode(const DataType& aValue)   // Constructor
	{	
		fValue = aValue;
		fNext = &NIL;
		fPrevious = &NIL;
	}

	void push_front(Node& aNode)
	{
		aNode.fNext = this;

		if (fPrevious != &NIL)
		{
			aNode.fPrevious = fPrevious;
			fPrevious->fNext = &aNode;
		}

		fPrevious = &aNode;
	}

	void push_back(Node& aNode)
	{
		aNode.fPrevious = this;                 // make this the backwards pointer of aNode

		if (fNext != &NIL)                    // make this's forward pointer aNode's
		{
			aNode.fNext = fNext;
			fNext->fPrevious = &aNode;          // tie back to Node
		}

		fNext = &aNode;
	}

	void remove()
	{
		if (fPrevious != &NIL)                // unlink previous
		{
			fPrevious->fNext = fNext;
		}

		if (fNext != &NIL)                    // unlink next
		{
			fNext->fPrevious = fPrevious;
		}

		fPrevious = &NIL;                       // isolate this node
		fNext = &NIL;
	}

	const DataType& getValue() const
	{
		
		return fValue;
	}

	const Node& getNext() const 
	{
		return  *fNext;
	}

	const Node& getPrevious() const
	{
		return *fPrevious;
	}
};
template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;

