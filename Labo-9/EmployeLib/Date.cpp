/**
 * \file Date.cpp
 * \brief Implantation de la classe Date
 *        révision : normes 12-2013
 *        balises Doxygen
 *        révision des commentaires de spécification d'en-tête des méthodes
 * \author Yves Roy Version initiale, THE
 * \date 28 octobre 2016
 * \version 2.4
 */

#include "Date.h"
#include <sstream>
#include <ctime>
#include <iostream>
static const long MAX_SECONDE = 2145848400;
static const long JOUR_EN_SECONDES = 60 * 60 * 24;
static const long MIN_SECONDE = 5 * 60 * 60; // 5 heure par rapport à Greenwich

using namespace std;
namespace util
{
/**
 * \brief constructeur par défaut \n
 * La date prise par défaut est la date du système
 */
Date::Date()
{
	m_temps = time(NULL);

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);

	asgDate(infoTempsP->tm_mday, infoTempsP->tm_mon + 1,
			infoTempsP->tm_year + 1900);

	INVARIANTS();
}
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Date à partir de valeurs passées en paramètres.
 * 		  Les attributs sont assignés seulement si la date est considérée comme valide.
 * 		  Autrement, une erreur d'assertion est générée.
 * \param[in] p_jour est un entier long qui représente le jour de la date
 * \param[in] p_mois est un entier long qui représente le mois de la date
 * \param[in] p_annee est un entier long qui représente l'année de la date
 * \pre p_jour, p_mois, p_annee doivent correspondre à une date valide
 * \post l'objet construit a été initialisé à partir des entiers passés en paramètres
 */
Date::Date(long p_jour, long p_mois, long p_annee)
{
	PRECONDITION (Date::validerDate(p_jour, p_mois, p_annee));

	asgDate(p_jour, p_mois, p_annee);

	POSTCONDITION (reqJour() == p_jour);
	POSTCONDITION (reqMois() == p_mois);
	POSTCONDITION (reqAnnee() == p_annee);
	INVARIANTS();
}
/**
 * \brief Assigne une date à l'objet courant
 * \param[in] p_jour est un entier long qui représente le jour de la date
 * \param[in] p_mois est un entier long qui représente le mois de la date
 * \param[in] p_annee est un entier long qui représente l'année de la date
 * \pre p_jour, p_mois, p_annee doivent correspondre à une date valide
 * \post l'objet a été assigné à partir des entiers passés en paramètres
 */
void Date::asgDate(long p_jour, long p_mois, long p_annee)
{
	PRECONDITION(Date::validerDate(p_jour, p_mois, p_annee));

	struct tm infoTemps;

	infoTemps.tm_year = (p_annee - 1900);
	infoTemps.tm_mon = (p_mois - 1);
	infoTemps.tm_mday = p_jour;
	infoTemps.tm_hour = 0;
	infoTemps.tm_min = 0;
	infoTemps.tm_sec = 0;
	infoTemps.tm_isdst = -1;

	m_temps = mktime(&infoTemps);

	POSTCONDITION(reqJour() == p_jour);
	POSTCONDITION(reqMois() == p_mois);
	POSTCONDITION(reqAnnee() == p_annee);
	INVARIANTS();
}
/**
 * \brief Ajoute ou retire un certain nombre de jours à la date courante
 * \param p_nbJour est une entier long qui représente le nombre de jours à ajouter ou à soustraire s'il est négatif
 * \return un booléen qui indique si l'opération a réussi ou non
 */
bool Date::ajouteNbJour(long p_nbJour)
{
	bool bRet = true;

	long tModif = m_temps + (p_nbJour * JOUR_EN_SECONDES);
	if (tModif < MIN_SECONDE || tModif > MAX_SECONDE)
	{
		bRet = false;
	}
	else
	{
		m_temps = m_temps + (p_nbJour * JOUR_EN_SECONDES);
	}

	INVARIANTS();
	return bRet;
}
/**
 * \brief retourne le jour de la date
 * \return un entier long qui représente le jour de la date
 */
long Date::reqJour() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_mday;
}
/**
 * \brief retourne le mois de la date
 * \return un entier long qui représente le mois de la date
 */
long Date::reqMois() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_mon + 1;
}
/**
 * \brief retourne l'année de la date
 * \return un entier long qui représente l'année de la date
 */
long Date::reqAnnee() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_year + 1900;
}
/**
 * \brief retourne le ième jour de l'année correspondant au jour de la date
 * \return un entier long qui représente le ième jour de l'année
 */
long Date::reqJourAnnee() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_yday + 1;
}
/**
 * \brief Déterminer si une année est bissextile ou non
 * \param[in] p_annee un entier long qui représente l'année à vérifier
 * \return estBissextile un booléen qui a la valeur true si l'année est bissextile et false sinon
 */
