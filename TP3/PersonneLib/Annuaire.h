/**
 * \file Annuaire.h
 * \brief
 * \author Philippe Trépanier
 * \date 2017-03-29
 */

#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_
#include <string>
#include <vector>
#include "Joueur.h"
#include "Entraineur.h"

namespace tp
{

class Annuaire
{
public:
	Annuaire(const std::string& p_nomClub);
	~Annuaire();
	std::string reqNom() const;
	std::string reqAnnuaireFormate() const;

	void ajouterPersonne(const Personne& p_personne);

private:
	std::string m_nomClub;
	std::vector<Personne*> m_vMembres;

};

} /* namespace tp */

#endif /* ANNUAIRE_H_ */
