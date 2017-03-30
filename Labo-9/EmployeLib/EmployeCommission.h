/**
 * \file EmployeCommission.h
 * \brief Classe EmployeCommission, dérivée de la classe Employe.
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */

#ifndef EMPLOYECOMMISSION_H_
#define EMPLOYECOMMISSION_H_

#include "Employe.h"

namespace labo10
{
/**
 * \class EmployeCommission
 * \brief Classe dérivée de la classe Employe
 */
class EmployeCommission: public Employe {
public:

	EmployeCommission(const std::string& p_nom, const std::string& p_prenom,
				double p_salaire = 0.0,
				double p_commission = 0.0, int p_quantite = 0);

   // ajout des accesseurs
    double reqSalaire() const;
   	double reqCommission() const;
   	int reqQuantite() const;

   	void asgSalaire( double p_salaire );
   	void asgCommission( double p_commission);
   	void asgQuantite( int p_quantite);

   virtual double gains() const;
   virtual std::string reqEmployeFormate() const;

private:

   double m_salaire;      // salaire hebdomadaire de base.
   double m_commission;   // montant par article vendu.
   int m_quantite;        // total d'articles vendus pour la semaine.

};

}  // namespace labo10

#endif /* EMPLOYECOMMISSION_H_ */
