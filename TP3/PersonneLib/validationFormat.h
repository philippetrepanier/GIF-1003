/**
 * \file validationFormat.h
 * \brief Fichier de déclaration des fonctions permettant de valider des paramètres du programme
 * \date 2017-02-04
 * \author Philippe Trepanier
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

namespace util
{

bool validerTelephone(const std::string& p_telephone);
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom,
		int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);
bool validerFormatNom(const std::string& p_nom);

void convertitEnMajuscules(std::string& p_chaine);

} //Namespace util
#endif /* VALIDATIONFORMAT_H_ */
