/*
 * main.cpp
 *
 *  Created on: 2017-01-25
 *      Author: etudiant
 */
#include <iostream>
#include "fonctions.h"

using namespace std;

int main(void)
{
	int tableau[maximum];
	int taille = 0;

	saisirTableau(&taille, tableau);
	float moyenne = calculerMoyenne(taille, tableau);
	afficherTableau(taille, moyenne, tableau);

}

