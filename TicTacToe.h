//Homework 20

/*
 *  Filename:           TicTacToe.h
 * 
 *  Purpose:            The purpose of this program is to initialize
 *                      the private member variables and public member
 *                      functions of the TicTacToe class.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               2/13/2017 16:30 PST
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

//Preprocessor Directives
#include <iostream>
#include <cstdlib>

//Namespace
using namespace std;

//Enumeration for current status of game
enum status{WIN, DRAW, CONTINUE};

//--------------------------------------------------------------------------//

//User Defined Class TicTacToe
class TicTacToe
{
private:
    //2x2 array to hold moves
    char board[3][3];
    //variable for counting number of moves
    int moves;
public:
    // Function to play the game
    void play();
    // Function to print the board
    void displayBoard() const;
    // Function to determine if a move is valid
    bool isValidMove(int row, int col) const;
    // Function to get a move for a player
    bool getMove(char moveSymbol);
    // Function to determine the current status of the game
    // Uses the status enumeration data type for members WIN,
    // DRAW, and CONTINUE
    status gameStatus();
    // Function to restart the game
    void restart();
    // Default constructor 
    TicTacToe();
};

//--------------------------------------------------------------------------//

#endif /* TICTACTOE_H */

