/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #5

****************************************************************************/

using namespace std;
#include <iostream>
#include "proj05.fraction.h"

/*-----------------------------------------------------------------------------
   Name:  GCD

   Purpose:  greatest common denominator
-----------------------------------------------------------------------------*/
int Fraction::GCD( int a, int b )
    {
    	while (true)
    	{
    		a = a % b;
    		if (a == 0) 
    		{
    			return b;
    		}
    		b = b % a;
    		if (b == 0) 
    		{
    			return a;
    		}
    	}
    }
    
/*-----------------------------------------------------------------------------
   Name:  default constructor for class "Fraction"

   Purpose:  null routine.
-----------------------------------------------------------------------------*/

Fraction::Fraction(int newNumerator_, int newDenominator_)
{
  	//simplifying
  	int gcd = 1; //greatest common denominator 
    
    gcd = GCD(newNumerator_, newDenominator_); 	
 	Numerator_ = newNumerator_ / gcd;
  	Denominator_ = newDenominator_ /gcd;
  	if (newDenominator_ == 0)
  	{
  	cerr << "INV" << endl;
  	}
}

/*-----------------------------------------------------------------------------
   Name:  copy constructor for class "Fraction"

   Purpose:  Initialize the value and scale inside a Fraction object.
   Receive:  The fraction which is to be copied
-----------------------------------------------------------------------------*/

Fraction::Fraction( const Fraction& newFrac)
{
	Numerator_ = newFrac.Numerator_;
	Denominator_ = newFrac.Denominator_;
}

/*-----------------------------------------------------------------------------
   Name:  assignment operator for class "Fraction" 

   Purpose:  Copy the contents of one fraction into another.
   Receive:  The fraction which is to be copied
   Return:   The fraction on the righthand side (for chaining)
-----------------------------------------------------------------------------*/

Fraction& Fraction::operator=( const Fraction& newFrac )
{
	Numerator_ = newFrac.Numerator_;
	Denominator_ = newFrac.Denominator_;
	return *this;
}

/*-----------------------------------------------------------------------------
   Name:  IsValid
 
   Purpose:  Test a Fraction object to see if it is valid.
   Return:   The Boolean value "true" if the fraction is valid
-----------------------------------------------------------------------------*/
 
bool Fraction::IsValid() const
{
	if (Denominator_==0)
	{
		cout << "INV" << endl;
		return (Denominator_!=0);
	}

	else
	{
		return (Denominator_!=0);
	}
}
  
  /*-----------------------------------------------------------------------------
   Name:  Numerator

   Purpose:  Return the value of a Numerator.
   Return:   The Numerator value
-----------------------------------------------------------------------------*/

int Fraction::Numerator() const
{
	return Numerator_;
}


/*-----------------------------------------------------------------------------
   Name:  denominator

   Purpose:  Return the scale of a denominator object.
   Return:   The denominator scale 
-----------------------------------------------------------------------------*/

int Fraction::Denominator() const
{
	return Denominator_;
}

 
 /*-----------------------------------------------------------------------------
   Name:  operator<<

   Purpose:  Put a Fraction object into an output stream.
   Receive:  A reference to an output stream
             A constant reference to a Fraction
   Return:   The output stream
   Output:   A fraction 
-----------------------------------------------------------------------------*/

ostream& operator<<( ostream& Out, const Fraction& Item )
{
	if (Item.Denominator_ == 1)
	{
		Out << Item.Numerator_;
	}
	else if (Item.Denominator_ == 0)
	{
		Out << "INV";
	}
	else
	{
		Out << Item.Numerator_ << "/" << Item.Denominator_;
	}
	return Out;
}


/*-----------------------------------------------------------------------------
   Name:  operator>>

   Purpose:  Extract a Fraction object from an input stream.
   Receive:  A reference to an input stream
             A reference to a Fraction
   Return:   The input stream
   Input:    A fraction
-----------------------------------------------------------------------------*/


istream& operator>>( istream& In, Fraction&  Item)
{
	int Numerator;
	int Denominator;
	char c;
	In >> Numerator >> c >> Denominator;
    	
	if (In.good())
	{
		Item.Numerator_ = Numerator;
		Item.Denominator_ = Denominator;
	}
    		
	return In;
}




