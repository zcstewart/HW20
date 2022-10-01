//Homework 20

/*
 *  Filename:           TicTacToe.cpp
 * 
 *  Purpose:            The purpose of this program is to define all of the
 *                      member function variables.                      
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               2/13/2017 16:30 PST
 */

//Include TicTacToe header file
#include "TicTacToe.h"

//--------------------------------------------------------------------------//
//TicTacToe Member function definitions

//TicTacToe::play() Function
//Inputs:   none
//Outputs:  none
//Purpose:  The purpose of this program is to allow the user to play the
//          Tic-Tac-Toe game through generating a menu display of the board,
//          prompting user for input, using the bool getMove(char moveSymbol)
//          function, checking the validity of the user input 
//          bool (TicTacToe::isValidMove(int row, int col) const, function is 
//          nested within the getMove function), updating the board,
//          incrementing the moves, and determining the status of the game
//          after every move (status TicTacToe::gameStatus()). The status
//          of the game is an enumeration of type status. The possible
//          conditions are WIN, DRAW, and CONTINUE. The program will determine
//          the status of the game, and if not a draw, the winner will be
//          determined. The program will prompt the user asking if they
//          would like to play again. If yes, the program is restarted,
//          and the current Tic-Tac-Toe board is cleared and reset using the
//          void TicTacToe::restart() function.
void TicTacToe::play()
{
    //Variable to allow user to play another game
    bool playStatus = false;
    //Input option to play another game
    char playAgain = 'Y';
    while(playAgain == 'Y')
    {
        //Initialize and declare enumeration of type status
        //Determines WIN, DRAW, or CONTINUE
        status gameState = CONTINUE;
        //Variable for counting current number of moves
        moves = 0;
        do
        {
            //Clear screen for Tic-Tac-Toe board
            system("clear");
            //show board
            displayBoard();
            //Determine which player has the current turn to move
            if((moves % 2) == 0)
            {
                //X's turn
                getMove('X');
            }
            else
            {
                //Y's turn
                getMove('O');
            }
            //Increment moves after move has been made
            moves++;
            gameState = gameStatus();
            //If moves are remaining and game isn't won
            //Continue executing loop. Else, continue to next if statement
        }while(moves != 9 && gameState == CONTINUE);
        
        //If the game has been won
        if(gameState == WIN)
        {
            //Show the winning board
            displayBoard();
            //Because moves was still incremented after a player has made
            //a move (whether they won or not) the evaluation is now 
            //made with != as compared to ==
            if(moves % 2 != 0)
            {
                //Player X is winner
                cout << "Player X wins!" << endl << endl;
            }
            else
            {
                //Player Y is winner
                cout << "Player O wins!" << endl << endl;
            }
        }
        else
        {
            //Nobody wins
            cout << "The game is a draw!" << endl;
        }
        //Prompt user to play again
        cout << "Would you like to play again?" << endl;
        cout << "Enter \"y\" or \"Y\" to play again" << endl;
        cout << "Enter \"n\" or \"N\" to quit" << endl;
        cin >> playAgain;
        //Precautionary conversion to upper case
        playAgain = toupper(playAgain);
        //Determine whether to repeat game, exit game, or invalid input
        while(!playStatus)
        {
            //If y or Y play again
            if(playAgain == 'Y')
            {
                playStatus = true;
                //Create new board to play next game
                restart();
            }
            //If n or N don't play again
            else if(playAgain == 'N')
            {
                exit(EXIT_SUCCESS);
            }
            //Else invalid input
            else
            {
                //Prompt user for input after notification of invalid
                //input
                cout << "Invalid input, please try again!" << endl << endl;
                cout << "Would you like to play again?" << endl;
                cout << "Enter \"y\" or \"Y\" to play again" << endl;
                cout << "Enter \"n\" or \"N\" to quit" << endl;
                cin >> playAgain;
                //Precautionary upper case conversion
                playAgain = toupper(playAgain);
            }
        }
    }  
}

//TicTacToe::displayBoard() const Function
//Inputs:   none
//Outputs:  None, return type void
//Purpose:  The purpose of this program is to print out the current
//          Tic-Tac-Toe game board to the screen for the user to see.

