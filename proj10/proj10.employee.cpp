/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #10

****************************************************************************/

using namespace std;
#include <iostream>
#include <iomanip>
#include <new>
#include <stdlib.h>
#include "proj10.employee.h"
#include <string>
#include <fstream>
#include <sstream> 
#include <stdio.h>

/*-----------------------------------------------------------------------------
   Name:  default constructor

   Purpose:  Initialize Employee to empty (create header node, Employee Num to 0).
-----------------------------------------------------------------------------*/

Employee::Employee()
{
	Num = 0;
	HeadName = new (nothrow) Node;
	HeadName->SuccName = NULL;
	HeadIden = new (nothrow) Node;
	HeadIden->SuccIden = NULL;
}


/*-----------------------------------------------------------------------------
   Name:  is_present

   Purpose:  Test for presence of specified item in Employee.
   Returns:  True if the item was present; false otherwise.
-----------------------------------------------------------------------------*/

bool Employee::is_present( unsigned X ) const
{
  	Node * Temp = HeadIden->SuccIden;	
	
	for (unsigned I = 0; I < Num; I++)
	{
		if (X == Temp->Iden) return true;
		else
		{
		    Temp = Temp->SuccIden;
		}
	}
	return false;
}



/*-----------------------------------------------------------------------------
   Name:  department_name

   Purpose:  Take department code and turn it into name of department
-----------------------------------------------------------------------------*/
string Employee::department_name( unsigned N ) const
{
	string name;
	if (N == 32)
	{
		name = "Accounting              ";
	}
	
	if (N == 33)
	{
		name = "Human Resources         ";
	}

	if (N == 34)
	{
		name = "Information Services    ";
	}
	
	if (N == 35)
	{
		name = "Research and Development";
	}
	
	if (N == 36)
	{
		name = "Sales and Marketing     ";
	}
	
	if (N == 37)
	{
		name = "Shipping and Receiving  ";
	}
	return name;
}
	
/*-----------------------------------------------------------------------------
   Name:  salary_change

   Purpose:  Take salary and turn it into properly formatted salary
-----------------------------------------------------------------------------*/
string Employee::salary_change( unsigned S ) const
{
	unsigned salary = S;
	string String = static_cast<ostringstream*>( &(ostringstream() << S) )->str();
	unsigned length = String.length();
	unsigned commas = length/3;
	string newString;
	while (commas > 0)
	{
		unsigned remainder = salary % 1000;
		string remainder_str = static_cast<ostringstream*>( &(ostringstream() << remainder) )->str();
		if (remainder==0) {remainder_str = "000";}
		salary = salary/1000;
		newString.insert(0, remainder_str);
		newString.insert(0, ",");
		commas--;
	}

	string salary_str = static_cast<ostringstream*>( &(ostringstream() << salary) )->str();
	newString.insert(0, salary_str);
	newString.insert(0, "$");
	return newString;
}


/*-----------------------------------------------------------------------------
   Name:  by_iden

   Purpose:  Display the Employees by identification with proper formatting.
-----------------------------------------------------------------------------*/

void Employee::by_iden( ofstream& name) 
{
  	Node * Prev = HeadIden;
  	Node * Curr = HeadIden->SuccIden;
    name << resetiosflags( ios::right ) << setiosflags( ios::left ) 
    << setw (31) << "Name" << setw (8) << "ID" << 
 	setw (28) << "Department" << "  "	<< "Salary" << endl;


	if (Num != 0)
	{
		for (unsigned I=0; I<Num; I++)
		{
    		string Department = department_name (Curr->Dept);
  			string SalaryFormat = salary_change( Curr->Salary );
    		name << setw (31) << Curr->Name << 
    		setw (8) << Curr->Iden << 
    		setw (28) << Department << "  "
    		<< SalaryFormat 
    		<< endl;
    		Prev = Curr;
			Curr = Curr->SuccIden;
		}
	}
	name << endl;
}


/*-----------------------------------------------------------------------------
   Name:  by_iden_new

   Purpose:  Display the Employees by identification with proper formatting.
-----------------------------------------------------------------------------*/

void Employee::by_iden_new( ofstream& name) 
{
  	Node * Prev = HeadIden;
  	Node * Curr = HeadIden->SuccIden;
	if (Num != 0)
	{
		for (unsigned I=0; I<Num; I++)
		{
    		string Department = department_name (Curr->Dept);
  			string SalaryFormat = salary_change( Curr->Salary );
    		name << Curr->Iden << "  " << Curr->Dept << "  " <<
    		Curr->Salary << "  " << Curr->Name << endl;
    		Prev = Curr;
			Curr = Curr->SuccIden;
		}
	}
	name << endl;
}


/*-----------------------------------------------------------------------------
   Name:  by_name

   Purpose:  Display the Employees by name with proper formatting.
-----------------------------------------------------------------------------*/

