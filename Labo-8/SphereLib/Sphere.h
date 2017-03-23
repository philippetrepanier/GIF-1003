/**
 * \file Sphere.h
 * \brief
 * \author etudiant
 * \date 2017-03-19
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <string>

namespace labo8
{

class Sphere
{
public:
	Sphere();
	Sphere(double rayon);

	virtual ~Sphere();
	double reqRayon() const;
	void asgRayon(double rayon);
	double reqVolume() const;
	std::string reqSphereFormate() const;

private:
	double m_rayon;
	void verifieInvariant() const;
};

} /* namespace labo8 */

#endif /* SPHERE_H_ */
