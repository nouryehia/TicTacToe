#include <iostream>
#include <cstring>

/* Tic Tac Toe
 * Author: Nour Yehia
 * Date:
 * This program allows two  users to play a game of Tic Tac Toe against each other. */

using namespace std;

char board[4][4]; //Create grid.
void initializeBoard();
void printBoard();
bool checkWin(int person);
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
  input[3] = '\0';
  while (playing == true){
  initializeBoard();
  checkWin(int player) = false;
  while (checkWin(xMove) == false && checkWin(oMove) == false){
    printBoard();
    cin.get(input, 3);
    cin.ignore(3, '\n');
    if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
      cout << "Please enter a row (a, b, or c) followed by a column (1, 2, 3)." << endl;
    }
    else if(input[1] != '1' && input[1] != '2' && input[1] != '3'){
      cout << "Please enter a row (a, b, or c) followed by a column (1, 2, 3)." << endl;
    }
    else{
      row = input[0] - 'a'+ 1;
      column = input[1] - '1' + 1;
      if (board[row][column] != ' '){
	cout << "There is already a piece there" << endl;
      }
      else if (turn == xTurn){
	board[row][column] = 'X';
	checkWin(xMove);
	turn = oTurn;
      }
      else if (turn == oTurn){
	board[row][column] = 'O';
	checkWin(oMove);
	turn = xTurn;
      }
    }
  }
  if (checkWin(xMove) == true) {
    xWins+= 1;
    cout << "X wins!" << endl;
  }
  if (checkWin(oMove) == true){
    oWins+= 1;
    cout << "O wins!" << endl;
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
  cout << "Do you want to play again?" << endl;
  cin >> answer;
  while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'){
    cout << "Please enter 'Y' for yes and 'N' for no." << endl;
    cin >> answer;
  }
  if (answer == 'Y' || answer == 'y') {
    playing = true;
  }
}
}

void initializeBoard(){
  
  board[0][0] = ' '; //Label grid.
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

void printBoard(){
  for(int i= 0; i<4; i++){ //Print grid.
    for(int j=0; j<4; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool checkWin(int person){
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
