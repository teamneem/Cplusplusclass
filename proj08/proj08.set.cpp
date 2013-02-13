/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #8

****************************************************************************/

using namespace std;
#include <iostream>
#include <new>
#include <stdlib.h>
#include "/user/cse232/Projects/project08.set.h"

/*-----------------------------------------------------------------------------
   Name:  default constructor

   Purpose:  Initialize set to empty (create header node, set Num to 0).
-----------------------------------------------------------------------------*/

Set::Set()
{
  Num = 0;
  Head = new (nothrow) Node;
  Head->Succ = NULL;
}

/*-----------------------------------------------------------------------------
   Name:  destructor

   Purpose:  De-initialize the set.
-----------------------------------------------------------------------------*/

Set::~Set()
{
  	Node * Temp1 = Head->Succ;
  	Node * Temp2;

  	while (Temp1 != NULL)
    {
    	Temp2 = Temp1;
    	Temp1 = Temp1->Succ;
    	delete Temp2;
    }

	Head->Succ = NULL;
	Num = 0;
}


/*-----------------------------------------------------------------------------
   Name:      copy constructor

   Purpose:   Initialize a new set by copying an existing set.
-----------------------------------------------------------------------------*/

Set::Set( const Set& Source )
{
  	bool Flag;

  	Num = 0;
  	Head = new (nothrow) Node;
  	Head->Succ = NULL;
  	
  	Node * Temp = Source.Head->Succ;
  	for (unsigned I=0; I<Source.Num; I++)
	{
	   	Flag = insert( Temp->Item );
		Temp = Temp->Succ;
    }
}


/*-----------------------------------------------------------------------------
   Name:      assignment operator

   Purpose:   Assign into a set by copying an existing set.
-----------------------------------------------------------------------------*/

Set& Set::operator=( const Set& RHS )
{
	bool Flag;

	if (this != &RHS)
	{
		Node * Temp1 = Head->Succ;
  		Node * Temp2;

		while (Temp1 != NULL)
		{
			Temp2 = Temp1;
			Temp1 = Temp1->Succ;
			delete Temp2;
		}

		Head->Succ = NULL;
		Num = 0;

  	
  		Node * Temp = RHS.Head->Succ; 
		for (unsigned I=0; I<RHS.Num; I++)
    	{
      		Flag = insert( Temp->Item );
			Temp = Temp->Succ;
    	}
  	}
  	return *this;      
}

/*-----------------------------------------------------------------------------
   Name:  is_present

   Purpose:  Test for presence of specified item in set.
   Returns:  True if the item was present; false otherwise.
-----------------------------------------------------------------------------*/

bool Set::is_present( int X ) const
{
  	Node * Temp = Head->Succ;	
	
	for (unsigned I = 0; I < Num; I++)
	{
		if (X == Temp->Item) return true;
		else
		{
		    Temp = Temp->Succ;
		}
	}
	return false;
}


/*-----------------------------------------------------------------------------
   Name:  remove

   Purpose:  Remove the specified item, if possible.
   Returns:  True if the item was removed; false otherwise.
-----------------------------------------------------------------------------*/

bool Set::remove( int X )
{
  	bool Flag = false;
  	unsigned Position = 0;
  	Node * Prev = Head;
  	Node * Curr = Head->Succ;
  
	if (is_present(X)==true)
	{	
		while (X != Curr->Item)
    	{
			Prev = Curr;
			Curr = Curr->Succ;
		}

	    Prev->Succ = Curr->Succ;
    	delete Curr;
    	Num--;

    	Flag = true;
	}
  	return Flag;
}  
	                    

/*-----------------------------------------------------------------------------
   Name:  insert

   Purpose:  Insert X into the set, if possible.  If the set
     is full, allocate additional space before inserting the item.
   Returns:  True if the item was inserted; false otherwise.
-----------------------------------------------------------------------------*/

bool Set::insert( int X )
{
	bool Flag = false;
    unsigned Position = 0;
  	Node * Prev = Head;
  	Node * Curr = Head->Succ;
  	Node * Temp;

	if (is_present(X)) return false;

    Temp = new (nothrow) Node;
    if (Temp != NULL)
    {
    	while ((Position < Num) && (X > Curr->Item))
      	{
        	Position++;
        	Prev = Curr;
        	Curr = Curr->Succ;
      	}
      	Temp->Item = X;
      	Temp->Succ = Curr;
      	Prev->Succ = Temp;
      	Num++;
      	Flag = true;
    }
  	
  	return Flag;
}


/*-----------------------------------------------------------------------------
   Name:  display

   Purpose:  Display the set with proper formatting.
-----------------------------------------------------------------------------*/

void Set::display( ostream& name) const
{
  	Node * Prev = Head;
  	Node * Curr = Head->Succ;
	name << "{";

	if (!(Num == 0))
	{
		for (unsigned I=0; I<Num-1; I++)
		{
    		name << Curr->Item << ", ";
    		Prev = Curr;
			Curr = Curr->Succ;
		}
		
		name << Curr->Item;
	}
	name << "}" << endl;
}


/*-----------------------------------------------------------------------------
   Name:  union

   Purpose:  Produce the union of two sets
-----------------------------------------------------------------------------*/

Set::Set operator+( const Set& A, const Set& B )
{
	Set C = B;
	
	bool Flag;	
	if (A.is_empty() && B.is_empty()) return C;

	Set D;
    D.Head = A.Head;
  	D.Head->Succ = A.Head->Succ;

	for (unsigned I=0; I<A.size(); I++)
    	{
			D.Head = D.Head->Succ;
			Flag = C.insert( D.Head->Item );
		}

	return C;
}


/*-----------------------------------------------------------------------------
   Name:  intersection

   Purpose:  Produce the intersection of two sets
-----------------------------------------------------------------------------*/

Set::Set operator^( const Set& A , const Set& B )
{
	Set C = A;
	Set D;
    D.Head = A.Head;
  	D.Head->Succ = A.Head->Succ;

	for (unsigned I=0; I<A.size(); I++)
    {
		D.Head = D.Head->Succ;
		if (!(B.is_present(D.Head->Item)))
		{
			C.remove(D.Head->Item);
		}
	}
	return C;
}

/*-----------------------------------------------------------------------------
   Name:  difference

   Purpose:  Produce the difference of two sets
-----------------------------------------------------------------------------*/

Set::Set operator-( const Set& A , const Set& B )
{
	Set C = A+B;
	Set D = A^B;
	Set E = C;
	for (unsigned I=0; I<C.size(); I++)
    {
		if ((D.is_present(C.Head->Item)))
		{
			E.remove(C.Head->Item);
		}
		C.Head = C.Head->Succ;
	}
	return E;
}
