
// COS30008, Problem Set 3, 2019

#pragma once

// forward declaration to break mutual recursion of
// FibonacciSequence and FibonacciSequence
class FibonacciSequence;

class FibonacciSequenceIterator
{
private:
    FibonacciSequence* fPtrToSequenceObject;    // pointer to sequence object
    unsigned long fIndex;                       // current iterator position

public:
    
    // iterator constructor, takes a pointer to a FibonacciSequence object
    // pointers can be compared
    FibonacciSequenceIterator( FibonacciSequence* aPtrToSequenceObject,
                               unsigned long aStart = 1 );
    
    // iterator methods
    
    const unsigned long& operator*() const;      // return current Fibonacci number
    FibonacciSequenceIterator& operator++();     // prefix, next Fibonacci number
    FibonacciSequenceIterator operator++( int ); // postfix (extra unused argument)
    bool operator==( const FibonacciSequenceIterator& aOther ) const;
    bool operator!=( const FibonacciSequenceIterator& aOther) const;

    // iterator methods
    
    // return new iterator positioned at start
    FibonacciSequenceIterator begin() const;

    // return new iterator positioned at limit
    FibonacciSequenceIterator end() const;
};
