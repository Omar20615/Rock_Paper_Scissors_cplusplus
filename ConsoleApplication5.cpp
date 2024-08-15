//  *********Rock Paper Scisors game*********


//   Made by Omar Sibghat, Muhammad Salman, Myhammad Haris Fayyaz, Maham Pervez


#include <iostream>  // header file iostream 
#include<stdlib.h>   // header file stdlib to change color and  use randomize function
#include <string>   // string file for grtline function
#include <fstream>  // header file fstresm to read and write a file

using namespace std;  // using standerd name space

void multiplayer();  // function for multiplayer mode
void singleplayer();  // function for single player mode
void filehandling();   // function to read a file

struct results   // structure which is declaring almost all the variables
{
	string name_1;    // declaring name_1 for name of user 1
	string name_2;    // declaring name_2 for name of user 2 
	int wins = 0;      // wins of user 1 or loses of user 2 at start 0
	int loses = 0;     // loses of user 1 or wins of user 2  at start 0
	int draw = 0;      // draws if user 1 or user 2 at start 0
	int mode = 0;      // declaring mode to ask user for game mode
	int choice_1 = 0;    // declaring choice_1 for choice of user 1
	int choice_2 = 0;    // declaring choice_1 for choice of user 1
	char changemode;     // declaring changemode if user wants to chamge mode
	int save = 0;       // declaring save to ask user if they want to save data
};

int main()      // main program starts here
{
	system("Color 0a");   // changing background and font color
	results obj;

	//*Rules of the game*//
	cout << "\t\t" << "GAMES RULES:" << endl;
	cout << "Rock beats scissors" << endl;
	cout << "Scissors beats paper" << endl;
	cout << "Paper beats Rock" << endl;
	cout << endl;
	cout << "Enter The Mode:  " << endl;   // asking from the user which mode he/she want to play //
	cout << "Press 1 for Multiplayer mode" << endl;  // for multiplayer mode press 1 //
	cout << "Press 2 for Single player mode" << endl; // for single player mode press 2 //
	cout << "Press 3 if you only want to see previous records" << endl; //if user wants to see previous data//
	cin >> obj.mode;
	cout << endl;

	system("CLS");  // clearing screen

	switch (obj.mode)    // using switch because there are two modes in - game
	{
	case 1:   // case 1 for multiplayer game mode
	{
		multiplayer();  // calling multiplayer function
		break;
	}
	case 2:    // case 2 for single player game mode
	{
		singleplayer();  // calling single player function
		break;

	}
	case 3:   // case 3 to check previous results
	{
		filehandling();
		break;
	}
	}
}


