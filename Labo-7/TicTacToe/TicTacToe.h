/**
 * \file TicTacToe.h
 * \brief
 * \author etudiant
 * \date 2017-03-03
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
#include <string>

namespace labo
{

class TicTacToe
{
public:
	TicTacToe();

	void placerMarque(int, int, char);
	bool peutContinuerAJouer() const;

	friend std::ostream& operator<<(std::ostream&, const TicTacToe);

private:
	const static int TAILLE_PLATEAU = 3;
	char m_plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
	std::string reqPlateauFormate() const;
};

} /* namespace labo */

#endif /* TICTACTOE_H_ */
