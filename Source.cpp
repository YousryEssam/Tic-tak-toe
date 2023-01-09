#include<iostream>
using namespace std;
string board[4];
int isWin();
void drawBoard();
void takeTurns();
void startNewGame();
bool validPlace(int n);
int main()
{
	bool continuePlaying = 1;
	while (continuePlaying)
	{
		startNewGame();
		takeTurns();
		cout << "Do you want play agin !?\nEnter y or Y to yes or Press any other button to exit\n";
		string str;
		cin >> str;
		if (str != "y" && str != "Y")
		{
			continuePlaying = 0;
			cout << "Good bye (:\n";
		}
	}
	return 0;
}
void startNewGame()
{
	cout << "--------STARTIG NEW GAME-------\n";
	for (int i = 1; i <= 3; i++)
	{
		string s = "-";
		for (int j = 1; j <= 3; j++)
		{
			s += char((i - 1) * 3 + j + '0');
		}
		board[i] = s;
	}
}
void takeTurns()
{
	int place;
	bool turn = 0;
	while (isWin() == 0)
	{
		cout << "Player ";
		if (!turn) cout << " X ";
		else cout << " O ";
		// Cheek if place valed 
		cin >> place;
		while (validPlace(place) == 0)
		{
			cout << "Invaled Place pleace select another one !!\n";
			cin >> place;
		}
		// convert the number to XY 
		int x = 0, y = 0;
		if (place == 9)
		{
			x = 3, y = 3;
		}
		else
		{
			x = (1 + (place / 3));
			if (place % 3 == 0)
				y = 3;
			else
				y = place % 3;
		}
		(!turn) ? board[x][y] = 'X' : board[x][y] = 'O';
		turn = !(turn);
		drawBoard();
	}

	if (isWin() == 1)
	{
		if (turn) cout << "Player X WON the game!!\n";
		else cout << "Player O WON the game!!\n";
	}
	else cout << "The game ended in a draw\n";
}
bool validPlace(int n)
{
	int x = 0, y = 0;
	
	if (n > 9 || n < 1) return 0;
	else if (n == 9)
	{
		x = 3;
		y = 3;
	}
	else
	{
		x = (1 + (n / 3));
		if (n % 3 == 0) y = 3;
		else y = n % 3;
	}
	
	if (board[x][y] >= '1' && board[x][y] <= '9') return 1;

	return 0;
}
int isWin()
{
	if (board[1][1] == board[1][2] && board[1][1] == board[1][3] ||
		board[2][1] == board[2][2] && board[2][1] == board[2][3] ||
		board[3][1] == board[3][2] && board[3][1] == board[3][3])
		return 1;

	if (board[1][1] == board[2][1] && board[1][1] == board[3][1] ||
		board[1][2] == board[2][2] && board[1][2] == board[3][2] ||
		board[1][3] == board[3][2] && board[1][3] == board[3][3])
		return 1;

	if (board[1][1] == board[2][2] && board[1][1] == board[3][3] ||
		board[1][3] == board[2][2] && board[1][3] == board[3][1])
		return 1;

	int cnt = 0;
	
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (!(board[i][j] >= '1' && board[i][j] <= '9')) cnt++;
		}
	}
	
	if (cnt == 9) return -1;
	
	return 0;
}
void drawBoard()
{
	cout << "-------------------------------\n";
	cout << "|---------|---------|---------|\n";
	cout << "|         |         |         |\n";
	cout << "|    " << board[1][1] << "    |    " << board[1][2] << "    |    " << board[1][3] << "    |\n";
	cout << "|         |         |         |\n";
	cout << "|---------|---------|---------|\n";
	cout << "|         |         |         |\n";
	cout << "|    " << board[2][1] << "    |    " << board[2][2] << "    |    " << board[2][3] << "    |\n";
	cout << "|         |         |         |\n";
	cout << "|---------|---------|---------|\n";
	cout << "|         |         |         |\n";
	cout << "|    " << board[3][1] << "    |    " << board[3][2] << "    |    " << board[3][3] << "    |\n";
	cout << "|         |         |         |\n";
	cout << "|---------|---------|---------|\n";
	cout << "-------------------------------\n";
}