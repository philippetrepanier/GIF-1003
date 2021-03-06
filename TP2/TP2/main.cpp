/**
 * \file main.cpp
 * \brief Fichier principal du programme qui permet la création d'une personne et l'assignation de ses paramètres
 * 			Par la suite le programme demande à l'utilisateur un changement de numero de télephone.
 * \author Philippe Trepanier
 * \date 2017-02-19
 */

#include "Personne.h"
#include <iostream>
#include <sstream>
using namespace std;
using namespace tp;

int main()
{

	cout << "=============================================" << endl;
	cout << "|Bienvenue à l'outil d'ajout d'une personne!|" << endl;
	cout << "=============================================" << endl << endl;

	//Entrée du nom
	cout << "-Entrez le nom de la personne: " << endl;
	string nom;
	char buffer[256];
	cin.getline(buffer, 255);
	nom = buffer;

	while (util::validerFormatNom(nom) == false)
	{
		cout << "Le nom de la personne ne doit comporter que des lettres" << endl;
		cout << "-Entrez le nom de la personne: " << endl;
		cin.getline(buffer, 255);
		nom = buffer;
	}

	//Entrée du prenom
	cout << endl << "-Entrez le prenom de la personne: " << endl;
	string prenom;
	cin.getline(buffer, 255);
	prenom = buffer;

	while (util::validerFormatNom(prenom) == false)
	{
		cout << "!--Le prenom de la personne ne doit comporter que des lettres--!" << endl;
		cout << "-Entrez le prenom de la personne: " << endl;
		cin.getline(buffer, 255);
		prenom = buffer;
	}

	//Entrée du numero de telephone
	cout << endl << "-Entrez le numero de telephone de la personne: " << endl;
	string telephone;
	cin.getline(buffer, 255);
	telephone = buffer;

	while (util::validerTelephone(telephone) == false)
	{
		cout << "!--Le numero de telephone doit avoir un format valide--!" << endl;
		cout << "-Entrez le numero de telephone de la personne: " << endl;
		cin.getline(buffer, 255);
		telephone = buffer;
	}

	//Entrée de la date de naissaance

	cout << endl << "-Entrez la date de naissance de la personne: " << endl;
	cout << "Veuillez entrer le jour [1...31] : ";
	int jourNaissance = 0;
	cin >> jourNaissance;

	cout << "Veuillez entrer le mois [1...12] : ";
	int moisNaissance = 0;
	cin >> moisNaissance;

	cout << "Veuillez entrer l'année [1970...] : ";
	int anneeNaissance = 0;
	cin >> anneeNaissance;

	while (util::Date::validerDate(jourNaissance, moisNaissance, anneeNaissance) == false)
	{
		cout << "!--Veuillez entrer une date valide--!" << endl;
		cout << endl << "-Entrez la date de naissance de la personne: " << endl;
		cout << "Veuillez entrer le jour [1...31] : ";
		cin >> jourNaissance;

		cout << "Veuillez entrer le mois [1...12] : ";
		cin >> moisNaissance;

		cout << "Veuillez entrer l'année [1970...] : ";
		cin >> anneeNaissance;
	}
	util::Date dateNaissance(jourNaissance, moisNaissance, anneeNaissance);

	//Création de la personne
	tp::Personne personne(nom, prenom, dateNaissance, telephone);

	//Impression de la nouvelle personne
	cout << endl << "=======================" << endl;
	cout << "|  Nouvelle personne  |" << endl;
	cout << "=======================" << endl << endl;
	cout << personne.reqPersonneFormate() << endl << endl;

	//Entrée du nouveau numero de telephone
	cout << "Entrez le nouveau numéro de téléphone de la personne:" << endl;
	string nvTelephone;
	cin.ignore();
	cin.getline(buffer, 255);
	nvTelephone = buffer;

	while (util::validerTelephone(nvTelephone) == false)
	{
		cout << "!--Le numero de telephone doit avoir un format valide--!" << endl;
		cout << "-Entrez le numero de telephone de la personne: " << endl;
		cin.getline(buffer, 255);
		nvTelephone = buffer;
	}
	personne.asgTelephone(nvTelephone);
	cout << endl << "===========================" << endl;
	cout << "|  Modification réussie!  |" << endl;
	cout << "===========================" << endl << endl;
	cout << personne.reqPersonneFormate() << endl << endl;

	cout << "======================" << endl;
	cout << "|  Fin du programme  |" << endl;
	cout << "======================" << endl << endl;

	return 0;

}

