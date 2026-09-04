#include <iostream>
using namespace std;

int validCount = 0;

bool isValid(int board[], int row, int column)
{
	if (column == 0) return true;
	for (int i = 0; i < column; i++)
	{
		if (board[i] == row) return false;
		else if (board[i] == row - (column - i)) return false;
		else if (board[i] == row + (column - i)) return false;
	}
	return true;
}

void CheckQueen(int (&board)[8], int column)
{
	if (column == 8)
	{
		validCount++;
		return;
	}
	for (int row = 0; row < 8; row++)
	{
		if (isValid(board, row, column))
		{
			board[column] = row;
			CheckQueen(board, column + 1);
			board[column] = -1; //not necessary
		}
	}
}

int main()
{
	int board[8];
	for(int i = 0; i < 8; i++)
	{
		board[i] = -1;
	}
	CheckQueen(board, 0);
	cout << validCount;
	return 0;
}