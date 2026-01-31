#include "Game.h"
#include<iostream>
using  namespace std;

const int Game::win[8][3][2]
{
	//Vence nas linhas
	{{0,0},{0,1},{0,2}},
	{{1,0},{1,1},{1,2}},
	{{2,0},{2,1},{2,2}},

	//vence nas colunas
	{{0,0},{1,0},{2,0}},
	{{0,1},{1,1},{2,1}},
	{{0,2},{1,2},{2,2}},

	//vence nas diagonais
	{{0,0},{1,1},{2,2}},
	{{0,2},{1,1},{2,0}},
};

//construtor
Game::Game()
{
	player1 = 'X';
	player2 = 'O';

	


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
		cout << "Escolha " << player1 << " ou " << player2 << " para iniciar ";
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

	int pos = checkPlay(player);
	if (pos == 0 && board[0][0] != player1 && board[0][0] != player2)
	{
		board[0][0] = player;
		system("cls");
		return switchPlayer(player);
	}
	
	if (pos == 1 && board[0][1] != player1 && board[0][1] != player2)
	{
		board[0][1] = player;
		system("cls");
		return switchPlayer(player);;
	}

	if (pos == 2 && board[0][2] != player1 && board[0][2] != player2)
	{
		board[0][2] = player;
		system("cls");
		return switchPlayer(player);
	}
			
	if (pos == 3 && board[1][0] != player1 && board[1][0] != player2)
	{
		board[1][0] = player;
		system("cls");
		return switchPlayer(player);
	}
			
	if (pos == 4 && board[1][1] != player1 && board[1][1] != player2)
	{
		board[1][1] = player;
		system("cls");
		return switchPlayer(player);
	}
			

	if (pos == 5 && board[1][2] != player1 && board[1][2] != player2)
	{
		board[1][2] = player;
		
		system("cls");
		return switchPlayer(player);
	}
			
	if (pos == 6 && board[2][0] != player1 && board[2][0] != player2)
	{
		board[2][0] = player;
		system("cls");
		return switchPlayer(player);
	}

	if (pos == 7 && board[2][1] != player1 && board[2][1] != player2)
	{
		board[2][1] = player;
		system("cls");
		return switchPlayer(player);
	}

	if (pos == 8 && board[2][2] != player1 && board[2][2] != player2)
	{
		board[2][2] = player;
		system("cls");
		return switchPlayer(player);
	}

	
}
//Verifica se alguem ganhou
char Game::checkWinner()const
{
	for (auto &line : win)
	{
		char a = board[line[0][0]][line[0][1]];
		char b = board[line[1][0]][line[1][1]];
		char c = board[line[2][0]][line[2][1]];

		if (a == b && b == c)
		{
			if (a == player1)
				return player1;
			else
				return player2;
		}
			
	}
	
	return 'E';

}
//faz a troca de jogadores
char Game::switchPlayer(const char& player)
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
int Game::checkPlay(const char& player)
{
	int pos = -1;
	while (true)
	{
		
		cout << "\nDeseja colocar " << player << " em qual posicao ? \n";
		cin >> pos;

		system("cls");
		draw();
		
		if (cin.fail() || pos > 8)
		{
			
			cout << "\n Valor digitado invalido! \n";
		

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
			
		}
		else if(validPositions[pos] != player1 && validPositions[pos] != player2)
		{
			validPositions[pos] = player;
			return pos;
		}
		else
		{
			cout << "\nCasa ocupada! \n";
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

