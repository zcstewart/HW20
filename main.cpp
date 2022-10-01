//Homework 20

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to create a simulation
 *                      of a Tic-Tac-Toe game for two users to play.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               2/13/2017 16:30 PST
 */

//Preprocessor Directives
#include <cstdlib>
#include "TicTacToe.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//
//  ***MAIN function***

//Inputs:   none
//Outputs:  none
//Purpose:  The purpose of this program is to include the TicTacToe class
//          in order to combine all of the separate files. The program will
//          create an object 'game' of type 'TicTacToe'. The program will
//          then call the play() function of the class in order to execute
//          the program.
int main(int argc, char** argv)
{
    //Declare object of type TicTacToe (initialized by default constructor)
    TicTacToe game;
    //Play TicTacToe game
    game.play();
    //Arbitrary exit call
    //Included as safety measure
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

