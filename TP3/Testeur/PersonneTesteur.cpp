/**
 * \file PersonneTesteur.cpp
 * \brief
 * \author Philippe Trépanier
 * \date 2017-04-06
 */

#include "Personne.h"
#include <gtest/gtest.h>

using namespace tp;
using namespace util;
using namespace std;

/**
 * \brief Création d'une fixture à utiliser pour les méthodes publiques de la classe de test
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

TEST(Personne,ConstructeurParDefaut)
{
	PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 123-4567");

	ASSERT_EQ("Trepanier", unePersonne.reqNom());
	ASSERT_EQ("Philippe", unePersonne.reqPrenom());
	ASSERT_EQ(util::Date(18, 5, 1997), unePersonne.reqDateNaissance());
	ASSERT_EQ("418 123-4567", unePersonne.reqTelephone());
}

//cas invalide
TEST(Employe,ConstructeurInvalideNom)
{
	ASSERT_THROW(PersonneImpl unePersonne("Trepanier", "", util::Date(18, 5, 1997), "418 123-4567"),ContratException);

}
TEST(Employe,ConstructeurInvalidePrenom)
{
	ASSERT_THROW(PersonneImpl unePersonne("", "Philippe", util::Date(18, 5, 1997), "418 123-4567"),ContratException);

}
TEST(Employe,ConstructeurInvalideTelephone)
{
	ASSERT_THROW(PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(18, 5, 1997), "418 12389-4567"),ContratException);

}
TEST(Employe,ConstructeurInvalideDate)
{
	ASSERT_THROW(PersonneImpl unePersonne("Trepanier", "Philippe", util::Date(1, 10, 1900), "418 123-4567"),ContratException);

}

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

TEST_F(PersonneParam, reqPersonneFormate)
{
	ostringstream os;

	os << "Nom               : Trepanier" << endl;
	os << "Prenom            : Philippe" << endl;
	os << "Date de naissance : " << personneTest.reqDateNaissance().reqDateFormatee() << endl;
	os << "Telephone         : " << "418 123-4567" << endl;

	ASSERT_EQ(os.str(), personneTest.reqPersonneFormate());
}

