/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #4

****************************************************************************/

using namespace std;

#include "proj04.support.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

//record for a day with temperatures, precipitation, range of temperatures, and
//a flag for if the day is special (largest or smallest range) or not
struct Day
{
	int Max;
	int Min;
	float Precipitation;
	int Range;
};

//declaring all functions
void print( const Day[], int, int, int );
void MaxTemp(const Day[], int );
void MinTemp(const Day[], int );
void Precip(const Day[], int );
int largestRange(const Day[], int );
int smallestRange(const Day[], int );

/*-----------------------------------------------------------------------------
   Name:  main

   Purpose:  Take in values from a file, output weather information for days
-----------------------------------------------------------------------------*/

int main()
{
	const int MAX = 31;
	const int MIN = 28;
	Day Temp, List[MAX];
	int Num = 0;

	for (;;)
	{
		cin >> Temp.Max >> Temp.Min >> Temp.Precipitation;

		if (Temp.Precipitation < 0)
		{
		cout << "Invalid input, stopping program now" << endl;
		exit(1);
		}

		
		else if (!cin.good())
		{
		break;
		}
		
		
		Temp.Range = Temp.Max - Temp.Min;
		List[Num] = Temp;
    	Num++;
	}

	if (Num < MIN || Num > MAX)
  		{
  		cout << "Wrong number of days, invalid input, stopping program" << endl;
  		exit(1);
		}


	int largeFlag = largestRange( List, Num );
	int smallFlag = smallestRange( List, Num );
	print( List, Num, largeFlag, smallFlag );
	MaxTemp( List, Num );
	MinTemp( List, Num );
	Precip( List, Num );
}


    
/*-----------------------------------------------------------------------------
   Name:  print

   Purpose:  Takes in records, prints information
-----------------------------------------------------------------------------*/

void print( const Day List[], int Count, int largeRange, int smallRange)
{
  cout << "Day     Maximum      Minimum    Precipitation  Temperature\n";
  cout << "      Temperature  Temperature                    Range   \n";
  cout << "          (F)          (F)           (in)          (F)    \n";
  cout << "----  -----------  -----------  -------------  -----------\n";

	for (int I=0; I<Count; I++)
	{
		cout << setiosflags( ios::fixed ) << setprecision(2);

			if (I+1 == largeRange)
			{
				cout << setw(4) << I+1 << "  "
				<< setw(11) << List[I].Max << "  "
				<< setw(11) << List[I].Min << "  "
				<< setw(13) << List[I].Precipitation
				<< setw(13) << List[I].Range   
				<< setw(20) << "Largest Temp Range" << endl;
			}
			
			else if (I+1 == smallRange)
			{		
				cout << setw(4) << I+1 << "  "
				<< setw(11) << List[I].Max << "  "
				<< setw(11) << List[I].Min << "  "
				<< setw(13) << List[I].Precipitation
				<< setw(13) << List[I].Range   
				<< setw(20) << "Smallest Temp Range" << endl;
			}
			
			else
			{		
				cout << setw(4) << I+1 << "  "
				<< setw(11) << List[I].Max << "  "
				<< setw(11) << List[I].Min << "  "
				<< setw(13) << List[I].Precipitation
				<< setw(13) << List[I].Range << endl;
			}
	}
}

/*-----------------------------------------------------------------------------
   Name:  MaxTemp

   Purpose:  Takes in maximum temperatures, outputs largest, smallest and 
   average temperature
-----------------------------------------------------------------------------*/

