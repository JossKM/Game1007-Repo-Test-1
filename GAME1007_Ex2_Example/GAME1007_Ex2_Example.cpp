#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	///Welcoming the players, getting their inputs for their names
	string Player1, Player2;
	int correctNumber, playerGuess = 0, attempts = 0, playersTurn, guessLimit = 6;
	bool outOfAttempts = false;

	cout << "===================================\n";
	cout << "Hello, welcome to the guessing game! \n";
	cout << "===================================\n";

	cout << "Please enter name of Player 1: ";
	cin >> Player1;
	cout << "Welcome " << Player1 << "!\n\n";

	cout << "Please enter name of Player 2: ";
	cin >> Player2;
	cout << "Welcome " << Player2 << "!\n\n";

	//Generates number from 1-100
	srand(time(0));
	correctNumber = rand() % 100 + 1;


	cout << "A number from 1 - 100 will be generated, guess it right to win the game!(Attempts: 6) \n\n";


	//Generate number from 1-2 for who's turn it is
	playersTurn = rand() % 2 + 1;


	//While players guess is not equal to correct number and is not out of attempts, player 1 goes, if it's not equal to 1 then player 2 goes
	while (playerGuess != correctNumber && !outOfAttempts)
	{
		if (playersTurn == 1)
		{
			cout << Player1;
		}
		else
		{
			cout << Player2;
		}

		//Swaps turns between players
		playersTurn = (1 - (playersTurn - 1)) + 1;

		//Requests a number from user
		cout << ", enter a number: " << endl;
		cin >> playerGuess;
		cout << "\n";
		//Starts counting after a number is entered
		attempts++;


		//If the limit (6) is less than or equal to attemps, the program stops
		if (guessLimit <= attempts)
		{
			cout << "You lost! All 6 attempts were used :( \n";
			break;
		}


		//Tells user if guess is too low or too high, or if they got the answer correct
		if (playerGuess < correctNumber)

		{
			cout << "You guessed too low!\n\n";
		}
		else if (playerGuess > correctNumber)
		{
			cout << "You guessed too high!\n\n" << endl;
		}
		else
		{
			cout << "We have a winner! You got the correct number in " << attempts << " guesses!!\n\n";
			cout << "Thank you for playing!\n\n";
		}
	}
	return 0;
}