void Employee::by_name( ofstream& name) 
{
  	Node * Prev = HeadName;
  	Node * Curr = HeadName->SuccName;
    name << resetiosflags( ios::right ) << setiosflags( ios::left ) 
    << setw (31) << "Name" << setw (8) << "ID" << 
 	setw (28) << "Department" << "  "	<< "Salary" << endl;


	if (Num != 0)
	{
		for (unsigned I=0; I<Num; I++)
		{
    		string Department = department_name (Curr->Dept);
  			string SalaryFormat = salary_change( Curr->Salary );
    		name << setw (31) << Curr->Name << 
    		setw (8) << Curr->Iden << 
    		setw (28) << Department << "  "
    		<< SalaryFormat 
    		<< endl;
    		Prev = Curr;
			Curr = Curr->SuccName;
		}
	}
	name << endl;
}

/*-----------------------------------------------------------------------------
   Name:  remove

   Purpose:  Remove the specified item, if possible.
   Returns:  True if the item was removed; false otherwise.
-----------------------------------------------------------------------------*/

bool Employee::remove( unsigned X )
{
  	bool Flag = false;
  	unsigned Position = 0;
  	Node * Prev = HeadIden;
  	Node * Curr = HeadIden->SuccIden;
  	Node * PrevN = HeadName;
  	Node * CurrN = HeadName->SuccName;
  
	if (is_present(X)==true)
	{	
		while (X != Curr->Iden)
    	{
			Prev = Curr;
			Curr = Curr->SuccIden;
			PrevN = CurrN;
			CurrN = CurrN->SuccName;
		}

	    Prev->SuccIden = Curr->SuccIden;
	    PrevN->SuccName = CurrN->SuccName;
    	delete Curr;
    	Num--;

    	Flag = true;
	}
  	return Flag;
}  
	                    

/*-----------------------------------------------------------------------------
   Name:  insert

   Purpose:  Insert X into the Employee, if possible.  If the Employee
     is full, allocate additional space before inserting the item.
   Returns:  True if the item was inserted; false otherwise.
-----------------------------------------------------------------------------*/

bool Employee::insert( unsigned I, unsigned D, unsigned S, string N )
{
	bool Flag = false;
    unsigned Position = 0;
    unsigned Position2 = 0;
  	Node * Prev = HeadIden;
  	Node * Curr = HeadIden->SuccIden;
  	Node * PrevN = HeadName;
  	Node * CurrN = HeadName->SuccName;
  	Node * Temp;

	if (is_present(I)) return false;
	if (I < 10000 || I > 99999)
	{
		cout << "Invalid employee identifier" << endl;
		return false;
	}
	if (!(D > 31 && D < 38))
	{
		cout << "Invalid department" << endl;
		return false;
	}
	
    Temp = new (nothrow) Node;
    if (Temp != NULL)
    {
    	while ((Position < Num) && (I > Curr->Iden))
      	{
        	Position++;
        	Prev = Curr;
        	Curr = Curr->SuccIden;
      	}
      	
      	while ((Position2 < Num) && (N.compare(PrevN->Name) > 0))
      	{
        	Position2++;
        	PrevN = CurrN;
        	CurrN = CurrN->SuccName;
      	}
      	
      	Temp->Iden = I;
      	Temp->Dept = D;
      	Temp->Salary = S;
      	Temp->Name = N;
      	Temp->SuccIden = Curr;
      	Prev->SuccIden = Temp;
      	Temp->SuccName = CurrN;
      	PrevN->SuccName = Temp;
      	Num++;
      	Flag = true;
      }
      	

  	
  	return Flag;
}

/*-----------------------------------------------------------------------------
   Name:  update_department

   Purpose:  Update the department of the employee if possible
   Returns:  True if the item was updated; false otherwise.
-----------------------------------------------------------------------------*/

bool Employee::update_department( unsigned I, unsigned D )
{
	bool Flag = false;
  	unsigned Position = 0;
  	Node * Prev = HeadIden;
  	Node * Curr = HeadIden->SuccIden;
  
	if (is_present(I)==true && D > 31 && D < 38)
	{	
		while (I != Curr->Iden)
    	{
			Prev = Curr;
			Curr = Curr->SuccIden;
		}

		Curr->Dept = D;
    	Flag = true;
	}
	
	if (is_present(I)==false)
	{
		cout << "Employee not found" << endl;
	}
	
	if (!(D > 31 && D < 38))
	{
		cout << "Invalid department" << endl;
  	}
  	return Flag;
}
	
/*-----------------------------------------------------------------------------
   Name:  update_salary

   Purpose:  Update the salary of the employee if possible
   Returns:  True if the item was updated; false otherwise.
-----------------------------------------------------------------------------*/

bool Employee::update_salary( unsigned I, unsigned S )
{	
	bool Flag = false;
  	unsigned Position = 0;
  	Node * Prev = HeadIden;
  	Node * Curr = HeadIden->SuccIden;
  
	if (is_present(I)==true)
	{	
		while (I != Curr->Iden)
    	{
			Prev = Curr;
			Curr = Curr->SuccIden;
		}

		Curr->Salary = S;
    	Flag = true;
	}
	
	if (is_present(I)==false)
		{
			cout << "Employee not found" << endl;
		}
  	return Flag;
}