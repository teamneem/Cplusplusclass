/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #3

****************************************************************************/

using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <float.h>
#include "/user/cse232/Projects/project03.library.h"

/*-----------------------------------------------------------------------------
   Name:  absolute

   Purpose:  Compute the absolute value of an integer.
   Receive:  The value of X
   Return:   The absolute value of X
-----------------------------------------------------------------------------*/

double absolute( double X )
{
	double absoluteResult;
	
	//if the number is below zero, then take the absolute value
	if (X<0)
	{
    	absoluteResult = X * -1;
    }
    
    else
    {
    	absoluteResult = X;
    }
	
	return absoluteResult;
}

/*-----------------------------------------------------------------------------
   Name:  modulo

   Purpose:  Compute the remainder of the division of X by Y.
   Receive:  The value of X and Y
   Return:   The remainder value of X/Y
-----------------------------------------------------------------------------*/

double modulo( double X, double Y )
{
	double moduloResult;

	//error checking
	if (Y==0)
	{
		moduloResult = NAN;
	}
	//error checking cause you can't divide by zero
	
	//if the numbers are valid, find the modulo
	else if ((finite(X)) && finite(Y))
	{
		int divisionResult;
		divisionResult = X/Y;
		moduloResult = X - (Y * divisionResult);
	}
	
	else
	{
		moduloResult = NAN;
	}
	//error checking
	
	return moduloResult;
}


/*-----------------------------------------------------------------------------
   Name:  factorial

   Purpose:  Compute the factorial of a non-negative integer.
   Receive:  The value of N
   Return:   The value of N!
-----------------------------------------------------------------------------*/

double factorial( unsigned N )
{
	double factorialResult = 1.0;
	
	if (finite(N))
	{
		double M = (double)N;
		for (double count = 2; count <= M; count++)
		{
	    factorialResult = factorialResult * count;
	    }
    }
    
    else
	{
		factorialResult = INFINITY;
	}
	//error checking 
	
	return factorialResult;
}


/*-----------------------------------------------------------------------------
   Name:  power

   Purpose:  Compute X to the power of N.
   Receive:  The value of X and N
   Return:   The value of X^N
-----------------------------------------------------------------------------*/

double power( double X, unsigned N )
{
	double powerResult = 1.0;
	int count;
	
	if ((finite(X)) && (finite(N)))
    {
        for (double count = 1; count <= N; count++)
        {
        powerResult *= X;
        }
	}
	
	else
	{
		powerResult = INFINITY;
	}
    	//return the "double" value Infinity for error checking  
	return powerResult;
}

/*-----------------------------------------------------------------------------
   Name:  sine

   Purpose:  Compute the sine of X, where X is measured in radians.
   Receive:  The value of X
   Return:   The value of sin(X)
-----------------------------------------------------------------------------*/

double sine( double X )
{

	double sineValue;
	
	if (finite(X))
	{
		double period = 2*M_PI;
		double wrap = modulo(X, period);
		//calculates the smallest number that can be used for calculations based on 
		//how the period is 2*pi
			
		
		double epsilon = 0.00000001;
		//epsilon is the given value that we are to stop computing
		double count = 0;
		
		//power series to compute sine
		for (double term = wrap; absolute(term) > epsilon; count += 1)
		{	
			term = (power(-1, count) * (power(wrap, count*2 + 1))) / (factorial(count*2 + 1));
			sineValue += term;
		}
	}
	
		else
	{
		sineValue = NAN;
	}

	return sineValue;
	
}
	

	  
/*-----------------------------------------------------------------------------
   Name:  cosine

   Purpose:  Compute the cosine of X, where X is measured in radians.
   Receive:  The value of X
   Return:   The value of cos(X)
-----------------------------------------------------------------------------*/

double cosine( double X )
{
	double cosineValue;
	
	if (finite(X))
	{
		double period = 2*M_PI;
		double wrap = modulo(X, period);
		//calculates the smallest number that can be used for calculations based on 
		//how the period is 2*pi
		
		double epsilon = 0.00000001;
		//epsilon is the given value that we are to stop computing
		double count = 0;
		
		//power series to compute cosine
		for (double term = wrap; absolute(term) > epsilon; count += 1)
		{	
			term = (power(-1, count) * (power(wrap, count*2))) / (factorial(count*2));
			cosineValue += term;
		}
	}
	
		else
	{
		cosineValue = NAN;
	}
	//return the "double" value Not-A-Number
	return cosineValue;
}
