
// COS30008, Tutorial 7 - Self Study Project, 2019

#include "DoublyLinkedNode.h"

#include <iostream>
#include <string>

using namespace std;

void test1()
{
	string s1("Easter");
	string s2("Self");
	string s3("Study");
	string s4("Project");
	typedef DoublyLinkedNode<string>::Node StringNode;
	StringNode n1(s1);
	StringNode n2(s2);
	StringNode n3(s3);
	StringNode n4(s4);
	cout << "\nTest push_back:" << endl;
	n1.push_back(n4);
	n1.push_back(n3);
	n1.push_back(n2);
	cout << "The nodes:" << endl;
	for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext())
	{
		cout << "(";
		if (&pn->getPrevious() != &StringNode::NIL)
			cout << pn->getPrevious().getValue();
		else
			cout << "<NULL>";
		cout << "," << pn->getValue() << ",";
		if (&pn->getNext() != &StringNode::NIL)
			cout << pn->getNext().getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
	n2.remove();
	cout << "The nodes:" << endl;
	for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext())
	{
		cout << "(";
		if (&pn->getPrevious() != &StringNode::NIL)
			cout << pn->getPrevious().getValue();
		else
			cout << "<NULL>";
		cout << "," << pn->getValue() << ",";
		if (&pn->getNext() != &StringNode::NIL)
			cout << pn->getNext().getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
}

void test2()
{
    string s1( "Project" );
    string s2( "Study" );
    string s3( "Self" );
    string s4( "Easter" );

    typedef DoublyLinkedNode<string>::Node StringNode;
    
    StringNode n1( s1 );
    StringNode n2( s2 );
    StringNode n3( s3 );
    StringNode n4( s4 );
    
    cout << "\nTest push_front:" << endl;
    
    n4.push_front( n1 );
    n4.push_front( n2 );
    n4.push_front( n3 );
    
    cout << "The nodes:" << endl;
    
    for ( const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext() )
    {
        cout << "(";
        if ( &pn->getPrevious() != &StringNode::NIL )
            cout << pn->getPrevious().getValue();
        else
            cout << "<NULL>";
        
        cout << "," << pn->getValue()<< ",";
        
        if ( &pn->getNext() != &StringNode::NIL )
            cout << pn->getNext().getValue();
        else
            cout << "<NULL>";
        
        cout << ")" << endl;
    }
    
    n3.remove();
    
    cout << "The nodes:" << endl;
    
    for ( const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext() )
    {
        cout << "(";
        if ( &pn->getPrevious() != &StringNode::NIL )
            cout << pn->getPrevious().getValue();
        else
            cout << "<NULL>";
        
        cout << "," << pn->getValue() << ",";
        
        if ( &pn->getNext() != &StringNode::NIL )
            cout << pn->getNext().getValue();
        else
            cout << "<NULL>";
        
        cout << ")" << endl;
    }
}

int main()
{
	test1();
    
	test2();
    
	return 0;
}
