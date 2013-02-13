/******************************************************************************
Tasneem Pierce
Section 8
Computer Project #1
******************************************************************************/

using namespace std;


#include <iostream>
#include <iomanip>
#include <math.h>

/*-----------------------------------------------------------------------------
  Name:  main

  Purpose:  Take length of triangle sides and output information about triangle
  Input:    Lengths of sides of the triangle
  Output:   Length of sides, angles, perimeter, and area of triangle 
-----------------------------------------------------------------------------*/

int main()
{
  double sideA, sideB, sideC; //lengths of the sides of the triangle
  double angleABdeg, angleACdeg, angleBCdeg; //angles between sides in degrees
  double angleABradians,angleACradians, angleBCradians; //anges in radians
  double perimeter; //perimeter of triangle
  double area; //area of triangle

 
  //Sets the precision such that there are only two decimal places
  cout << setiosflags( ios::fixed ) << setprecision(2);

  //take in input for triangle side lengths
  cout << endl << "Please enter the length of side A of the triangle (cm): ";
  cin >> sideA;
  cout << endl;
  cout << "The value entered for side A: " << sideA << endl;

  cout << endl << "Please enter the length of side B of the triangle (cm): ";
  cin >> sideB;
  cout << endl;
  cout << "The value entered for side B: " << sideB << endl;

  cout << endl << "Please enter the length of side C of the triangle (cm): ";
  cin >> sideC;  
  cout << endl;
  cout << "The value entered for side C: " << sideC << endl;
  cout << endl;

  //using the side lengths, calculate the angles between sides in radians
  //formula: angle12 = acos((side1^2 + side2^2 -side3^2)/(2*side1*side2)
  angleABradians = acos((pow(sideA, 2) + pow(sideB, 2) - pow(sideC, 2))/(2 * sideA * sideB));
  angleACradians = acos((pow(sideA, 2) + pow(sideC, 2) - pow(sideB, 2))/(2 * sideA * sideC));
  angleBCradians = acos((pow(sideB, 2) + pow(sideC, 2) - pow(sideA, 2))/(2 * sideB * sideC));
  
  //Converts angles in degrees to radians by multiplying by Pi and dividing 180
  angleABdeg = angleABradians / M_PI * 180;
  angleACdeg = angleACradians / M_PI * 180;
  angleBCdeg = angleBCradians / M_PI * 180;

  //Calculate the perimeter of the triangle
  perimeter = sideA + sideB + sideC;

  //Calculate area of the triangle
  //Formula: 0.5* length of sideA * length of side B * sin(angleAB in radians)
  area = 0.5* sideA * sideB * sin(angleABradians);

  //Output all the information about the triangle
  cout << "Length of side A (cm): " << sideA << endl;
  cout << "Length of side B (cm): " << sideB << endl;
  cout << "Length of side C (cm): " << sideC << endl;
  cout << "Measure of the angle between sides A and B (degrees): " << angleABdeg << endl;
  cout << "Measure of the angle between sides A and C (degrees): " << angleACdeg << endl;
  cout << "Measure of the angle between sides B and C (degrees): " << angleBCdeg << endl;
  cout << "Measure of the angle between sides A and B (radians): " << angleABradians << endl;
  cout << "Measure of the angle between sides A and C (radians): " << angleACradians << endl;
  cout << "Measure of the angle between sides B and C (radians): " << angleBCradians << endl;
  cout << "Perimeter of the triangle (cm): " << perimeter << endl;
  cout << "Area of the triangle (cm^2): " << area << endl<< endl;
}
