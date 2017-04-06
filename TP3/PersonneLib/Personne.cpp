/**
 * \file Personne.cpp
 * \brief Implémentation de la classe de base abstraite Personne. Elle contient les informations de base sur les personnes.
 * \author Philippe Trepanier
 * \date 2017-02-19
 */

#include <sstream>
#include "Personne.h"

using namespace std;

namespace tp
{
/**
 * \brief Retourne le nom de la personne
 * \return nom de la personne
 */
const string& Personne::reqNom() const
{
	return m_nom;
}

/**
 * \brief Retourne le prenom de la personne
 * \return prenom de la personne
 */
const string& Personne::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief Retourne la date de naissance de la personne
 * \return date de naissance de la personne
 */
const util::Date Personne::reqDateNaissance() const
{

	return m_dateNaissance;
}

/**
 * \brief Retourne le numero de telephone de la personne
 * \return numero de telephone de la personne
 */
const string& Personne::reqTelephone() const
{
	return m_telephone;
}

/**
 * \brief Assigne un nouveau numero de telephone à une personne
 * \param[in] p_telephone est le nouveau numero de telephone qui respecte le format national
 * \pre p_telephone doit correspondre à un numero de telephone valide
 * \post m_telephone prend la valeur de p_telephone
 */
void Personne::asgTelephone(const string& p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}

/**
 * \brief Constructeur d'un nouvel objet de la classe Personne
 * \param[in] p_nom nom de la personne
 * \param[in] p_prenom prenom de la personne
 * \param[in] p_dateNaissance date de la naissance de la personne
 * \param[in] p_telephone numero de telephone qui respecte le format national
 * \pre p_nom, p_prenom, p_dateNaissance et p_telephone doivent correspondent à un format valide
 * \post m_nom prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 * \post m_dateNaissance prend la valeur de p_dateNaissance
 * \post m_telephone prend la valeur de p_telephone
 */
Personne::Personne(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
		const string& p_telephone) :
		m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
	PRECONDITION(util::validerFormatNom(p_nom));
	PRECONDITION(util::validerFormatNom(p_prenom));
	PRECONDITION(util::validerTelephone(p_telephone));
	PRECONDITION(
			util::Date::validerDate(p_dateNaissance.reqJour(), p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee()));
	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_dateNaissance == p_dateNaissance);
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}

/**
 * \brief Renvoie les informations de la personne dans un formatage adapté à la console
 * \return Informations de la personne dans un formatage texte adapté console
 */
string Personne::reqPersonneFormate() const
{

	ostringstream os;

	os << "Nom               : " << Personne::reqNom() << endl;
	os << "Prenom            : " << Personne::reqPrenom() << endl;
	os << "Date de naissance : " << Personne::reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone         : " << Personne::reqTelephone() << endl;

	return os.str();

}
/**
 * \brief Surcharge de l'opérateur == qui permet de vérifier si deux personnes sont identiques
 * \param[in] p_personne objet personne à comparer
 * \return valeur booléene de la comparaison des deux objets personne
 */
bool Personne::operator ==(const Personne& p_personne) const
{
	if (m_nom == p_personne.m_nom && m_prenom == p_personne.m_prenom && m_dateNaissance == p_personne.m_dateNaissance)
	{
		return true;
	}
	else
	{
		return false;
	}

}
/**
 * \brief Vérifie les invariants de classe
 */
void Personne::verifieInvariant() const
{
	INVARIANT(util::validerFormatNom(m_nom));
	INVARIANT(util::validerFormatNom(m_prenom));
	INVARIANT(
			util::Date::validerDate(m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee()));
	INVARIANT(util::validerTelephone(m_telephone));
}
} // namespace tp

