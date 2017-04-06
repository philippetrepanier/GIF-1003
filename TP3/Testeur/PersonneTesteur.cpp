/**
 * \file PersonneTesteur.cpp
 * \brief Test unitaire de la classe Personne
 * \author Philippe Trépanier
 * \date 2017-04-06
 */

#include "Personne.h"
#include <gtest/gtest.h>

using namespace tp;
using namespace util;
using namespace std;

/**
 * \brief Création d'une fixture à utiliser pour les méthodes publiques de la classe de Personne virtuelle pure
 */

class PersonneImpl: public Personne
{
public:

	PersonneImpl(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
			const string& p_telephone) :
			Personne(p_nom, p_prenom, p_dateNaissance, p_telephone)
	{
	}
	virtual PersonneImpl* clone() const
	{
		return PersonneImpl::clone();
	}
};

/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Personne et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		  		Nom invalide
 *		  		Prenom invalide
 *		  		Telephone invalide
 *		  		Date Invalide
 */
TEST(Personne,ConstructeurParDefaut)
{
	PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567");

	ASSERT_EQ("Trepanier", unePersonne.reqNom());
	ASSERT_EQ("Philippe", unePersonne.reqPrenom());
	ASSERT_EQ(util::Date(18, 5, 1997), unePersonne.reqDateNaissance());
	ASSERT_EQ("418 123-4567", unePersonne.reqTelephone());
}
//cas invalide
TEST(Personne,ConstructeurInvalideNom)
{
	ASSERT_THROW(PersonneImpl unePersonne("Trepanier", "1", util::Date(18, 5, 1997), "418 123-4567"),ContratException);

}
TEST(Personne,ConstructeurInvalidePrenom)
{
	ASSERT_THROW(PersonneImpl unePersonne("1", "Philippe", util::Date(18, 5, 1997), "418 123-4567"),ContratException);

}
TEST(Personne,ConstructeurInvalideTelephone)
{
	ASSERT_THROW(PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 12389-4567"),ContratException);

}
TEST(Personne,ConstructeurInvalideDate)
{
	ASSERT_THROW(PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(1, 10, 1900), "418 123-4567"),ContratException);

}

/**
 * \test Test de la surcharge de l'opérateur égal égal
 *
 * 		  Cas valides: Création de deux objets Personne et vérification de la surcharge ==
 *		  Cas invalides:
 *		  		Deux objets non égaux
 */
TEST(Personne,OperateurEgalEgal)
{
	PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567");
	PersonneImpl deuxPersonne("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567");

	ASSERT_EQ(true, unePersonne==deuxPersonne);
}
// cas invalide
TEST(Personne,OperateurEgalEgalInvalide)
{
	PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567");
	PersonneImpl deuxPersonne("Trepanier", "Phil", util::Date(18, 5, 1997), "418 123-4567");

	ASSERT_EQ(false, unePersonne==deuxPersonne);
}
/**
 * \brief Création d'une fixture à utiliser pour les méthodes de la classe Personne
 */
class PersonneParam: public ::testing::Test
{
public:
	PersonneParam() :
			personneTest("test", "test", Date(2, 4, 2000), "418 666-6666")
	{
	}

protected:
	string nom;
	string prenom;
	Date dateNaissance;
	string telephone;

	PersonneImpl personneTest;

	virtual void SetUp()
	{
		nom = "Trepanier";
		prenom = "Philippe";
		dateNaissance = Date(18, 5, 1997);
		telephone = "418 123-4567";
		personneTest = PersonneImpl(nom, prenom, dateNaissance, telephone);
	}

	virtual void TearDown()
	{
		// ménage
	}
};
/**
 * \test Test de la méthode reqPersonneFormate()
 *
 *     Cas valide: vérifier le retour des informations de la personne
 *     Cas invalide: aucun
 */
TEST_F(PersonneParam, reqPersonneFormate)
{
	ostringstream os;

	os << "Nom               : Trepanier" << endl;
	os << "Prenom            : Philippe" << endl;
	os << "Date de naissance : " << personneTest.reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone         : " << "418 123-4567" << endl;

	ASSERT_EQ(os.str(), personneTest.reqPersonneFormate());
}

