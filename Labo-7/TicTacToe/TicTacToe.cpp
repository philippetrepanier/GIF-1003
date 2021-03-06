/**
 * \file TicTacToe.cpp
 * \brief
 * \author etudiant
 * \date 2017-03-03
 */

#include "TicTacToe.h"
#include <sstream>

using namespace std;

namespace labo
{

TicTacToe::TicTacToe()
{
	for (int i = 0; i < TicTacToe::TAILLE_PLATEAU; ++i)
	{
		for (int j = 0; j < TicTacToe::TAILLE_PLATEAU; ++j)
		{
			m_plateau[i][j] = ' ';
		}
	}

}

void TicTacToe::placerMarque(int ligne, int colonne, char marque)
{
	if (ligne < 0 || ligne >= TicTacToe::TAILLE_PLATEAU)
	{
		return;
	}
	if (colonne < 0 || colonne >= TicTacToe::TAILLE_PLATEAU)
	{
		return;
	}

	if (m_plateau[ligne][colonne] != ' ')
	{
		return;
	}
	m_plateau[ligne][colonne] = marque;

}

bool TicTacToe::peutContinuerAJouer() const
{
	bool uneCaseVide = false;
	for (int i = 0; i < TicTacToe::TAILLE_PLATEAU; ++i)
	{
		for (int j = 0; j < TicTacToe::TAILLE_PLATEAU; ++j)
		{
			if (m_plateau[i][j] == ' ')
			{
				uneCaseVide = true;
			}
		}
	}
	if (!uneCaseVide)
	{
		return false;
	}

	bool ligneGagnante = false;
	for (int i = 0; i < TicTacToe::TAILLE_PLATEAU; ++i)
	{
		char marquePremiereCol = m_plateau[i][0];

		if (marquePremiereCol == ' ')
		{
			continue;
		}
		for (int j = 1; j < TicTacToe::TAILLE_PLATEAU; ++j)
		{
			if (m_plateau[i][j] != marquePremiereCol)
			{
				break;
			}
			else if (j == TicTacToe::TAILLE_PLATEAU - 1)
			{
				ligneGagnante = true;
			}
		}
	}
	if (ligneGagnante)
	{
		return false;
	}

	bool colonneGagnante = false;
	for (int i = 0; i < TicTacToe::TAILLE_PLATEAU; ++i)
	{
		char marquePremiereLigne = m_plateau[0][i];

		if (marquePremiereLigne == ' ')
		{
			continue;
		}
		for (int j = 1; j < TicTacToe::TAILLE_PLATEAU; ++j)
		{
			if (m_plateau[j][i] != marquePremiereLigne)
			{
				break;
			}
			else if (j == TicTacToe::TAILLE_PLATEAU - 1)
			{
				colonneGagnante = true;
			}
		}
	}
	if (colonneGagnante)
	{
		return false;
	}

	if (m_plateau[0][0] != ' ' && m_plateau[0][0] == m_plateau[1][1] && m_plateau[0][0] == m_plateau[2][2])
	{
		return false;
	}

	if (m_plateau[0][2] != ' ' && m_plateau[0][2] == m_plateau[1][1] && m_plateau[0][2] == m_plateau[2][0])
	{
		return false;
	}

	return true;

}

ostream& operator<<(ostream& os, const TicTacToe t)
{
	os << t.reqPlateauFormate();
	return os;
}

string TicTacToe::reqPlateauFormate() const
{
	ostringstream os;
	for (int i = 0; i < TicTacToe::TAILLE_PLATEAU; ++i)
	{
		for (int j = 0; j < TicTacToe::TAILLE_PLATEAU; ++j)
		{
			os << " " << m_plateau[i][j];
			if (j != TicTacToe::TAILLE_PLATEAU - 1)
			{
				os << " |";
			}
		}
		os << endl;
		if (i != TicTacToe::TAILLE_PLATEAU - 1)
		{
			os << "-----------" << endl;
		}
	}
	return os.str();
}

} /* namespace labo */

