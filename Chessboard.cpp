/*
contains all functions for class Chessboard from Chessboard.h
*/

# include <string>
using std::string;

# include "Chessboard.h"

Chessboard::Chessboard() {
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			board[row][column] = '-';
		}
	}
}

char Chessboard::getBoardElement(int row, int column) {
	return board[row][column];
}

void Chessboard::setBoardElement(char symbol, string pname, string mode) {
	/*
	function allows setting an element of the bord to 'x' or 'o'
	args:
		- char symbol: allows symbol to be set as 'x' or 'o'
		- string pname: name of the respective player
		- mode: playing mode ['normalPlayer','computerPlayer']. "normalPlayer" allows to
			manually input the desired coordinate,"computerPlayer" sets its value randomly
	*/

	int row;
	int column;
	int* r;

	if (mode == "normalPlayer") {
		r = getRowColumnFromUser(pname);
		row = r[0];
		column = r[1];
	}
	else if (mode == "computerPlayer") {
		row = rand() % 4 + 1;
		column = rand() % 4 + 1;
		if (board[row][column] == 'x' || board[row][column] == 'o') {
			setBoardElement(symbol, pname, mode);
			return;
		}
		cout << "Computer chose (" << row << ", " << column << "):\n";
	}
	else {
		string modeIn;
		cout << "\nYour entered mode is not supported. Please specify a playing mode from ['normalPlayer','computerPlayer'] \n";
		cin >> modeIn;
		setBoardElement(symbol, pname, modeIn);
		return;
	}

	if (symbol != 'x' && symbol != 'o' && symbol != '-') {
		cout << "The entered symbol is not allowed, please enter >x< or >o<\n\n";
		cin >> symbol;
		cout << "You entered " << symbol;
	}
	if (board[row][column] == 'x' || board[row][column] == 'o') {
		cout << "\nThere is already a symbol " << board[row][column] << " at the given position, please specify new position:\n\n";
		setBoardElement(symbol, pname, mode);
		return;
	}
	board[row][column] = symbol;
}

void Chessboard::printBoard() {
	int r;
	cout << setw(4);
	cout << "____________\n";
	cout << "   " << "1" << " " << "2" << " " << "3" << " " << "4\n";
	for (int row = 0; row < 4; row++) {
		r = row + 1;
		cout << r << " |" << board[row][0] << "|" << board[row][1] << "|" << board[row][2] << "|" << board[row][3] << "|" << "\n";
	}
	cout << "____________\n";
}

int Chessboard::checkWin() {
	int output = 0;
	if (checkRows() > 0 || checkColumns() > 0 || checkDiagonals() > 0) {
		output = checkRows() + checkColumns() + checkDiagonals();
	}
	return output;
}

int Chessboard::checkRows() {
	for (int row = 0; row < 4; row++) {
		int foundX = 0;
		int foundO = 0;
		for (int column = 0; column < 4; column++) {
			if (board[row][column] == 'x') {
				foundX++;
			}
			else if (board[row][column] == 'o') {
				foundO++;
			}
		}
		if (foundX == 4) {
			return 1;
		}
		if (foundO == 4) {
			return 2;
		}
	}
	return 0;
}

int Chessboard::checkColumns() {
	for (int column = 0; column < 4; column++) {
		int foundX = 0;
		int foundO = 0;
		for (int row = 0; row < 4; row++) {
			if (board[row][column] == 'x') {
				foundX++;
			}
			else if (board[row][column] == 'o') {
				foundO++;
			}
		}
		if (foundX == 4) {
			return 1;
		}
		if (foundO == 4) {
			return 2;
		}
	}
	return 0;
}

int Chessboard::checkDiagonals() {
	if (board[0][0] == 'x' and board[1][1] == 'x' and board[2][2] == 'x' and board[3][3] == 'x') {
		return 1;
	}
	else if (board[0][0] == 'o' and board[1][1] == 'o' and board[2][2] == 'o' and board[3][3] == 'o') {
		return 2;
	}
	else if (board[0][3] == 'x' and board[1][2] == 'x' and board[2][1] == 'x' and board[3][0] == 'x') {
		return 1;
	}
	else if (board[0][3] == 'o' and board[1][2] == 'o' and board[2][1] == 'o' and board[3][0] == 'o') {
		return 2;
	}
	else {
		return 0;
	}
}