void multiplayer()
{
	cout << "--------------Welcome to multiplayer mode--------------" << endl;
	results obj;

	// **in starting there is no wins and draws from both the players** //

	char again;
	cout << "Player 1 enter your name:";
	cin.ignore();
	getline(cin, obj.name_1);  // name of the first player //
	cout << "Player 2 enter your name:";

	getline(cin, obj.name_2);                                   //name of the second player
	system("CLS");     //screen cleared //
	do
	{

		cout << "--------------------------------------------------------------" << endl;
		cout << "Lets play Rock Paper Scissors game" << endl;
		cout << "--------------------------------------------------------------" << endl;


		cout << obj.name_1 << endl;
		cout << "what do you want to choose:" << endl;
		cout << "press 1 for Rock" << endl;
		cout << "press 2 for Paper" << endl;
		cout << "press 3 for Scissors" << endl;
		cin >> obj.choice_1;           //  player 1 choose your move //
		cout << endl;

		system("CLS");

		cout << "------------------------------------------------------------------" << endl;
		cout << "Lets play Rock Paper Scissors game" << endl;
		cout << "------------------------------------------------------------------" << endl;


		cout << obj.name_2 << endl;
		cout << "what do you want to choose:" << endl;
		cout << "press 1 for Rock" << endl;
		cout << "press 2 for Paper" << endl;
		cout << "press 3 for Scissor" << endl;
		cin >> obj.choice_2;          // player 2 choose your move //
		cout << endl;

		system("CLS");

		cout << "-----------------------------------------------------" << endl;
		cout << "Let's play Rock Paper Scissors game" << endl;
		cout << obj.name_1 << "\t VS \t" << obj.name_2 << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << endl;
		if (obj.choice_1 == 1 && obj.choice_2 == 1)        //when both the player choose is Rock //
		{
			cout << obj.name_1 << "\t" << "chose Rock" << endl;
			cout << obj.name_2 << "\t" << "chose Rock" << endl;
			cout << " It's a  Draw" << endl;
			obj.draw++;
		}
		else if (obj.choice_1 == 2 && obj.choice_2 == 2)    //when both player choose is paper  //
		{
			cout << obj.name_1 << "\t" << "chose Paper" << endl;
			cout << obj.name_2 << "\t" << "chose Paper" << endl;
			cout << "It's a draw" << endl;
			obj.draw++;
		}
		else if (obj.choice_1 == 3 && obj.choice_2 == 3)      //when both player choose is scissors //
		{
			cout << obj.name_1 << "\t" << "chose Scissors" << endl;
			cout << obj.name_2 << "\t" << "chose Scissors" << endl;
			cout << "It's a draw" << endl;
			obj.draw++;
		}
		else if (obj.choice_1 == 2 && obj.choice_2 == 3)  // when first player choose paper and second player choose scissors //
		{
			cout << obj.name_1 << "\t" << "chose Paper" << endl;
			cout << obj.name_2 << "\t" << "chose Scissors" << endl;
			cout << "Scissors beats Paper" << endl;
			cout << obj.name_2 << " Wins !!!!!" << endl;
			obj.loses++;
		}
		else if (obj.choice_1 == 1 && obj.choice_2 == 2)   // when first player choose is Rock and second player choose is paper //
		{
			cout << obj.name_1 << "\t" << "chose Rock" << endl;
			cout << obj.name_2 << "\t" << "chose Paper" << endl;
			cout << "Paper beats Rock" << endl;
			cout << obj.name_2 << " Wins !!!!!" << endl;
			obj.loses++;
		}
		else if (obj.choice_1 == 3 && obj.choice_2 == 1)  //when player one choose is scissors and second player choose is Rock //
		{
			cout << obj.name_1 << "\t" << "chose Scissors" << endl;
			cout << obj.name_2 << "\t" << "chose Rock" << endl;
			cout << "Rock beats Scissors" << endl;
			cout << obj.name_2 << " Wins !!!!!" << endl;
			obj.loses++;
		}
		else if (obj.choice_1 == 1 && obj.choice_2 == 3)    //when first player choose is Rock and second player choose is scissors //
		{
			cout << obj.name_1 << "\t" << "chose Rock" << endl;
			cout << obj.name_2 << "\t" << "chose Scissors" << endl;
			cout << "Rock beats Scissors" << endl;
			cout << obj.name_1 << " Wins !!!!!" << endl;
			obj.wins++;
		}
		else if (obj.choice_1 == 2 && obj.choice_2 == 1)   // when player one choose is paper and second player choose is Rock //
		{
			cout << obj.name_1 << "\t" << "chose Paper" << endl;
			cout << obj.name_2 << "\t" << "chose Rock" << endl;
			cout << "Paper beats Rock" << endl;
			cout << obj.name_1 << " Wins !!!!!" << endl;
			obj.wins++;
		}
		else if (obj.choice_1 == 3 && obj.choice_2 == 2)  //when player one choose is scissors and second player choose is paper //
		{
			cout << obj.name_1 << "\t" << "chose Scissors" << endl;
			cout << obj.name_2 << "\t" << "chose Paper" << endl;
			cout << "Scissors Beat Paper" << endl;
			cout << obj.name_1 << " Wins !!!!!" << endl;
			obj.wins++;
		}
		else
		{
			cout << "You didn't select from the given option" << endl;
		}
		cout << endl;

		cout << obj.name_1 << " Total Wins= " << obj.wins << endl;    // displaying results
		cout << obj.name_2 << " Total Wins= " << obj.loses << endl;
		cout << "Total draws= " << obj.draw << endl;

		cout << endl;

		cout << "Do you want to play again" << endl;    // asking user if they want to play again
		cout << "To play again press 'y' or 'Y'" << endl;
		cin >> again;
		system("CLS");  // screen cleared for next play //
	} while (again == 'y' || again == 'Y');

	cout << "Do you want to play in single player mode or quit ?" << endl;  // asking user if they want to play different game mode
	cout << "Press 'y' or 'Y' if you want to change modes" << endl;
	cin >> obj.changemode;

	if (obj.changemode == 'y' || obj.changemode == 'Y')  // if user wants to change game mode
	{
		system("CLS");  // clearing screen

		cout << "Do you want to store data " << endl;    // asking if user wants to save the results in a file
		cout << "Press 1 if you want to store data :";
		cin >> obj.save;

		if (obj.save == 1)   // if user wants to save data
		{
			fstream store;

			store.open("result.txt", ios::app);  // opening file 

			// saving data in the file //

			store << "Multiplayer game mode " << endl;
			store << obj.name_1 << endl;
			store << "Total wins =" << obj.wins << endl;
			store << "Total draws =" << obj.draw << endl;
			store << "Total loses=" << obj.loses << endl;
			store << endl;
			store << obj.name_2 << endl;;
			store << "Total wins =" << obj.loses << endl;
			store << "Total draws =" << obj.draw << endl;
			store << "Total loses =" << obj.wins << endl;
			store << endl;

			store.close();  // closing file
		}
		system("CLS");
		singleplayer();  // calling singleplayer function
	}
	else   // if user wants to quit
	{
		cout << "Thank you for playing" << endl;   // displaying gratitude

		cout << "Do you want to store data " << endl;     // asking if user wants to save the results in a file
		cout << "Press 1 if you want to store data :";
		cin >> obj.save;

		if (obj.save == 1)   // if user wants to save data
		{
			fstream store;

			store.open("result.txt", ios::app);   // opening file 

			// saving data in the file //

			store << "Multiplayer game mode " << endl;
			store << obj.name_1 << endl;
			store << "Total wins =" << obj.wins << endl;
			store << "Total draws =" << obj.draw << endl;
			store << "Total loses=" << obj.loses << endl;
			store << endl;
			store << obj.name_2 << endl;;
			store << "Total wins =" << obj.loses << endl;
			store << "Total draws =" << obj.draw << endl;
			store << "Total loses =" << obj.wins << endl;
			store << endl;

			store.close();   // closing file
		}

	}
}


