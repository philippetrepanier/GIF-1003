/**
 * \file Personne.cpp
 * \brief
 * \author etudiant
 * \date 2017-02-19
 */

#include "Personne.h"

namespace tp
{

const std::string& tp::Personne::reqNom() const
{
	return m_nom;
}

const std::string& tp::Personne::reqPrenom() const
{
	return m_prenom;
}

util::Date tp::Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}

const std::string& tp::Personne::reqTelephone() const
{
	return m_telephone;
}

void tp::Personne::asgTelephone(const std::string& p_telephone)
{
	if (util::validerTelephone(p_telephone) == true)
	{
		m_telephone = p_telephone;
	}
}

tp::Personne::Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
		const std::string& p_telephone)
{
}

const std::string tp::Personne::reqPersonneFormate() const
{
	return "TEMP_STRING";
}

bool Personne::operator ==(const Personne& p_personne) const
{
	return true;
}

} // namespace tp
