/**
 * \file Joueur.h
 * \brief Classe Joueur, dérivée de la classe Joueur.
 * \author Philippe Trépanier
 * \date 2017-03-29
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include "Personne.h"

namespace tp
{
/**
 * \class Joueur
 * \param Classe dérivée de la classe Personne
 */
class Joueur: public Personne
{
public:
	Joueur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			const std::string& p_telephone, const std::string& p_position);

	virtual ~Joueur();
	virtual std::string reqPersonneFormate() const;
	virtual Personne* clone() const;

	const std::string& reqPosition() const;

private:
	void verifieInvariant() const;
	std::string m_position;
};

} /* namespace tp */

#endif /* JOUEUR_H_ */
