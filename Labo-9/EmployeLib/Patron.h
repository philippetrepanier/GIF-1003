/**
 * \file Patron.h
 * \brief Classe Patron, dérivée de la classe Employe.
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */

#ifndef PATRON_H_
#define PATRON_H_

#include "Employe.h"

namespace labo10
{
/**
 * \class Patron
 * \brief Classe dérivée de la classe Employe
 */
class Patron: public Employe
{
public:
	Patron(const std::string& p_nom, const std::string& p_prenom,
			 double p_salaireHebdo = 0.0);

	void asgSalaireHebdo(double p_salaireHebdo);
	virtual double gains() const;
	virtual std::string reqEmployeFormate() const;

private:
	double m_salaireHebdo;

};

}  // namespace labo10

#endif /* PATRON_H_ */
