/**
 * \file Utilisation.cpp
 * \brief Programme principal pour la création des objets des classes enfants dela classe parent Employe.
 * \author etudiant
 * \version 0.1
 * \date 2014-11-13
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Employe.h"
#include "Patron.h"
#include "EmployeCommission.h"
#include "EmployeHoraire.h"
#include "time.h"

using namespace std;
using namespace labo10;
//using namespace util;

int determineMois();  // Détermine le mois courant
int main()
{
        Patron unPatron( "Soucy", "Jean", 800.00);
	   	EmployeCommission unEmployeCommisssion( "Sue", "Jones", 200.0, 3.0, 150);
	   	EmployeHoraire unEmployeHoraire( "Price", "Karen", 13.75, 40);
	   	Employe * v_entreprise[ 3 ] = { &unPatron, &unEmployeCommisssion, &unEmployeHoraire };
	   	int mois = determineMois();
	   	for ( int x = 0; x < 3; x++ )
	   	{
	   		cout << v_entreprise[x]->reqEmployeFormate() << " a gagné " << v_entreprise[x]->gains() << endl;
	   	}
	   return 0;
}

/**
 * \brief Détermination du mois courant
 * \return le mois courant
 */
int determineMois()
{
	time_t tempsCourant;
	char chaineMois[ 3 ];

	time( &tempsCourant );
	strftime( chaineMois, 3, "%m",      // strftime %m Le numéro du mois (entre 01 et 12)
		localtime( &tempsCourant ) );    // date et heure courante
	return atoi( chaineMois );      // atoi conversion d'un string en entier
}



