/**
 * \file EmployeHoraire.h
 * \brief Déclaration de la classe EmployeHoraire héritant de la classe Employe
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */

#ifndef EMPLOYEHORAIRE_H_
#define EMPLOYEHORAIRE_H_

#include "Employe.h"

namespace labo10
{
/**
 * \class EmployeHoraire
 * \brief Classe dérivée de la classe Employe
 */
class EmployeHoraire: public Employe {
public:
   EmployeHoraire( const std::string& p_nom, const std::string& p_prenom,
		   	   	   double p_tauxHoraire= 0.0, double p_heures= 0.0);

   double reqTauxHoraire() const;
   double reqHeure() const;
   void asgPaie( double p_tauxHoraire );
   void asgHeures( double p_heuresTravaillees );
   virtual double gains() const;

   virtual std::string reqEmployeFormate() const;

private:
   double m_tauxHoraire; // taux horaire.
   double m_heures;      // m_heures travaillées pour la semaine.
};


}  // namespace labo10

#endif /* EMPLOYEHORAIRE_H_ */
