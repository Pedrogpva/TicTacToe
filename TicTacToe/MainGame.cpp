#include<iostream>
#include "Game.h";
int main()
{
	char gamer;
	bool winner = false;
	Game MyGame;
	gamer = MyGame.initi();


	while (gamer != 88 && gamer != 79)
	{
		gamer = MyGame.initi();
		system("cls");
	}

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


	MyGame.finilize(gamer);

	return 0;


}
