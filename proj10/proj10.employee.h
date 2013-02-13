/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #10

****************************************************************************/

#ifndef Employee_
#define Employee_

using namespace std;

#include <iostream>
#include <string>


class Employee
{

private:

	struct Node
	{
		unsigned Iden;
		unsigned Dept;
		unsigned Salary;
		string Name;
		// User data item
		Node * SuccName;
		//Link to node's successor in name order
		Node * SuccIden;
		// Link to the node's successor in identification order
	}
	;

	string prefix;
	unsigned Num;
	// Current count of items in the Employee list
  
	Node * HeadIden;
	Node * HeadName;
	// Link to the head of the chain

public:

	// Initialize the Employee to empty
	Employee();
	
	//Report all employees in the data set by identification number
	void by_iden( ofstream& );
	
	//Report all employees in the data set by their name
	void by_name( ofstream& );
	
	//Report all employees in the data set by their ID
	void by_iden_new( ofstream& );
	
	//Update the department code for employee
	bool update_department ( unsigned, unsigned );
	
	//Update the salary for employee
	bool update_salary (unsigned, unsigned );

	// Test for presence of a specified identification number in the Employee
	bool is_present( unsigned ) const;

	// Take department code and turn it into name of department
	string department_name( unsigned ) const;
	
	// Take salary and turn it into properly formatted salary
	string salary_change( unsigned ) const;
	
	// Remove a specified employee, if possible
	bool remove( unsigned );

	// Insert a specified employee, if possible
	bool insert( unsigned, unsigned, unsigned, string );

}
  ;


#endif

