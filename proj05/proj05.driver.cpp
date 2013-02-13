/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #5

****************************************************************************/

using namespace std;
#include <iostream>
#include "proj05.fraction.h"



int main()
{
	Fraction A;
	Fraction B;
	Fraction C;
	Fraction D;
	Fraction E;
	Fraction F;
	Fraction G;
	Fraction H;
	Fraction I;
	
	cin >> A >> B >> C >> D >> E >> F >> G >> H;	

	std::cout.setf(std::ios::boolalpha);

	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	cout << "A Numerator: " << A.Numerator() << endl;
	cout << "A Denominator: " << A.Denominator() << endl;
	cout << "B Numerator: " << B.Numerator() << endl;
	cout << "B Denominator: " << B.Denominator() << endl;
	cout << "A equal to B: " << (A==B) << endl;
	cout << "A is not equal to B: " << (A!=B) << endl;
	cout << "A is less than B: " << (A<B) << endl;
	cout << "A is less than or equal to B: " << (A<=B) << endl;
	cout << "A is more than B: " << (A>B) << endl;
	cout << "A is more than or equal to B: " << (A>=B) << endl;
	cout << "A+B: " << A+B << endl;
	cout << "A-B: " << A-B << endl;
	cout << "A*B: " << A*B << endl;
	cout << "A/B: " << A/B << endl << endl;
	
	I = A;
	cout << "A: " << A << endl;
	cout << "I: " << I << endl;
	cout << "A Numerator: " << A.Numerator() << endl;
	cout << "A Denominator: " << A.Denominator() << endl;
	cout << "I Numerator: " << I.Numerator() << endl;
	cout << "I Denominator: " << I.Denominator() << endl;
	cout << "A equal to I: " << (A==I) << endl;
	cout << "A is not equal to I: " << (A!=I) << endl;
	cout << "A is less than I: " << (A<I) << endl;
	cout << "A is less than or equal to I: " << (A<=I) << endl;
	cout << "A is more than I: " << (A>I) << endl;
	cout << "A is more than or equal to I: " << (A>=I) << endl;
	cout << "A+I: " << A+I << endl;
	cout << "A-I: " << A-I << endl;
	cout << "A*I: " << A*I << endl;
	cout << "A/I: " << A/I << endl << endl;
	
	cout << "C: " << C << endl;
	cout << "D: " << D << endl;
	cout << "C Numerator: " << C.Numerator() << endl;
	cout << "C Denominator: " << C.Denominator() << endl;
	cout << "D Numerator: " << D.Numerator() << endl;
	cout << "D Denominator: " << D.Denominator() << endl;
	cout << "C equal to D: " << (C==D) << endl;
	cout << "C is not equal to D: " << (C!=D) << endl;
	cout << "C is less than D: " << (C<D) << endl;
	cout << "C is less than or equal to D: " << (C<=D) << endl;
	cout << "C is more than D: " << (C>D) << endl;
	cout << "C is more than or equal to D: " << (C>=D) << endl;
	cout << "C+D: " << C+D << endl;
	cout << "C-D: " << C-D << endl;
	cout << "C*D: " << C*D << endl;
	cout << "C/D: " << C/D << endl << endl;
	
	cout << "D: " << D << endl;
	cout << "E: " << E << endl;
	cout << "D Numerator: " << D.Numerator() << endl;
	cout << "D Denominator: " << D.Denominator() << endl;
	cout << "E Numerator: " << E.Numerator() << endl;
	cout << "E Denominator: " << E.Denominator() << endl;
	cout << "D equal to E: " << (D==E) << endl;
	cout << "D is not equal to E: " << (D!=E) << endl;
	cout << "D is less than E: " << (D<E) << endl;
	cout << "D is less than or equal to E: " << (D<=E) << endl;
	cout << "D is more than E: " << (D>E) << endl;
	cout << "D is more than or equal to E: " << (D>=E) << endl;
	cout << "D+E: " << D+E << endl;
	cout << "D-E: " << D-E << endl;
	cout << "D*E: " << D*E << endl;
	cout << "D/E: " << D/E << endl << endl;
	
	cout << "E: " << E << endl;
	cout << "F: " << F << endl;
	cout << "E Numerator: " << E.Numerator() << endl;
	cout << "E Denominator: " << E.Denominator() << endl;
	cout << "F Numerator: " << F.Numerator() << endl;
	cout << "F Denominator: " << F.Denominator() << endl;
	cout << "E equal to F: " << (E==F) << endl;
	cout << "E is not equal to F: " << (E!=F) << endl;
	cout << "E is less than F: " << (E<F) << endl;
	cout << "E is less than or equal to F: " << (E<=F) << endl;
	cout << "E is more than F: " << (E>F) << endl;
	cout << "E is more than or equal to F: " << (E>=F) << endl;
	cout << "E+F: " << E+F << endl;
	cout << "E-F: " << E-F << endl;
	cout << "E*F: " << E*F << endl;
	cout << "E/F: " << E/F << endl << endl;
	
	cout << "F: " << F << endl;
	cout << "G: " << G << endl;
	cout << "F Numerator: " << F.Numerator() << endl;
	cout << "F Denominator: " << F.Denominator() << endl;
	cout << "G Numerator: " << G.Numerator() << endl;
	cout << "G Denominator: " << G.Denominator() << endl;
	cout << "F equal to G: " << (F==G) << endl;
	cout << "F is not equal to G: " << (F!=G) << endl;
	cout << "F is less than G: " << (F<G) << endl;
	cout << "F is less than or equal to G: " << (F<=G) << endl;
	cout << "F is more than G: " << (F>G) << endl;
	cout << "F is more than or equal to G: " << (F>=G) << endl;
	cout << "F+G: " << F+G << endl;
	cout << "F-G: " << F-G << endl;
	cout << "F*G: " << F*G << endl;
	cout << "F/G: " << F/G << endl << endl;
	
	cout << "H: " << H << endl;
	cout << "G: " << G << endl;
	cout << "H Numerator: " << H.Numerator() << endl;
	cout << "H Denominator: " << H.Denominator() << endl;
	cout << "G Numerator: " << G.Numerator() << endl;
	cout << "G Denominator: " << G.Denominator() << endl;
	cout << "H equal to G: " << (H==G) << endl;
	cout << "H is not equal to G: " << (H!=G) << endl;
	cout << "H is less than G: " << (H<G) << endl;
	cout << "H is less than or equal to G: " << (H<=G) << endl;
	cout << "H is more than G: " << (H>G) << endl;
	cout << "H is more than or equal to G: " << (H>=G) << endl;
	cout << "H+G: " << H+G << endl;
	cout << "H-G: " << H-G << endl;
	cout << "H*G: " << H*G << endl;
	cout << "H/G: " << H/G << endl << endl;
}
