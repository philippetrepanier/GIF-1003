/*
 * main.cpp
 *
 *  Created on: 2017-02-04
 *      Author: etudiant
 */
#include "validationFormat.h"
#include <iostream>

using namespace std;

int main()
{
	const std::string p_telephone = "418 558-2888";
	bool telephone = validerTelephone(p_telephone);

	cout << "Telephone valide: " << telephone << endl;

	return 0;
}
