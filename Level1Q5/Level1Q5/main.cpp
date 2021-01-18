/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/A     Assignment: Level 1 Question 5
File Name: Assignment1-Q1

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Playing the game 23 with an computer algorithm that chooses the computer's move
Purpose: Practice with logic and conditions for certain scenarios that may screw the game up
Due Date: Sept 25 2020
*/

#include <iostream>
using namespace std;

void sticks_game () {
    //declaring variables and setting the stage for the numbers needed. sticks = 23 is the sticks in the game, I set remove_sticks to 1 to let my code work once and is changed by player input, and computer_sticks = 4 because the formula to figure out how many sticks the computer takes is 4- remove_Sticks. the bool determines who wins, based on the code
    int sticks = 23;
    int remove_sticks = 1;
    int computer_sticks = 4;
    bool win_value = true;
    
    //loop allows game to keep playing as long as number of sticks is above win condition
    while (sticks > 1) {
        
        // need to reset computer_sticks to 4 to allow
        computer_sticks = 4;
        cout << "Enter the amount of sticks you would like to remove from 1 and 3" << endl;
        cin >> remove_sticks;
        
        //this block checks whether the input is valid, and if it is, it'll execute the player's move
        if (remove_sticks < 1 || remove_sticks > 3)
            continue;
        else
            sticks -= remove_sticks;
        
        // this is the win condition for the player if he outmaneuvers the computer into letting him leave one stick.
        if (sticks == 1){
            cout << "You remove " << remove_sticks << " sticks" << endl;
            break;
        }
        else if (sticks < 1){
            win_value = false;
            cout << "You took the last stick!" << endl;
            break;
        }
        
        // this block determines what value of sticks the computer will remove from the remainder of sticks, and the bottom 3 are win conditions for the computer
        computer_sticks -= remove_sticks;
        if (sticks > 1 && sticks < 5){
            if (sticks == 4){
                computer_sticks = 3;
                win_value = false;
            }
            else if (sticks == 3){
                computer_sticks = 2;
                win_value = false;
            }
            else{
                computer_sticks = 1;
                win_value = false;
            }}
        
        // this block executes the computers move
        sticks -= computer_sticks ;
        
        // this block echoes the users move, the computers move, and the remaining number of sticks.
        cout << "You remove " << remove_sticks << " sticks" << endl;
        cout << "The computer removes " << computer_sticks << " sticks" << endl;
        cout << "There are " << sticks << " sticks remaining" << endl;
    }
    
    // the output that states whether the player wins or loses
    if (win_value)
        cout << "There are " << sticks << " stick(s) remaining" << endl << "You win!" << endl;
    else
        cout << "You lose!" << endl;
}
int main() {
    sticks_game();
}
