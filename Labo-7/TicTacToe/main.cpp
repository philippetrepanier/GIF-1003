/**
 * \file main.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-03
 */

#include "TicTacToe.h"

using namespace std;
using namespace labo;

int main()
{

	TicTacToe jeu;
	cout << jeu << endl;
	jeu.placerMarque(0, 2, 'X');
	jeu.placerMarque(1, 1, 'X');
	jeu.placerMarque(2, 0, 'X');
	cout << jeu << endl;
	cout << jeu.peutContinuerAJouer() << endl;
	return 0;
}

