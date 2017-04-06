/**
 * \file Entraineur.h
 * \brief Classe Entraineur, dérivée de la classe Personne
 * \author Philippe Trépanier
 * \date 2017-03-28
 */

#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_

#include "Personne.h"

namespace tp
{
/**
 * \class Entraineur
 * \param Classe entraineur dérivée de la classe Personne
 */
class Entraineur: public Personne
{
public:
	Entraineur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
			const std::string& p_telephone, const std::string& p_numRAMQ, char p_sexe);
	virtual ~Entraineur();

	virtual std::string reqPersonneFormate() const;
	const std::string& reqNumRamq() const;

	virtual Personne* clone() const;

private:
	void verifieInvariant() const;
	std::string m_numRAMQ;
	char m_sexe;

};

} /* namespace tp */

#endif /* ENTRAINEUR_H_ */
