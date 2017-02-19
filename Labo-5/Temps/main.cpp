/*
 * main.cpp
 *
 *  Created on: 2017-02-10
 *      Author: etudiant
 */
#include "Temps.h"
#include <iostream>

using namespace Temps2;
using namespace std;

int main()
{
	Temps tempsLocal;
	cout << tempsLocal.reqTempsFormate() << endl;
	cout << tempsLocal.reqMinute() << endl;
	cout << tempsLocal.reqNombreInstances() << endl;

	Temps temps1(23, 59, 59);
	temps1.tic();
	cout << temps1.reqTempsFormate() << endl;

	return 0;

}

