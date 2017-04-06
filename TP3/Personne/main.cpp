/**
 * \file main.cpp
 * \brief Fichier principal du programme qui permet la création d'une personne et l'assignation de ses paramètres
 * 			Par la suite le programme demande à l'utilisateur un changement de numero de télephone.
 * \author Philippe Trepanier
 * \date 2017-03-28
 */
#include "Personne.h"
#include "Joueur.h"
#include "Entraineur.h"
#include "Annuaire.h"
#include "validationFormat.h"
#include <iostream>
#include <sstream>

static const long JOURS_POUR_18_ANS = long(-18 * 365.25);
static const long JOURS_POUR_15_ANS = long(-15 * 365.25);

using namespace std;
using namespace tp;

int main()
{
	Annuaire annuaire("NOM DU CLUB");

	cout << "=============================================" << endl;
	cout << "|Bienvenue à l'outil d'ajout d'une personne!|" << endl;
	cout << "=============================================" << endl << endl;

	//Entrée du nom
	cout << "-Entrez le nom du joueur: " << endl;
	string nom;
	char buffer[256];
	cin.getline(buffer, 255);
	nom = buffer;
	util::convertitEnMajuscules(nom);

	while (util::validerFormatNom(nom) == false)
	{
		cout << "Le nom de la personne ne doit comporter que des lettres" << endl;
		cout << "-Entrez le nom du joueur: " << endl;
		cin.getline(buffer, 255);
		nom = buffer;
		util::convertitEnMajuscules(nom);
	}

	//Entrée du prenom
	cout << endl << "-Entrez le prenom du joueur: " << endl;
	string prenom;
	cin.getline(buffer, 255);
	prenom = buffer;
	util::convertitEnMajuscules(prenom);

	while (util::validerFormatNom(prenom) == false)
	{
		cout << "!--Le prenom de la personne ne doit comporter que des lettres--!" << endl;
		cout << "-Entrez le prenom du joueur: " << endl;
		cin.getline(buffer, 255);
		prenom = buffer;
		util::convertitEnMajuscules(prenom);
	}

	//Entrée du numero de telephone
	cout << endl << "-Entrez le numero de telephone du joueur: " << endl;
	string telephone;
	cin.getline(buffer, 255);
	telephone = buffer;

	while (util::validerTelephone(telephone) == false)
	{
		cout << "!--Le numero de telephone doit avoir un format valide--!" << endl;
		cout << "-Entrez le numero de telephone du joueur: " << endl;
		cin.getline(buffer, 255);
		telephone = buffer;
	}

	//Entrée de la date de naissaance

	cout << endl << "-Entrez la date sa date de naissance: " << endl;
	cout << "Veuillez entrer le jour [1...31] : ";
	int jourNaissance = 0;
	cin >> jourNaissance;

	cout << "Veuillez entrer le mois [1...12] : ";
	int moisNaissance = 0;
	cin >> moisNaissance;

	cout << "Veuillez entrer l'année [1970...] : ";
	int anneeNaissance = 0;
	cin >> anneeNaissance;

	util::Date datePour18;
	util::Date datePour15;
	datePour18.ajouteNbJour(JOURS_POUR_18_ANS);
	datePour15.ajouteNbJour(JOURS_POUR_15_ANS);

	while (util::Date::validerDate(jourNaissance, moisNaissance, anneeNaissance) == false
			|| ((datePour18 < util::Date(jourNaissance, moisNaissance, anneeNaissance)) == false)
			|| (util::Date(jourNaissance, moisNaissance, anneeNaissance) < datePour15) == false)
	{
		cout << "!--Date invalide, le joueur doit être agé entre 15 et 17 ans--!" << endl;
		cout << endl << "-Entrez la date de naissance de la personne: " << endl;
		cout << "Veuillez entrer le jour [1...31] : ";
		cin >> jourNaissance;

		cout << "Veuillez entrer le mois [1...12] : ";
		cin >> moisNaissance;

		cout << "Veuillez entrer l'année [1970...] : ";
		cin >> anneeNaissance;
	}
	util::Date dateNaissance(jourNaissance, moisNaissance, anneeNaissance);

	//Entrée de la position
	cout << endl << "-Entrez la position du joueur: " << endl;
	cin.ignore();
	string position;
	cin.getline(buffer, 255);
	position = buffer;
	util::convertitEnMajuscules(position);

	while (!(position == "CENTRE" || position == "AILIER" || position == "DEFENSEUR" || position == "GARDIEN"))
	{
		cout << "!--La position du joueur est invalide--!" << endl;
		cout << "-Entrez la position du joueur: " << endl;
		cin.getline(buffer, 255);
		position = buffer;
		util::convertitEnMajuscules(position);
	}

	//Création de la personne
	tp::Joueur joueur(nom, prenom, dateNaissance, telephone, position);

	annuaire.ajouterPersonne(joueur);

	//Entrée du nom
	cout << "-Entrez le nom de l'entraineur: " << endl;
	string nom_ent;
	cin.getline(buffer, 255);
	nom_ent = buffer;
	util::convertitEnMajuscules(nom_ent);

	while (util::validerFormatNom(nom_ent) == false)
	{
		cout << "Le nom de l'entraineur ne doit comporter que des lettres" << endl;
		cout << "-Entrez le nom de l'entraineur: " << endl;
		cin.getline(buffer, 255);
		nom_ent = buffer;
		util::convertitEnMajuscules(nom_ent);
	}

	//Entrée du prenom
	cout << endl << "-Entrez le prenom de l'entraineur: " << endl;
	string prenom_ent;
	cin.getline(buffer, 255);
	prenom_ent = buffer;
	util::convertitEnMajuscules(prenom_ent);

	while (util::validerFormatNom(prenom_ent) == false)
	{
		cout << "!--Le prenom de l'entraineur ne doit comporter que des lettres--!" << endl;
		cout << "-Entrez le prenom de l'entraineur: " << endl;
		cin.getline(buffer, 255);
		prenom_ent = buffer;
		util::convertitEnMajuscules(prenom_ent);
	}

	//Entrée du numero de telephone
	cout << endl << "-Entrez le numero de telephone de l'entraineur: " << endl;
	string telephone_ent;
	cin.getline(buffer, 255);
	telephone_ent = buffer;

	while (util::validerTelephone(telephone_ent) == false)
	{
		cout << "!--Le numero de telephone doit avoir un format valide--!" << endl;
		cout << "-Entrez le numero de telephone de l'entraineur: " << endl;
		cin.getline(buffer, 255);
		telephone_ent = buffer;
	}

	//Entrée de la date de naissaance

	cout << endl << "-Entrez la date sa date de naissance: " << endl;
	cout << "Veuillez entrer le jour [1...31] : ";
	int jourNaissance_ent = 0;
	cin >> jourNaissance_ent;

	cout << "Veuillez entrer le mois [1...12] : ";
	int moisNaissance_ent = 0;
	cin >> moisNaissance_ent;

	cout << "Veuillez entrer l'année [1970...] : ";
	int anneeNaissance_ent = 0;
	cin >> anneeNaissance_ent;

	while (util::Date::validerDate(jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent) == false
			|| (util::Date(jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent) < datePour18) == false)
	{
		cout << "!--Date invalide ou l'entraineur doit etre majeur--!" << endl;
		cout << endl << "-Entrez sa date de naissance: " << endl;
		cout << "Veuillez entrer le jour [1...31] : ";
		cin >> jourNaissance_ent;

		cout << "Veuillez entrer le mois [1...12] : ";
		cin >> moisNaissance_ent;

		cout << "Veuillez entrer l'année [1970...] : ";
		cin >> anneeNaissance_ent;
	}
	util::Date dateNaissance_ent(jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent);

	//Entrée le sexe de l'entraineur
	cout << endl << "-Entrez le sexe de l'entraineur: M ou F" << endl;
	cin.ignore();
	char sexe;
	cin >> sexe;

	while (sexe != 'M' && sexe != 'F')
	{
		cout << "!--Le sexe entré est invalide--!" << endl;
		cout << "-Entrez le sexe de l'entraineur: " << endl;
		cin.ignore();
		cin >> sexe;
	}

	//Entrée numero de RAMQ
	cout << endl << "-Entrez le numero de RAMQ de l'entraineur: " << endl;
	string RAMQ_ent;
	cin.ignore();
	cin.getline(buffer, 255);
	RAMQ_ent = buffer;

	while (util::validerNumRAMQ(RAMQ_ent, nom_ent, prenom_ent, jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent,
			sexe) == false)
	{
		cout << "!--Le numero de RAMQ est invalide--!" << endl;
		cout << "-Entrez le numero de RAMQ de l'entraineur: " << endl;
		cin.getline(buffer, 255);
		RAMQ_ent = buffer;
	}

	//Création de l'entraineur
	tp::Entraineur entraineur(nom_ent, prenom_ent, dateNaissance_ent, telephone_ent, RAMQ_ent, sexe);

	annuaire.ajouterPersonne(entraineur);

	cout << endl << annuaire.reqAnnuaireFormate() << endl << endl;

	cout << "======================" << endl;
	cout << "|  Fin du programme  |" << endl;
	cout << "======================" << endl << endl;

	util::Date naissanceVirge(18, 05, 1997);
	tp::Entraineur virginie("Beaudoin", "Virginie", naissanceVirge, "581 998-3637", "BEAV 9705 1818", 'M');

	tp::Annuaire annuaire_1("Club d'Alice");
	annuaire_1.ajouterPersonne(virginie);
	annuaire_1.ajouterPersonne(virginie);
	cout << annuaire_1.reqAnnuaireFormate() << endl;
	cout << "Bonjour :)" << endl;
	return 0;

}

