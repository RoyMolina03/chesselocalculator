//
// Created by Roy Molina on 4/22/24.
//
#include "calc.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//receive values for variables and assigns them to the object (acts as the main function for this class)
void Calc::setValues(double eloA, double eloB, int result) {
    this->playA = eloA;
    this->playB = eloB;
    setK(playA, playB);
    calcOutcome(result);
    calcElo();
}

//calculate k scale variables for each player
void Calc::setK(double eloA, double eloB) {

    //calc k scale for player A
    if (eloA < 1600)
    {
        this->playAk = k1;
    }
    else if (eloA < 2100)
    {
        this->playAk = k2;
    }
    else
    {
        this->playAk = k3;
    }


    //calc k scale for player B
    if (eloB < 1600)
    {
        this->playBk = k1;
    }
    else if (eloB < 2100)
    {
        this->playBk = k2;
    }
    else
    {
        this->playBk = k3;
    }
}

//calculate expected outcome
void Calc::calcOutcome(int result) {

    //update actual outcomes based on match result
    if (result == 1)
    {
        this->actualA = 1.0;
        this->actualB = 0;
    }
    else if (result == 2)
    {
        this->actualA = 0;
        this->actualB = 1.0;
    }
    else
    {
        this->actualA = 0.5;
        this->actualB = 0.5;
    }

    //calculate expected outcome for player A
    this->expectedA = 1 / (1 + pow(10, ( (playB - playA) / 400) ) );


    //calculate expected outcome for player B
    this->expectedB = 1 / (1 + pow(10, ( (playA - playB) / 400) ) );

}

//calculate elo now that all values have been set
void Calc::calcElo() {

    //player A new Elo
    this->newA = playA + (playAk * (actualA - expectedA) );

    //player B new Elo
    this->newB = playB + (playBk * (actualB - expectedB) );
}

//print a message about elo and whether it increased or decreased
void Calc::printElo() {
    double difference = 0;


    difference = newA - playA;
    //player A message
    if (newA > playA)
    {
        cout << endl << "Player A's Elo Increased by " << fixed << setprecision(2) << difference << " points!" << endl;
        cout << "Player A's new Elo is: " << fixed << setprecision(0) << newA;
    }
    else if (newA < playA)
    {
        cout << endl << "Player A's Elo Decreased by " << fixed << setprecision(2) << difference << " points." << endl;
        cout << "Player A's new Elo is: " << fixed << setprecision(0) << newA;
    }
    else
    {
        cout << endl << "Player A's Elo did not change." << endl;
        cout << "Player A's Elo remains at: " << fixed << setprecision(0) << newA;
    }

    difference = 0;
    difference = newB - playB;
    //player B message
    if (newB > playB)
    {
        cout << endl << "Player B's Elo Increased by " << fixed << setprecision(2) << difference << " points!" << endl;
        cout << "Player B's new Elo is: " << fixed << setprecision(0) << newB;
    }
    else if (newB < playB)
    {
        cout << endl << "Player B's Elo Decreased by " << fixed << setprecision(2) << difference << " points." << endl;
        cout << "Player B's new Elo is: " << fixed << setprecision(0) << newB;
    }
    else
    {
        cout << endl << "Player B's Elo did not change." << endl;
        cout << "Player B's Elo remains at: " << fixed << setprecision(0) << newB;
    }

}