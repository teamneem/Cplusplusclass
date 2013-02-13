/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #9

****************************************************************************/

using namespace std;
#include <iostream>
#include <new>
#include <stdlib.h>
#include "proj09.pqueue.h"


/*-----------------------------------------------------------------------------
   Name:      main
-----------------------------------------------------------------------------*/

int main()
{
	cout << boolalpha;
	PQueue<double> A;
	PQueue<int> B;
	bool Flag; 
	double Item;
	int Item2;

	//Empty Set
	cout << "Empty set A (double)" << endl;
    cout << "Show that length function works: " << A.length() << endl;
    A.display( std::cout, front_to_back );
    Flag = A.front(Item);
    cout << "Front item of A: " << Flag << ", " << Item << endl;
    Flag = A.back(Item);
    cout << "Back item of A: "<< Flag << ", " <<  Item << endl;
 	Flag =  A.get(Item);
	cout << "Get on A: " << Flag << endl;
	Flag = A.discard(1001);
	cout << "Discard 1001: " << Flag << endl << endl;

	A.put( 11.1, 3 );   // item 11.1, priority 3
	A.put( 22.2, 1 );   // item 22.2, priority 1
	A.put( 33.3, 3 );   // item 33.3, priority 3
	A.put( 44.4, 2 );   // item 44.4, priority 2
	A.put( 55.5, 1 );   // item 55.5, priority 1
    cout << "Display A after inputting 11.1(3), 22.2(1), 33.3(3), 44.4(2), 55.5(1)" << endl;
    cout << "Print front to back" << endl;
    A.display( std::cout, front_to_back );
    cout << "Print back to front" << endl;
    A.display( std::cout, back_to_front );
    Flag = A.front(Item);
    cout << "Front item of A: " << Flag << ", " << Item << endl;
    Flag = A.back(Item);
    cout << "Back item of A: "<< Flag << ", " <<  Item << endl;
 	Flag =  A.get(Item);
	cout << "Get on A: " << Flag << endl;
	Flag =  A.put( 12, 0 );
	cout << "Put with priority 0 in A: " << Flag << endl;
	Flag = A.discard(1001);
	cout << "Discard 1001: " << Flag << endl;
	Flag = A.discard(1007);
	cout << "Discard 1007: " << Flag << endl << endl;
	cout << "Reprinting A after 1001 was taken out and the first item was taken out" << endl;
    A.display( std::cout, front_to_back );

	cout << "Assignment operator: C=A" << endl;    
    PQueue<double> C = A;
    C.display( std::cout, front_to_back );
    
    cout << "Copy constructor: D(A)" << endl;
 	PQueue<double> D(A); 
    D.display( std::cout, front_to_back );
              
    PQueue<double> E = D;    
    cout << "E=D" << endl;  
    E.display( std::cout, front_to_back );     
    //Resetting PQueue E
    E.reset();
    cout << "Resetting set E" << endl;
	cout << "Set E: Value returned by 'size':   " << E.length() << endl << endl; 
    E.display( std::cout, front_to_back ); 
    
    E = C;
    cout << "E=C" << endl; 
    E.display( std::cout, front_to_back ); 
	E.~PQueue();
    cout << "Deinitializing set E" << endl;
	cout << "Set E: Value returned by 'size':   " << E.length() << endl << endl; 
    E.display( std::cout, front_to_back ); 
    
    
    	//Empty Set
	cout << "Empty set B (int)" << endl;
    cout << "Show that length function works: " << B.length() << endl;
    B.display( std::cout, front_to_back );
    Flag = B.front(Item2);
    cout << "Front item of B: " << Flag << ", " << Item2 << endl;
    Flag = B.back(Item2);
    cout << "Back item of B: "<< Flag << ", " <<  Item2 << endl;
 	Flag =  B.get(Item2);
	cout << "Get on B: " << Flag << endl;
	Flag = B.discard(1001);
	cout << "Discard 1001: " << Flag << endl << endl;

	B.put( 11, 3 );   // item 11, priority 3
	B.put( 22, 1 );   // item 22, priority 1
	B.put( 33, 3 );   // item 33, priority 3
	B.put( 44, 2 );   // item 44, priority 2
	B.put( 55, 1 );   // item 55, priority 1
	B.put( 46, 2 );   // item 46, priority 2
	B.put( 56, 1 );   // item 56, priority 1
    cout << "Display B after inputting 11(3), 22(1), 33(3), 44(2), 55(1), 46(2), 56(1)" << endl;
    cout << "Print front to back" << endl;
    B.display( std::cout, front_to_back );
    cout << "Print back to front" << endl;
    B.display( std::cout, back_to_front );
    Flag = B.front(Item2);
    cout << "Front item of B: " << Flag << ", " << Item2 << endl;
    Flag = B.back(Item2);
    cout << "Back item of B: "<< Flag << ", " <<  Item2 << endl;
 	Flag =  B.get(Item2);
	cout << "Get on B: " << Flag << endl;
	 Flag =  B.put( 12, 0 );
	cout << "Put with priority 0 in B: " << Flag << endl;
	Flag = B.discard(1001);
	cout << "Discard 1001: " << Flag << endl;
	Flag = B.discard(1007);
	cout << "Discard 1007: " << Flag << endl << endl;
	cout << "Reprinting B after 1001/1007 was taken out and the first item was taken out" << endl;
    B.display( std::cout, front_to_back );
    
    cout << "Assignment operator: F=B" << endl;    
    PQueue<int> F = B;
    F.display( std::cout, front_to_back );
    
    cout << "Copy constructor: G(B)" << endl;
 	PQueue<int> G(B); 
    G.display( std::cout, front_to_back );
}
