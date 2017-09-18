#include <iostream> //Imports.
#include <cstdlib>
#include <ctime>

/* Guessing Game
 * Author: Nour Yehia
 * This program choses a random number between 0 and 100, and counts how many times it takes the user to guess it. 
 */

using namespace std;

int main(){

  int guess; //Create variables.
  int count = 0;
  char again;
  bool stillPlaying = true; //Playing condition.
  while (stillPlaying == true){
    srand(time(NULL));
    int number = (rand()%100)+1; //Chose number.
    cout << "Guess the number!" << endl ; //Prompt user.
    while (guess != number){ 
      cin >> guess;
      if (guess < number){ //If guess is smaller.
	cout<< "The number is greater." << endl;
	count++;
      }
      else if (guess > number){
	cout << "The number is smaller." << endl; //If guess is bigger.
	count++;
      }
    }
    if (guess == number){ //If guess is right.
      count++;
      cout << "You got it! The number is " <<  number << "." << endl;
      cout << "It took you " << count << " tries." << endl;
      cout << "Do you want to play again?" << endl; //Prompt user.
      cin >> again;
      while ((again != 'Y')&&(again !='y')&&(again != 'N')&&(again != 'n')){
	cout << "Please enter 'Y' or 'N' as an answer" << endl;
	cin >> again;
      }
      if (again == 'y') {
	stillPlaying = true; //Restart Game
      }
      else if (again == 'n'){
	stillPlaying = false; //End Game
      }
    }
  }
}
