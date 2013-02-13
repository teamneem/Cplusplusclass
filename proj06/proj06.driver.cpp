/****************************************************************************
    Tasneem Pierce
    Section 8
    Computer Project #6

****************************************************************************/

using namespace std;
#include <iostream>
#include "/user/cse232/Projects/project06.word.h"



int main()
{
	Word A;
	Word B;
	Word C;
	Word D;
	Word E;
	Word F;
	Word G;
	Word H;
	Word I;
	


	std::cout.setf(std::ios::boolalpha);

	cout << "this shows off what happens when two similar words are compared" << endl;		
	cin >> A;
	cout << "A (apple): " << A << endl;
	cin >> B;
	cout << "B (apples): " << B << endl;
	cout << "A equal to B: " << (A==B) << endl;
	cout << "A is not equal to B: " << (A!=B) << endl;
	cout << "A is less than B: " << (A<B) << endl;
	cout << "A is less than or equal to B: " << (A<=B) << endl;
	cout << "A is more than B: " << (A>B) << endl;
	cout << "A is more than or equal to B: " << (A>=B) << endl;
	cout << "A+B: " << A+B << endl;
	A += B;
	cout << "A +=B: " << A << endl << endl;

	cout << "this shows off what happens when we call the = operator" << endl;		
	I = A;
	cout << "A (appleapples): " << A << endl;
	cout << "I (appleapples): " << I << endl;
	cout << "A equal to I: " << (A==I) << endl;
	cout << "A is not equal to I: " << (A!=I) << endl;
	cout << "A is less than I: " << (A<I) << endl;
	cout << "A is less than or equal to I: " << (A<=I) << endl;
	cout << "A is more than I: " << (A>I) << endl;
	cout << "A is more than or equal to I: " << (A>=I) << endl;
	cout << "A+I: " << A+I << endl;
	A += I;
	cout << "A +=I: " << A << endl << endl;
	
	cin >> C;
	cout << "C (applesauce): " << C << endl;
	cin >> D;
	cout << "D (appl-e): " << D << endl;
	cout << "C equal to D: " << (C==D) << endl;
	cout << "C is not equal to D: " << (C!=D) << endl;
	cout << "C is less than D: " << (C<D) << endl;
	cout << "C is less than or equal to D: " << (C<=D) << endl;
	cout << "C is more than D: " << (C>D) << endl;
	cout << "C is more than or equal to D: " << (C>=D) << endl;
	cout << "C+D: " << C+D << endl;
	C +=D;
	cout << "C +=D: " << C << endl << endl;
	
	cout << "D (appl-e): " << D << endl;
	cin >> E;
	cout << "this shows off what happens when an input starts incorrectly" << endl;		
	cout << "E ('apple): " << E << endl;
	cout << "D equal to E: " << (D==E) << endl;
	cout << "D is not equal to E: " << (D!=E) << endl;
	cout << "D is less than E: " << (D<E) << endl;
	cout << "D is less than or equal to E: " << (D<=E) << endl;
	cout << "D is more than E: " << (D>E) << endl;
	cout << "D is more than or equal to E: " << (D>=E) << endl;
	cout << "D+E: " << D+E << endl;
	D +=E;
	cout << "D +=E: " << D << endl << endl;

	cout << "this shows off what happens when an input starts incorrectly" << endl;		
	cout << "E ('apple): " << E << endl;
	cin >> F;
	cout << "this shows off what happens when an input ends incorrectly" << endl;	
	cout << "F (apple12): " << F << endl;
	cout << "E equal to F: " << (E==F) << endl;
	cout << "E is not equal to F: " << (E!=F) << endl;
	cout << "E is less than F: " << (E<F) << endl;
	cout << "E is less than or equal to F: " << (E<=F) << endl;
	cout << "E is more than F: " << (E>F) << endl;
	cout << "E is more than or equal to F: " << (E>=F) << endl;
	cout << "E+F: " << E+F << endl;
	E +=F;
	cout << "E +=F: " << E << endl << endl;
	
	cout << "this shows off what happens when input is too long" << endl;	
	cout << "F (apple): " << F << endl;
	cin >> G;
	cout << "G (monkeymonkeymonkeymonkeymonkeymonkey): " << G << endl;
	cout << "F equal to G: " << (F==G) << endl;
	cout << "F is not equal to G: " << (F!=G) << endl;
	cout << "F is less than G: " << (F<G) << endl;
	cout << "F is less than or equal to G: " << (F<=G) << endl;
	cout << "F is more than G: " << (F>G) << endl;
	cout << "F is more than or equal to G: " << (F>=G) << endl;
	cout << "F+G: " << F+G << endl;
	F += G;
	cout << "F += G: " << F << endl << endl;
	
	cout << "this shows off what happens when input is too long as next input is the excess" 
	<< endl;
	cout << "G (monkeymonkeymonkeymonkeymonkeym): " << G << endl;
	cin >> H;
	cout << "H (onkey): " << H << endl;
	cout << "H equal to G: " << (H==G) << endl;
	cout << "H is not equal to G: " << (H!=G) << endl;
	cout << "H is less than G: " << (H<G) << endl;
	cout << "H is less than or equal to G: " << (H<=G) << endl;
	cout << "H is more than G: " << (H>G) << endl;
	cout << "H is more than or equal to G: " << (H>=G) << endl;
	cout << "H+G: " << H+G << endl;
	H +=G;
	cout << "H+=G: " << H << endl << endl;
}
