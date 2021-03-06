/*
 * fonctionsUtilitairesSolution.cpp
 *
 *  Created on: 2015-01-13
 *      Author: etudiant
 */

#include <iomanip>
#include <iostream>

#include "fonctionsUtilitaires.h"

using namespace std;

/**
 * \brief
 * \param[in] p_valeurs un tableau de valeurs
 * \param[in] p_taille la taille du tableau d'entrée
 * \return valeur_max la valeur maximum du tableau
 */
int max(int p_valeurs[], int p_taille)
{
	int valeur_max = 0;
	for (int i = 0; i < p_taille; i++)
	{
		if (valeur_max < p_valeurs[i])
		{
			valeur_max = p_valeurs[i];
		}
	}
	return valeur_max;
}

int max_2d(int p_valeurs[HAUTEUR][LARGEUR])
{
	int valeur_max = 0;

	for (int i = 0; i < HAUTEUR; i++)
	{
		int max_local = max(p_valeurs[i], LARGEUR);

		if (valeur_max < max_local)
		{
			valeur_max = max_local;
		}
	}
	return valeur_max;
}

void saisie(int p_valeurs[], int nb_valeurs)
{
	for (int i = 0; i < nb_valeurs; i++)
	{
		cout << "Valeur" << i + 1 << ":";
		cin >> p_valeurs[i]; //mémoristion des données saisies
	}
}

/**
 * \brief initialise  le tableau passé en paramètre à la valeur transmise
 * \param[in] nb_colonnes le nombre de colonnes
 * \param[in] p_valeur la valeur d'initialisation
 * \param[out] p_tableau le tableau à initialiser
 */
void initialise(int* p_tableau, int nb_colonnes, int p_valeur)
{
	for (int j = 0; j <= nb_colonnes; j++)
	{
		p_tableau[j] = p_valeur;
	}
}

/**
 * \brief détermine l'histogramme d'une image passée sous la forme d'un tableau 2D
 * \param[in] p_image l'image source
 * \param[out] p_frequences occurences des valeurs des niveaux de gris
 */
void histogramme(int p_image[HAUTEUR][LARGEUR], int p_frequences[])
{
	//calcule les frequences
	for (int ligne = 0; ligne < HAUTEUR; ligne++)
	{
		for (int colonne = 0; colonne < LARGEUR; ++colonne)
		{
			p_frequences[p_image[ligne][colonne]]++;
		}
	}
}

/**
 * \brief affiche l'histogramme sous forme d'étoiles
 * \param[in] p_frequences le tableau contenant les fréquences des valeurs correspondant à l'indice
 */
void affiche_histogramme(int p_frequences[], int p_valeurMax)
{
	//affiche l'histogramme
	cout << "....Histogramme...." << endl << endl;
	for (int i = 0; i <= p_valeurMax; i++)
	{
		cout << left;
		cout << i << " : ";
		cout << p_frequences[i] << "\t";
		for (int j = 0; j < p_frequences[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

}
