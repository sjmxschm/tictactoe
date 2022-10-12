#pragma once

class Chessboard {
	char board[4][4];
public:
	Chessboard();
	char getBoardElement(int row, int column);
	void setBoardElement(char symbol, string pname, string mode);
	void printBoard();
	int checkWin();
	int checkRows();
	int checkColumns();
	int checkDiagonals();
};