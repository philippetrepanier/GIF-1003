/**
 * \file main.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-03
 */

#include <iostream>
#include "Complexe.h"

using namespace std;
using namespace labo;

int main()
{
	Complexe z1(-1.0, -2.0);
	Complexe z2(3.0, -4.0);

	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	cout << "z1 + z2 = " << z1 + z2 << endl;
	cout << "z1 + 4 = " << z1 + 4 << endl;
	cout << "z1 * z2 = " << z1 * z2 << endl;
	cout << "conj(z1) = " << z1.reqConjugue() << endl;
	cout << "|z2| = " << z2.reqModule() << endl;
	cout << "z1/z2 = " << z1 / z2 << endl;

	return 0;
}

