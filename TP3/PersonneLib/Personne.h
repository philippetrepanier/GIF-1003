/**
 * \file Personne.h
 * \brief Fichier qui déclare la classe personne contenant les informations d'un membre partie de l'équipe
 * \author Philippe Trepanier
 * \date 2017-02-19
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>
#include "Date.h"
#include "validationFormat.h"
#include "ContratException.h"

namespace tp
{
/**
 * \class Personne
 * \brief Classe personne qui contient les informations d'un jouer de l'équipe
 *        Elle contient le nom complet, la date de naissance, le numero de telephone.
 *        Une méthode permet de renvoyer une personne formatée et de changer le numero de telephone
 *		Classe purement virtuelle
 */
class Personne
{
public:
	Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			const std::string& p_telephone);

	virtual ~Personne()
	{
	}
	;

	virtual Personne* clone() const = 0;

	//Getters
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	const util::Date reqDateNaissance() const;
	const std::string& reqTelephone() const;
	virtual std::string reqPersonneFormate() const;

	//Setters
	void asgTelephone(const std::string& p_telephone);

	//Surcharges
	bool operator==(const Personne& p_personne) const;

protected:

	std::string m_nom;
	std::string m_prenom;
	util::Date m_dateNaissance;
	std::string m_telephone;
private:

	void verifieInvariant() const;
};
} // namespace tp
#endif /* PERSONNE_H_ */
