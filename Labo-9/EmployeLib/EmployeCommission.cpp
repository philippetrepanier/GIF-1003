/**
 * \file EmployeCommission.cpp
 * \brief Implémentation de la classe EmployeCommission.
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */

#include <iostream>
#include <sstream>
#include "EmployeCommission.h"

using namespace std;
namespace labo10
{
/**
 * \brief Constructeur avec paramètre
 *        Création d'un objet EmployeCommission à partir de valeurs passées en paramètres.
 * \param[in] p_nom nom de l'employe
 * \param[in] p_prenom prenom de l'employe
 * \param[in] p_dateNaissance date de naissance de l'employe
 * \param[in] p_salaire salaire de l'employe
 * \param[in] p_commission commission de l'employe
 * \param[in] p_quantite quantité de l'employe
 * \param[in] p_codeDepartement code du departement auquel appartient l'employe
 * \pre p_salaire > 0
 * \pre p_commission >= 0
 * \pre p_quantite >= 0
 * \post m_salaire prend la valeur de p_salaire
 * \post m_commission prend la valeur de p_commission
 * \post m_quantite prend la valeur de p_quantite
 */
EmployeCommission::EmployeCommission(const std::string& p_nom,
		const std::string& p_prenom,
		double p_salaire, double p_commission, int p_quantite) :
	Employe(p_nom, p_prenom),m_salaire(p_salaire), m_commission(p_commission), m_quantite(p_quantite)
{

}
/**
 * \brief Accesseur sur le salaire de l'employé.
 * \return le salaire
 */
double EmployeCommission::reqSalaire() const
{
	return m_salaire;
}
/**
 * \brief Accesseur sur la commission de l'employé.
 * \return la commission
 */
double EmployeCommission::reqCommission() const
{
	return m_commission;
}
/**
 * \brief Accesseur sur la quantité.
 * \return la quantité.
 */
int EmployeCommission::reqQuantite() const
{
	return m_quantite;
}
/**
 * \brief Ajuste le salaire de base hebdo de l'EmployeCommission
 * \param[in] p_salaire salaire de l'employe
 * \pre p_salaire > 0
 * \post m_salaire prend la valeur de p_salaire
 */
void EmployeCommission::asgSalaire( double p_salaire )
{

	m_salaire = p_salaire > 0 ? p_salaire: 0;

}
/**
 * \brief Ajuste la commission de l'EmployeCommission
 * \param[in] p_commission commission de l'employe
 * \pre p_commission >= 0
 * \post m_commission prend la valeur de p_commission
 */
void EmployeCommission::asgCommission( double p_commission )
{

	m_commission = p_commission > 0 ? p_commission: 0;

}
/**
 * \brief Ajustement de la quantité de l'EmployeCommission
 * \param[in] p_quantite quantité de l'employé
 * \pre p_quantite >= 0
 * \post m_quantite prend la valeur de p_quantite
 */
void EmployeCommission::asgQuantite( int p_quantite )
{

	m_quantite = p_quantite > 0 ? p_quantite: 0;

}
/**
 * \brief retourne la paie de l'EmployeCommission.
 *        methode virtuelle
 * \return les gains de l'employé
 */
double EmployeCommission::gains() const
{
	return m_salaire + m_commission * m_quantite;
}
/**
 * \brief Affiche les informations de l'employé commission sous forme d'une chaîne de caractère formatée
 * \return les informations sur un employé
 */
std::string EmployeCommission::reqEmployeFormate() const
{
    ostringstream os;
   	os << std::endl << " Employé à commission: ";
   	os << Employe::reqEmployeFormate();
   	return os.str();
}


} // namespace labo10
