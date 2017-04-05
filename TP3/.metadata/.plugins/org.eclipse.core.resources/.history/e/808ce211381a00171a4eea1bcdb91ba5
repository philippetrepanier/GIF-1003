/**
 * \file Personne.cpp
 * \brief Fichier d'implémentation de la classe Personne
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
 * \post l'objet courant a été correctement assigné
 */
void Personne::asgTelephone(const string& p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
}

/**
 * \brief Constructeur d'un nouvel objet de la classe Personne
 * \param[in] p_nom nom de la personne
 * \param[in] p_prenom prenom de la personne
 * \param[in] p_dateNaissance date de la naissance de la personne
 * \param[in] p_telephone numero de telephone qui respecte le format national
 * \pre p_nom, p_prenom, p_dateNaissance et p_telephone doivent correspondent à un format valide
 * \post l'objet courant a été correctement créé et assigné
 */
Personne::Personne(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
		const string& p_telephone) :
		m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
	PRECONDITION(util::validerFormatNom(p_prenom));
	PRECONDITION(util::validerFormatNom(p_prenom));
	PRECONDITION(util::validerTelephone(p_telephone));
	PRECONDITION(
			util::Date::validerDate(p_dateNaissance.reqJour(), p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee()));
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

} // namespace tp
