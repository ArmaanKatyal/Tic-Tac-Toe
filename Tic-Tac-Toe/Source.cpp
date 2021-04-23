#include <iostream>
#include <string>
using namespace std;
// This is a tic tac toe game. it can be played by two players at a time and it is co-ordinate based game.
const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);

int main() {
	runGame();
	return 0;
}

void runGame(){
	string ticArray[ROWS][COLS];
	initializeGameBoard(ticArray);
	printCurrentBoard(ticArray);
	while (true) {
		if (isBoardFull(ticArray) != true) {
			for (int i = 0; i < 9; i++) {
				if (i % 2 == 0) 
				{
					getUserInput(true, ticArray);
					printCurrentBoard(ticArray);
					string result = getWinner(ticArray);
					if (result != "") 
					{
						cout << result << endl;
						break;
					}
					else 
					{
						continue;
					}
				}
				else {
					getUserInput(false, ticArray);
					printCurrentBoard(ticArray);
					string result = getWinner(ticArray);
					if (result != "") {
						cout << result << endl;
						break;
					}
					else {
						continue;
					}
				}
			}
			break;
		}
		else {
			cout << "The game is draw. No one is the winner!" << endl;
			break;
		}
	}
}

void initializeGameBoard(string gameBoard[ROWS][COLS]){
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			gameBoard[i][j] = " ";
		}
	}
}

void printCurrentBoard(string gameBoard[ROWS][COLS]){
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (j == 0 || j == 1) {
				cout << gameBoard[i][j] << " | ";
			}
			else {
				cout << gameBoard[i][j];
			}
		}
		cout << endl;
		if (i == 0 || i == 1) {
			cout << "- - - - - -" << endl;
		}
	}
}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]){
	if (xTurn == true) {
		// X turn Code
		while (true) {
			int rowInput, colInput;
			cout << "X's Turn, Please enter the row and col (0,1,2) :" << endl;
			cin >> rowInput >> colInput;
			if (cellAlreadyOccupied(rowInput, colInput, gameBoard)) {
				cout << "The cell is already filled. Please try again" << endl;
				continue;
			}
			else {
				gameBoard[rowInput][colInput] = "X";
				break;
			}
		}
	}
	else if(xTurn == false){
		while (true) {
			int rowInput, colInput;
			cout << "O's Turn, Please enter the row and col (0,1,2) :" << endl;
			cin >> rowInput >> colInput;
			if (cellAlreadyOccupied(rowInput, colInput, gameBoard)) {
				cout << "The cell is already filled. Please try again" << endl;
				continue;
			}
			else {
				gameBoard[rowInput][colInput] = "O";
				break;
			}
		}
	}
}

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]){
	if (gameBoard[row][col] == " ") {
		return false;
	}
	return true;
}

string getWinner(string gameBoard[ROWS][COLS]){
	for (int i = 0; i < ROWS; i++) {
		if (gameBoard[i][0] == "O" && gameBoard[i][1] == "O" && gameBoard[i][2] == "O") {
			return "O is the winner of this game";
		}
		else if (gameBoard[i][0] == "X" && gameBoard[i][1] == "X" && gameBoard[i][2] == "X") {
			return "X is the winner of this game";
		}
		else if (gameBoard[0][i] == "O" && gameBoard[1][i] == "O" && gameBoard[2][i] == "O") {
			return "O is the winner of this game";
		}
		else if (gameBoard[0][i] == "X" && gameBoard[1][i] == "X" && gameBoard[2][i] == "X") {
			return "X is the winner of this game";
		}
	}
	if (gameBoard[0][0] == "X" && gameBoard[1][1] == "X" && gameBoard[2][2] == "X") {
		return "X is the winner of this game";
	}
	else if (gameBoard[0][0] == "O" && gameBoard[1][1] == "O" && gameBoard[2][2] == "O") {
		return "O is the winner of this game";
	}
	else if (gameBoard[0][2] == "X" && gameBoard[1][1] == "X" && gameBoard[2][0] == "X") {
		return "X is the winner of this game";
	}
	else if (gameBoard[0][2] == "O" && gameBoard[1][1] == "O" && gameBoard[2][0] == "O") {
		return "O is the winner of this game";
	}
	return "";
}

bool isBoardFull(string gameBoard[ROWS][COLS]){
	int count = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (gameBoard[i][j] != " ") {
				count++;
			}
		}
	}
	if (count == 9) {
		return true;
	}
	return false;
}
