
/******************************************************************************
  Project #9 -- Template for type "PQueue" (priority pqueue)
******************************************************************************/

#ifndef PQUEUE_
#define PQUEUE_

using namespace std;

#include <iostream>
#include <iomanip>
#include <new>

enum Direction { front_to_back, back_to_front };

template <typename EType>
class PQueue
{
  private:
 
	struct Node
	{
		EType Item;
		unsigned Priority;
		unsigned Identifier;
		Node * Pred;
		Node * Succ;
	};
 
    Node * Head;    // Pointer to head of chain (front)
    Node * Tail;    // Pointer to tail of chain (back)
    unsigned Num;
    unsigned IdentifierNum;
    
    //Put operation that also adds the identifier
    bool putiden( const EType&, unsigned, unsigned );

  public:

    // Initialize pqueue to empty
    //
    PQueue();

    // De-initialize pqueue
    //
    ~PQueue();

    // Re-initialize pqueue to empty
    //
    void reset();

    // Initialize pqueue using existing pqueue
    //
    PQueue( const PQueue<EType>& );

    // Assign into pqueue from other pqueue
    //
    PQueue<EType>& operator=( const PQueue<EType>& );

    // Display attributes and contents of pqueue
    // (from front to back, or back to front)
    //
    void display( ostream&, Direction ) const;

    // Return number of items in pqueue
    //
    unsigned length() const;

    // Return copy of item at front of pqueue (unless pqueue is empty)
    //
    bool front( EType& ) const;

    // Return copy of item at back of pqueue (unless pqueue is empty)
    //
    bool back( EType& ) const;

    // Insert one item (with specified priority) into pqueue (if possible)
    //
    bool put( const EType&, unsigned );

    // Remove item with highest priority from pqueue (unless pqueue is empty)
    //
    bool get( EType& );

    // Discard item with specified identifier from pqueue (if possible)
    //
    bool discard( unsigned );
};

/*-----------------------------------------------------------------------------
   Name:  default constructor

   Purpose:  Initialize PQueue to empty (create header node, set Num to 0).
-----------------------------------------------------------------------------*/

template <typename EType>
PQueue<EType>::PQueue()
{
	Num = 0;
	IdentifierNum = 1000;
	Head = new (nothrow) Node;
	Tail = new (nothrow) Node;
	Head->Succ = Tail;
	Tail->Pred = Head;
}

/*-----------------------------------------------------------------------------
   Name:  destructor

   Purpose:  De-initialize PQueue (reset PQueue, de-allocate header node).
-----------------------------------------------------------------------------*/

template <typename EType>
PQueue<EType>::~PQueue()
{
	reset();
	delete Head;
	delete Tail;
	Head = NULL;
	Tail = NULL;
	Num = 0;
}

/*-----------------------------------------------------------------------------
   Name:  reset

   Purpose:  Re-initialize PQueue (de-allocate all data nodes).
-----------------------------------------------------------------------------*/

template <typename EType>
void PQueue<EType>::reset()
{
	if (Head !=NULL)
	{
		Node * Temp1 = Head->Succ;
		Node * Temp2;
	
		while (Temp1 != NULL && Temp1 != Tail)
		{
    		Temp2 = Temp1;
    		Temp1 = Temp1->Succ;
			delete Temp2;
		}
  	
		Head->Succ = Tail;
		Tail->Pred = Head;
		Num = 0;
		IdentifierNum = 1000;
	}
}


/*-----------------------------------------------------------------------------
   Name:      copy constructor

   Purpose:   Initialize a new PQueue by copying an existing PQueue.
-----------------------------------------------------------------------------*/

template <typename EType>
PQueue<EType>::PQueue( const PQueue& Source )
{
  	bool Result;

  	Num = 0;
  	IdentifierNum = 1000;
  	Head = new (nothrow) Node;
  	Tail = new (nothrow) Node;
  	Head->Succ = Tail;
  	Tail->Pred = Head;
  	
  	Node * Temp = Source.Head->Succ;
	
	for (unsigned I=0; I<Source.Num; I++)
	{
		Result = putiden( Temp->Item, Temp->Priority, Temp->Identifier );
		Temp = Temp->Succ;
    }
}


