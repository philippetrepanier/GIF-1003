/**
 * \file Entraineur.cpp
 * \brief Implémentation de la classe Entraineur.
 * \author Philippe Trépanier
 * \date 2017-03-28
 */

#include "Entraineur.h"
#include <sstream>
static const long JOURS_POUR_18_ANS = long(-18 * 365.25);

using namespace std;

namespace tp
{
/**
 * \brief Constructeur d'un nouvel objet de la classe Entraineur
 * \param[in] p_nom nom de l'entraineur
 * \param[in] p_prenom prenom de l'entraineur
 * \param[in] p_dateNaissance date de la naissance de l'entraineur
 * \param[in] p_telephone numero de telephone de l'entraineur
 * \pre p_nom, p_prenom, p_dateNaissance et p_telephone doivent correspondent à un format valide
 * \post m_nom prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 * \post m_dateNaissance prend la valeur de p_dateNaissance
 * \post m_telephone prend la valeur de p_telephone
 */
Entraineur::Entraineur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
		const std::string& p_telephone, const std::string& p_numRAMQ, char p_sexe) :
		Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_numRAMQ(p_numRAMQ), m_sexe(p_sexe)
{
	PRECONDITION(p_sexe == 'M' || p_sexe == 'F' || p_sexe == 'm' || p_sexe == 'f');
	PRECONDITION(
			util::validerNumRAMQ(p_numRAMQ, p_nom, p_prenom, p_dateNaissance.reqJour(), p_dateNaissance.reqMois(),
					p_dateNaissance.reqAnnee(), p_sexe));

	util::Date datePour18;
	datePour18.ajouteNbJour(JOURS_POUR_18_ANS);
	PRECONDITION(p_dateNaissance < datePour18);

	POSTCONDITION(m_numRAMQ == p_numRAMQ);
	POSTCONDITION(m_sexe == p_sexe);
	INVARIANTS();
}
Entraineur::~Entraineur()
{

}
/**
 * \brief Retourne une string contenant les informations contenues pour un entraineur
 * \return informations de l'entraineur
 */
std::string Entraineur::reqPersonneFormate() const
{
	ostringstream os;
	os << Personne::reqPersonneFormate();

	os << "Numero de RAMQ    : " << Entraineur::reqNumRamq() << endl;
	os << "---------------------" << endl;

	return os.str();
}
/**
 * \brief Retourne le numero de RAMQ de l'entraineur
 * \return informations de l'annuaire
 */
const std::string& Entraineur::reqNumRamq() const
{
	return m_numRAMQ;
}
/**
 * \brief Retourne un clone de l'objet entraineur
 * \return une copie de l'entraineur
 */
Personne* Entraineur::clone() const
{
	return new Entraineur(*this);
}
/**
 * \brief Vérifier les invariants de classe
 */
void Entraineur::verifieInvariant() const
{
	INVARIANT(m_sexe == 'M' || m_sexe == 'F' || m_sexe == 'm' || m_sexe == 'f');
	INVARIANT(
			util::validerNumRAMQ(m_numRAMQ, m_nom, m_prenom, m_dateNaissance.reqJour(), m_dateNaissance.reqMois(),
					m_dateNaissance.reqAnnee(), m_sexe));
}

} /* namespace tp */
