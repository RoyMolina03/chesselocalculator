//
// Created by Roy Molina on 4/22/24.
//

#ifndef ELOCALC_CALC_H
#define ELOCALC_CALC_H
#include <vector>
#include <cstdlib>
using namespace std;

class Calc {
private:
    //constants for scaling variable
    int const k1 = 32;
    int const k2 = 24;
    int const k3 = 16;

    //variables for player elos + new elo scores
    double playA;
    double playB;
    double newA;
    double newB;

    //individual k scores
    int playAk;
    int playBk;

    //expect and actual outcomes
    double expectedA;
    double expectedB;
    double actualA;
    double actualB;

public:
    //setting values
    void setK(double eloA, double eloB);
    void setValues(double eloA, double eloB, int result);
    void calcOutcome(int result);

    //calculating elo
    void calcElo();

    //printing results
    void printElo();


};




#endif //ELOCALC_CALC_H
