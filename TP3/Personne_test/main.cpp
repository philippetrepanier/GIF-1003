/**
 * \file main.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-28
 */
#include "Personne.h"
#include "Entraineur.h"
#include "Annuaire.h"
#include <iostream>

using namespace std;

int main()
{
	util::Date naissanceVirge(18, 05, 1997);
	tp::Entraineur virginie("Beaudoin", "Virginie", naissanceVirge, "581 998-3637", "BEAV 9705 1818", 'M');

	tp::Annuaire annuaire_1("Club d'Alice");
	annuaire_1.ajouterPersonne(virginie);
	annuaire_1.ajouterPersonne(virginie);
	cout << annuaire_1.reqAnnuaireFormate();
	cout << "Bonjour :)" << endl;
	return 0;
}

