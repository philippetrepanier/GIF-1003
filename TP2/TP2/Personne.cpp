/**
 * \file Personne.cpp
 * \brief
 * \author Philippe Trepanier
 * \date 2017-02-19
 */

#include <sstream>
#include "Personne.h"
using namespace std;

namespace tp
{

const string& Personne::reqNom() const
{
	return m_nom;
}

const string& Personne::reqPrenom() const
{
	return m_prenom;
}

util::Date Personne::reqDateNaissance() const
{

	return m_dateNaissance;
}

const string& Personne::reqTelephone() const
{
	return m_telephone;
}

void Personne::asgTelephone(const string& p_telephone)
{
	if (util::validerTelephone(p_telephone) == true)
	{
		m_telephone = p_telephone;
	}
}

Personne::Personne(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
		const string& p_telephone) :
		m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
}

const string Personne::reqPersonneFormate() const
{

	ostringstream os;

	os << "Nom               : " << Personne::reqNom() << endl;
	os << "Prenom            : " << Personne::reqPrenom() << endl;
	os << "Date de naissance : " << Personne::reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone         : " << Personne::reqTelephone() << endl;

	return os.str();

}

bool Personne::operator ==(const Personne& p_personne) const
{
	if (m_nom == p_personne.m_nom && m_prenom == p_personne.m_prenom && m_dateNaissance == p_personne.m_dateNaissance
			&& m_telephone == p_personne.m_telephone)
	{
		return true;
	}
	else
	{
		return false;
	}

}

} // namespace tp
