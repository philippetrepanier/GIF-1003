/**
 * \file Joueur.cpp
 * \brief Implémentation de la classe Joueur.
 * \author Philippe Trépanier
 * \date 2017-03-29
 */

#include "Joueur.h"
#include <sstream>

using namespace std;

namespace tp
{

Joueur::~Joueur()
{
}

Joueur::Joueur(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
		const string& p_telephone, const string& p_position) :
		Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_position(p_position)
{
	PRECONDITION();

	util::Date datePour18;
	datePour18.ajouteNbJour(JOURS_POUR_18_ANS);
	PRECONDITION(p_dateNaissance < datePour18);

	POSTCONDITION(m_position == p_position);
	INVARIANTS();
}

string Joueur::reqPersonneFormate() const
{
	ostringstream os;
	os << Personne::reqPersonneFormate();

	os << "Position          : " << Joueur::reqPosition() << endl;
	os << "---------------------" << endl;

	return os.str();
}

Personne* Joueur::clone() const
{
	return new Joueur(*this);
}

const string& Joueur::reqPosition() const
{
	return m_position;
}

} /* namespace tp */
