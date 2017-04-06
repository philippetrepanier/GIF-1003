/**
 * \file JoueurTesteur.cpp
 * \brief Test unitaire de la classe Joueur
 * \author Philippe Trepanier
 * \date 2017-04-05
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Joueur.h"
#include "Date.h"
using namespace tp;
using namespace std;
using namespace util;

/**
 * \defgroup JoueurTesteur Test des classes pour Annuaire
 *	@{
 */
/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Joueur et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		  		age < 15 ans
 *		  		age > 18 ans
 *		  		position = "Julie"
 *		  		numero de telephone = "911"
 *
 */
TEST(Joueur,ConstructeurDefaut)
{
	string nom = "Osborne";
	string prenom = "Julie";
	Date dateNaissance(29, 12, 2001);
	string numeroTelephone = "581 998-3333";
	string position = "CENTRE";

	Joueur unJoueur(nom, prenom, dateNaissance, numeroTelephone, position);

	ASSERT_EQ(nom, unJoueur.reqNom());
	ASSERT_EQ(prenom, unJoueur.reqPrenom());
	ASSERT_EQ(dateNaissance, unJoueur.reqDateNaissance());
	ASSERT_EQ(numeroTelephone, unJoueur.reqTelephone());
	ASSERT_EQ(position, unJoueur.reqPosition());
}
// CAS INVALIDE
TEST(Joueur,ConstructeurAgeInvalide)
{
	ASSERT_THROW(Joueur unJoueur("Osborne", "Julie", Date(12,12,2016), "418 656-2131", "CENTRE"), PreconditionException);
}
TEST(Joueur,ConstructeurAgeInvalide2)
{
	ASSERT_THROW(Joueur unJoueur("Osborne", "Julie", Date(12,12,1997), "418 656-2131", "CENTRE"), PreconditionException);
}
TEST(Joueur,ConstructeurPositionInvalide)
{
	ASSERT_THROW(Joueur unJoueur("Osborne", "Julie", Date(12,12,2001), "418 656-2131", "gauche"), PreconditionException);
}
TEST(Joueur,ConstructeurTelephoneInvalide)
{
	ASSERT_THROW(Joueur unJoueur("Osborne", "Julie", Date(12,12,2001), "911", "CENTRE"), PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe Joueur
 */
class UnJoueur: public ::testing::Test
{
public:
	UnJoueur() :
			unJoueur("NOM", "PRENOM", Date(12, 12, 2001), "418 656-2131", "CENTRE")
	{
	}
	;
	Joueur unJoueur;
};
/**
 * \test Test de la méthode reqPosition()
 *
 *     Cas valide: vérifier le retour de la position de Joueur
 *     Cas invalide: aucun
 */
TEST_F(UnJoueur, reqPosition)
{
	ASSERT_EQ("CENTRE",unJoueur.reqPosition());
}
/**
 * \test Test de la méthode reqPersonneFormate()
 *
 *     Cas valide: vérifier le retour des informations sur la Personne
 *     Cas invalide: aucun
 */
TEST_F(UnJoueur, reqPersonneFormate)
{
	ostringstream os;
	os << "Nom               : " << "NOM" << endl;
	os << "Prenom            : " << "PRENOM" << endl;
	os << "Date de naissance : " << unJoueur.reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone         : " << "418 656-2131" << endl;
	os << "Position          : " << "CENTRE" << endl;
	os << "---------------------" << endl;

	ASSERT_EQ(os.str(), unJoueur.reqPersonneFormate());
}
/** @} Fin defgroup*/
