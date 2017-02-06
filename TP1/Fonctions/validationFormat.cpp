/*
 * validationFormat.cpp
 *
 *  Created on: 2017-02-04
 *      Author: Philippe Trepanier
 */
#include "validationFormat.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <algorithm>
#include <sstream>
#include <locale>

using namespace std;
std::locale loc;

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
			else if (not isdigit(*lettre, loc))
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
		stringstream numero_ss;

		//Mettre les lettres requises du prenom et du nom en majuscules et dans le bon ordre
		for (int i = 0; i < 3; ++i)
		{
			numero_ss << toupper(p_nom[i], loc);
		}

		numero_ss << toupper(p_prenom[0], loc);

		//Dépendant du format de l'année de naissance
		if (p_anneeNaissance < 100)
		{
			numero_ss << p_anneeNaissance;
		}
		else
		{
			numero_ss << p_anneeNaissance % 100;
		}

		//Pour un Homme
		if (p_sex == 'M' || p_sex == 'm')
		{
			if (p_moisNaissance < 10)
			{
				numero_ss << 0 << p_moisNaissance;
			}
			else
			{
				numero_ss << p_moisNaissance;
			}

		}
		//Pour une femme
		else if (p_sex == 'F' || p_sex == 'f')
		{
			numero_ss << (p_moisNaissance + 50);
		}

		//Jour de naissance
		numero_ss << p_jourNaissance;

		//Convertir le stream en string
		string numero_fabrique = numero_ss.str();

		//Vérifier que le string a bien 10 char de long, sinon erreur quelquepart
		if (numero_fabrique.size() != 10)
		{
			return false;
		}

		//Boucler pour comparer les 10 premiers char de la string synth et entrée
		for (int i = 0; i < 10; ++i)
		{
			if (numero_fabrique[i] != p_numero[i])
			{
				return false;
			}
		}

		//Vérifier que les 2 derniers char du parametre sont des nombres
		if (not isdigit(p_numero[10], loc) || not isdigit(p_numero[11], loc))
		{
			return false;
		}

		return true;
	}
	return false;
}
