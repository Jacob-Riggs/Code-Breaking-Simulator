// Keywords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;


int main()
{
	char playAgain; // the variable that defines whether or not the user wants to play again or not
	enum fields {WORD, HINT, NUM_FIELDS}; // Enumerator
	const int NUM_WORDS = 10; // Number of words that can be stored
	const string WORDS[NUM_WORDS][NUM_FIELDS] = { // The array that holds the words and the hints for them
		{ "government","What you work for" },
		{ "president","The head of some countries" },
		{ "military","What fights wars" },
		{ "missile","Gets launched" },
		{ "aircraft","Flies in the air" },
		{ "ship","Floats in the water" },
		{ "convoy","Moves things on the ground" },
		{ "radar","Detects movement" },
		{ "airstrike","Bombs from the sky" },
		{ "tank","Treads along on land" }
	};

	srand(static_cast<unsigned int>(time(0))); // Random int

	do { // A do loop that will repeat at least once, but will go if the user wants to to keep playing

		int word1Attempts = 0; // A variable that stores attempts for the first word
		int word2Attempts = 0; // A variable that stores attempts for the second word
		int word3Attempts = 0; // A variable that stores attempts for the third word

		for (int goodAnswers = 0; goodAnswers < 3; goodAnswers++) { // This will make the program run three times for three words

			int choice = (rand() % NUM_WORDS); // This chooses a random word from WORDS
			string theWord = WORDS[choice][WORD]; // This is the word that needs to be guessed
			string theHint = WORDS[choice][HINT]; // This is the hint for that word
			string jumble = theWord; // This is the jumbled of the word
			int length = jumble.size(); // This is the length of the word that was jumbled
			for (int i = 0; i < length; ++i) { // This will jumble the word
				int index1 = (rand() % length); // This makes index1 a random number in the range of the letters
				int index2 = (rand() % length); // This makes index 2 a random number in the range of the letters
				char temp = jumble[index1]; // This looks at the number stored in index1 and finds the letter, setting it to temp
				jumble[index1] = jumble[index2]; // This looks at index1 and finds the number and sets it equal to the letter in index2
				jumble[index2] = temp; // This makes the letter now in index2 equal to what temp had been
			}

			cout << "\t\t\Welcome to the Keywords Code Breaker.\n\n";
			cout << "Unscramble the letters to get the code.\n";
			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the simulation.\n\n";
			cout << "The jumble is: " << jumble; // Displays the jumbled word
			string guess; // Stores the users input
			cout << "\nYour guess: ";
			cin >> guess; // User inputs guess

			if (goodAnswers == 0) { // Goes here if on first word
				word1Attempts++; // Add 1 to attempts for word 1
			}

			else if (goodAnswers == 1) { // Goes here for second word
				word2Attempts++; // Add 1 to attempts for word 2
			}

			else if (goodAnswers == 2) { // Goes here for third word
				word3Attempts++; // Add 1 to attempts for word 3
			}

			while ((guess != theWord) && (guess != "quit")) { // The main loop for the game. While the user doesn't quit and is wrong, it loops
				if (guess == "hint") { // If user enters hint
					cout << theHint; // Displays the hint
				}
				else { // If answer isn't correct
					cout << "Sorry, that's not it.";
				}

				cout << "\n\nYour guess: ";
				cin >> guess; // User inputs guess

				if (goodAnswers == 0) { // Goes here if on first word
					word1Attempts++; // Add 1 to attempts for word 1
				}

				else if (goodAnswers == 1) { // Goes here for second word
					word2Attempts++; // Add 1 to attempts for word 2
				}

				else if (goodAnswers == 2) { // Goes here for third word
					word3Attempts++; // Add 1 to attempts for word 3
				}
			}

			if (guess == theWord) { // If the guess is correct
				cout << "\nThat's it! You guessed it!\n";
				if (goodAnswers == 0) { // Goes here if on first word
					cout << "It took you " << word1Attempts << " try(s) to decrypt this word.\n\n";
				}

				else if (goodAnswers == 1) { // Goes here for second word
					cout << "It took you " << word2Attempts << " try(s) to decrypt this word.\n\n";
				}

				else if (goodAnswers == 2) { // Goes here for third word
					cout << "It took you " << word3Attempts << " try(s) to decrypt this word.\n\n";
				}
			}
		}
		cout << "Congratulations, you have successfully decrypred all the words.\n";
		cout << "Stats: \n" << "Word 1: " << word1Attempts << "\nWord 2: " << word2Attempts << "\nWord 3: " << word3Attempts << endl;
		cout << "Would you like to play again (Y/N)?\n";
		cin >> playAgain; // User input on whether to play again or not.

	} while (playAgain == 'y' || playAgain == 'Y'); // If user wants to play again, it returns to the top of the do loop.
	cout << "Thanks for playing.\n";


	system("pause");
    return 0;
}

