/**
 * \file programmePrincipalSolution.cpp
 * \brief  programme qui affiche l'histogramme d'une image
 * construit l'histogramme de cette saisie dans un tableau à une dimension
 * recherche la valeur maximum pour limiter la taille de l'histogramme à cette valeur
 * calcule l'histogramme
 * affiche l'histogramme sous forme d'étoiles
 *
 * \author theud1
 * \version 0.1
 * \date 2015-01-13
 */
#include <iostream>
#include "fonctionsUtilitaires.h"
using namespace std;

const int LARGEUR = 13;
const int HAUTEUR = 13;

int main()
{
	//initialisation pour une image en niveau de gris de 13*13 pixels
	int image[HAUTEUR][LARGEUR] =
	{
	{ 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72 },
	{ 72, 72, 71, 70, 70, 70, 70, 70, 70, 70, 70, 72, 72 },
	{ 72, 107, 116, 145, 137, 130, 154, 118, 165, 111, 173, 116, 72 },
	{ 72, 126, 150, 178, 158, 175, 163, 169, 170, 160, 176, 163, 70 },
	{ 72, 130, 192, 195, 197, 186, 129, 185, 196, 196, 193, 195, 70 },
	{ 72, 126, 187, 166, 85, 75, 106, 185, 191, 191, 189, 188, 69 },
	{ 72, 121, 183, 111, 100, 51, 137, 188, 187, 186, 184, 180, 69 },
	{ 72, 117, 177, 143, 58, 77, 137, 180, 171, 183, 178, 173, 69 },
	{ 72, 111, 172, 108, 101, 110, 115, 67, 49, 120, 175, 165, 68 },
	{ 72, 107, 145, 105, 145, 120, 85, 51, 51, 56, 138, 157, 68 },
	{ 72, 103, 147, 158, 155, 131, 115, 114, 114, 115, 121, 152, 68 },
	{ 72, 79, 146, 161, 163, 165, 168, 167, 164, 162, 158, 114, 70 },
	{ 72, 69, 53, 49, 49, 49, 49, 49, 49, 49, 50, 61, 72 } };

	//recherche du maximum des valeurs pour connaitre la dimension de l'histogramme
	int v = max_2d(image);
	cout << v << endl;

	//déclaration et initialisation du tableau de l'histogramme
	int frequences[v];
	initialise(frequences, v);

	//calcul de l'histogramme
	histogramme(image, frequences);

	//affichage de l'histogramme
	affiche_histogramme(frequences, v);

	return 0;
}
