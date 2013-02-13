/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #5

****************************************************************************/

using namespace std;


#ifndef FRACTION_
#define FRACTION_

using namespace std;

#include <iostream>

class Fraction
{
  private:
	int Numerator_;
	int Denominator_;
	int GCD( int a, int b );
    // Insert your declarations here

  public:

    // Construct fraction from numerator and denominator
    //
    Fraction( int = 0, int = 1 );

    // Construct fraction by copying existing fraction
    //
    Fraction( const Fraction& );

    // Assign into fraction by copying existing fraction
    //
    Fraction& operator=( const Fraction& );

    // Return true if fraction is valid (non-zero denominator)
    //
    bool IsValid() const;

    // Return value of numerator
    //
    int Numerator() const;

    // Return value of denominator
    //
    int Denominator() const;

    // Input/Output operations
    //
    friend istream& operator>>( istream&, Fraction& );
    friend ostream& operator<<( ostream&, const Fraction& );
};

// Comparative operations
//
bool operator==( const Fraction&, const Fraction& );
bool operator!=( const Fraction&, const Fraction& );
bool operator< ( const Fraction&, const Fraction& );
bool operator<=( const Fraction&, const Fraction& );
bool operator> ( const Fraction&, const Fraction& );
bool operator>=( const Fraction&, const Fraction& );

// Arithmetic operations
//
Fraction operator+( const Fraction&, const Fraction& );
Fraction operator-( const Fraction&, const Fraction& );
Fraction operator*( const Fraction&, const Fraction& );
Fraction operator/( const Fraction&, const Fraction& );

#endif

