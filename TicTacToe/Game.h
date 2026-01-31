#ifndef GAME_H
#define GAME_H

class Game
{
private:
	char board[3][3];
	char validPositions[9];
	char player1, player2;
	static const int win[8][3][2];

public:
	Game();
	char initi();
	char update(const char& player);
	void draw();
	bool finilize(const char& winner)const;
	char checkWinner()const;
	char switchPlayer(const char &player);
	int checkPlay(const char &player);
	const bool isDigit(const char pos);
};
#endif // !GAME_H