void TicTacToe::displayBoard() const
{
    //Display Board
    cout << "Tic-Tac-Toe Game" << endl << endl;
    //Columns 1 through 3
    cout << "   1   2   3" << endl;
    cout << "     |   |   " << endl;
    //Row One
    //[0][0],[0][1],[0][2]
    cout << "1  " << board[0][0] << " | " << board[0][1] << " | ";
    cout << board[0][2] << " " << endl;
    cout << "  ___|___|___" << endl;
    cout << "     |   |   " << endl;
    //Row Two
    //[1][0],[1][1],[1][2]
    cout << "2  " << board[1][0] << " | " << board[1][1] << " | ";
    cout << board[1][2] << " " << endl;
    cout << "  ___|___|___" << endl;
    cout << "     |   |   " << endl;
    //Row Three
    //[2][0],[2][1],[2][2]
    cout << "3  " << board[2][0] << " | " << board[2][1] << " | ";
    cout << board[2][2] << " " << endl;
    cout << "     |   |   " << endl;
}

//TicTacToe::isValidMove(int row, int col) const Function
//Inputs:   int row, int col
//Outputs:  bool valid
//Purpose:  The purpose of this program is to determine whether the
//          coordinates entered in the getMove(char moveSymbol) function
//          is a valid move. The function will check the user input row and
//          col values. If they are smaller than one or greater than three,
//          the input is invalid and a value of false is returned. The 
//          row and col values are subtracted by one when searching the
//          array of characters. This is done to prevent exiting the
//          boundaries of the array index. If the user entered row or column
//          has already been taken by a previous player, the function will
//          return false. If neither of these conditions are true, the move
//          is valid and the program is allowed to proceed.
bool TicTacToe::isValidMove(int row, int col) const
{
    //Set true by default 
    bool valid = true;
    //If row or col are not integers 1, 2, or 3
    if(row < 1 || row > 3 || col < 1 || col > 3)
    {
        //Not a valid move (valid = false)
        valid = false;
    }
    //If the current spot on the Tic-Tac-Toe board is not a blank whitespace
    //character
    if(board[row - 1][col - 1] != ' ')
    {
        //Not a valid move (valid = false)
        valid = false;
    }
    //Else move is valid
    //Function returns true
    return valid;
}

//TicTacToe::getMove(char moveSymbol) Function
//Inputs:   char moveSymbol
//Outputs:  bool moveStatus
//Purpose:  The purpose of the program is to absorb a char value (moveSymbol)
//          from the parameters of the function to determine which players
//          turn it is play. The program will read in either two integer
//          values separated by spaces, or two integer values separated by
//          commas. The program ill then call the isValidMove() function
//          as a control variable for a while loop. The while loop will
//          continuously prompt the user for input if incorrect input 
//          is received. Once a valid move is received, the program will
//          insert the appropriate moveSymbol character for the player.
//          The program will return true to indicate that the move was
//          completed successfully.
bool TicTacToe::getMove(char moveSymbol)
{
    int row, col;
    char junk;
    bool moveStatus = false;
    //Prompt appropriate player to enter move
    cout << "Player "<< moveSymbol << " Enter Move:";
    //Read move
    //Acceptable Formats integer + " " + integer
    //                           or
    //                   integer + "," + integer
    cin >> row;
    cin.get(junk);
    cin >> col;
    cout << endl;
    //If the move is invalid, continuously prompt the user to enter the
    //correct input. Loop ends when input move is valid or cin enters
    //fail state
    while(!isValidMove(row, col) || !cin)
    {
        //Inform user input is invalid
        cout << "Invalid Move" << endl << endl;
        //Re-prompt for input
        cout << "Player " << moveSymbol << " Enter Move:" << endl;
        cin >> row;
        cin.get(junk);
        cin >> col;
    }
    //Subtract each coordinate by one to fit into appropriate array index
    board[row - 1][col - 1] = moveSymbol;
    //getMove function performed task successfully
    moveStatus = true;
    //Return True
    return moveStatus;
}

//TicTacToe::gamesStatus() Function
//Inputs:   none
//Outputs:  (enum) status gameState
            //WIN, DRAW, CONTINUE
