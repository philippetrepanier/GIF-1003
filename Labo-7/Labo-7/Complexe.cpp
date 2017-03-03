/**
 * \file Complexe.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-03
 */

#include "Complexe.h"
#include <sstream>
#include <cmath>

using namespace std;

namespace labo
{

Complexe::Complexe(double re, double im) :
		m_re(re), m_im(im)
{
}

Complexe Complexe::reqConjugue() const
{
	return Complexe(m_re, -m_im);
}

double Complexe::reqModule() const
{
	return sqrt(pow(m_re, 2) + pow(m_im, 2));
}

Complexe Complexe::operator+(const Complexe& z2) const
{
	double re = m_re + z2.m_re;
	double im = m_im + z2.m_im;
	return Complexe(re, im);
}

ostream& operator<<(ostream& os, const Complexe& z)
{
	os << z.reqComplexeFormate();
	return os;
}

Complexe Complexe::operator +(int i) const
{
	double re = m_re + i;
	return Complexe(re, m_im);
}

Complexe Complexe::operator*(const Complexe& z2) const
{
	double re = m_re * z2.m_re - m_im * z2.m_im;
	double im = m_re * z2.m_im + m_im * z2.m_re;
	return Complexe(re, im);
}

Complexe Complexe::operator /(const Complexe& z2) const
{
	double moduleCarreZ2 = pow(z2.reqModule(), 2);
	Complexe z3 = (*this) * z2.reqConjugue();
	z3.m_re = z3.m_re / moduleCarreZ2;
	z3.m_im = z3.m_im / moduleCarreZ2;
	return z3;
}

string Complexe::reqComplexeFormate() const
{
	ostringstream os;
	os << m_re;
	if (m_im >= 0)
	{
		os << " + " << m_im;
	}
	else
	{
		os << " - " << -m_im;
	}

	os << "i";
	return os.str();
}

}

/* namespace labo */
