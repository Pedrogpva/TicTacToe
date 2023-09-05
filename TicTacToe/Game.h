#ifndef GAME_H
#define GAME_H

class Game
{
private:
	char board[3][3];
	int  cont;
	char player1, player2;

public:
	Game();
	char initi();
	bool update(const char& player);
	void draw();
	bool finilize(const char& winner)const;
	char checkWinner()const;
	char trocaJogador(const char &player);
	char isDigit(const char &player);
};
#endif // !GAME_H


