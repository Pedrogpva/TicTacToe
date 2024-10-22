#include "Game.h"
#include<iostream>
using  namespace std;
//construtor
Game::Game()
{
	player1 = 0x58;                               // Tecla X
	player2 = 0x4F;								  // Tecla O

	// Inicializa a matriz no construtor
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '0';
		}
	}
	for (int i = 0; i < 9; i++)
		validPositions[i] = '0';
	
}
//Inicia o jogo
char Game::initi()
{
	char player = ' ';
	char initialValue = '0';
	cout << "Inicializando Jogo..." << endl;
	cout << "Excolha " << player1 << " ou " << player2 << " para iniciar ";
	cin >> player;
	while (player != player1 && player != player2)
	{
		
		cout << "Valor invalido!\n";
		cout << "Excolha " << player1 << " ou " << player2 << " para iniciar ";
		cin >> player;
		system("cls");

	}
	system("cls");

	// Prenche a matriz com caracteres de 0 a 8
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = initialValue;
			initialValue++;
		}

	}
	//Prenche o vetor com os caracteres numéricos válidos para jogadas 0 a 8
	initialValue = '0';
	for (int i = 0; i < 9; i++)
	{
		validPositions[i] = initialValue;
		initialValue++;
	}
		


	if (player == player1)
		return player1;

	if (player == player2)
		return player2;
}
//desenha a matriz
void Game::draw()
{

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ' ' << board[i][j];
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
char Game::update(const char& player)
{

	char pos = isDigit(player);
	if (pos == '0' && board[0][0] != player1 && board[0][0] != player2)
	{
		board[0][0] = player;
		system("cls");
		return trocaJogador(player);
	}
	
	if (pos == '1' && board[0][1] != player1 && board[0][1] != player2)
	{
		board[0][1] = player;
		system("cls");
		return trocaJogador(player);;
	}

	if (pos == '2' && board[0][2] != player1 && board[0][2] != player2)
	{
		board[0][2] = player;
		system("cls");
		return trocaJogador(player);
	}
			
	if (pos == '3' && board[1][0] != player1 && board[1][0] != player2)
	{
		board[1][0] = player;
		system("cls");
		return trocaJogador(player);
	}
			
	if (pos == '4' && board[1][1] != player1 && board[1][1] != player2)
	{
		board[1][1] = player;
		system("cls");
		return trocaJogador(player);
	}
			

	if (pos == '5' && board[1][2] != player1 && board[1][2] != player2)
	{
		board[1][2] = player;
		
		system("cls");
		return trocaJogador(player);
	}
			
	if (pos == '6' && board[2][0] != player1 && board[2][0] != player2)
	{
		board[2][0] = player;
		system("cls");
		return trocaJogador(player);
	}

	if (pos == '7' && board[2][1] != player1 && board[2][1] != player2)
	{
		board[2][1] = player;
		system("cls");
		return trocaJogador(player);
	}

	if (pos == '8' && board[2][2] != player1 && board[2][2] != player2)
	{
		board[2][2] = player;
		system("cls");
		return trocaJogador(player);
	}

	
}
//Verifica se alguem ganhou
char Game::checkWinner()const
{
	// vence nas linhas
	if (board[0][0] == player1 && board[0][1] == player1 && board[0][2] == player1)
	{
		return player1;
	}
	else if (board[0][0] == player2 && board[0][1] == player2 && board[0][2] == player2)
	{
		return player2;
	}

	if (board[1][0] == player1 && board[1][1] == player1 && board[1][2] == player1)
	{

		return player1;
	}
	else if (board[1][0] == player2 && board[1][1] == player2 && board[1][2] == player2)
	{
		return player2;
	}

	if (board[2][0] == player1 && board[2][1] == player1 && board[2][2] == player1)
	{
		return player1;
	}
	else if (board[2][0] == player2 && board[2][1] == player2 && board[2][2] == player2)
	{
		return player2;
	}


	//vence nas colunas 
	if (board[0][0] == player1 && board[1][0] == player1 && board[2][0] == player1)
	{
		return player1;
	}
	else if (board[0][0] == player2 && board[1][0] == player2 && board[2][0] == player2)
	{
		return player2;
	}

	if (board[0][1] == player1 && board[1][1] == player1 && board[2][1] == player1)
	{
		return player1;
	}
	else if (board[0][1] == player2 && board[1][1] ==  player2 && board[2][1] == player2)
	{
		return player2;
	}

	if (board[0][2] == player1 && board[1][2] == player1 && board[2][2] == player1)
	{
		return player1;
	}
	else if (board[0][2] == player2 && board[1][2] == player2 && board[2][2] == player2)
		return player2;

	// Vence na diagonais
	if (board[0][0] == player1 && board[1][1] == player1 && board[2][2] == player1)
	{
		return player1;
	}
	else if (board[0][0] == player2 && board[1][1] == player2 && board[2][2] == player2)
	{
		return player2;
	}

	if (board[0][2] == player1 && board[1][1] == player1 && board[2][0] == player1)
	{
		return player1;
	}
	else if (board[0][2] == player2 && board[1][1] == player2 && board[2][0] == player2)
	{
		return player2;
	}
	return 'E';

}
//faz a troca de jogadores
char Game::trocaJogador(const char& player)
{
	if (player == player1)
	{
		return player2;
	}
	else
	{
		return player1;
	}
}
char Game::isDigit(const char& player)
{
	char pos;
	while (true)
	{
		
		cout << "\nDeseja colocar " << player << " em qual posicao ?";
		cin >> pos;

		for (int i = 0; i < 10; i++)
		{
			if (pos == validPositions[i])
			{
				validPositions[i] = player;
				return pos;
			}
			else if (i >= 9)
			{
				cout << "Valor digitado invalido ";
				
			}

		}
		
	}
	
	
}
bool Game::finilize(const char& winner)const
{
	char option = 'N';
	if (winner == player1 || winner == player2)
	{
		cout << "\nParabens, " << winner << " Venceu!\n";
		cout << "Deseja jogar novamnete S/N ";
		cin >> option;
	}
	else
	{
		cout << "\nNao houve ganhador!\n";
		cout << "Deseja jogar novamnete S/N ";
		cin >> option;
	}

	while (true)
	{
		switch (option)
		{
		case 'S':
			system("cls");
			return false;
		case 'N':
			return true;
		default: cout << "Opcao invalida!\n";
			cout << "Deseja jogar novamnete S/N ";
			cin >> option;
		}
	}
	
}

