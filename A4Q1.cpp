//**************************************************************
//  Student Name: Parmin Patel && Darren Choi
//  Student Number:  20900440 && 20876806
//  SYDE 121 Lab: Assignment: #4
//  Filename: a4_q1.cpp
//  We hereby declare that this code, submitted for credit for the course
//  SYDE121, is a product of my own efforts.  This coded solution has
//  not been plagiarized from other sources and has not been knowingly
//  plagiarized by others.
//  Project:  Tic Tac Toe Game
//  Purpose: Create a Tic Tac Toe Game for player
//  Due Date:  Friday, Nov 6th, 2020
//**************************************************************
/*
TESTING:
Tested for invalid inputs above 16, below 1 and repeated inputs where the pace is occupied
Tested for multiple games and invalid inputs when trying to play again
Tested the score and outputs after every game and when program terminates
NOTE: if string values are inputted the program will not work
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//OUTPUT: Prints out the game board
void display_board(int game_board[4][4]) {
    /*
    FUNCTION: prints out the game board to the user
    PARAMTER: a integer 2d array of the game board
    */

    //Initilized the variables required for the program
    string display_board[4][4] = {          //A string 2d array 
      {"1","2","3","4"},
      {"5","6","7","8"},
      {"9","10","11","12"},
      {"13","14","15","16"}
    };
    //iterates through the 2d array to change the string 2d array values
    for (int horizontal = 0; horizontal < 4; horizontal++) {
        for (int vertical = 0; vertical < 4; vertical++) {

            //if the integer 2d array is 20
            if (game_board[horizontal][vertical] == 20) {
                display_board[horizontal][vertical] = "X";      // at the same index in string 2d it replaces it with a X
            }

            //if the integer 2d array is 0
            else if (game_board[horizontal][vertical] == 0) {
                display_board[horizontal][vertical] = "O";      // at the same index in string 2d it replaces it with a O
            }
        }
    }

    //Used to print out the string array which is identical to the integer array
    for (int horizontal = 0; horizontal < 4; horizontal++) {    //for the horizontal part of the array 

        for (int vertical = 0; vertical < 4; vertical++) {          //for the vertical part of the array

            cout << "\t\t";                                       // used for formatting
            cout << display_board[horizontal][vertical];          //prints out the string array to the user
        }
        cout << endl;                                           //when it goes to a new line a line break is created
    }
}

bool x_winner(int game_board[4][4]) {
    /*
    FUNCTION: check to see if player 1 has won
    PARAMETER: takes the game board PARAMETER
    RETURN:   checks if there is a vertical, horizontal, or diagonal combination of four X's if there are then it returns true
              if its not win the returns false
    */
    //vertical line win 
    if (game_board[0][0] == 20 && game_board[1][0] == 20 && game_board[2][0] == 20 && game_board[3][0] == 20) {
        return true;
    }

    else if (game_board[0][1] == 20 && game_board[1][1] == 20 && game_board[2][1] == 20 && game_board[3][1] == 20) {
        return true;
    }

    else if (game_board[0][2] == 20 && game_board[1][2] == 20 && game_board[2][2] == 20 && game_board[3][2] == 20) {
        return true;
    }
    else if (game_board[0][3] == 20 && game_board[1][3] == 20 && game_board[2][3] == 20 && game_board[3][3] == 20) {
        return true;
    }
    //diagonal line win 
    else if (game_board[0][0] == 20 && game_board[1][1] == 20 && game_board[2][2] == 20 && game_board[3][3] == 20) {
        return true;
    }
    else if (game_board[0][3] == 20 && game_board[1][2] == 20 && game_board[2][1] == 20 && game_board[3][0] == 20) {
        return true;
    }
    //horizontal line win 
    if (game_board[0][0] == 0 && game_board[0][1] == 0 && game_board[0][2] == 0 && game_board[0][3] == 0) {
        return true;
    }
    else if (game_board[1][0] == 0 && game_board[1][1] == 0 && game_board[1][2] == 0 && game_board[1][3] == 0) {
        return true;
    }
    else if (game_board[2][0] == 0 && game_board[2][1] == 0 && game_board[2][2] == 0 && game_board[2][3] == 0) {
        return true;
    }
    else if (game_board[3][0] == 0 && game_board[3][1] == 0 && game_board[3][2] == 0 && game_board[3][3] == 0) {
        return true;
    }
    else {
        return false;
    }
}

