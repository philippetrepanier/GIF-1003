/*
 * Temps.cpp
 *
 *  Created on: 2017-02-10
 *      Author: etudiant
 */

#include "Temps.h"
#include <time.h>
#include <sstream>

using namespace std;

namespace Temps2
{

int Temps::nombreInstances = 0;

/**
 * \brief Constructeur par défaut de ... initialise un objet Temps avec l'heure locale
 */
Temps::Temps()
{
	nombreInstances++;
	time_t timer;
	struct tm *tempsLocal;

	time(&timer);
	tempsLocal = localtime(&timer);

	m_heure = tempsLocal->tm_hour;
	m_minute = tempsLocal->tm_min;

}

Temps::~Temps()
{
	--nombreInstances;
	// TODO Auto-generated destructor stub
}

int Temps::reqHeure() const
{
	return m_heure;
}

/**
 * \brief Assignation de l'at...
 *
 * \param heure: heure assignée à l'attribut m_heure
 */
void Temps::asgHeure(int heure)
{
	m_heure = heure;
}

/**
 * \brief ...
 * \return le nombre de .
 */
int Temps::reqMinute() const
{
	return m_minute;
}

std::string Temps::reqTempsFormate() const
{
	ostringstream os;

	os << m_heure << ":" << m_minute << endl;

	return os.str();
}

Temps::Temps(int int1, int int2, int int3)
{
	m_heure = int1;
	m_minute = int2;
	m_seconde = int3;
}

int Temps::reqNombreInstances()
{
	return nombreInstances;
}

void Temps::asgMinute(int minute)
{
	m_minute = minute;
}

int Temps::reqSeconde() const
{
	return m_seconde;
}

void Temps::tic()
{
	m_seconde++;
	if (m_seconde > 59)
	{
		m_seconde = 0;
		m_minute++;
		if (m_minute > 59)
		{
			m_minute = 0;
			m_heure++;
			if (m_heure > 23)
			{
				m_heure = 0;
			}
		}
	}

}

void Temps::asgSeconde(int seconde)
{
	m_seconde = seconde;
}

std::ostream& operator<<(std::ostream& os, Temps& t)
{
	os << t.reqTempsFormate();
	return os;

}

}
