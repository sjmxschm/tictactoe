/*
This programm creates a simple version of TicTacToe. It
____
1. Creates a 4x4 game board
____
2.1 Prompts the first user (the 'x' user) to enter their name
2.2 Prompts the second user (the 'o' user) to enter their name
____
3.1. Prompts the 'x' user to select a grid position where they would like to place an 'x'.
3.2. Prompts the 'o' user to select a grid position where they would like to place an 'o'.
____
4. After each user has a turn, check for any row, column, diagonal that has 4 'x's or 4 'o's.
____
5.1. If 4 'x's are found in the same col, row, diagonal, declare the 'x' user the winner.
5.2. If 4 'o's are found in the same col, row, diagonal, declare the 'o' user the winner.
____
6. End the game and declare the winner.
____
7. If the grid is filled (each player gets 8 turns) and there is not a row, column, diagonal
	with 4 of the same symbol, the game is tied. Declare a tie game.
*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#include "mainClasses.cpp"

int main() {
	string playerNameTemp;
	string playingMode;
	int playingModeIn;
	char symbolIn;
	int playing = 0;


	// create chessboard
	Chessboard board;

	// create users
	Player player1, player2;
	
	cout << "\n___ TicTacToe Ultimate ____\n";

	// select playing mode
	cout << "Please select the game type:\n";
	cout << "---> type >>> 1 <<< for single Player to play against the computer or\n";
	cout << "---> type >>> 2 <<< for dual Player mode \n-->";
	cin >> playingModeIn;
	if (playingModeIn == 1)
		playingMode = "computerPlayer";
	else if (playingModeIn == 2)
		playingMode = "normalPlayer";
	else
		cout << "\nYour input does not match 1 or 2, please start program again!";

	// promt users to enter names
	cout << "\nPlease specify Player 1 name:\n";
	cin >> playerNameTemp;
	player1.setName(playerNameTemp);

	if (playingMode == "normalPlayer") {
		cout << "\nPlease specify Player 2 name:\n";
		cin >> playerNameTemp;
	}
	else {
		playerNameTemp = "Computer";
		cout << "\n";
	}
	player2.setName(playerNameTemp);

	int movesPlayed = 0;
	while (movesPlayed <= 16) {

		symbolIn = 'x';
		board.setBoardElement(symbolIn, player1.getName(),"normalPlayer");
		board.printBoard();
		cout << "\n______________________\n";
		movesPlayed++;
		
		// check if someone won already
		if (board.checkWin() > 0) {
			break;
		}

		symbolIn = 'o';
		board.setBoardElement(symbolIn, player2.getName(), playingMode);
		board.printBoard();
		cout << "\n______________________\n";
		
		movesPlayed++;

		// check if someone won already
		if (board.checkWin() > 0) {
			break;
		}
	}

	// end game and declare winner or declare tie
	cout << "\n#######################################\n";
	if (board.checkWin() == 1) {
		cout << "We have a winner!! Congrats to " << player1.getName() << "\n";
	}
	else if (board.checkWin() == 2) {
		cout << "We have a winner!! Congrats to " << player2.getName() << "\n";
	}
	else {
		cout << "Game Over - It is a tie!";
	}
	cout << "\n######################################\n";

	return 0;
}
