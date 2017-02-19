/*
 * Temps.h
 *
 *  Created on: 2017-02-10
 *      Author: etudiant
 */

#ifndef TEMPS_H_
#define TEMPS_H_

#include <string>
#include <iostream>

namespace Temps2
{

/**
 * \class Temps
 */
class Temps
{
public:
	Temps();
	Temps(int, int, int);
	~Temps();

	std::string reqTempsFormate() const;

	void tic();

	static int reqNombreInstances();

	int reqHeure() const;
	void asgHeure(int heure);
	int reqMinute() const;
	void asgMinute(int minute);
	int reqSeconde() const;
	void asgSeconde(int seconde);

	friend std::ostream& operator<<(std::ostream&, Temps&);

private:
	int m_heure;
	int m_minute;
	int m_seconde;

	static int nombreInstances;
};
}
#endif /* TEMPS_H_ */
