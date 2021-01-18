/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: 3      Assignment: 3 Question 1
File Name: A3Q1

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Simulating a soccer game
Purpose: Control Flow
Due Date: Oct 30, 2020
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;

/*
Output:
 Number of events 15
 Welcome to the game between Team A and Team B!
 That is the kickoff! The game has started!
 Oooh! Team B commits a foul and Team A is awarded a free kick!
 Team A has scored!
 Team B player is given a yellow card.
 Ouch! Team A commits a foul and Team B is awarded a free kick!
 The fre kick was saved by the goalkeeper!
 Team B has shot!
 Team B has scored!
 Ouch! Team A commits a foul and Team B is awarded a free kick!
 The team B striker missed the goal!
 Team A player is given a yellow card.
 Oooh! Team B commits a foul and Team A is awarded a free kick!
 Team A has scored!
 Team A has shot!
 Team A has scored!
 That foul by Team A is going to grant a penalty kick to Team B!
 Team B has scored!
 Team A player is given a red card.
 It's halftime! Please wait while we wait for our favourite teams of letters come back on the the field!
 Here are the stats at halftime!
 Stat           Team A         Team B
 Goals          3              2
 Blocks         1              0
 Shots on Goal  3              3
 Shots off Goal 0              1
 Fouls          2              2
 Yellow Cards   1              1
 Red Cards      1              0
 We will be back in
 15
 14
 13
 12
 11
 10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 Here we go! And that's kickoff!
 Team A has shot!
 The shot was saved by the goalkeeper!
 That foul by Team A is going to grant a penalty kick to Team B!
 The fre kick was saved by the goalkeeper!
 Team A player is given a yellow card.
 Team A has shot!
 What a spectacular save from the defender!
 Team A has shot!
 Team A has scored!
 Ouch! Team A commits a foul and Team B is awarded a free kick!
 What a spectacular save from the defender!
 Team A player is given a red card.
 Team B has shot!
 Team B has scored!
 Team B has shot!
 The team B striker missed the goal!
 Team B has commited a foul inside the penalty box and Team A is awarded with a penalty kick!
 The free kick was saved by the goalkeeper!
 What a game between the two teams! Here are the final stats!
 Stat           Team A         Team B
 Goals          4              3
 Blocks         3              3
 Shots on Goal  7              6
 Shots off Goal 0              2
 Fouls          3              2
 Yellow Cards   2              1
 Red Cards      2              0
 */


