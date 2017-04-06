/**
 * \file Annuaire.cpp
 * \brief Implémentation de la classe Annuaire
 * \author Philippe Trépanier
 * \date 2017-03-29
 */

#include "Annuaire.h"
#include <sstream>
#include "ContratException.h"

using namespace std;
namespace tp
{
/**
 * \brief Constructeur d'un nouvel objet de la classe Annuaire
 * \param[in] p_nomClub nom du club
 * \pre p_nomClub est un nom valide
 * \post p_nomClub prend la valeur de p_nomClub
 */
Annuaire::Annuaire(const string& p_nomClub) :
		m_nomClub(p_nomClub)
{
	PRECONDITION(!(p_nomClub.empty()));

	POSTCONDITION(p_nomClub == m_nomClub);
}

Annuaire::~Annuaire()
{
	for (size_t i = 0; i < m_vMembres.size(); ++i)
	{
		delete m_vMembres[i];
	}
	m_vMembres.clear();
}
/**
 * \brief Retourne la date de naissance de la personne
 * \return date de naissance de la personne
 */
string Annuaire::reqNom() const
{
	return m_nomClub;
}
/**
 * \brief Retourne une string contenant les informations contenues dans l'annuaire
 * \return informations de l'annuaire
 */
string Annuaire::reqAnnuaireFormate() const
{
	ostringstream os;
	os << "Club : " << reqNom() << endl;
	os << "---------------------" << endl;
	for (size_t i = 0; i < m_vMembres.size(); ++i)
	{
		os << (*m_vMembres[i]).reqPersonneFormate();
	}

	return os.str();
}
/**
 * \brief Permet l'ajoute d'une personne (Joueur ou entraineur) à l'annuaire
 * \param[in] p_personne Objet de type personne
 */
void Annuaire::ajouterPersonne(const Personne& p_personne)
{
	m_vMembres.push_back(p_personne.clone());
	INVARIANTS();
}
/**
 * \brief Vérifier les invariants de classe
 */
void Annuaire::verifieInvariant() const
{
	INVARIANT(!(m_nomClub.empty()));
}

} /* namespace tp */

