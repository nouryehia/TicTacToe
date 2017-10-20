#include <iostream>
#include <cstring>

/* Tic Tac Toe
 * Author: Nour Yehia
 * Date: 10-20-17
 * This program allows two  users to play a game of Tic Tac Toe against each other. */

using namespace std;

char board[4][4]; //Declare variables and functions.
void initializeBoard();
void printBoard();
bool fullBoard();
bool checkWin(int person);
bool checkTie();
int xMove = 1;
int oMove = 2;
int xTurn = 0;
int oTurn = 1;
int turn = xTurn;
int xWins = 0;
int oWins = 0;
char answer;
int row;
int column;

int main(){
  bool playing = true;
  char input[3];
  input[2] = '\0';
  initializeBoard(); //Empty grid.
  while (playing == true){ //While user still wants to play.
    while (checkWin(xMove) == false && checkWin(oMove) == false && checkTie() == false){ //While there is no win or tie.
      printBoard();//Print grid.
      cin >> input; //Take user input.
      if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){ //Check if input translates to a move.
	cout << "Please enter a row (a, b, or c) followed by a column (1, 2, 3)." << endl;
      }
      else if(input[1] != '1' && input[1] != '2' && input[1] != '3'){
	cout << "Please enter a row (a, b, or c) followed by a column (1, 2, 3)." << endl;
      }
      else{
	row = input[0] - 'a' + 1;
	column = input[1] - '1' + 1;
	if (board[row][column] != ' '){ //Check if move is legal.
	  cout << "There is already a piece there" << endl;
	}
	else if (turn == xTurn){ //Draw X.
	  board[row][column] = 'X';
	  checkWin(xMove);
	  turn = oTurn;
	}
	else if (turn == oTurn){ //Draw O.
	  board[row][column] = 'O';
	  checkWin(oMove);
	  turn = xTurn;
	}
      }
    }

    if (checkWin(xMove) == true){ //Print out results.
      printBoard();
      xWins += 1;
      cout << "X wins!" << endl;
    }
    if (checkWin(oMove) == true){
      printBoard();
      oWins += 1;
      cout << "O wins!" << endl;
    }
    if (checkTie() == true){
      printBoard();
      cout << "It's a tie!" << endl;
    }
    if (xWins == 1){
      cout << "X: 1 win." << endl;
    }
    else if (xWins != 1){
      cout << "X: " << xWins << " wins." << endl;
    }
    if (oWins == 1){
      cout << "O: 1 win." << endl;
    }
    else if (oWins != 1){
      cout << "O: " << oWins << " wins." << endl;
    }

    cout << "Do you want to play again?" << endl; //Prompt to play again.
    cin >> answer;
    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'){
      cout << "Please enter 'Y' for yes and 'N' for no." << endl;
      cin >> answer;
    }
    if (answer == 'Y' || answer == 'y') { //Restart game if yes.
      initializeBoard();
      turn = xTurn;
      playing = true;
    }
    if (answer == 'N' || answer == 'n') { //End game if no.
      playing = false;
    }
  }
}

void initializeBoard(){ //Empty and label the grid.
  board[0][0] = ' ';
  board[0][1] = '1';
  board[0][2] = '2';
  board[0][3] = '3';
  board[1][0] = 'a';
  board[1][1] = ' ';
  board[1][2] = ' ';
  board[1][3] = ' ';
  board[2][0] = 'b';
  board[2][1] = ' ';
  board[2][2] = ' ';
  board[2][3] = ' ';
  board[3][0] = 'c';
  board[3][1] = ' ';
  board[3][2] = ' ';
  board[3][3] = ' ';
}

void printBoard(){ //Print grid.
  for(int i= 0; i<4; i++){
    for(int j=0; j<4; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool fullBoard(){ //Check if the grid is full
  if (board[1][1] != ' ' && board[1][2] != ' ' && board[1][3] != ' ' &&
      board[2][1] != ' ' && board[2][2] != ' ' && board[2][3] != ' ' &&
      board[3][1] != ' ' && board[3][2] != ' ' && board[3][3] != ' '){
    return true;
  }
  return false;
}

bool checkWin(int person){ //Check all possible wins.
  char player = 'X';
  if (person == oMove) {
    player = 'O';
  }
  if (board[1][1] == player && board[1][2] == player && board[1][3] == player) {
    return true;
  }
  if (board[2][1] == player && board[2][2] == player && board[2][3] == player) {
    return true;
  }
  if (board[3][1] == player && board[3][2] == player && board[3][3] == player) {
    return true;
  }
  if (board[1][1] == player && board[2][1] == player && board[3][1] == player) {
    return true;
  }
  if (board[1][2] == player && board[2][2] == player && board[3][2] == player) {
    return true;
  }
  if (board[1][3] == player && board[2][3] == player && board[3][3] == player) {
    return true;
  }
  if (board[1][1] == player && board[2][2] == player && board[3][3] == player) {
    return true;
  }
  if (board[1][3] == player && board[2][2] == player && board[3][1] == player) {
    return true;
  }
  return false;
}

bool checkTie(){ //Check if it is a tie.
  if (fullBoard() == true && checkWin(xMove) == false && checkWin(oMove) == false){
    return true;
  }
  return false;
}
