
// COS30008 - Problem Set 7, 2019

#include "NTree.h"
#include "TreeVisitorPS7.h"

#include <iostream>
#include <string>

using namespace std;

void testDepthFirstTraversal()
{
    string A( "A" );
    string A1( "AA" );
    string A2( "AB" );
    string A3( "AC" );
    string AA1( "AAA" );
    string AB1( "ABA" );
    string AB2( "ABB" );
    
    typedef NTree<string,3> NS3Tree;
    
    NS3Tree lTree( A );
    
    lTree.attachNTree( 0, *(new NS3Tree( A1 )) );
    lTree.attachNTree( 1, *(new NS3Tree( A2 )) );
    lTree.attachNTree( 2, *(new NS3Tree( A3 )) );
    
    lTree[0].attachNTree( 0, *(new NS3Tree( AA1 )) );
    lTree[1].attachNTree( 0, *(new NS3Tree( AB1 )) );
    lTree[1].attachNTree( 1, *(new NS3Tree( AB2 )) );
    
    cout << "Depth-first traversal:" << endl;
    
    lTree.traverseDepthFirst( PreOrderVisitor<string>() );
    
    cout << endl << "Success." << endl;
}

void testBreadthFirstTraversal()
{
    string A( "A" );
    string A1( "AA" );
    string A2( "AB" );
    string A3( "AC" );
    string AA1( "AAA" );
    string AB1( "ABA" );
    string AB2( "ABB" );
    
    typedef NTree<string,3> NS3Tree;
    
    NS3Tree lTree( A );
    
    lTree.attachNTree( 0, *(new NS3Tree( A1 )) );
    lTree.attachNTree( 1, *(new NS3Tree( A2 )) );
    lTree.attachNTree( 2, *(new NS3Tree( A3 )) );
    
    lTree[0].attachNTree( 0, *(new NS3Tree( AA1 )) );
    lTree[1].attachNTree( 0, *(new NS3Tree( AB1 )) );
    lTree[1].attachNTree( 1, *(new NS3Tree( AB2 )) );
    
    cout << "Breadth-first traversal:" << endl;
    
    lTree.traverseBreadthFirst( TreeVisitor<string>() );
    
    cout << endl << "Success." << endl;
}

void testLinearRepresentation()
{
    string A( "A" );
    string A1( "AA" );
    string A2( "AB" );
    string A3( "AC" );
    string AA1( "AAA" );
    string AB1( "ABA" );
    string AB2( "ABB" );
    
    typedef NTree<string,3> NS3Tree;
    
    NS3Tree lTree( A );
    
    lTree.attachNTree( 0, *(new NS3Tree( A1 )) );
    lTree.attachNTree( 1, *(new NS3Tree( A2 )) );
    lTree.attachNTree( 2, *(new NS3Tree( A3 )) );
    
    lTree[0].attachNTree( 0, *(new NS3Tree( AA1 )) );
    lTree[1].attachNTree( 0, *(new NS3Tree( AB1 )) );
    lTree[1].attachNTree( 1, *(new NS3Tree( AB2 )) );
    
    cout << "Linear representation:" << endl;
    
    lTree.traverseDepthFirst( LeftLinearVisitor<string>() );
    
    cout << endl << "Success." << endl;
}

int main()
{
    testDepthFirstTraversal();

    testBreadthFirstTraversal();

    testLinearRepresentation();

    return 0;
}
