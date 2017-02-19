/**
 * \file Personne.h
 * \brief
 * \author etudiant
 * \date 2017-02-19
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>
#include "Date.h"

namespace tp
{
/**
 * \class Personne
 * \brief Classe personne qui contient les informations d'un jouer de l'équipe
 */
class Personne
{
public:
	Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			const std::string& p_telephone);

	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	util::Date reqDateNaissance() const;
	const std::string& reqTelephone() const;
	void asgTelephone(const std::string& telephone);

private:
	std::string m_nom;
	std::string m_prenom;
	std::string p_telephone;
	util::Date p_dateNaissance;

};
} // namespace tp
#endif /* PERSONNE_H_ */