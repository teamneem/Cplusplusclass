/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #3

****************************************************************************/

using namespace std;
#include "/user/cse232/Projects/project03.library.h"
#include <iomanip>
#include <cmath>
#include <iostream>

/*-----------------------------------------------------------------------------
   Name:  main

   Purpose:  Driver to test the functions.
   Output:   The value of functions created versus the values from cmath
-----------------------------------------------------------------------------*/

int main()
{
	double m = 2, n = -2, zero = 0, one = 1, o = 4, p = -5, a = M_PI, q = 6.75, j = 2.3;
	cout << endl << setiosflags( ios::fixed ) << setprecision(8);
	

	//test cases for absolute value
	
	//case 1: positive number
    cout << endl << "Argument: " << m << " absolute: " << absolute( m ) << " fabs: "
    << fabs( m ) << endl;
    
    //case 2: negative number
    cout << endl << "Argument: " << n << " absolute: " << absolute( n ) << " fabs: "
    << fabs( n ) << endl;
    
    //case 3: error checking to catch infinity
    cout << endl << "Argument: " << INFINITY << " absolute: " << absolute( INFINITY ) 
    << " fabs: " << fabs( INFINITY) << endl;
    
    //case 4: error checking to catch not a number
    cout << endl << "Argument: " << NAN << " absolute: " << absolute( NAN ) << " fabs: "
    << fabs( NAN ) << endl;

	//test cases to test modulo
	//case 1: two positive numbers
    cout << endl << "Argument: " << q << " Divisor: " << j  << " modulo: " << 
    modulo( q, j ) << " fmod: " << fmod( q, j ) << endl;
    
    //case 2: two negative numbers
    cout << endl << "Argument: " << p << " Divisor: " << n << " modulo: " << 
    modulo( p, n ) << " fmod: " << fmod( p, n ) << endl;
    
    //case 3: positive number divided by negative number
    cout << endl << "Argument: " << q << " Divisor: " << n << " modulo: " << 
    modulo( q, n ) << " fmod: " << fmod( q, n ) << endl;
    
    //case 4: negative number divided by a positive number
    cout << endl << "Argument: " << p << " Divisor: " << m << " modulo: " << 
    modulo( p, m ) << " fmod: " << fmod( p, m ) << endl;
    
    //case 5: divide by 0
    cout << endl << "Argument: " << q << " Divisor: " << zero << " modulo: " << 
    modulo( q, zero ) << " fmod: " << fmod( q, zero ) << endl;
    
    //case 6: divide by infinity
    cout << endl << "Argument: " << q << " Divisor: " << INFINITY << " modulo: " << 
    modulo( q, +INFINITY ) << " fmod: " << fmod( q, +INFINITY )<< endl;
    
    //case 7: divide by not a number
    cout << endl << "Argument: " << q << " Divisor: " << NAN << " modulo: " << 
    modulo( q, +NAN ) << " fmod: " << fmod( q, +NAN ) << endl;
    
    //case 8: 0 divided by something
    cout << endl << "Argument: " << zero << " Divisor: " << q << " modulo: " << 
    modulo( zero, q ) << " fmod: " << fmod( zero, q ) << endl;
    
    //case 9: Infinity divided by something
    cout << endl << "Argument: " << INFINITY << " Divisor: " << q << " modulo: " << 
    modulo( +INFINITY, q ) << " fmod: " << fmod( +INFINITY, q ) << endl;
    
    //case 10: not a number divided by something
    cout << endl << "Argument: " << NAN << " Divisor: " << q << " modulo: " << 
    modulo( +NAN, q ) << " fmod: " << fmod( +NAN, q )<< endl;

	//test cases to test factorial
	//Test case 1: positive number
    cout << endl << "Argument: " << m << " factorial: " << factorial( m ) << endl;
    
    //Test case 2: negative number
    cout << endl << "Argument: " << n << " factorial: " << factorial( n ) << endl;
        	
	//Test case 3: 0
    cout << endl << "Argument: " << zero << " factorial: " << factorial( zero ) << endl;
    
    //Test case 4: 1
	cout << endl << "Argument: " << one << " factorial: " << factorial( one ) << endl;
	
	//Test cases for power function
	
	//Test case 1: Both positive numbers
    cout << endl << "Argument: " << m << " to the power of: " << o << " power: "
    << power( m, o ) << " pow: " << pow( m, o ) << endl;
        
    //Test case 2: Negative number to the power of a positive number
    cout << endl << "Argument: " << n << " to the power of: " << m << " power: "
    << power( n, m ) << " pow: " << pow( n, m ) << endl;

    //Test case 3: Positive number to the power of 0
    cout << endl << "Argument: " << m << " to the power of: " << zero << " power: "
    << power( m, zero ) << " pow: " << pow( m, zero ) << endl;
    
    //Test case 4: To the power of Infinity
    cout << endl << "Argument: " << m << " to the power of: " << INFINITY << " power: "
    << power( m, INFINITY ) << " pow: " << pow( m, INFINITY ) << endl;
    
    //Test case 5: To the power of NaN
    cout << endl << "Argument: " << m << " to the power of: " << NAN << " power: "
    << power( m, NAN ) << " pow: " << pow( m, NAN ) << endl;    
    
    //Test case 6: Infinity to the power of number
    cout << endl << "Argument: " << INFINITY << " to the power of: " << m << " power: "
    << power( INFINITY, m ) << " pow: " << pow( INFINITY, m )  << endl;
    
    //Test case 7: NaN to the power of number
    cout << endl << "Argument: " << NAN << " to the power of: " << m << " power: "
    << power( NAN, m ) << " pow: " << pow( NAN, m ) << endl;    
    
    //Test cases for sine
    
    //case 1: positive number
    cout << endl << "Argument: " << o << " sine: " << sine( o ) << " sin: "
    << sin( o ) << endl;    
    
    //case 2: negative number
    cout << endl << "Argument: " << n << " sine: " << sine( n ) << " sin: "
    << sin( n ) << endl;    
    
    //case 3: infinity
     cout << endl << "Argument: " << INFINITY << " sine: " << sine( INFINITY ) << " sin: "
    << sin( INFINITY ) << endl;   
        
    //case 4: not a number
     cout << endl << "Argument: " << NAN << " sine: " << sine( NAN ) << " sin: "
    << sin( NAN ) << endl;    
    
	//case 5: positive number
    cout << endl << "Argument: " << a << " sine: " << sine( a ) << " sin: "
    << sin( a ) << endl;  
       
    //Test cases for cosine
    
    //case 1: positive number
    cout << endl << "Argument: " << o << " cosine: " << cosine( o ) << " cos: "
    << cos( o ) << endl;  
    
    //case 2: negative number
    cout << endl << "Argument: " << n << " cosine: " << cosine( n ) << " cos: "
    << cos( n ) << endl;  
        
    //case 3: infinity
    cout << endl << "Argument: " << INFINITY << " cosine: " << cosine( INFINITY ) << " cos: "
    << cos( INFINITY ) << endl;  
        
    //case 4: not a number
    cout << endl << "Argument: " << NAN << " cosine: " << cosine( NAN ) << " cos: "
    << cos( NAN ) << endl;  

    //case 5: positive number
    cout << endl << "Argument: " << a << " cosine: " << cosine( a ) << " cos: "
    << cos( a ) << endl;  
    
  	cout << endl;
}  

