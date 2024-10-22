#ifndef GAME_H
#define GAME_H

class Game
{
private:
	char board[3][3];
	char validPositions[9];
	char player1, player2;

public:
	Game();
	char initi();
	char update(const char& player);
	void draw();
	bool finilize(const char& winner)const;
	char checkWinner()const;
	char switchPlayer(const char &player);
	char isDigit(const char &player);
};
#endif // !GAME_H


