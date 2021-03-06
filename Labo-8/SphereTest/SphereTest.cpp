/**
 * \file SphereTest.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-19
 */

#include "Sphere.h"
#include <gtest/gtest.h>
#include <cmath>

using namespace labo8;
using namespace std;

TEST(Sphere, SphereConstructeur)
{
	Sphere test;
	ASSERT_EQ(0, test.reqRayon());
}

TEST(Sphere, SphereConstructeurUnparam)
{
	double rayonEnvoye = 5;
	Sphere test(rayonEnvoye);
	ASSERT_EQ(rayonEnvoye, test.reqRayon());
}

class SphereTest: public ::testing::Test
{
protected:
	Sphere sphere2;
	double rayon;

	virtual void SetUp()
	{
		rayon = 5.0;
		sphere2 = Sphere(rayon);
	}
};

TEST_F(SphereTest, VolumeCoherent)
{
	ASSERT_EQ(4.0 / 3.0 * M_PI * pow(rayon, 3), sphere2.reqVolume());
}

TEST_F(SphereTest, SphereFormate)
{
	string valeurAttendue = "Sphere de rayon 5";
	ASSERT_EQ(valeurAttendue, sphere2.reqSphereFormate());

}