// checks whether o wins by being passed the game board and if any of the columns, rows, or diagonals, are filled with o, then it returns true for the function to read and say o wins
bool o_winner(int game_board[4][4]) {
    // horizontal line win
    if (game_board[0][0] == 0 && game_board[0][1] == 0 && game_board[0][2] == 0 && game_board[0][3] == 0) {
        return true;
    }

    else if (game_board[1][0] == 0 && game_board[1][1] == 0 && game_board[1][2] == 0 && game_board[1][3] == 0) {
        return true;
    }

    else if (game_board[2][0] == 0 && game_board[2][1] == 0 && game_board[2][2] == 0 && game_board[2][3] == 0) {
        return true;
    }
    else if (game_board[3][0] == 0 && game_board[3][1] == 0 && game_board[3][2] == 0 && game_board[3][3] == 0) {
        return true;
    }
    //diagonal line win
    else if (game_board[0][0] == 0 && game_board[1][1] == 0 && game_board[2][2] == 0 && game_board[3][3] == 0) {
        return true;
    }
    else if (game_board[0][3] == 0 && game_board[1][2] == 0 && game_board[2][1] == 0 && game_board[3][0] == 0) {
        return true;
    }
    //vertical line win
    if (game_board[0][0] == 20 && game_board[1][0] == 20 && game_board[2][0] == 20 && game_board[3][0] == 20) {
        return true;
    }

    else if (game_board[0][1] == 20 && game_board[1][1] == 20 && game_board[2][1] == 20 && game_board[3][1] == 20) {
        return true;
    }

    else if (game_board[0][2] == 20 && game_board[1][2] == 20 && game_board[2][2] == 20 && game_board[3][2] == 20) {
        return true;
    }
    else if (game_board[0][3] == 20 && game_board[1][3] == 20 && game_board[2][3] == 20 && game_board[3][3] == 20) {
        return true;
    }
    // if none of the win conditions are met, it returns false
    return false;

}


// gets passed the cache array, the players input, and the current storage value to store the player input if the value is not found in the cache array
bool is_occupied(int inputted_values[16], int player_input, int iterator) {

    for (int i = 0; i < 16; i++) {
        if (inputted_values[i] == player_input) {            //sees if the value already exists or not 
            cout << "Invalid input: Occupied. " << endl;
            return true;
        }
    }
    inputted_values[iterator] = player_input;
    return false;
}


