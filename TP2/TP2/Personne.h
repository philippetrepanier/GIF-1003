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
#include "validationFormat.h"

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

	//Getters
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	util::Date reqDateNaissance() const;
	const std::string& reqTelephone() const;
	const std::string reqPersonneFormate() const;

	//Setters
	void asgTelephone(const std::string& telephone);

	//Surcharge
	bool operator==(const Personne& p_personne) const;

private:
	std::string m_nom;
	std::string m_prenom;
	util::Date m_dateNaissance;
	std::string m_telephone;

};
} // namespace tp
#endif /* PERSONNE_H_ */