void soccer_game(){
    // Call srand to generate random numbers and generate a number of events from 1-20
    srand(static_cast<unsigned int> (time(0)));
    int events = rand() % 20 + 1;
    
    // initialize enough variables to store all the data required for the stats of the game.
    int team_a_goals = 0;
    int team_a_fouls = 0;
    int team_a_shots_on = 0;
    int team_a_shots_off = 0;
    int team_a_blocks = 0;
    int team_a_yellow = 0;
    int team_a_red = 0;
    int team_b_goals = 0;
    int team_b_fouls = 0;
    int team_b_shots_on = 0;
    int team_b_shots_off = 0;
    int team_b_blocks = 0;
    int team_b_yellow = 0;
    int team_b_red = 0;
    
    // declare these variables that will be initialized later with a random value to decide what happens depending on the outcome.
    int play_call;
    int shot_outcome;
    int if_foul;
    
    // a little introduction I coded to introduce the program and state how many events occur in the game.
    cout << "Number of events " << events << endl;
    cout << "Welcome to the game between Team A and Team B!" << endl;
    cout << "That is the kickoff! The game has started!" << endl;
    
    // this for loop is the "first half" of the game, and iterates up to that point
    for (int index = 0; index < events / 2; index++){
        
        // sleep_for is to allow the reader to understand what happened in the current event, and gives a little sense of realism because events don't happen instantly.
        this_thread::sleep_for(2s);
        
        // play_call decides what happens for the event.
        play_call = rand() % 6 + 1;
        
        // This occurs if play_call == 1. Team A shoots, and shot_outcome is randomized to decide what happens from the shot
        if (play_call == 1){
            cout << "Team A has shot!" << endl;
            shot_outcome = rand() % 4;
            if (shot_outcome == 0){
                cout << "Team A has scored!" << endl;
                team_a_goals += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The shot was saved by the goalkeeper!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team A striker missed the goal!" << endl;
                team_a_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
        }
        
        // This occurs if play_call == 2. Team B shoots, and shot_outcome is randomized to decide what happens from the shot
        else if (play_call == 2){
            cout << "Team B has shot!" << endl;
            shot_outcome = rand() % 4;
            if (shot_outcome == 0){
                cout << "Team B has scored!" << endl;
                team_b_goals += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The shot was saved by the goalkeeper!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team B striker missed the goal!" << endl;
                team_b_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
        }
        
        // if play_call == 3, Team A is awarded a free kick due to Team B foul. shot_outcome is called to decide what happens, and if_foul is called to decide if a card is given to the player commiting the foul.
        else if (play_call == 3){
            cout << "Oooh! Team B commits a foul and Team A is awarded a free kick!" << endl;
            team_b_fouls += 1;
            shot_outcome = rand() % 4;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team A has scored!" << endl;
                team_a_goals += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team A striker missed the goal!" << endl;
                team_a_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team B player is given a yellow card." << endl;
                team_b_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team B player is given a red card." << endl;
                team_b_red += 1;
            }
        }
        
        // if play_call == 4, Team B is awarded a free kick due to Team A foul. shot_outcome is called to decide what happens, and if_foul is called to decide if a card is given to the player commiting the foul.
        else if (play_call == 4){
            cout << "Ouch! Team A commits a foul and Team B is awarded a free kick!" << endl;
            team_a_fouls += 1;
            shot_outcome = rand() % 4;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team B has scored!" << endl;
                team_b_goals += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team B striker missed the goal!" << endl;
                team_b_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team A player is given a yellow card." << endl;
                team_a_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team A player is given a red card." << endl;
                team_a_red += 1;
            }
        }
        
        // if play_call == 5, Team A is awarded a penalty kick due to Team B foul. shot_outcome is called to decide what happens, and if_foul is called to decide if a card is given to the player commiting the foul.
        else if (play_call == 5){
            cout << "Team B has commited a foul inside the penalty box and Team A is awarded with a penalty kick!" << endl;
            shot_outcome = rand() % 3;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team A has scored!" << endl;
                team_a_goals += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team A striker missed the goal!" << endl;
                team_a_shots_off += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team B player is given a yellow card." << endl;
                team_b_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team B player is given a red card." << endl;
                team_b_red += 1;
            }
        }
        
        // if play_call == 6, Team B is awarded a penalty kick due to Team A foul. shot_outcome is called to decide what happens, and if_foul is called to decide if a card is given to the player commiting the foul.
        else if (play_call == 6){
            cout << "That foul by Team A is going to grant a penalty kick to Team B!" << endl;
            shot_outcome = rand() % 3;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team B has scored!" << endl;
                team_b_goals += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team B striker missed the goal!" << endl;
                team_b_shots_off += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team A player is given a yellow card." << endl;
                team_a_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team A player is given a red card." << endl;
                team_a_red += 1;
            }
        }
    }
    
    // This is the halftime code, and it outputs the current stats of the game in a table format
    cout << "It's halftime! Please wait while we wait for our favourite teams of letters come back on the the field!" << endl;
    cout << "Here are the stats at halftime!"<< endl;
    cout << left << setw(15) << "Stat" << fixed << left << setw(15) << "Team A" << "Team B"<< endl;
    cout << left << setw(15) << "Goals" << fixed << left << setw(15) << team_a_goals << team_b_goals << endl;
    cout << left << setw(15) << "Blocks" << fixed << left << setw(15) << team_a_blocks << team_b_blocks << endl;
    cout << left << setw(15) << "Shots on Goal" << fixed << left << setw(15) << team_a_shots_on << team_b_shots_on << endl;
    cout << left << setw(15) << "Shots off Goal" << fixed << left << setw(15) << team_a_shots_off << team_b_shots_off << endl;
    cout << left << setw(15) << "Fouls" << fixed << left << setw(15) << team_a_fouls << team_b_fouls << endl;
    cout << left << setw(15) << "Yellow Cards" << fixed << left << setw(15) << team_a_yellow << team_b_yellow << endl;
    cout << left << setw(15) << "Red Cards" << fixed << left << setw(15) << team_a_red << team_b_red << endl;
    
    // This code is a count down from 15s, and then the program continues after 15 seconds.
    cout << "We will be back in" << endl;
    for (int index = 15; index > 0; index--){
        cout << index << endl;
        this_thread::sleep_for(1s);
    }
    cout << "Here we go! And that's kickoff!" << endl;
    
    
    // this for loop is identical to the first half, but it just iterates from events / 2 to events, so the "second half".
    for (int index = events / 2; index < events; index++){
        this_thread::sleep_for(2s);
        play_call = rand() % 6 + 1;
        if (play_call == 1){
            cout << "Team A has shot!" << endl;
            shot_outcome = rand() % 4;
            if (shot_outcome == 0){
                cout << "Team A has scored!" << endl;
                team_a_goals += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The shot was saved by the goalkeeper!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team A striker missed the goal!" << endl;
                team_a_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
        }
        
        else if (play_call == 2){
            cout << "Team B has shot!" << endl;
            shot_outcome = rand() % 4;
            if (shot_outcome == 0){
                cout << "Team B has scored!" << endl;
                team_b_goals += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The shot was saved by the goalkeeper!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team B striker missed the goal!" << endl;
                team_b_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
        }
        
        else if (play_call == 3){
            cout << "Oooh! Team B commits a foul and Team A is awarded a free kick!" << endl;
            team_b_fouls += 1;
            shot_outcome = rand() % 4;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team A has scored!" << endl;
                team_a_goals += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team A striker missed the goal!" << endl;
                team_a_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team B player is given a yellow card." << endl;
                team_b_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team B player is given a red card." << endl;
                team_b_red += 1;
            }
        }
        
        else if (play_call == 4){
            cout << "Ouch! Team A commits a foul and Team B is awarded a free kick!" << endl;
            team_a_fouls += 1;
            shot_outcome = rand() % 4;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team B has scored!" << endl;
                team_b_goals += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team B striker missed the goal!" << endl;
                team_b_shots_off += 1;
            }
            else if (shot_outcome == 3){
                cout << "What a spectacular save from the defender!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team A player is given a yellow card." << endl;
                team_a_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team A player is given a red card." << endl;
                team_a_red += 1;
            }
        }
        
        else if (play_call == 5){
            cout << "Team B has commited a foul inside the penalty box and Team A is awarded with a penalty kick!" << endl;
            shot_outcome = rand() % 3;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team A has scored!" << endl;
                team_a_goals += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_b_blocks += 1;
                team_a_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team A striker missed the goal!" << endl;
                team_a_shots_off += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team B player is given a yellow card." << endl;
                team_b_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team B player is given a red card." << endl;
                team_b_red += 1;
            }
        }
        
        else if (play_call == 6){
            cout << "That foul by Team A is going to grant a penalty kick to Team B!" << endl;
            shot_outcome = rand() % 3;
            if_foul = rand() % 3;
            
            if (shot_outcome == 0){
                cout << "Team B has scored!" << endl;
                team_b_goals += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 1){
                cout << "The free kick was saved by the goalkeeper!" << endl;
                team_a_blocks += 1;
                team_b_shots_on += 1;
            }
            else if (shot_outcome == 2){
                cout << "The team B striker missed the goal!" << endl;
                team_b_shots_off += 1;
            }
            
            if (if_foul == 0){
                continue;
            }
            else if (if_foul == 1){
                cout << "Team A player is given a yellow card." << endl;
                team_a_yellow += 1;
            }
            else if (if_foul == 2){
                cout << "Team A player is given a red card." << endl;
                team_a_red += 1;
            }
        }
    }
    
    // This code outputs the end game stats.
    cout << "What a game between the two teams! Here are the final stats!" << endl;
    cout << left << setw(15) << "Stat" << fixed << left << setw(15) << "Team A" << "Team B"<< endl;
    cout << left << setw(15) << "Goals" << fixed << left << setw(15) << team_a_goals << team_b_goals << endl;
    cout << left << setw(15) << "Blocks" << fixed << left << setw(15) << team_a_blocks << team_b_blocks << endl;
    cout << left << setw(15) << "Shots on Goal" << fixed << left << setw(15) << team_a_shots_on << team_b_shots_on << endl;
    cout << left << setw(15) << "Shots off Goal" << fixed << left << setw(15) << team_a_shots_off << team_b_shots_off << endl;
    cout << left << setw(15) << "Fouls" << fixed << left << setw(15) << team_a_fouls << team_b_fouls << endl;
    cout << left << setw(15) << "Yellow Cards" << fixed << left << setw(15) << team_a_yellow << team_b_yellow << endl;
    cout << left << setw(15) << "Red Cards" << fixed << left << setw(15) << team_a_red << team_b_red << endl;
}

int main() {
    soccer_game();
}
