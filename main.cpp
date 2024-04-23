/**
 * Created by Roy Molina on 04-22-24
 *
 * Chess Elo Score Calculator
 *    - Stores entered values and calculates Elo ratings for two players at a time
 *    - Input validation to store correct values and prevent exceptions / miscalculations
 *    - Looping input that only quits when the user inputs the 'quit' keyword
 *    - Object-Oriented Approach with Calc Class and simplified Main Method
 *
 * Latest Version : v1.0 (04-22-24)
 */

#include "calc.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

double checkElo (double a, char player);
int checkNum (int a);
int main() {
    //variables for main
    char choice;
    int result;
    double player1, player2;
    Calc eloCalc;

    //greeting + 1st iteration of input loop
    cout << "Welcome to the Chess Elo Calculator! Input Player A's Elo followed by Player B's Elo, " <<
         "and the result of the match to calculate their new Elo Scores!" << endl;

    cout << "Player A's Current Elo Score: ";
    cin >> player1;
    player1 = checkElo(player1, 'A');
    cout << endl;

    cout << "Player B's Current Elo Score: ";
    cin >> player2;
    player2 = checkElo(player2, 'B');
    cout << endl;

    cout << "Who won the match?" << endl << "1 - Player A Won" << endl << "2 - Player B Won" << endl <<
            "0 - It was a draw" << endl;
    cout << "Input Result: ";
    cin >> result;
    result = checkNum(result);

    eloCalc.setValues(player1, player2, result);
    eloCalc.printElo();

    //looping input
    do {

        cout << endl << endl << "Would you like to Calculate More Elo?" << endl << "\t\t Y  /  N  ?" << endl;
        cout << "Continue? : ";
        cin >> choice;
        tolower(choice);

        //if yes is selected, input is asked for again and elo is calculated once more
        if (choice == 'y')
        {
            cout << endl;

            cout << "Player A's Current Elo Score: ";
            cin >> player1;
            player1 = checkElo(player1, 'A');
            cout << endl;

            cout << "Player B's Current Elo Score: ";
            cin >> player2;
            player2 = checkElo(player2, 'B');
            cout << endl;

            cout << "Who won the match?" << endl << "1 - Player A Won" << endl << "2 - Player B Won" << endl <<
                 "0 - It was a draw" << endl;
            cout << "Input Result: ";
            cin >> result;
            result = checkNum(result);

            eloCalc.setValues(player1, player2, result);
            eloCalc.printElo();

        }
    }while(choice != 'n');

    cout << endl << endl << "Thank you for using my Chess Elo Calculator. Have a great day!";

    return 0;
}

//check elo to make sure it's not negative
double checkElo (double a, char player) {

    //check elo scores
    if (a < 0)
    {
        do
        {
            cout << endl << "Error! Elo cannot be negative! Please re-enter Elo with a non-negative value." << endl;
            cout << "Re-enter Elo: ";
            cin >> a;
        }while( a < 0);
    }

    return a;
}

//make sure that choice is one of the three options and nothing else
int checkNum (int a){

    do{
        switch(a)
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                cout << "Error! Not a valid option!" << endl;
                cout << "Who won the match?" << endl << "1 - Player A Won" << endl << "2 - Player B Won" << endl <<
                     "0 - It was a draw" << endl;
                cout << "Input Result: ";
                cin >> a;
        }
    }while ( (a < 0) || (a > 2) );

    return a;
}