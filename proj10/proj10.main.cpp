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
#include <sstream> 
#include <fstream>


/*-----------------------------------------------------------------------------
   Demonstrate selected operations from the Employee class template
-----------------------------------------------------------------------------*/

int main()
{
	Employee Old;
	string InName;         // The name of the input file
	string OutName;        // The name of the output file
	string Prefix;

	ifstream InStream;     // Data object representing the input file
	ifstream TransStream;
	ofstream OutStream;    // Data object representing the output file
	ofstream Reports;

	cout << "\nPlease enter the name of the input file: ";
	cin >>  Prefix;
	InName = Prefix;
	InName.append(".employees.old");

	InStream.open( InName.c_str(), ios::in );

	if (InStream.fail())
	{
		cerr << "\n*** Unable to read from '" << InName << "' ***\n\n";
	}
  
	else
	{
		//Open the new employee file
		OutName = Prefix;
		OutName.append(".employees.new");
    	OutStream.open( OutName.c_str(), ios::out );

		if (OutStream.fail())
		{
			cerr << "\n*** Unable to write into '" << OutName << "' ***\n\n";
		}
    
		else
		{
			unsigned iden, dept, salary;  
			string Name;
			
			//Make the employee array
			while (!InStream.eof())
			{
				InStream >>  iden;
				InStream >> dept;
				InStream >> salary;
				//InStream >> Name;
				//istream& getline( istream& is, string& str, char delim = '\n' );
				std::getline( InStream, Name);
				string name = Name.erase(0, 2);
				Old.insert( iden, dept, salary, name);
      		}
      		
      	InStream.close();
		}
 	

	//Open up transaction file
	string TransName = Prefix;
	TransName.append(".transactions");
	TransStream.open( TransName.c_str(), ios::in );

  	if (TransStream.fail())
	{
		cerr << "\n*** Unable to read from '" << TransName << "' ***\n\n";
	}
	
	else
	{
		string ReportsName = Prefix;
		ReportsName.append(".reports");
		Reports.open( ReportsName.c_str(), ios::out );

		if (Reports.fail())
		{
			cerr << "\n*** Unable to write into '" << Reports << "' ***\n\n";
		}
		while (!TransStream.eof())
		{
			string function;
			TransStream >> function;
			if (function == "report")
			{
				//Prints reports to report file
				string what;
				unsigned identity;
				TransStream >> what;
				if (what == "by_name")
				{
					Old.by_name( Reports );
				}
				if (what == "by_number")
				{
					Old.by_iden( Reports );
				}		
				if (!(what == "by_number" || what == "by_name"))
				{
					string line;
					getline(TransStream, line);
					cout << "Error in transaction type3" << endl;
				}
			}

		
			if (function == "update")
			{
				string what;
				unsigned identity, department, salary;
				TransStream >> what;
				TransStream >> identity;
			
				//update an employees department			
				if (what == "department")
				{
					TransStream >> department;
					Old.update_department( identity, department );
				}
				
				//update an employees salary
				if (what == "salary")
				{
					TransStream >> salary;
					Old.update_salary( identity, salary );
				}
				
				if (!(what == "salary" || what == "department"))
				{
					string line;
					getline(TransStream, line);
					//TransStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Error in transaction type2" << endl;
				}
			}
			
			//remove an employee
			if (function == "remove")
			{
				string emp;
				unsigned identity;
				TransStream >> emp >> identity;
				Old.remove( identity );
			}
			
			//insert a new employee
			if (function == "insert")
			{
				string Name, emp;
				unsigned identity, department, salary;			
				TransStream >> emp;
				TransStream >> identity;
				TransStream >> department;
				TransStream >> salary;
				std::getline( TransStream, Name);
				string name = Name.erase(0, 2);
				Old.insert( identity, department, salary, name);
			}
			
			if (!(function =="remove" || function == "insert" ||
				function == "update" || function == "report" ||
				function == ""))
			{
				string line;
				getline(TransStream, line);
				cout << "Error in transaction type4" << endl;
			}
		}
	}
	
	//Print new employee list
	Old.by_iden_new(OutStream);
	OutStream.close();  
}
}