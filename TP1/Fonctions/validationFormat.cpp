/*
 * validationFormat.cpp
 *
 *  Created on: 2017-02-04
 *      Author: etudiant
 */
#include "validationFormat.h"
#include <iostream>
#include <typeinfo>

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

bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom,
		int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex)
{

}