/*-----------------------------------------------------------------------------
   Name:  operator==

   Purpose:  Compare two fractions for equality.
   Receive:  The two fractions to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator==( const Fraction& One, const Fraction& Two )
{
	return (One.Numerator() * Two.Denominator() == Two.Numerator() * One.Denominator());
}


/*-----------------------------------------------------------------------------
   Name:  operator!=

   Purpose:  Compare two fractions for inequality.
   Receive:  The two fractions to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator!=( const Fraction& One, const Fraction& Two )
{
	return (One.Numerator() * Two.Denominator() != Two.Numerator() * One.Denominator());
}

/*-----------------------------------------------------------------------------
   Name:  operator<

   Purpose:  Compare two fractions to see if the second is bigger
   Receive:  The two fractions to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator<( const Fraction& One, const Fraction& Two )
{
	return (One.Numerator() * Two.Denominator() < Two.Numerator() * One.Denominator());
}


/*-----------------------------------------------------------------------------
   Name:  operator<=

   Purpose:  Compare two fractions to see if the second is bigger or equal
   			 to the first fraction
   Receive:  The two fractions to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/
bool operator<=( const Fraction& One, const Fraction& Two )
{
	return (One.Numerator() * Two.Denominator() <= Two.Numerator() * One.Denominator());
}

/*-----------------------------------------------------------------------------
   Name:  operator>

   Purpose:  Compare two fractions to see if the first fraction is bigger
   Receive:  The two fractions to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/

bool operator>( const Fraction& One, const Fraction& Two )
{
	return (One.Numerator() * Two.Denominator() > Two.Numerator() * One.Denominator());
}

/*-----------------------------------------------------------------------------
   Name:  operator>=

   Purpose:  Compare two fractions to see if the first is bigger or equal
   			 to the second fraction
   Receive:  The two fractions to be compared
   Return:   The Boolean result for the comparison
-----------------------------------------------------------------------------*/
bool operator>=( const Fraction& One, const Fraction& Two )
{
	return (One.Numerator() * Two.Denominator() >= Two.Numerator() * One.Denominator());
}

/*-----------------------------------------------------------------------------
   Name:  operator+

   Purpose:  Add a fraction and another fraction.
   Receive:  The fraction and fraction to be added
   Return:   The fraction which is the sum of the parameters
-----------------------------------------------------------------------------*/

Fraction operator+( const Fraction& One, const Fraction& Two )
{
	Fraction newFrac;
	newFrac = Fraction((One.Numerator() * Two.Denominator()) + 
		(Two.Numerator() * One.Denominator()), One.Denominator() * Two.Denominator());
	return newFrac;

}


/*-----------------------------------------------------------------------------
   Name:  operator-

   Purpose:  Subtract a fraction from another fraction.
   Receive:  The fraction and fraction to be subtracted
   Return:   The fraction from the difference
-----------------------------------------------------------------------------*/

Fraction operator-( const Fraction& One, const Fraction& Two )
{
	Fraction newFrac;
	newFrac = Fraction((One.Numerator() * Two.Denominator()) - 
		(Two.Numerator() * One.Denominator()), One.Denominator() * Two.Denominator());
	return newFrac;
}

/*-----------------------------------------------------------------------------
   Name:  operator*

   Purpose:  Multiply a fraction with another fraction.
   Receive:  The fraction and fraction to be multiplied
   Return:   The fraction from product of the multiplication
-----------------------------------------------------------------------------*/

Fraction operator*( const Fraction& One, const Fraction& Two )
{
	Fraction newFrac;
	newFrac = Fraction(One.Numerator() * Two.Numerator(), 
		One.Denominator() * Two.Denominator());
	return newFrac;
}


/*-----------------------------------------------------------------------------
   Name:  operator/

   Purpose:  Divide a fraction by another fraction.
   Receive:  The fraction to be divided and fraction to divide with
   Return:   The fraction that is the quotient of the division
-----------------------------------------------------------------------------*/

Fraction operator/( const Fraction& One, const Fraction& Two )
{
	Fraction newFrac(0,1);
	if (Two.Numerator() == 0)
	{
		cout << "Can't divide by zero" << endl;
	}
	
	else
	{
		newFrac = Fraction(One.Numerator() * Two.Denominator(), 
		One.Denominator() * Two.Numerator());
	}
	return newFrac;
}

