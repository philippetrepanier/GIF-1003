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
	return p_dateNaissance;
}

const std::string& tp::Personne::reqTelephone() const
{
	return p_telephone;
}

void tp::Personne::asgTelephone(const std::string& telephone)
{
	p_telephone = telephone;
}
} // namespace tp