bool Date::estBissextile(long p_annee)
{
	bool estBissextile = false;

	if (((p_annee % 4 == 0) && (p_annee % 100 != 0)) || ((p_annee % 4 == 0) && (p_annee
			% 100 == 0) && (p_annee % 400 == 0)))
	{
		estBissextile = true;
	}

	return estBissextile;
}
/**
 * \brief retourne le nom du jour de la semaine en français
 * \return une chaîne de caractères qui représente le nom du jour de la semaine en français
 */
string Date::reqNomJourSemaine() const
{
	static string JourSemaine[] =
	{ "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);//AssertionException si l'heure système n'a pas correctement été récupérée
	return JourSemaine[infoTempsP->tm_wday];

}
/**
 * \brief retourne le nom du mois en français
 * \return une chaîne de caractères qui représente le nom du mois en français
 */
string Date::reqNomMois() const
{
	static string NomMois[] =
	{ "janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout",
			"septembre", "octobre", "novembre", "decembre" };

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);//AssertionException si l'heure système n'a pas correctement été récupérée
	return NomMois[infoTempsP->tm_mon];
}
/**
 * \brief retourne une date formatée dans une chaîne de caracères (string)
 * \return la date formatée dans une chaîne de caractères
 */
 string Date::reqDateFormatee() const
{
	ostringstream os;

	os << reqNomJourSemaine() << " le ";
	if (reqJour() < 10)
	{
		os << "0";
	}
	os << reqJour() << " ";
	os << reqNomMois() << " ";
	os << reqAnnee();

	return os.str();
}

/**
 * \brief Vérifie la validité d'une date
 * \param[in] p_jour un entier long représentant le jour de la date
 * \param[in] p_mois un entier long représentant  le mois de la date
 * \param[in] p_annee un entier long représentant l'année de la date
 * \return un booléen indiquant si la date est valide ou non
 */
bool Date::validerDate(long p_jour, long p_mois, long p_annee)
{
	long JourParMois[] =
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static const long DEBUT_TEMPS = 1970;
	static const long FIN_TEMPS = 2037;

	bool valide = false;

	if (p_mois > 0 && p_mois <= 12 && p_annee >= DEBUT_TEMPS && p_annee <= FIN_TEMPS)
	{
		if (p_mois == 2 && Date::estBissextile(p_annee))
		{
			JourParMois[p_mois - 1]++;
		}
		if (p_jour > 0 && p_jour <= JourParMois[p_mois - 1])
		{
			valide = true;
		}
	}
	return valide;
}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_date à comparer à la date courante
 * \return un booléen indiquant si les deux dates sont égales ou non
 */
bool Date::operator==(const Date& p_date) const
{
	return m_temps == p_date.m_temps;
}

/**
 * \brief surcharge de l'opérateur <
 * \param[in] p_date à comparer à la date courante
 * \return un booléen indiquant si la date courante est plus petite que la date passée en paramètre
 */
bool Date::operator<(const Date& p_date) const
{
	return m_temps < p_date.m_temps;
}

/**
 * \brief retourne le nombre de jours entre deux dates
 * \param[in] p_date à soustraire à la date courante
 * \return un entier qui représente le nombre de jours entre la date courante
 * 	et celle passée en paramètre
 */
int Date::operator-(const Date& p_date) const
{
	double nbSec = difftime(m_temps, p_date.m_temps);
	return static_cast<int> (nbSec / JOUR_EN_SECONDES);
}

/**
 * \relates Date
 * \brief surcharge de la fonction << d'écriture dans un flux de sortie
 * \param[in] p_os un flux de sortie  dans laquelle on va écrire
 * \param[in] p_date sortie dans le flux
 * \return le flux dans lequel on a écrit la date, ceci pour les appels en cascade
 */
 ostream& operator<<( ostream& p_os, const Date& p_date)
{
	long jour = p_date.reqJour();
	long mois = p_date.reqMois();

	if (jour < 10)
	{
		p_os << "0";
	}
	p_os << jour << "/";
	if (mois < 10)
	{
		p_os << "0";
	}
	p_os << mois << "/";
	p_os << p_date.reqAnnee();

	return p_os;
}

/**
 * \brief Teste l'invariant de la classe Date. L'invariant de cette classe s'assure que la date est valide
 */
void Date::verifieInvariant() const
{
	INVARIANT(m_temps >= MIN_SECONDE);
	INVARIANT(m_temps <= MAX_SECONDE);
	INVARIANT(Date::validerDate(reqJour(), reqMois(), reqAnnee()));
}
}// namespace util
