/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #2

****************************************************************************/

using namespace std;

#include <iostream>
#include "proj02.support.h"

/*-----------------------------------------------------------------------------
   Name:  usage

   Purpose:  Calculate energy usage
   Input:    Beginning and end meter reading
   Output:   Amount of energy used 
-----------------------------------------------------------------------------*/

double usage(int beginning, int end)
	{
	int total;
	//finds out how much energy used from meter reading
  	if (beginning < end)
	{
		total = end - beginning;
	}
		
	//if the end reading is lower than the beginning reading, this triggers
	//this occurs when the meter goes over 999999
	else
	{
		int converted;
		converted = 1000000 + end;
		total = converted - beginning;
	}

	//takes total from meter reading and converts to kilowatt-hours
	double kilowatts;
	kilowatts = total;
	kilowatts = kilowatts/10;
    return kilowatts;
	}

/*-----------------------------------------------------------------------------
   Name:  bill

   Purpose:  Calculate customer's bill
   Input:    Customer classification and energy usage
   Output:   Total bill for customer
-----------------------------------------------------------------------------*/

double bill(char custCode, double energy)
	{
	double billTotal;
	if (custCode == 'P')
	//$0.07 per KWH for the first 300 KiloWatt-Hours, $0.08 per KWH for the next 300 KiloWatt-Hours, and $0.09 per KWH after that.//
	
	{
		if (energy <= 300)
		{
			billTotal = energy * 0.07;
		}
		
		else if (energy <= 600)
		{
			billTotal = 300*0.07;
			billTotal += (energy - 300) * 0.08;
		}
		
		else if (energy > 600)
		{
			energy = energy - 600;
			billTotal = 300*0.07 + 300*0.08;
			billTotal += energy * 0.09;
		}
		
	}
	else if (custCode == 'A')
	// $0.07 per KWH for the first 200 KiloWatt-Hours, $0.08 per KWH for the next 200 KiloWatt-Hours, and $0.09 per KWH after that.

	{
		if (energy <= 200)
		{
			billTotal = energy * 0.07;
		}
		
		else if (energy <= 400)
		{
			billTotal = 200*0.07;
			billTotal += (energy - 200) * 0.08;
		}
		
		else if (energy > 400)
		{
			energy = energy - 400;
			billTotal = 200*0.07 + 200*0.08;
			billTotal += energy * 0.09;
		}
	}
	
	else if (custCode == 'F')
	// $10.00 plus $0.07 per KWH.
	{
		billTotal = energy * 0.07;
		billTotal += 10.00;
	}
	
	else if (custCode == 'C')
	// $700.00 for 10000 KiloWatt-Hours or less, and $0.09 for each additional KiloWatt-Hour used.
	{
		if (energy <= 10000)
		{
			billTotal = 700.00;
		}
		
		else if (energy > 10000)
		{
			billTotal += 700.00;
			billTotal += (energy - 10000) * 0.09;
		}
	}
	
	else
	{
	// Function "bill" will return a value of zero for an unrecognized customer code.
		billTotal = 0.0;
	}
	
	return billTotal;
	}