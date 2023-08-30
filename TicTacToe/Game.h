#ifndef GAME_H
#define GAME_H

class Game
{
private:
	char tabuleiro[3][3];
	char jog1, jog2;

public:
	Game();
	char initi();
	bool update(char);
	void draw();
	void finilize(char);
	bool checkWinner();
	char trocaJogador(char);
	char isDigit(char gamer);
};
#endif // !GAME_H