//Purpose:  The purpose of this program is to scan the array of char
//          values in every possible direction that could correlate to a win.
//          The program will check row 1, row 2, row 3, col 1, col 2, col 3,
//          top left to bottom right diagonal, and the top right to bottom
//          left diagonal. If any arrangement contains matching characters
//          and none of those characters are blank whitespaces (initial
//          condition), the game is a WIN. If there are no moves remaining,
//          the game is a DRAW. Else, the status is CONTINUE, and the
//          program continues to execute. The return type is the enumeration
//          status, which can be either WIN, DRAW, or CONTINUE.
status TicTacToe::gameStatus()
{   
    //Initialize status variable
    status gameState;
    //Check row one for same char value
    //[0][0], [0][1], [0][2]
    //If all items in row one match AND none are whitespace characters
    if((board[0][0] == board[0][1] && board[0][0] == board[0][2])
        &&(board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //Check row two for same char value
    //[1][0],[1][1],[1][2]
    //If all items in row two match AND none are whitespace characters
    else if((board[1][0] == board[1][1] && board[1][0] == board[1][2])
        &&(board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //Check row three for same char value
    //[2][0],[2][1],[2][2]
    //If all items in row three match AND none are whitespace characters
    else if((board[2][0] == board[2][1] && board[2][0] == board[2][2])
        &&(board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //Check column one for same char value
    //[0][0],[1][0],[2][0]
    //If all items in column one match AND none are whitespace characters
    else if((board[0][0] == board[1][0] && board[0][0] == board[2][0])
        &&(board[0][0] != ' ' && board[1][0] != ' ' && board[2][0] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //Check column two for same char value
    //[0][1],[1][1],[2][1]
    //If all items in column two match AND none are whitespace characters
    else if((board[0][1] == board[1][1] && board[0][1] == board[2][1])
        &&(board[0][1] != ' ' && board[1][1] != ' ' && board[2][1] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //Check column three for same char value
    //[0][2],[1][2],[2][2]
    //If all items in column three match AND none are whitespace characters
    else if((board[0][2] == board[1][2] && board[0][2] == board[2][2])
        &&(board[0][2] != ' ' && board[1][2] != ' ' && board[2][2] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //Check Diagonal (top left to bottom right) for same char
    //[0][0],[1][1],[2][2]
    else if((board[0][0] == board[1][1] && board[0][0] == board[2][2])
        &&(board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //Check Diagonal (top right to bottom left) for same char
    //[0][2],[1][1],[2][0]
    else if((board[0][2] == board[1][1] && board[0][2] == board[2][0])
        &&(board[0][2] != ' ' && board[1][1] != ' ' && board[2][0] != ' '))
    {
        //Game has been won
        gameState = WIN;
    }
    //No moves remain
    else if(moves == 9)
    {
        //Game ends with DRAW
        gameState = DRAW;
    }
    //Moves remain
    //Game has not been won
    else
    {
        //Game continues
        gameState = CONTINUE;
    }
    //Return the status of the game
    return gameState;
}

//TicTacToe::restart() Function
//Inputs:   none
//Outputs:  none (return type void)
//Purpose:  The purpose of this program is to reset the TicTacToe board
//          (array) back to its initial condition. The function uses a for
//          loop to initialize each element of the array to ' '. The moves
//          private member variable is reset to 0. This function uses the
//          exact same logic of the default constructor of the class.
void TicTacToe::restart()
{
    //for row 1 - 3
    for(int i = 0; i < 3; i++)
    {
        //for col 1 - 3
        for(int j = 0; j < 3; j++)
        {
            //Set index to ' ' character
            board[i][j] = {' '};
        }
    }
    //Set moves to 0
    moves = 0;
}

//TicTacToe::TicTacToe() Default Constructor
//Inputs:   None
//Outputs:  None
//Purpose:  The purpose of this function is to create an object of a class
//          that is initialized to is default values. This is automatically
//          called by the program when a new class member is declared.
TicTacToe::TicTacToe()
{
   //for row 1 - 3
    for(int i = 0; i < 3; i++)
    {
        //for col 1 - 3
        for(int j = 0; j < 3; j++)
        {
            //Set index to ' ' character
            board[i][j] = {' '};
        }
    }
    //Set moves to 0
    moves = 0;
}

//--------------------------------------------------------------------------//