/*-----------------------------------------------------------------------------
   Name:      assignment operator

   Purpose:   Assign into a PQueue by copying an existing PQueue.
-----------------------------------------------------------------------------*/

template <typename EType>
PQueue<EType> &PQueue<EType>::operator=( const PQueue& RHS )
{
	bool Result;

	if (this != &RHS)
	{
		reset();

		Node * Temp = RHS.Head->Succ; 
		for (unsigned I=0; I<RHS.Num; I++)
		{
		   	Result = putiden( Temp->Item, Temp->Priority, Temp->Identifier );
			Temp = Temp->Succ;
		}
	}
  	return *this;      
}


/*-----------------------------------------------------------------------------
   Name:      length

   Purpose:   Provides length of the pqueue.
   Returns:   Length of pqueue
-----------------------------------------------------------------------------*/
template <typename EType>
unsigned PQueue<EType>::length( ) const
{ 
	return Num; 
}


/*-----------------------------------------------------------------------------
   Name: display 

   Purpose:  Display each element of the pqueue
   Receive:  pqueue to be displayed
-----------------------------------------------------------------------------*/

template <class EType>
void PQueue<EType>::display( ostream&, Direction X) const
{
	cout << "Number of elements: " << Num << endl;
	cout << "Head Address: " <<  (unsigned long)Head << endl;
 	cout << "Tail Address: " <<  (unsigned long)Tail << endl << endl;
 	
	if (Num != 0)
	{
		cout << "<" << setw(6) << "Item "
		<< setw (9) << "Priority"
		<< setw (12) << "Identifier"
		<< setw (10) << "Node"
		<< setw (10) << "Pred"
		<< setw (12)<< "Succ >" << endl;
	}

	
	if (Head != NULL && Num!=0 && X==front_to_back)
	{
		Node * First = Head;
		Node * Curr = Head->Succ;
  
		for (unsigned i=0; i<=Num && Curr!=Tail; i++)
    	{	
    		EType X = Curr->Item;
    		unsigned Y = Curr->Priority;
    		unsigned Z = Curr->Identifier;
    		
    		cout << "<" << setw (5)
    		<< X << setw (10)
    		<< Y << setw (12)
    		<< Z << setw (10)
    		<<  (unsigned long)Curr << setw (10)
    		<<  (unsigned long)Curr->Pred << setw (10)
    		<<  (unsigned long)Curr->Succ << " >" << endl;
    		First = Curr;
			Curr = Curr->Succ;
		}
		cout << endl;
	}
	
	if (Head != NULL && Num!=0 && X==back_to_front)
	{
		Node * Last = Tail;
		Node * Curr = Tail->Pred;
  
		for (unsigned i=0; i<=Num && Curr!=Head; i++)
    	{	
    		EType X = Curr->Item;
    		unsigned Y = Curr->Priority;
    		unsigned Z = Curr->Identifier;
    		
    		cout << "<" << setw (5)
    		<< X << setw (10)
    		<< Y << setw (12)
    		<< Z << setw (10)
    		<<  (unsigned long)Curr << setw (10)
    		<<  (unsigned long)Curr->Pred << setw (10)
    		<<  (unsigned long)Curr->Succ << " >" << endl;
    		Last = Curr;
			Curr = Curr->Pred;
		}
		cout << endl;
	}
}


/*-----------------------------------------------------------------------------
   Name:      front

   Purpose:   Provide copy of element at front of pqueue.
   Returns:   True if pqueue is not empty; false otherwise.
              Copy of front element (via reference parameter).
-----------------------------------------------------------------------------*/

template <typename EType>
bool PQueue<EType>::front( EType& X ) const
{
	bool Result = false;

	if (Head != NULL && Num!=0)
	{
		X = Head->Succ->Item;
		Result = true;
	}
  	
	return Result;
}


/*-----------------------------------------------------------------------------
   Name:      back

   Purpose:   Provide copy of element at back of pqueue.
   Returns:   True if pqueue is not empty; false otherwise.
              Copy of back element (via reference parameter).
-----------------------------------------------------------------------------*/