string input(int& x_wins, int& o_wins, int& ties, int game_counter) {
    //declaring proper variables and the layout for the game board. we use the variables to count wins, find inputs, and properly iterate through arrays to store numbers
    int game_board[4][4] = {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
      {13,14,15,16}
    };
    int player_o_input = 0;
    int player_x_input = 0;
    int winner = 0;
    bool if_winner = false;
    int inputted_values[16] = { 0 };
    int iterator = 0;
    int valid_input = true;
    display_board(game_board);

    // when it's player x's turn to go first
    if (game_counter % 2 == 1) {
        cout << "***PLAYER X GOES FIRST*****" << endl;

        // for while the turn counter for each player is less than 8, thus not a tie yet, and when a winenr hasn't been decided
        while (winner != 8 && if_winner == false) {
            // resets player input each turn to allow to enter the while loop
            player_x_input = 0;
            player_o_input = 0;

            //if invalid input asks user again
            while (player_x_input > 16 || player_x_input < 1 || valid_input == false) {
                cout << "Player X: Where would you put the mark: ";
                cin >> player_x_input;


                valid_input = !is_occupied(inputted_values, player_x_input, iterator);    //calls a function to see if place is occupied
            }
            iterator++;
            while (player_o_input > 16 || player_o_input < 1 || valid_input == false) {
                cout << "Player O: Where would you put the mark: ";
                cin >> player_o_input;

                valid_input = !is_occupied(inputted_values, player_o_input, iterator);

            }
            iterator++;

            //input function for the player inputs for the 2-D array with player x being priority
            for (int horizontal = 0; horizontal < 4; horizontal++) {
                for (int vertical = 0; vertical < 4; vertical++) {
                    if (game_board[horizontal][vertical] == player_x_input) {
                        game_board[horizontal][vertical] = 20;
                    }
                    else if (game_board[horizontal][vertical] == player_o_input) {
                        game_board[horizontal][vertical] = 0;
                    }
                }
            }

            // checks for winner with player x being priority, since they went first this "turn"
            if (x_winner(game_board) == true) {
                if_winner = true;
                x_wins++;
                return "PLAYER X WINS THE GAME!";
            }
            else if (o_winner(game_board) == true) {
                if_winner = true;
                o_wins++;
                return "PLAYER O WINS THE GAME!";
            }

            // a turn counter, and display of the board after each player's turn
            display_board(game_board);
            cout << endl;
            winner++;
        }

        // this can only happen when the turn clock runs out, and thus only happens when a tie occurs.  So, it adds ties and outputs that to console
        ties++;
        return "The game is a tie.";
    }



    // for when its player o's turn to go first
    if (game_counter % 2 == 0) {
        cout << "***PLAYER 0 GOES FIRST*****" << endl;

        // for while the turn counter for each player is less than 8, thus not a tie yet, and when a winenr hasn't been decided
        while (winner != 8 && if_winner == false) {
            // needs to reset player input each time to enter the while function
            player_x_input = 0;
            player_o_input = 0;

            //if invalid input asks user again
            while (player_o_input > 16 || player_o_input < 1 || valid_input == false) {
                cout << "Player O: Where would you put the mark: ";
                cin >> player_o_input;
                valid_input = !is_occupied(inputted_values, player_o_input, iterator);
            }
            // runs iterator number for storing of previous inputs
            iterator++;

            while (player_x_input > 16 || player_x_input < 1 || valid_input == false) {
                cout << "Player X : Where would you put the mark: ";
                cin >> player_x_input;

                valid_input = !is_occupied(inputted_values, player_x_input, iterator);

            }
            iterator++;



            //input function for the player inputs for the 2-D array
            for (int horizontal = 0; horizontal < 4; horizontal++) {
                for (int vertical = 0; vertical < 4; vertical++) {
                    if (game_board[horizontal][vertical] == player_o_input) {
                        game_board[horizontal][vertical] = 0;
                    }
                    else if (game_board[horizontal][vertical] == player_x_input) {
                        game_board[horizontal][vertical] = 20;
                    }
                }
            }

            // checks for winner with player o being priority, since they went first this "turn"
            if (o_winner(game_board) == true) {
                if_winner = true;
                o_wins++;
                return "PLAYER O WINS THE GAME!";
            }
            else if (x_winner(game_board) == true) {
                if_winner = true;
                x_wins++;
                return "PLAYER X WINS THE GAME!";
            }

            // a turn counter, and display of the board after each player's turn
            display_board(game_board);
            cout << endl;
            winner++;
        }

        // this can only happen when the turn clock runs out, and thus only happens when a tie occurs.  So, it adds ties and outputs that to console
        ties++;
        return "The game is a tie.";
    }
    // if for some reason it doesn't hit a return, returns 0
    return 0;
}

// prints the wins, and ties
void print_wins(int o_wins, int x_wins, int ties) {
    cout << "|X Wins: " << x_wins << endl;
    cout << "|O Wins: " << o_wins << endl;
    cout << "|Ties: " << ties << endl;
}

int main() {
    // these keep track of wins, whether the players want to play again, and whose turn it is
    int o_wins = 0;
    int x_wins = 0;
    int ties = 0;
    bool play_again = true;
    char play;
    int game_counter = 1;

    while (play_again == true) {
        // prints the outcome of the came, and calls the function to allow the players to play the game
        cout << input(x_wins, o_wins, ties, game_counter) << endl;

        // lets the funciton know which player goes first
        game_counter++;

        // asks the user whether they want to play again, and breaks the code to allow the loop to run if yes and makes the above condition false to stop playing to break the loop
        while (play != 'Y' || play != 'N') {
            print_wins(o_wins, x_wins, ties);
            cout << "Would you like to play again(Y to play again or N to stop playing):" << endl;
            cin >> play;
            if (play == 'Y' || play == 'y') {
                break;
            }

            else if (play == 'N' || play == 'n') {
                play_again = false;
                break;
            }
        }
    }
    // When entering stop playing, thanks the user and prints final score
    cout << "Thanks for playing." << endl;
    print_wins(o_wins, x_wins, ties);
    exit(0);
}
