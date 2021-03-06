/*
 * fonctions.cpp
 *
 *  Created on: 2017-01-25
 *      Author: etudiant
 */
#include <iostream>
#include "fonctions.h"

using namespace std;

void saisirTableau(int* taille, int tableau[])
{

	do
	{
		cout << "Combien de valeurs voulez-vous entrer?";
		cin >> *taille;
	} while (*taille > 10 || *taille < 0);

	cout << "Entrez des entiers :" << endl;
	for (int i = 0; i < *taille; ++i)
	{
		do
		{
			cout << "Entrez la valeur no " << i << " : " << endl;
			cin >> tableau[i];
		} while (tableau[i] > 10 || tableau[i] < 0);
	}
}

float calculerMoyenne(int taille, int tableau[])
{
	float somme = 0;

	for (int i = 0; i < taille; ++i)
	{
		somme += tableau[i];
	}
	float moyenne = somme / taille;
	return moyenne;
}

void afficherTableau(int taille, float moyenne, int tableau[])
{
	cout << "Voici les entiers que vous avez saisi : " << endl;
	for (int i = 0; i < taille; ++i)
	{
		cout << tableau[i] << endl;
	}
	cout << "Voici la moyenne : " << moyenne << endl;
}

