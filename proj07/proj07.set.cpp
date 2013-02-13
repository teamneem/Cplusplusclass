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
   Name:  destructor

   Purpose:  De-initialize the set.
-----------------------------------------------------------------------------*/

Set::~Set()
{
  Num = 0;
  Cap = 0;
  delete [] Pool;
  Pool = NULL;
}


/*-----------------------------------------------------------------------------
   Name:      copy constructor

   Purpose:   Initialize a new set by copying an existing set.
-----------------------------------------------------------------------------*/

Set::Set( const Set& Source )
{
	Num = Source.Num;
	Cap = Source.Cap;

	Pool = new (nothrow) int [Cap];
	if (Pool == NULL)
  	{
    	cerr << "*** Fatal: unable to allocate " << Cap << " elements\n";
    	exit( 1 );
	}

	for (unsigned I=0; I<Cap; I++)
	{
    	Pool[I] = Source.Pool[I];
	}
}


/*-----------------------------------------------------------------------------
   Name:      assignment operator

   Purpose:   Assign into a set by copying an existing set.
-----------------------------------------------------------------------------*/

Set& Set::operator=( const Set& RHS )
{
	if (this != &RHS)
	{
		Num = RHS.Num;
		Cap = RHS.Cap;

    	delete [] Pool;
    	Pool = new (nothrow) int [Cap];
    	if (Pool == NULL)
    	{
      		cerr << "*** Fatal: unable to allocate " << Cap << " elements\n";
      		exit( 1 );
		}

    	for (unsigned I=0; I<Cap; I++)
    	{
      		Pool[I] = RHS.Pool[I];
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
	for (unsigned I = 0; I < Num; I++)
	{
		if (X == Pool[I]) return true;
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

	if (is_present(X)==true)
	{		
		unsigned Position = 0;

  		while ((Position < Num)&& !(X == Pool[Position]))
  		{
			Position++;
		}
  
   		X = Pool[Position];
    	for (unsigned J=Position+1; J<Num; J++)
    	{
			Pool[J-1] = Pool[J];
		}
		
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

bool Set::insert( int X)
{
	if (is_present(X)) return false;
	
    if (Num == Cap)
	{
		const unsigned Inc = 8;

		int * Temp = new (nothrow) int[Cap+Inc];
		if (Temp != NULL)
  			{
    			for (unsigned J=0; J<Num; J++)
    			{
					Temp[J] = Pool[J];
				}

    			delete [] Pool;
    			Pool = Temp;

    			Cap = Cap + Inc;
  			}
	}
	
    if (Num < Cap)
	{
		unsigned Position = 0;

  		while ((Position < Num)&& (X > Pool[Position]))
  		{
			Position++;
		}
		
    	for (unsigned K=Num; K>Position; K--)
    	{
			Pool[K] = Pool[K-1];
		}
    	
		Pool[Position] = X;
		Num++;
		return true;
	}
	
	return false;
}


/*-----------------------------------------------------------------------------
   Name:  display

   Purpose:  Display the set with proper formatting.
-----------------------------------------------------------------------------*/

void Set::display( ostream& name) const
{
	name << "{";

	if (!(Num == 0))
	{
		for (unsigned I=0; I<Num-1; I++)
		{
    		name << Pool[I] << ", ";
		}
		name << Pool[Num-1];
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
	
	if (A.is_empty() && B.is_empty()) return C;
	
	for (unsigned I = 0; I < A.size(); I++)
	{
		C.insert(A.Pool[I]);
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
	
	for (unsigned I = 0; I < A.size(); I++)
	{
		if (!(B.is_present(A.Pool[I])))
		{
			C.remove(A.Pool[I]);
		}
	}
	return C;
}