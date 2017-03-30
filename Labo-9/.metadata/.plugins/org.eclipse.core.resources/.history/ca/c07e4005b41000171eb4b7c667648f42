/**
 * \file Employe.h
 * \brief Classe de base abstraite Employe
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */
#ifndef EMPLOYE_H_
#define EMPLOYE_H_

#include "Date.h"
#include "ContratException.h"

namespace labo10
{
/**
 * \class Employe
 * \brief Classe de base
 */
class Employe
{
public:

	Employe(const std::string& p_nom, const std::string& p_prenom);
	virtual ~Employe(){};

	//Accesseurs
	std::string reqPrenom() const;
	std::string reqNomFamille() const;


   virtual double gains() const;
   virtual std::string reqEmployeFormate() const; // virtuelle.

private:
     std::string m_nomFamille;
   	 std::string m_prenom;

};

}
#endif /* EMPLOYE_H_ */
