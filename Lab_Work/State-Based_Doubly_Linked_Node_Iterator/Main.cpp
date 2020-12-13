
// COS30008, Tutorial 9, 2019

#include "DoublyLinkedNodeIteratorLab9.h"

#include <iostream>

using namespace std;
 
void testDoublyLinkedNodeIterator()
{
    typedef DoublyLinkedNode<int>::Node IntNode;
    
    IntNode n1( 1 );
    IntNode n2( 2 );
    IntNode n3( 3 );
    IntNode n4( 4 );
    IntNode n5( 5 );
    IntNode n6( 6 );
    
    n1.push_back( n6 );
    n1.push_back( n5 );
    n1.push_back( n4 );
    n1.push_back( n3 );
    n1.push_back( n2 );
    
    DoublyLinkedNodeIterator<int> iter( n1 );
    
    iter--;
    
    cout << "Forward iteration I:" << endl;
    for ( iter++; iter != iter.end(); iter++ )
        cout << *iter << endl;
    
    cout << "Backward iteration I:" << endl;
    for ( iter--; iter != iter.rend(); iter-- )
        cout << *iter << endl;
    
    cout << "Forward iteration II:" << endl;
    for ( iter = iter.begin(); iter != iter.end(); ++iter )
        cout << *iter << endl;
    
    cout << "Backward iteration II:" << endl;
    for ( iter = iter.rbegin(); iter != iter.rend(); --iter )
        cout << *iter << endl;
    
    DoublyLinkedNodeIterator<int> iter2( DoublyLinkedNode<int>::NIL );
    
    if ( iter2 == iter2.end() )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    if ( iter2.begin() == iter2.end() )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    if ( iter2.rbegin() == iter2.rend() )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    testDoublyLinkedNodeIterator();
    
	return 0;
}
