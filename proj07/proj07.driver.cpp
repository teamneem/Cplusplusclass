/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #7

****************************************************************************/

using namespace std;
#include <iostream>
#include <new>
#include <stdlib.h>
#include "/user/cse232/Projects/project07.set.h"


/*-----------------------------------------------------------------------------
   Demonstrate selected operations from the Set class template
-----------------------------------------------------------------------------*/

int main()
{
	//Testing initializing set
	Set A;
	unsigned Position;
	bool Flag;
	
	cout << boolalpha;

	//Testing insert function for initial value
	A.insert( 500);
	A.insert( 500);
	A.insert( 300);
	A.insert( 400);
	A.insert( 600);
	A.insert( 200);

	//Printing the set of A
	cout << "Printing set A" << endl;
	A.display(std::cout);
	
	//Testing to see if values are present
	Flag = A.is_present( 500 );
    cout << "Is '500' present? Flag: " << Flag  << endl;
    Flag = A.is_present( 800 );
    cout << "Is '800' present? Flag: " << Flag  << endl;
    
    //Displaying if Set A is empty and it's size
    cout << "Set A: Value returned by 'is_empty': " << A.is_empty() << endl;
	cout << "Set A: Value returned by 'size':   " << A.size() << endl << endl;   

	//Test inserting an item that's smallest
	A.insert(100);
	cout << "Printing set A after adding small item" << endl;
	A.display(std::cout);
	
	//Test inserting a middle item
	A.insert(350);
	cout << "Printing set A after adding item in middle" << endl;
	A.display(std::cout);
	
	//Test inserting a large item
	A.insert(700);
	cout << "Printing set A after adding item in end" << endl;
	A.display(std::cout);
	
	//Test inserting an item already there
	Flag = A.insert(700);
	cout << "Printing set A after adding item that's already there" << endl;
	cout << "Did it insert? " << Flag << endl;
	A.display(std::cout);
	
	//Test inserting an item that increases capacity
	A.insert( 1000);
	cout << "Printing set A after adding item that increases capacity" << endl;
	A.display(std::cout);

	//Test removing an item from the beginning
	A.remove(100);
	cout << "Printing set A after removing item from beginning" << endl;
	A.display(std::cout);
	
	//Test removing an item from the middle
	A.remove(400);
	cout << "Printing set A after removing item from middle" << endl;
	A.display(std::cout);
	
	//Test removing an item from the end
	A.remove(1000);
	cout << "Printing set A after removing item from end" << endl;
	A.display(std::cout);
	
	//Test removing an item that's not there
	Flag = A.remove(1000);
	cout << "Printing set A after removing item that's not there" << endl;
	cout << "Did it remove? " << Flag << endl;
	A.display(std::cout);
	cout << endl;	  	

	//Test removing an item from the front
	Set B;
	cout << "Set B: ";
	B.display(std::cout);	
	B.insert(800);
	B.insert(600);
	B.insert(700);
	B.insert(400);
	
	cout << "Set B after inserting 800, 600, 700, 400: ";
	B.display(std::cout);
	cout << "Set B: Value returned by 'is_empty': " << B.is_empty() << endl;
	cout << "Set B: Value returned by 'size':   " << B.size() << endl << endl;   
	
	cout << "Set A: ";
	A.display(std::cout);
	
	cout << "Set B: ";
	B.display(std::cout);
	
	//Test assignment constructor
	Set C = B;
	cout << "Set C = B: ";
	C.display(std::cout);	
	
	//Test copy constructor
	Set D(A);
	cout << "Set D(A): ";
	D.display(std::cout);	
	
	//Test union
	Set E = C+D;
	cout << "Set E = C+D: ";
	E.display(std::cout);		
	
	//Test union with an empty set
	Set F;
	F = C+F;
	cout << "Set F = C+F (empty set): ";
	F.display(std::cout);	
	
	//Test intersection
	Set G = C^D;
	cout << "Set G = C^D: ";
	G.display(std::cout);	
	
	//Test the intersection of two sets, equaling an empty set
	Set H;
	Set I;
	Set J;
	J = H^I;
	
	cout << "Set H: ";
	H.display(std::cout);
	cout << "Set I: ";
	I.display(std::cout);
	cout << "Set J = H^I: ";
	J.display(std::cout);
	cout << endl;
	
	//Test the intersection of two sets, equaling an empty set
	H.insert(10);
	H.insert(20);
	I.insert(50);
	J = H^I;
	
	cout << "Set H: ";
	H.display(std::cout);
	cout << "Set I: ";
	I.display(std::cout);
	cout << "Set J = H^I: ";
	J.display(std::cout);
	cout << endl;
	
	//Deinitializing set A
	A.~Set();
    //Displaying if Set A is empty and it's size
    cout << "Deinitializing set A" << endl;
    cout << "Set A: Value returned by 'is_empty': " << A.is_empty() << endl;
	cout << "Set A: Value returned by 'size':   " << A.size() << endl << endl; 
}
