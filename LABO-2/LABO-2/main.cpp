/*
 * main.cpp
 *
 *  Created on: 2017-01-20
 *      Author: etudiant
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int cube = 0;
	cout << "Veuillez entrer un nombre n: " << endl;
	cin >> n;
#
	cube = n * n * n;
	int s = 0;
	int p = 1;
	int k = 1;

	while (s != cube) {
		if (s > cube) {
			s = s - (2 * k - 1);
			k++;
		} else {
			s = s + (2 * p - 1);
			p++;
		}
	}
	int premier = 2 * k - 1;
	int dernier = 2 * (p - 1) - 1;
	cout << "Cube = " << cube << endl;
	k = premier;

	while (k < dernier) {
		cout << "k = " << k << endl;
		k += 2;
	}
	cout << "Dernier = " << dernier << endl;

	return 0;
}

