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
#include <algorithm>  //ToUpper
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

		//Vérification du format, caractères et espace.
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

		//Vérification de l'indicatif régional dans la liste connue
		string liste_indicatifs[54] =
		{ "403", "587", "780", "825", "236", "250", "604", "778", "204", "431", "506", "709", "902", "226", "249",
				"289", "343", "365", "416", "437", "519", "613", "647", "705", "807", "905", "418", "438", "450", "514",
				"579", "581", "819", "873", "306", "867", "900", "800", "822", "833", "844", "855", "866", "877", "880",
				"881", "882", "883", "884", "885", "886", "887", "888", "889" };

		// Variable temporaire
		int indicatif_dans_liste = 0;
		for (int i = 0; i < 54; ++i)
		{
			if (p_telephone.substr(0, 3) == liste_indicatifs[i])
			{
				indicatif_dans_liste += 1;
			}
		}

		if (indicatif_dans_liste == 0)
		{
			return false;
		}

		return true;
	}
}

bool validerNumRAMQ(const string& p_numero, const string& p_nom, const string& p_prenom, int p_jourNaissance,
		int p_moisNaissance, int p_anneeNaissance, char p_sex)
{

	//Vérifier que le numero a 14 char de long avec les espaces
	if (p_numero.size() != 14)
	{
		return false;
	}
	else
	{
		//Conception d'une string avec les paramètres fournis en entrée
		stringstream numero_ss;

		//Mettre les lettres requises du prenom et du nom en majuscules et dans le bon ordre avec un espace après
		for (int i = 0; i < 3; ++i)
		{
			numero_ss << toupper(p_nom[i], loc);
		}

		numero_ss << toupper(p_prenom[0], loc) << " ";

		//Dépendant du format de l'année de naissance
		if (p_anneeNaissance < 100)
		{
			if (p_anneeNaissance < 10)
			{
				numero_ss << 0 << p_anneeNaissance;
			}
			else
			{
				numero_ss << p_anneeNaissance;
			}
		}
		else
		{
			if ((p_anneeNaissance % 100) < 10)
			{
				numero_ss << 0 << p_anneeNaissance % 100;
			}
			else
			{
				numero_ss << p_anneeNaissance % 100;
			}
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

		//Espace pour respecter le format
		numero_ss << " ";

		//Jour de naissance
		if (p_jourNaissance < 10)
		{
			numero_ss << 0 << p_jourNaissance;
		}
		else
		{
			numero_ss << p_jourNaissance;
		}

		//Convertir le stream en string
		string numero_fabrique = numero_ss.str();

		//Vérifier que le string a bien 12 char de long, sinon erreur quelquepart
		if (numero_fabrique.size() != 12)
		{
			return false;
		}

		//Boucler pour comparer les 12 premiers char de la string synth et entrée
		for (int i = 0; i < 12; ++i)
		{
			if (numero_fabrique[i] != p_numero[i])
			{
				return false;
			}
		}

		return true;
	}
	return false;
}
