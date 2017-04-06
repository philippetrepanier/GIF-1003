/**
 * \file EntraineurTesteur.cpp
 * \brief Test unitaire de la classe Entraineur
 * \author Philippe Trepanier
 * \date 2017-04-06
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include "Entraineur.h"

using namespace std;
using namespace tp;
using namespace util;
/**
 * \defgroup EntraineurTesteur Test des classes pour Annuaire
 *	@{
 */
/**
 * \test Test du constructeur
 *
 * 		Cas valides: Création d'un objet Entraineur et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Prénom vide et sans chiffre
 *		    Nom vide et sans chiffre
 *		    Numero de RAMQ valide
 *		    Date invalide (mineur)
 *		    Numero de telephone valide
 *
 */
TEST(Entraineur,Constructeur)
{
	Entraineur UnEntraineur("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567", "TREP 9705 1819", 'M');

	ASSERT_EQ("Trepanier", UnEntraineur.reqNom());
	ASSERT_EQ("Philippe", UnEntraineur.reqPrenom());
	ASSERT_EQ(util::Date(18, 5, 1997), UnEntraineur.reqDateNaissance());
	ASSERT_EQ("418 123-4567", UnEntraineur.reqTelephone());
	ASSERT_EQ("TREP 9705 1819", UnEntraineur.reqNumRamq());
}

//cas invalide
TEST(Entraineur,ConstructeurInvalideNom)
{
	ASSERT_THROW(Entraineur UnEntraineur("", "Philippe", util::Date(18, 5, 1997), "418 123-4567", "TREP 9705 1819", 'M'),ContratException);
}
TEST(Entraineur,ConstructeurInvalidePrenom)
{
	ASSERT_THROW(Entraineur UnEntraineur("Trepanier", "", util::Date(18, 5, 1997), "418 123-4567", "TREP 9705 1819", 'M'),ContratException);
}
TEST(Entraineur,ConstructeurInvalideNumeroRamq)
{
	ASSERT_THROW(Entraineur UnEntraineur("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567", "TREP97051818", 'M'),ContratException);
}
TEST(Entraineur,ConstructeurInvalideDate)
{
	ASSERT_THROW(Entraineur UnEntraineur("Trepanier", "Philippe", util::Date(18, 5, 2007), "418 123-4567", "TREP 0705 1819", 'M'),ContratException);
}
TEST(Entraineur,ConstructeurInvalideNumeroTelephone)
{
	ASSERT_THROW(Entraineur UnEntraineur("Trepanier", "Philippe", util::Date(18, 5, 1997), "4181234567", "TREP 9705 1818", 'M'),ContratException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnEntraineur: public ::testing::Test
{
public:
	UnEntraineur() :
			entraineur("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567", "TREP 9705 1819", 'M')
	{
	}
	;
	Entraineur entraineur;
};

/**
 * \test Test de la méthode reqNom()
 *
 *     Cas valide: vérifier le retour du nom de famille.
 *     Cas invalide: aucun.
 */
TEST_F(UnEntraineur, reqNom)
{
	ASSERT_EQ("Trepanier",entraineur.reqNom());
}
/**
 * \test Test de la méthode reqPrenom()
 *
 *     Cas valide: vérifier le retour du prénom de l'entraineur
 *     Cas invalide: aucun
 */
TEST_F(UnEntraineur, reqPrenom)
{
	ASSERT_EQ("Philippe",entraineur.reqPrenom());
}

/**
 * \test Test de la méthode reqDateNaissance()
 *
 *     Cas valide: vérifier le retour de la date de naissance de l'entraineur
 *     Cas invalide: aucun
 */
TEST_F(UnEntraineur, reqDateNaissance)
{
	ASSERT_EQ(util::Date(18,5,1997),entraineur.reqDateNaissance());
}

/**
 * \test Test de la méthode reqDateNaissance()
 *
 *     Cas valide: vérifier le retour de la date de naissance de l'entraineur
 *     Cas invalide: aucun
 */
TEST_F(UnEntraineur, reqNumRamq)
{
	ASSERT_EQ("TREP 9705 1819",entraineur.reqNumRamq());
}

/**
 * \test Test de la méthode std::string reqEntraineurFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objets Entraineur formaté
 *        Cas invalides: aucun
 */
TEST_F(UnEntraineur,reqEntraineurFormate)
{

	ostringstream os;

	os << "Nom               : Trepanier" << endl;
	os << "Prenom            : Philippe" << endl;
	os << "Date de naissance : " << entraineur.reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone         : 418 123-4567" << endl;
	os << "Numero de RAMQ    : TREP 9705 1819" << endl;
	os << "---------------------" << endl;

	ASSERT_EQ(os.str(), entraineur.reqPersonneFormate());
}
/**
 * \test Test de la méthode clone();
 *
 *        Cas valides: vérifier la copie d'un objet avec la méthode clone()
 *        Cas invalides: aucun
 */
TEST_F(UnEntraineur, clone)
{
	Personne* clone = entraineur.clone();
	ASSERT_EQ(entraineur.reqPersonneFormate(), clone->reqPersonneFormate());
}

