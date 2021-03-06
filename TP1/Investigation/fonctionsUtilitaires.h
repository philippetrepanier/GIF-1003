/*
 * fonctionsUtilitairesSolution.h
 *
 *  Created on: 2015-01-13
 *      Author: etudiant
 */

#ifndef FONCTIONSUTILITAIRESSOLUTION_H_
#define FONCTIONSUTILITAIRESSOLUTION_H_

//dimension des images
const int LARGEUR = 13;
const int HAUTEUR = 13;

void initialise(int* p_tableau, int nb_colonnes, int p_valeur);
void saisie(int p_valeurs[], int nb_valeurs);

int max(int p_valeurs[], int p_taille);
int max_2d(int p_valeurs[HAUTEUR][LARGEUR]);

void histogramme(int p_image[HAUTEUR][LARGEUR], int p_frequences[]);
void affiche_histogramme(int p_frequences[], int p_valeurMax);
void initialise(int* p_tableau, int nb_colonnes);

#endif /* FONCTIONSUTILITAIRESSOLUTION_H_ */