void MaxTemp(const Day List[], int Count)
{
	int averageTemp = 0;
	int tempTotal = 0;
	int smallestTemp = List[0].Max;
	int largestTemp = List[0].Max;
	for (int I=0; I<Count; I++)
	{

		tempTotal +=List[I].Max;

  		//calculates largest temperature  	
		if (List[I].Max > largestTemp)
  		{
  			largestTemp = List[I].Max;
  		}
  		
  		else
  		{}
  	
  		//calculates smallest temperature
		if (List[I].Max < smallestTemp)
			{
			smallestTemp = List[I].Max;
			} 	
		else
		{}
	}
	
	averageTemp = tempTotal/(Count + 1); //calculates average temperature
	cout << endl;
  	cout << "Average Maximum Temperature (F): " << averageTemp << endl;
  	cout << "Largest Maximum Temperature (F): " << largestTemp << endl;
  	cout << "Smallest Maximum Temperature (F): " << smallestTemp << endl << endl;
  	
}

/*-----------------------------------------------------------------------------
   Name:  MinTemp

   Purpose:  Takes in minimum temperatures, outputs largest, smallest and 
   average temperature
-----------------------------------------------------------------------------*/
void MinTemp(const Day List[], int Count)
{
	int averageTemp = 0;
	int tempTotal = 0;
	int smallestTemp = List[0].Min;
	int largestTemp = List[0].Min;
	for (int I=0; I<Count; I++)
	{

		tempTotal +=List[I].Min;
  	
  		//calculates largest temperature  	
		if (List[I].Min > largestTemp)
  		{
  			largestTemp = List[I].Min;
  		}
  		
  		else
  		{}
  
  		//calculates smallest temperature	
		if (List[I].Min < smallestTemp)
			{
			smallestTemp = List[I].Min;
			} 	
		else
		{}
	}
	
	averageTemp = tempTotal/(Count + 1); //calculates average temperature
  	cout << "Average Minimum Temperature (F): " << averageTemp << endl;
  	cout << "Largest Minimum Temperature (F): " << largestTemp << endl;
  	cout << "Smallest Minimum Temperature (F): " << smallestTemp << endl << endl;
  	
}


/*-----------------------------------------------------------------------------
   Name:  Precip

   Purpose:  Takes in precipitation, outputs largest, smallest and 
   average precipitation when there was precipitation
-----------------------------------------------------------------------------*/
void Precip(const Day List[], int Count)
{
	float averagePrecipitation = 0;
	float precipitationTotal = 0;
	int precipDays = 0;

	for (int I=0; I<Count; I++)
	{
		//adds precipitation to total if there was precipitation
		if (List[I].Precipitation > 0)
		{
			precipitationTotal +=List[I].Precipitation;
			precipDays +=1;
		}
	}
	
	averagePrecipitation = precipitationTotal/(precipDays); //calculates average temperature
	
	cout << endl << setiosflags( ios::fixed ) << setprecision(2);
  	cout << "Total Precipitation (in): " << precipitationTotal << endl;
  	cout << "Number of Days Precipitation Fell: " << precipDays << endl;
	cout << "Average Precipitation (in): " << averagePrecipitation << endl << endl;
  	
}

int largestRange(const Day List[], int Count)
{
	int tempRange = 0;
	int largeRange = 0;
	int largestIndex = 0;
	
	for (int I=0; I<Count; I++)
	{
		tempRange = List[I].Max - List[I].Min;
  	
  		//calculates largest range	
		if (tempRange > largeRange)
  		{
  			largeRange = tempRange;
  			largestIndex = I;
  		}
  		else
  		{}
  	}
  	largestIndex +=1;
  	return largestIndex;
}

int smallestRange(const Day List[], int Count)
{
	int tempRange = 0;
	int smallRange = List[0].Max - List[0].Min;
	int smallestIndex = 0;
	
	for (int I=0; I<Count; I++)
	{
		tempRange = List[I].Max - List[I].Min;
  		
  		//calculates smallest range 	
		if (tempRange < smallRange)
  		{
  			smallRange = tempRange;
  			smallestIndex = I;
  		}
  		else
  		{}
  	}
	smallestIndex +=1;
  	return smallestIndex;
}



/*

*still need to fix error checking for less than 28 days
You should not assume that the input file will contain a valid number of data
records (between 28 and 31),  */
