/**
 * \file EmployeHoraire.cpp
 * \brief Implémentation de la classe EmployeHoraire
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */

#include <iostream>
#include <sstream>
#include "EmployeHoraire.h"

namespace labo10
{
/**
 * \brief Constructeur avec paramètre
 *        Création d'un objet EmployeHoraire à partir de valeurs passées en paramètres.
 * \param[in] p_nom nom de l'employe
 * \param[in] p_prenom prenom de l'employe
 * \param[in] p_tauxHoraire taux hortaire du salaire
 * \param[in] p_dateNaissance date de naissance de l'employe
 * \param[in] p_heures nombre d'heures travaillées
 * \param[in] p_codeDepartement code du departement auquel appartient l'employe
 * \pre p_tauxHoraire > 0
 * \pre p_heure > 0
 * \post m_tauxHoraire prend la valeur de p_tauxHoraire
 * \post m_heure prend la valeur de p_heure
 */
EmployeHoraire::EmployeHoraire(const std::string& p_nom,
		const std::string& p_prenom,double p_tauxHoraire, double p_heures) :
			Employe(p_nom, p_prenom),
			m_tauxHoraire(p_tauxHoraire), m_heures(p_heures) // appelle du constructeur de la classe de base.
{

}
/**
 * \brief Accesseur sur le taux horaire de l'employé
 * \return le taux horaire
 */
double EmployeHoraire::reqTauxHoraire() const
{
	return m_tauxHoraire;
}
/**
 * \brief Accesseur sur les heures de travail de l'employé
 * \return les heures de travail
 */
double EmployeHoraire::reqHeure() const
{
	return m_heures;
}
/**
 * \brief Ajuste le taux horaire.
 * \param[in] p_tauxHoraire le nouveau taux horaire de l'employé.
 * \pre p_tauxHoraire > 0
 * \post m_tauxHoraire prend la valeur de p_tauxHoraire
 */
void EmployeHoraire::asgPaie( double p_tauxHoraire )
{

	m_tauxHoraire = p_tauxHoraire > 0 ? p_tauxHoraire: 0;

}
/**
 * \brief Ajuste les heures travaillées.
 * \param[in] p_heuresTravaillees nouveau nombre d'heures travaillées de l'employé.
 * \pre p_heure > 0
 * \post m_heure prend la valeur de p_heure
 */
void EmployeHoraire::asgHeures( double p_heuresTravaillees )
{

	m_heures = p_heuresTravaillees >= 0 && p_heuresTravaillees < 168 ? p_heuresTravaillees: 0;

}
/**
 * \brief retourne la paie de l'EmployeHoraire.
 *        methode virtuelle
 * \return les gains de l'employé
 */
double EmployeHoraire::gains() const
{
   double gainsEmploye;
   if ( m_heures <= 40 ) // pas de temps supplémentaire.
	   gainsEmploye = m_tauxHoraire * m_heures;
   else
	   // temps supplémentaire = temps et demi.
	   gainsEmploye = 40 * m_tauxHoraire + (m_heures - 40) * m_tauxHoraire* 1.5;
   return gainsEmploye;
}
/**
 * \brief Affiche les informations de l'employé horaire sous forme d'une chaîne de caractère formatée
 * \return les informations sur un employé
 */
std::string EmployeHoraire::reqEmployeFormate() const
{
	std::ostringstream os;
	os << std::endl << " Employé horaire : ";
	os << Employe::reqEmployeFormate(); // appel de la méthode reqEmployeFormate de la classe parent Employe
	return os.str();
}


} // namespace labo10
