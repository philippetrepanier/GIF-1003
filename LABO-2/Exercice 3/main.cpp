/*
 * main.cpp
 *
 *  Created on: 2017-01-20
 *      Author: etudiant
 */
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int nombre;
	string phrase;
	cout << "Entrez un nombre" << endl;
	cin >> nombre;
	cin.ignore();
	cout << "Entrez une phrase comprenant des espaces" << endl;
	getline(cin, phrase);
	cout << phrase << endl;
	return 0;
}

