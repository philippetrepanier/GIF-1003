/**
 * \file Sphere.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-19
 */

#include "Sphere.h"
#include "ContratException.h"
#include <cmath>
#include <sstream>
using namespace std;

namespace labo8
{

Sphere::Sphere() :
		m_rayon(0)
{
	POSTCONDITION(m_rayon == 0);
}

Sphere::Sphere(double rayon) :
		m_rayon(rayon)
{
	PRECONDITION(rayon >= 0);
	POSTCONDITION(m_rayon == rayon);
	INVARIANTS();
}

Sphere::~Sphere()
{
}

double Sphere::reqRayon() const
{
	return m_rayon;
}

void Sphere::asgRayon(double rayon)
{
	m_rayon = rayon;
}
void Sphere::verifieInvariant() const
{
	INVARIANT(m_rayon >= 0);
}

double Sphere::reqVolume() const
{
	return (4.0 / 3.0 * M_PI * pow(m_rayon, 3));
}
string Sphere::reqSphereFormate() const
{
	ostringstream os;
	os << "Sphere de rayon " << reqRayon();
	return os.str();
}
} /* namespace labo8 */

