#include "Game.h"
#include<iostream>
using  namespace std;
//construtor
Game::Game()
{
	jog1 = 'X';
	jog2 = 'O';
	int cont = 0;
	char chr[] = "string";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			chr[6] = cont + '0';
			tabuleiro[i][j] = chr[6];
			cont += 1;

		}

	}


}
//Inicia o jogo
char Game::initi()
{
	char esc;
	cout << "Inicializando Jogo..." << endl;
	cout << "Excolha " << jog1 << " ou " << jog2 << " para iniciar";
	cin >> esc;

	if (esc == jog1)
		return jog1;

	if (esc == jog2)
		return jog2;

}
//dezenha a matriz
void Game::draw()
{

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ' ' << tabuleiro[i][j];
			if (j < 2)
			{
				cout << ' ' << '|';
			}
		}
		if (i < 2)
		{
			cout << "\n-----------\n";
		}

	}

}
//atualiza a matriz
void Game::update(char gamer)
{
	unsigned pos;
	cout << "\nDeseja colocar " << gamer << " em qual posicao ?";
	cin >> pos;

	switch (pos)
	{
	case 0: tabuleiro[0][0] = gamer;
		break;
	case 1: tabuleiro[0][1] = gamer;
		break;
	case 2: tabuleiro[0][2] = gamer;
		break;
	case 3: tabuleiro[1][0] = gamer;
		break;
	case 4: tabuleiro[1][1] = gamer;
		break;
	case 5: tabuleiro[1][2] = gamer;
		break;
	case 6: tabuleiro[2][0] = gamer;
		break;
	case 7: tabuleiro[2][1] = gamer;
		break;
	case 8: tabuleiro[2][2] = gamer;;
		break;
	default: cout << "Opçao invalida!";
	}
}
//Verifica se alguem ganhou
bool Game::checkWinner()
{
	// vence nas linhas
	if (tabuleiro[0][0] == jog1 && tabuleiro[0][1] == jog1 && tabuleiro[0][2] == jog1)
	{

		return 1;
	}
	else if (tabuleiro[0][0] == jog2 && tabuleiro[0][1] == jog2 && tabuleiro[0][2] == jog2)
	{
		return 1;
	}

	if (tabuleiro[1][0] == jog1 && tabuleiro[1][1] == jog1 && tabuleiro[1][2] == jog1)
	{

		return 1;
	}
	else if (tabuleiro[1][0] == jog2 && tabuleiro[1][1] == jog2 && tabuleiro[1][2] == jog2)
	{
		return 1;
	}

	if (tabuleiro[2][0] == jog1 && tabuleiro[2][1] == jog1 && tabuleiro[2][2] == jog1)
	{
		return 1;
	}
	else if (tabuleiro[2][0] == jog2 && tabuleiro[2][1] == jog2 && tabuleiro[2][2] == jog2)
	{
		return 1;
	}


	//vence nas colunas 
	if (tabuleiro[0][0] == jog1 && tabuleiro[1][0] == jog1 && tabuleiro[2][0] == jog1)
	{
		return 1;
	}
	else if (tabuleiro[0][0] == jog2 && tabuleiro[1][0] == jog2 && tabuleiro[2][0] == jog2)
	{
		return 1;
	}

	if (tabuleiro[0][1] == jog1 && tabuleiro[1][1] == jog1 && tabuleiro[2][1] == jog1)
	{
		return 1;
	}
	else if (tabuleiro[0][1] == jog2 && tabuleiro[1][1] == jog2 && tabuleiro[2][1] == jog2)
	{
		return 1;
	}

	if (tabuleiro[0][2] == jog1 && tabuleiro[1][2] == jog1 && tabuleiro[2][2] == jog1)
	{
		return 1;
	}
	else if (tabuleiro[0][2] == jog2 && tabuleiro[1][2] == jog2 && tabuleiro[2][2] == jog2)
		return 1;

	// Vence na diagonais
	if (tabuleiro[0][0] == jog1 && tabuleiro[1][1] == jog1 && tabuleiro[2][2] == jog1)
	{
		return 1;
	}
	else if (tabuleiro[0][0] == jog2 && tabuleiro[1][1] == jog2 && tabuleiro[2][2] == jog2)
	{
		return 1;
	}

	if (tabuleiro[0][2] == jog1 && tabuleiro[1][1] == jog1 && tabuleiro[2][0] == jog1)
	{
		return 1;
	}
	else if (tabuleiro[0][2] == jog2 && tabuleiro[1][1] == jog2 && tabuleiro[2][0] == jog2)
	{
		return 1;
	}
	return 0;




}
//faz a troca de jogadoreshh
char Game::trocaJogador(char gamer)
{
	if (gamer == jog1)
	{
		return jog2;
	}
	else
	{
		return jog1;
	}
}
void Game::finilize(char gamer)
{
	cout << "Parabens, " << gamer << " Venceu!\n";

}

