/*############################################################################
Jogo da velha
Criado por Pedro Henrique Fernandes

Programa tem como objetivo criar um jogo da velha
utilizando POO
##############################################################################*/
#include<iostream>
#include "Game.h";
int main()
{
	char  gamer;
	bool winner = false;
	Game MyGame{};


	gamer = MyGame.initi();

	do {
		MyGame.draw();
		MyGame.update(gamer);
		winner = MyGame.checkWinner();
		if (winner == false)
		{
			gamer = MyGame.trocaJogador(gamer);
		}

		system("cls");

	} while (winner == false);

	MyGame.draw();
	MyGame.finilize(gamer);

	return 0;


}
