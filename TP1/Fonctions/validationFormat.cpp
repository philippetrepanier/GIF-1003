/*
 * validationFormat.cpp
 *
 *  Created on: 2017-02-04
 *      Author: etudiant
 */
#include "validationFormat.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <algorithm>

using namespace std;

bool validerTelephone(const string& p_telephone)
{
	if (p_telephone.size() != 12)
	{
		return false;
	}
	else
	{
		int i = 0;
		for (string::const_iterator lettre = p_telephone.begin(), end = p_telephone.end(); lettre != end; ++lettre, ++i)
		{
			if (i == 3)
			{
				if (*lettre == ' ')
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			else if (i == 7)
			{
				if (*lettre == '-')
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			else if (*lettre != '0' && *lettre != '1' && *lettre != '2' && *lettre != '3' && *lettre != '4'
					&& *lettre != '5' && *lettre != '6' && *lettre != '7' && *lettre != '8' && *lettre != '9')
			{
				return false;
			}
		}
		return true;
	}
}

bool validerNumRAMQ(const string& p_numero, const string& p_nom, const string& p_prenom, int p_jourNaissance,
		int p_moisNaissance, int p_anneeNaissance, char p_sex)
{
	//Enlever les espaces dans le numero reçu en entrée
	string numero_RAMQ = p_numero;
	numero_RAMQ.erase(remove_if(numero_RAMQ.begin(), numero_RAMQ.end(), ::isspace), numero_RAMQ.end());

	//Vérifier que le numero a 12 char de long
	if (p_numero.size() != 12)
	{
		return false;
	}
	else
	{
		//Conception d'une string avec les paramètres fournis en entrée

		//Découpage de la chaine afin d'isoler les parties à vérifier
		string numero_nom = numero_RAMQ.substr(0, 3);
		string numero_prenom = numero_RAMQ.substr(3, 1);
		string numero_annee = numero_RAMQ.substr(4, 2);
		string numero_mois = numero_RAMQ.substr(6, 2);
		string numero_jour = numero_RAMQ.substr(8, 2);

		return true;
	}
	return false;
}
