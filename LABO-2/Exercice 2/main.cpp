/*
 * main.cpp
 *
 *  Created on: 2017-01-20
 *      Author: etudiant
 */
#include <iostream>
using namespace std;

int main() {
	int nombrelignes;
	cout << "Veuillez entrer un nombre: " << endl;
	cin >> nombrelignes;

	for (int i = 1; i <= nombrelignes; i++) {
		for (int espaces = 1; espaces <= (nombrelignes - i); espaces++) {
			cout << " ";
		}
		for (int stars = 1; stars <= (2 * i - 1); stars += 1) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

