
// COS30008, Problem Set 5, 2019

#include <iostream>
#include <string>

// enable problem 1
#define CopyControl
#include "List.h"

// enable problem 2

#define StackTest
#include "Stack.h"
#include "StackIterator.h"


// enable problem 3
/*
#define QueueTest
#include "Queue.h"
#include "QueueIterator.h"
*/
using namespace std;

void testCoopyControl()
{
#ifdef CopyControl
    
    string s1( "AAAA" );
    string s2( "BBBB" );
    string s3( "CCCC" );
    string s4( "DDDD" );
    string s5( "EEEE" );
    
    List<string> lList;
    
    lList.push_front( s4 );
    lList.push_front( s3 );
    lList.push_front( s2 );
    
    List<string> copy( lList );
    
    // iterate from the top
    cout << "A - Top to bottom: " << copy.size() << " elements" << endl;
    
    for ( const string& element : copy )
    {
        cout << "A list element: " << element << endl;
    }
    
    // override list
    lList = copy;
    
    lList.push_front( s1 );
    lList.push_back( s5 );
    
    // iterate from the top
    cout << "B – Bottom to top: " << lList.size() << " elements" << endl;
    
    for ( List<string>::Iterator iter = lList.rbegin();
                iter != iter.rend(); iter-- )
    {
        cout << "A list element: " << *iter << endl;
    }
    
#endif
    
    cout << "Test of copy contol completed." << endl;
}

void testStack()
{
#ifdef StackTest
    
    Stack<string> lStack;
    
    lStack.push( "AAAA" );
    lStack.push( "BBBB" );
    lStack.push( "CCCC" );
    lStack.push( "DDDD" );
    
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    cout << "size: " << lStack.size() << endl;
    cout << "is empty: " << (lStack.isEmpty() ? "T" : "F" ) << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "is empty: " << (lStack.isEmpty() ? "T" : "F" ) << endl;
    
#endif
    
    cout << "Test of stack completed." << endl;
}


void testStackIterator()
{
#ifdef StackTest
    
    Stack<string> lStack;
    
    string s1( "One" );
    string s2( "Two" );
    string s3( "Three" );
    string s4( "Four" );
    string s5( "Five" );
    string s6( "Six" );
    
    lStack.push( s1 );
    lStack.push( s2 );
    lStack.push( s3 );
    lStack.push( s4 );
    lStack.push( s5 );
    lStack.push( s6 );
    
    cout << "Traverse elements" << endl;
    StackIterator<string> iter( lStack );

    for ( StackIterator<string> i = iter.begin(); i != i.end(); ++i )
    {
        cout << "value: " << *i++ << endl;
    }
    
#endif
    
    cout << "Test of stack iterator completed." << endl;
}

void testQueue()
{
#ifdef QueueTest

    Queue<int> lQueue;
    
    lQueue.enqueue( 1 );
    lQueue.enqueue( 2 );
    lQueue.enqueue( 3 );
    lQueue.enqueue( 4 );
    lQueue.enqueue( 5 );
    lQueue.enqueue( 6 );
    
    cout << "Queue elements:" << endl;
    
    for ( ;!lQueue.isEmpty(); lQueue.dequeue() )
    {
        cout << "value: " << lQueue.top() << endl;
    }
    
#endif
    
    cout << "Test of queue completed." << endl;
}

void testQueueIterator()
{
#ifdef QueueTest
    
    Queue<string> lQueue;
    
    string s1( "One" );
    string s2( "Two" );
    string s3( "Three" );
    string s4( "Four" );
    string s5( "Five" );
    string s6( "Six" );
    
    lQueue.enqueue( s1 );
    lQueue.enqueue( s2 );
    lQueue.enqueue( s3 );
    lQueue.enqueue( s4 );
    lQueue.enqueue( s5 );
    lQueue.enqueue( s6 );
    
    cout << "Traverse queue elements" << endl;
    QueueIterator<string> iter( lQueue );
    
    for ( QueueIterator<string> i = iter.begin(); i != i.end(); ++i )
    {
        cout << "value: " << *i++ << endl;
    }
    
#endif
    
    cout << "Test of queue iterator completed." << endl;
}

int main()
{
    testCoopyControl();
    testStack();
    testStackIterator();
    testQueue();
    testQueueIterator();

	return 0;
}
