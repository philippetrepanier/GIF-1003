/**
 * \file Annuaire.h
 * \brief
 * \author etudiant
 * \date 2017-03-29
 */

#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_
#include <string>
#include <vector>
#include "Personne.h"

namespace tp
{

class Annuaire
{
public:
	Annuaire(std::string p_nomClub);
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
