/**
 * \file Employe.cpp
 * \brief Implémentation de la classe de base abstraite Employe.
 *        Note: aucune définition de la méthode virtuelle pure.
 * \author etudiant
 * \version 0.1
 * \date 2015-03-19
 */

#include "Employe.h"
#include <iostream>

using namespace std;
namespace labo10
{
/**
 * \brief Constructeur avec paramètre.
 *        Création d'un objet Employe à partir de valeurs passées en paramètres.
 * \param[in] p_nom est un string qui représente le nom de l'employé.
 * \param[in] p_prenom est un string qui représente le prénom de l'employé.
 * \param[in] p_dateNaissance est une date qui représente la date de naissance de l'employé.
 * \param[in] p_codeDepartement est un entier qui représente le code départemental de l'employé
 * \pre p_nom non vide
 * \pre p_prenom non vide
 * \pre p_codeDepartement supérieur à 0
 * \post m_nomFamille prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 * \post m_codeDepartement prend la valeur de p_codeDepartement
 * \post m_dateNaissance prend la valeur de p_dateNaissance
 */
Employe::Employe(const std::string& p_nom, const std::string& p_prenom)
          : m_nomFamille(p_nom), m_prenom(p_prenom)
{

}
/**
 * \brief Accesseur prénom de l'employé
 * \return le prénom
 */
std::string Employe::reqPrenom() const
{
	return m_prenom;
}
/**
 * \brief Accesseur nom de l'employé
 * \return le nom de famille
 */
std::string Employe::reqNomFamille() const
{
	return m_nomFamille;
}

/**
 * \brief Lit la paie de l'employé.
 *         methode virtuelle
 * \return les gains de l'employé
 */
double Employe::gains() const
{
	return 0;
}
/**
 * \brief Affichage du nom et prénom de l'employé.
 * \return Le nom et prénom de l'employé.
 */
std::string Employe::reqEmployeFormate() const
{
	return m_prenom + " " + m_nomFamille;
}

}
