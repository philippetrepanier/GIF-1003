/*
 * main.cpp
 *
 *  Created on: 2017-02-04
 *      Author: Philippe Trepanier
 */
#include "validationFormat.h"
#include <iostream>

using namespace std;

int main()
{
	const std::string p_telephone = "418 558-2888";
	bool telephone = validerTelephone(p_telephone);

	cout << "Telephone valide: " << telephone << endl;

	const string p_numero = "TREP 9705 0505";
	bool RAMQ = validerNumRAMQ(p_numero, "trepanier", "philippe", 5, 5, 1997, 'm');
	bool RAMQ2 = validerNumRAMQ("BONJ 7051 0112", "bonneau", "jeanne", 01, 01, 1970, 'F');

	cout << "RAMQ valide: " << RAMQ2 << endl;

	return 0;
}
