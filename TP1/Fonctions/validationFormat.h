/*
 * validationFormat.h
 *
 *  Created on: 2017-02-04
 *      Author: Philippe Trepanier
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

bool validerTelephone(const std::string& p_telephone);
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom,
		int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);

#endif /* VALIDATIONFORMAT_H_ */
