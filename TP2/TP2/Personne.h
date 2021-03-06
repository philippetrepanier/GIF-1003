/**
 * \file Personne.h
 * \brief Fichier qui déclare la classe personne cotenant les informations d'un joueur de hockey faisant partie de l'équipe
 * \author Philippe Trepanier
 * \date 2017-02-19
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>
#include "Date.h"
#include "validationFormat.h"

namespace tp
{
/**
 * \class Personne
 * \brief Classe personne qui contient les informations d'un jouer de l'équipe
 *        Elle contient le nom complet, la date de naissance, le numero de telephone.
 *        Une méthode permet de renvoyer une personne formatée et de changer le numero de telephone
 *
 */
class Personne
{
public:
	Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			const std::string& p_telephone);

	//Getters
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	const util::Date reqDateNaissance() const;
	const std::string& reqTelephone() const;
	std::string reqPersonneFormate() const;

	//Setters
	void asgTelephone(const std::string& p_telephone);

	//Surcharges
	bool operator==(const Personne& p_personne) const;

private:
	std::string m_nom;
	std::string m_prenom;
	util::Date m_dateNaissance;
	std::string m_telephone;

};
} // namespace tp
#endif /* PERSONNE_H_ */
