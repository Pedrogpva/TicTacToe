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
	char  player = ' ';
	bool ValidMove = false;
	bool endGame = false;
	int counterMove = 0;
	char winner = 'P';
	Game MyGame{};


	player = MyGame.initi();

	do {
		
		MyGame.draw();
		player = MyGame.update(player);
		winner = MyGame.checkWinner();

		if (winner == 'X' || winner == 'O' || counterMove >= 9)
		{
			MyGame.draw();
			endGame = MyGame.finilize(winner);

			if (endGame == false)
			{
				MyGame.initi();
				counterMove = 0;
			}
			
		}
		counterMove++;
	
	} while (endGame == false);

	std::cout << "Encerrando...";

	return 0;

}
