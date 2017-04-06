/**
 * \file Annuaire.h
 * \brief Classe Annuaire
 * \author Philippe Trépanier
 * \date 2017-03-29
 */

#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_
#include <string>
#include <vector>
#include "Joueur.h"
#include "Entraineur.h"
#include "ContratException.h"

namespace tp
{
/**
 * \class Annuaire
 * \brief Classe annuaire qui contient les Joueurs et les Entraineurs de l'équipe
 * 			Elle contient un attribut avec le nom du club.
 * 	        Une méthode permet de renvoyer l'annuaire sous une chaine de caractère formatée
 */
class Annuaire
{
public:
	Annuaire(const std::string& p_nomClub);
	~Annuaire();
	std::string reqNom() const;
	std::string reqAnnuaireFormate() const;

	void ajouterPersonne(const Personne& p_personne);

private:
	void verifieInvariant() const;
	std::string m_nomClub;
	std::vector<Personne*> m_vMembres;

};

} /* namespace tp */

#endif /* ANNUAIRE_H_ */
