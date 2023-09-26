#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string* square;

int WinBoardCondition(int size, int root);
int DiagonalWin(int i, int root, int size);
int WinCheck();
void FillArray(int size);
int rows = 3;
void Board();


int main()
{	
	int player = 1;
	int i = -1;
	int choice;
	int size = 8;
	string symbol;

	cout << "Enter a board size: ";
	cin >> size;
	

	while (sqrt(size) - floor(sqrt(size)) != 0)
	{
		system("cls");
		cout << "Invalid board size. Please enter a perfect square (e.g., 9, 16, 25, etc.)." << endl;
		cout << "Enter a board size: ";
		cin >> size;

		if (cin.gcount() != 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}

	rows = static_cast<int>(sqrt(size));
	square = new string[size + 1];
	FillArray(size);

	do
	{
		Board();
		player = (player % 2) ? 1 : 2;

		cout << "Player" << player << ", enter a number: ";
		cin >> choice;

		symbol = (player == 1) ? "X" : "O";


		//if ((choice >= 1 && choice <= size) && (stoi(square[choice])) == (choice)) { square[choice] = symbol; }

		if (choice >= 0 && choice <= size) {
			try {
				if (square[choice-1] == to_string(choice)) {
					square[choice-1] = symbol;
				}
				else {
					cout << "Invalid Move";
					player--;
					cin.ignore();
					cin.get();
				}
			}
			catch (const std::exception& e) {
				cout << "Invalid Move";
				player--;
				cin.ignore();
				cin.get();
			}
		}
		else
		{
			cout << "Invalid Move";
			player--;
			cin.ignore();
			cin.get();
		}

		i = WinCheck();
		player++;		
	} while (i == -1);


	if (i == 1)
	{
		cout << "==>\aPlayer " << --player << " wins";
	} else {cout <<"==>\aDraw" ;}

	cin.ignore();
	cin.get();

	return 0;
}

int WinCheck()
{
		for (int k = rows; k <= rows * rows; k += rows)
		{
			if (WinBoardCondition(k, rows) == 1) return 1;
		}
			if (DiagonalWin(0,3,4) == 1) return 1; 
			if (DiagonalWin(rows - 1,3,2) == 1) return 1; 


    return -1;
}

int DiagonalWin(int i, int root, int temp)
{
	bool win = true;
	string symbol = square[i];

	for (int j = 0; j <= rows * temp - temp; j+=temp)
	{
		if (square[i + j] != symbol)
		{
			win = false;
			break;
		}
	}

	if (win)
	{
		Board();
		cout << "Winning sequence starts at diagonal " << i + 1<< endl;
		return 1;
	}

	return -1;
}

int WinBoardCondition(int size, int root)
{
	//Horizontal
	for (int i = size - root; i <= size - root; i++)
	{
		bool win = true;
		string symbol = square[i];

		for (int j = 0; j <= root-1; j++)
		{
			if (square[i + j] != symbol)
			{
				win = false;
				break;
			}
		}

		if (win)
		{
			Board();
			cout << "Winning sequence starts at row " << i + 1<< endl;
			return 1;
		}
	}

	// Vertical
	for (int i = size - root; i <= rows; i++)
	{
		bool win = true;
		string symbol = square[i];

		for (int j = 0; j <= root * root - 1; j+= rows)
		{
			if (square[i + j] != symbol)
			{
				win = false;
				break;
			}
		}

		if (win)
		{
			Board();
			cout << "Winning sequence starts at column " << i + 1 << endl;
			return 1;
		}
	}

	return -1;
}

void Board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  - Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "  ";

	for (int temp = 1; temp <= rows; temp++)
	{
		cout << " _____";

	} cout << endl;

	int k = 0;
	for (int i = 1; i <= rows; i++)
	{

		for (int j = k; j <= k + rows - 1; j++)
		{
			cout << "  |  " << square[j];
		}

		cout << "  |" << endl;

		cout << "  ";

		for (int temp = 1; temp <= rows; temp++)
		{
			cout << " _____";

		} cout << endl;

		k += rows;
	}
}


void FillArray(int size)
{
	for (int i = 0; i < size; i++)
	{
		square[i] = to_string(i+1);
	}
}