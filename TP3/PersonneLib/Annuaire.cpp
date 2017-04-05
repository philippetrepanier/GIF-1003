/**
 * \file Annuaire.cpp
 * \brief
 * \author Philippe Trépanier
 * \date 2017-03-29
 */

#include "Annuaire.h"
#include <sstream>

using namespace std;
namespace tp
{

Annuaire::Annuaire(const string& p_nomClub) :
		m_nomClub(p_nomClub)
{
	// TODO Auto-generated constructor stub

}

Annuaire::~Annuaire()
{
	for (unsigned int i = 0; i < m_vMembres.size(); ++i)
	{
		delete m_vMembres[i];
	}
}

string Annuaire::reqNom() const
{
	return m_nomClub;
}

string Annuaire::reqAnnuaireFormate() const
{
	ostringstream os;
	os << "Club : " << reqNom() << endl;
	os << "---------------------" << endl;
	for (unsigned int i = 0; i < m_vMembres.size(); ++i)
	{
		os << (*m_vMembres[i]).reqPersonneFormate();
	}

	return os.str();
}

void Annuaire::ajouterPersonne(const Personne& p_personne)
{
	m_vMembres.push_back(p_personne.clone());
}

} /* namespace tp */
