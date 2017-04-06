/**
 * \file AnnuaireTesteur.cpp
 * \brief Test unitaire de la classe Annuaire
 * \author Philippe Trépanier
 * \date 2017-04-06
 */

#include "Annuaire.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;
using namespace util;
using namespace tp;
/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Annuaire avec un nom de club valide
 *		  Cas invalides:
 *		  		Nom de club invalide
 */
TEST(Annuaire, AnnuaireConstructeur)
{
	string nomClub = "unClub";
	Annuaire annuaire(nomClub);
	ASSERT_EQ(nomClub, annuaire.reqNom());
}
// cas invalide
TEST(Annuaire, AnnuaireConstructeurInvalide)
{
	string nomClub = "";
	ASSERT_THROW(Annuaire annuaire(nomClub), PreconditionException);
}
/**
 * \test Test de la méthode reqAnnuaireFormate()
 *
 *     Cas valide: vérifier le retour des informations sur l'Annuaire
 *     Cas invalide: aucun
 */
TEST(Annuaire, AnnuaireReqAnnuaireFormate)
{
	string nomClub = "unClub";
	Annuaire annuaire(nomClub);

	ostringstream os;
	os << "Club : " << nomClub << endl;
	os << "---------------------" << endl;

	ASSERT_EQ(os.str(), annuaire.reqAnnuaireFormate());
}
/**
 * \brief Création d'une fixture à utiliser pour les méthodes de la classe Annuaire
 */
class AnnuaireParam: public ::testing::Test
{
public:
	AnnuaireParam() :
			annuaire("NOM DU CLUB")
	{
	}

protected:
	string nomClub = "NOM DU CLUB";

	string nom_joueur = "Hockey";
	string prenom_joueur = "Joueur";
	Date dateNaissance_joueur = Date(5, 5, 2001);
	string telephone_joueur = "418 658-2222";
	string position_joueur = "CENTRE";

	string nom_ent = "Thibault";
	string prenom_ent = "Marc";
	Date dateNaissance_ent = Date(5, 5, 1980);
	string telephone_ent = "418 656-2177";
	char sexe_ent = 'M';
	string RAMQ_ent = "THIM 8005 0522";

	Annuaire annuaire;

	virtual void SetUp()
	{
		annuaire = Annuaire(nomClub);
		annuaire.ajouterPersonne(
				Joueur(nom_joueur, prenom_joueur, dateNaissance_joueur, telephone_joueur, position_joueur));
		annuaire.ajouterPersonne(Entraineur(nom_ent, prenom_ent, dateNaissance_ent, telephone_ent, RAMQ_ent, sexe_ent));

	}

};
/**
 * \test Test de la méthode reqNom()
 *
 *     Cas valide: vérifier le retour de la fonction reqNom()
 *     Cas invalide: aucun
 */
TEST_F(AnnuaireParam, reqNomFixture)
{
	ASSERT_EQ(nomClub,annuaire.reqNom());
};
/**
 * \test Test de la méthode reqAnnuaireFormate()
 *
 *     Cas valide: vérifier le retour des informations de l'annuaire
 *     Cas invalide: aucun
 */
TEST_F(AnnuaireParam, reqAnnuaireFormate)
{
	ostringstream os;
	os << "Club : " << annuaire.reqNom() << endl;
	os << "---------------------" << endl;
	os << Joueur(nom_joueur, prenom_joueur, dateNaissance_joueur, telephone_joueur, position_joueur).reqPersonneFormate();
	os << Entraineur(nom_ent, prenom_ent, dateNaissance_ent, telephone_ent, RAMQ_ent, sexe_ent).reqPersonneFormate();

	ASSERT_EQ(os.str(), annuaire.reqAnnuaireFormate());
};

