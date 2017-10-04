#include <iostream>
#include <cstring>

/* Palindrome
 * Author: Nour Yehia
 * Date: 9-28-17
 * This program reads in a series of chars, removes punctuation, and checks if the array makes up a palindrome.
 */ 

using namespace std;

int main(){

  char input[80]; //Declare strings to be used.
  char alpha[80];
  char output[80];
  input[80] = '\0';
  alpha[80] = '\0';
  output[80] = '\0';
  int count = 0; //Declare counters to be used.
  int count1 = 0;
  
  cin.get(input, 80); //Read in input.
  
  for (int i = 0; i < strlen(input); i++) { //Legalize input.
    if (isalpha(input[i])!=0){ //Remove non-alpha characters.
      input[i] = tolower(input[i]); //Convert everything to lowercase.
      alpha[count]= input[i];
      count++;
    }
  }
  alpha[count] = '\0';
  
  for (int i = count-1; i >= 0; i--){ //Check what the imput is backwards.
    output[count1] = alpha[i];
    count1++;
  }
  output[count1] = '\0';
  
  if (strcmp(alpha, output)==0){ //If forward and backwards are the same...
    cout << alpha << " is a palindrome!" << endl; //Palindrome!
  }
  else{ //If they're not...
    cout << alpha << " is not a palindrome." << endl; //No palindrome. 
  }
} 
