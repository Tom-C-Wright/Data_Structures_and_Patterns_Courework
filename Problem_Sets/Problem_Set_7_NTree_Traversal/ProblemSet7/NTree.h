#pragma once
#include <stdexcept>
#include "TreeVisitorPS7.h"
template<class T, int N>
class NTree
{
private:
	T fKey; // T() for empty NTree
	NTree<T, N>* fNodes[N]; // N subtrees of degree N

	// Private constructor so that users cannot create empty trees
	NTree() // sentinel constructor 
	{
		for (int i = 0; i < N; i++)
		{
			fNodes[i] = &NIL; // Initialise all children as Nil
		}
	}
public:
	static NTree<T, N> NIL; // sentinel
	NTree(const T& aKey) // a simple NTree with key and N subtrees
	{
		fKey = aKey;
		NTree(); // Initialize
	}

	NTree(const NTree& aOtherNTree) // copy constructor
	{
		if (aOtherNTree.isEmpty())
		{
			throw std::domain_error("Cant copy an empty boi");
		}

		fKey = aOtherNTree.fKey;

		for (int i = 0; i < N; i++)
		{
			fNodes[i] = aOtherNTree.fNodes[i]->clone();
		}
	}
	
	virtual ~NTree() // destructor
	{
		for (int i = 0; i < N; i++)
		{
			if (!fNodes[i]->isEmpty())
			{
				delete fNodes[i];
			}
		}
	}

	NTree& operator=(const NTree& aOtherNTree) // assignment operator
	{
		if (aOtherNTree.isEmpty())
		{
			throw std::domain_error("Can't assign an empty tree");
		}

		if (this != &aOtherNTree)
		{
			for (int i = 0; i < N; i++)
			{
				delete fNodes[i];
			}

			for (int i = 0; i < N; i++)
			{
				fNodes[i] = aOtherNTree.fNodes[i]->clone();
			}
		}
	}

	virtual NTree* clone() // clone a tree
	{
		if (isEmpty())
		{
			return this;
		}
		else
		{
			return new NTree(*this);
		}
	}

	bool isEmpty() const // is tree empty
	{
		return this == &NIL;
	}

	const T& key() const // get key (node value)
	{
		return fKey;
	}
						  
	NTree& operator[](unsigned int aIndex) const // indexer (allow for result modification by client - no const in result)
	{
		if (isEmpty())
		{
			throw std::domain_error("Tree is empty");
		}
		else
		{
			if (aIndex < N) // Unsigned, therefore cannot be < 0
			{
				return *fNodes[aIndex];
			}
			else
			{
				throw std::out_of_range("Index not in range");
			}
		}
	}

	// tree manipulators (using constant references)
	void attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree)
	{
		if (!isEmpty())
			throw std::domain_error("Empty NTree");

		if (aIndex < N)
		{
			if (fNodes[aIndex] == &NIL)
			{
				throw std::domain_error("Index is not empty");
			}

			fNodes[aIndex] = (NTree<T, N>*)&aNTree;
		}
		else
		{
			throw std::out_of_range("Index not in range");
		}
	}
	
	const NTree& detachNTree(unsigned int aIndex)
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty Node");
		}

		if (aIndex < N && fNodes[aIndex] != &NIL)
		{
			const NTree<T, N>& result = *fNodes[aIndex];
			fNodes[aIndex] = &NIL;
			return result;
		}
		else
		{
			throw std::out_of_range("Illegal index");
		}
	}
	
	// depth-first traversal
	void traverseDepthFirst(const TreeVisitor<T>& aVisitor) const
	{
		cout << fKey;

		if (isEmpty)
			cout << " ";

		for (int i = 0; i < N; i++)
		{
			if (fNodes[i] != &NIL)
			{
				fNodes[i]->traverseDepthFirst(aVisitor);
			}
		}
	}
	
	// breadth-first traversal
	void traverseBreadthFirst(const TreeVisitor<T>& aVisitor) const
	{

	}

};
