#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(void) {
	float fa = 1.0f;
	float fb = -4.0000000f;
	float fc = 3.9999999f;
	double da = 1.0;
	double db = -4.0000000;
	double dc = 3.9999999;
// résolution de l’équation en utilisant des variables de type float
	float d1 = fb * fb - 4.0f * fa * fc;
	float sd1 = sqrtf(d1);
	float rf1 = (-fb + sd1) / (2.0f * fa);
	float rf2 = (-fb - sd1) / (2.0f * fa);
	cout.precision(5);
	cout << rf1 << '\t' << rf2 << endl;
// résolution de l’équation en utilisant des variables de type double
	double d2 = db * db - 4.0 * da * dc;
	double sd2 = sqrt(d2);
	double rd1 = (-db + sd2) / (2.0 * da);
	double rd2 = (-db - sd2) / (2.0 * da);
	cout.precision(5);
	cout << rd1 << '\t' << rd2 << endl;
	return 0;
}
