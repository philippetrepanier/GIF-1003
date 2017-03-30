/**
 * \file Patron.cpp
 * \brief Implémentation de la classe Patron.
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */

#include <iostream>
#include <sstream>
#include "Patron.h"

using namespace std;
namespace labo10
{

/**
 * \brief Constructeur avec paramètre
 *        Création d'un objet Patron à partir de valeurs passées en paramètres.
 * \param[in] p_nom nom de l'employe
 * \param[in] p_prenom prenom de l'employe
 * \param[in] p_dateNaissance date de naissance de l'employe
 * \param[in] p_salaireHebdo salaire hébdomadaire de l'employe
 * \param[in] p_codeDepartement code du departement auquel appartient l'employe
 * \pre p_salaireHebdo > 0
 * \post m_salaireHebdo prend la valeur de p_salaireHebdo
 */
Patron::Patron(const std::string& p_nom, const std::string& p_prenom,
		 double p_salaireHebdo)
       : Employe( p_nom, p_prenom), m_salaireHebdo(p_salaireHebdo) // appelle constructeur de classe de base.
{

}
/**
 * \brief Ajuste le salaire du Patron
 * \param[in] p_salaireHebdo salaire hébdomadaire de l'employe
 * \pre p_salaireHebdo > 0
 * \post m_salaireHebdo prend la valeur de p_salaireHebdo
 */
void Patron::asgSalaireHebdo( double p_salaireHebdo )
{

	m_salaireHebdo = p_salaireHebdo > 0 ? p_salaireHebdo: 0;

}
/**
 * \brief Lit la paie du Patron.
 *         methode virtuelle
 * \return les gains de l'employé
 */
double Patron::gains() const
{
	return m_salaireHebdo;
}
/**
 * \brief Affiche les informations du Patron sous forme d'une chaîne de caractère formatee
 * \return les informations sur un employé
 */
std::string Patron::reqEmployeFormate() const
{
	ostringstream os;
	os << std::endl << " Patron : ";
	os << Employe::reqEmployeFormate();
	return os.str();
}


}  // namespace labo10
