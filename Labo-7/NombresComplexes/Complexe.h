/**
 * \file Complexe.h
 * \brief
 * \author etudiant
 * \date 2017-03-03
 */

#ifndef COMPLEXE_H_
#define COMPLEXE_H_

#include <iostream>
#include <string>

namespace labo
{

class Complexe
{
public:
	Complexe(double, double);

	Complexe reqConjugue() const;
	double reqModule() const;

	Complexe operator+(const Complexe&) const;
	Complexe operator+(int) const;
	Complexe operator*(const Complexe&) const;
	Complexe operator/(const Complexe&) const;

	friend std::ostream& operator<<(std::ostream&, const Complexe&);

private:
	std::string reqComplexeFormate() const;

	double m_re;
	double m_im;
};

} /* namespace labo */

#endif /* COMPLEXE_H_ */