void singleplayer()  // function for single playermode
{
	cout << "--------------Welcome to single player mode--------------" << endl;
	results obj;
	//* in start there is no win ,lose and draw *// 
	char again;
	cout << "Enter your name : ";   // asking for user name
	cin.ignore();
	getline(cin, obj.name_1);

	system("CLS");
	do
	{

		cout << "-----------------------------------------------------" << endl;
		cout << "Let's play Rock Paper Scissors game   " << obj.name_1 << endl;
		cout << "-----------------------------------------------------" << endl;

		cout << "what do you want to choose:" << endl;
		cout << "press 1 for Rock" << endl;
		cout << "press 2 for Paper" << endl;
		cout << "press 3 for Scissors" << endl;
		cin >> obj.choice_1;     //  choose your move //
		cout << endl;
		system("CLS");

		int computer = rand() % 3 + 1;
		// random choose of the computer and probability of Rock ,paper and scissors is 33.3 percent //

		cout << "-----------------------------------------------------" << endl;
		cout << "Let's play Rock  Paper  Scissors game" << endl;
		cout << "-----------------------------------------------------" << endl;

		if (computer == 1 && obj.choice_1 == 1)   //when computer choose is Rock and player choose is also rock //
		{
			cout << obj.name_1 << "\t" << "you chose Rock " << endl;
			cout << "Computer" << "\t" << "chose Rock" << endl;
			cout << "It's a draw" << endl;
			obj.draw++;
		}
		else if (computer == 2 && obj.choice_1 == 2) //when computer choose is paper and user choose is paper //
		{
			cout << obj.name_1 << "\t" << "you chose Paper" << endl;
			cout << "Computer" << "\t" << "chose Paper" << endl;
			cout << "It's a draw" << endl;
			obj.draw++;
		}
		else if (computer == 3 && obj.choice_1 == 3) //when computer choose is scissors and user choose is scissors //
		{
			cout << obj.name_1 << "\t" << "you chose Scissors" << endl;
			cout << "Computer" << "\t" << "chose Scissors" << endl;
			cout << "It's a draw" << endl;
			obj.draw++;
		}
		else if (computer == 1 && obj.choice_1 == 3)  // when computer choose is Rock and user choose is scissors //
		{
			cout << obj.name_1 << "\t" << "you chose Scissors" << endl;
			cout << "Computer" << "\t" << "chose  Rock" << endl;
			cout << "Rock beats Scissors" << endl;
			cout << "Computer wins" << endl;
			obj.loses++;
		}
		else if (computer == 2 && obj.choice_1 == 1) //when computer choose is paper and user choose is Rock //
		{
			cout << obj.name_1 << "\t" << "you chose Rock" << endl;
			cout << "Computer" << "\t" << "chose Paper" << endl;
			cout << "Paper beats Rock" << endl;
			cout << "Computer wins" << endl;
			obj.loses++;
		}
		else if (computer == 3 && obj.choice_1 == 2) // when computer choose is scissors and player choose is paper //
		{
			cout << obj.name_1 << "\t" << "you chose Paper" << endl;
			cout << "Computer" << "\t" << "chose Scissors" << endl;
			cout << "Scissors beat Paper" << endl;
			cout << "Computer wins" << endl;
			obj.loses++;
		}
		else if (computer == 3 && obj.choice_1 == 1) //when computer choose is scissors and user choose is Rock //
		{
			cout << obj.name_1 << "\t" << "you chose Rock" << endl;
			cout << "Computer" << "\t" << "chose Scissors" << endl;
			cout << "Rock beats Scissors" << endl;
			cout << obj.name_1 << " Wins !!!!!" << endl;
			obj.wins++;
		}
		else if (computer == 2 && obj.choice_1 == 3) // when computer choose is paper and player choose is scissors //
		{
			cout << obj.name_1 << "\t" << "you chose Scissors" << endl;
			cout << "Computer" << "\t" << "chose Paper" << endl;
			cout << "Scissors beat Paper" << endl;
			cout << obj.name_1 << " Wins!!!!!" << endl;
			obj.wins++;
		}
		else if (computer == 1 && obj.choice_1 == 2) // when computer choose is Rock and user choose is paper //
		{
			cout << obj.name_1 << "\t" << "you chose Paper" << endl;
			cout << "Computer" << "\t" << "choose Rock" << endl;
			cout << "Paper beats Scissors" << endl;
			cout << obj.name_1 << " Wins !!!!! " << endl;
			obj.wins++;
		}
		else
		{
			cout << "your move is invaild" << endl;
		}
		cout << endl;

		cout << obj.name_1 << " Total Wins=" << obj.wins << endl;   // displaying results
		cout << obj.name_1 << " Total loses=" << obj.loses << endl;
		cout << obj.name_1 << " Total draws=" << obj.draw << endl;
		cout << endl;

		cout << "Do you want to play again" << endl;   // asking if the user wants to play again
		cout << "yes  then press 'y' or 'Y'" << endl;
		cin >> again;

		system("CLS");  // clearing screen

	} while (again == 'y' || again == 'Y');

	cout << "Do you want to play multiplayer mode ? " << endl;    // asking if user wants to change game mode
	cout << "Prees Y or y if you want to play different mode" << endl;
	cin >> obj.changemode;

	if (obj.changemode == 'y' || obj.changemode == 'Y') // if user changes game mode
	{
		system("CLS");
		cout << "Do you want to store data " << endl;
		cout << "Press 1 if you want to store data :";   // asking if user wants to save the results in a file
		cin >> obj.save;

		if (obj.save == 1)   // if user wants to save data
		{
			fstream store;

			store.open("result.txt", ios::app);   // opening file

			// saving data in a file //

			store << "single player mode" << endl;
			store << obj.name_1 << endl;
			store << "Total wins =" << obj.wins << endl;
			store << "Total draws =" << obj.draw << endl;
			store << "Total loses =" << obj.loses << endl;
			store << endl;

			store.close();  // closing the file
		}
		system("CLS");

		multiplayer();  // calling multiplayer function
	}
	else
	{
		cout << "Thanks for Playing" << endl;   // displaying gratitude

		cout << "Do you want to store data " << endl;     // asking if user wants to save the results in a file
		cout << "Press 1 if you want to store data :";
		cin >> obj.save;

		if (obj.save == 1)   // if user wants to save data
		{
			fstream store;

			store.open("result.txt", ios::app);  // opening file

			// saving data in a file //

			store << "single player mode" << endl;
			store << obj.name_1 << endl;
			store << "Total wins =" << obj.wins << endl;
			store << "Total draws =" << obj.draw << endl;
			store << "Total loses =" << obj.loses << endl;
			store << endl;

			store.close();   // closing the file
		}

	}
}


void filehandling()   // function to read data from file
{
	string s;
	ifstream store;
	store.open("result.txt", ios::in); // opening file
	while (getline(store, s))  // getting data
	{
		cout << s << endl; //displaying data
	}
	store.close();  // closing file
}
