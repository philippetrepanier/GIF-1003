/**
 * \file Joueur.cpp
 * \brief Implémentation de la classe Joueur.
 * \author Philippe Trépanier
 * \date 2017-03-29
 */

#include "Joueur.h"
#include <sstream>
static const long JOURS_POUR_18_ANS = long(-18 * 365.25);
static const long JOURS_POUR_15_ANS = long(-15 * 365.25);

using namespace std;

namespace tp
{

Joueur::~Joueur()
{
}
/**
 * \brief Constructeur avec paramètre
 *        Création d'un objet Joueur à partir de valeurs passées en paramètres.
 * \param[in] p_nom nom du Joueur
 * \param[in] p_prenom prenom du Joueur
 * \param[in] p_dateNaissance date de naissance du Joueur
 * \param[in] p_telephone numero de telephone du Joueur
 * \param[in] p_position position du Joueur
 * \pre p_position est parmi la liste suivante: CENTRE, AILIER, DEFENSEUR, GARDIEN
 * \pre p_heure > 0
 * \post m_tauxHoraire prend la valeur de p_tauxHoraire
 * \post m_heure prend la valeur de p_heure
 */
Joueur::Joueur(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
		const string& p_telephone, const string& p_position) :
		Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_position(p_position)
{
	string p_positionUpper(p_position);
	util::convertitEnMajuscules(p_positionUpper);
	PRECONDITION(
			p_positionUpper == "CENTRE" || p_positionUpper == "AILIER" || p_positionUpper == "DEFENSEUR"
					|| p_positionUpper == "GARDIEN");

	util::Date datePour18;
	util::Date datePour15;
	datePour18.ajouteNbJour(JOURS_POUR_18_ANS);
	datePour15.ajouteNbJour(JOURS_POUR_15_ANS);
	PRECONDITION(datePour18 < p_dateNaissance);
	PRECONDITION(p_dateNaissance < datePour15);

	POSTCONDITION(m_position == p_position);
	INVARIANTS();
}
/**
 * \brief Affiche les informations du joueur sous forme d'une chaîne de caractère formatée
 * \return les informations sur un joueur
 */
string Joueur::reqPersonneFormate() const
{
	ostringstream os;
	os << Personne::reqPersonneFormate();

	os << "Position          : " << Joueur::reqPosition() << endl;
	os << "---------------------" << endl;

	return os.str();
}
/**
 * \brief Permet la copie d'un Joueur
 * \return objet copié
 */
Personne* Joueur::clone() const
{
	return new Joueur(*this);
}
/**
 * \brief Accesseur sur la position d'un joueur
 * \return la position
 */
const string& Joueur::reqPosition() const
{
	return m_position;
}
/**
 * \brief Vérifier les invariants de classe
 */
void Joueur::verifieInvariant() const
{
	string m_positionUpper(m_position);
	util::convertitEnMajuscules(m_positionUpper);
	INVARIANT(
			m_positionUpper == "CENTRE" || m_positionUpper == "AILIER" || m_positionUpper == "DÉFENSEUR"
					|| m_positionUpper == "GARDIEN");

}

} /* namespace tp */

