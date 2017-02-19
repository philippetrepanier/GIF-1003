/**
 * \file main.cpp
 * \brief
 * \author etudiant
 * \date 2017-02-19
 */

#include "Personne.h"
#include <iostream>
#include <sstream>

int main()
{
	tp::Personne julie("Bou", "Julie", util::Date(18, 5, 1997), "418 658-2888");

	std::cout << julie.reqPersonneFormate() << std::endl;

	return 0;

}