template <typename EType>
bool PQueue<EType>::back( EType& X ) const
{
  	bool Result = false;

  	if (Head != NULL && Num!=0)
  	{
		X = Tail->Pred->Item;
    	Result = true;
  	}
  	return Result;
}

/*-----------------------------------------------------------------------------
   Name:      put

   Purpose:   Insert one item (with specified priority) into pqueue (if possible)
   Returns:   True if new element inserted; false otherwise.
-----------------------------------------------------------------------------*/

template <typename EType>
bool PQueue<EType>::put( const EType& X, unsigned P )
{
	bool Flag = false;
	unsigned Position = 0;
  	
	Node * Prev = Head;
	Node * Curr = Head->Succ;
	Node * Temp;

	Temp = new (nothrow) Node;
	
	if (Temp !=NULL && P!=0)
    {		
    	while (Position <= Num &&  P >= Curr->Priority && Curr != Tail)
    	{
			Position++;
        	Prev = Curr;
        	Curr = Curr->Succ;
		}
	
    	Temp->Item = X;
    	Temp->Priority = P;
    	Num++;
    	IdentifierNum++;
	    Temp->Identifier = IdentifierNum;

		Temp->Pred = Prev;
		Temp->Succ = Prev->Succ;
		Curr->Pred = Temp;
		Prev->Succ = Temp;

    	Flag = true;
    }
    
	return Flag;
}

/*-----------------------------------------------------------------------------
   Name:      putiden

   Purpose:   Insert one item (with specified priority/identifier) into pqueue (if possible)
   Returns:   True if new element inserted; false otherwise.
-----------------------------------------------------------------------------*/

template <typename EType>
bool PQueue<EType>::putiden( const EType& X, unsigned P, unsigned I )
{
	bool Flag = false;
	unsigned Position = 0;
  	
	Node * Prev = Head;
	Node * Curr = Head->Succ;
	Node * Temp;

    Temp = new (nothrow) Node;
	
	if (Temp !=NULL && P!=0)
    {		
    	while (Position <= Num &&  P >= Curr->Priority && Curr != Tail)
    	{
			Position++;
        	Prev = Curr;
        	Curr = Curr->Succ;
		}
	
    	Temp->Item = X;
    	Temp->Priority = P;
    	Num++;
    	IdentifierNum++;
	    Temp->Identifier = I;

		Temp->Pred = Prev;
		Temp->Succ = Prev->Succ;
		Curr->Pred = Temp;
		Prev->Succ = Temp;

    	Flag = true;
    }
    
	return Flag;
}

/*-----------------------------------------------------------------------------
   Name:      get

   Purpose:   Remove item at with highest priority in the pqueue.
   Returns:   True if pqueue is not empty; false otherwise.
-----------------------------------------------------------------------------*/

template <typename EType>
bool PQueue<EType>::get( EType& X )
{
	bool Result = false;

	if (Head != NULL && Num!=0)
	{
		Node * Prev = Head;
		Node * Curr = Head->Succ;
		Node * Next = Curr->Succ;

    	X = Curr->Item;

	    Prev->Succ = Curr->Succ;
	    Next->Pred = Curr->Pred;
    	
    	delete Curr;
    	Num--;
    
    	Result = true;
	}
	return Result;
}
 

/*-----------------------------------------------------------------------------
   Name:  discard

   Purpose:  discard item with specified indentifier from pqueue (if possible)
   Returns:  True if the item was removed; false otherwise.
-----------------------------------------------------------------------------*/

template <typename EType>
bool PQueue<EType>::discard( unsigned I )
{
	bool Result = false;
	unsigned Position = 0;
	Node * Prev = Head;
	Node * Curr = Head->Succ;
  	
	if (Num>0 && I<=IdentifierNum)
	{
		while (Position < Num && Curr->Identifier!=I)
    	{
      		Position++;
      		Prev = Curr;
      		Curr = Curr->Succ;
    	}

		if (Curr->Identifier==I)
		{
			Curr->Succ->Pred = Prev;
    		Prev->Succ = Curr->Succ;
    		delete Curr;
    		Num--;

			Result = true;
		}
	}
  	
  	return Result;
}

#endif 



