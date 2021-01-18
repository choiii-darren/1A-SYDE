/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: 2     Assignment:2 Question 2
File Name: Assignment2Q2

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Outputting effects of gravity on the position of a baseball over time. Outputting effects of gravity on the position of a baseball as it reaches a certain distance, and once within a certain range, the time interval is split from 1 second into 0.1 seconds.
Purpose: Getting code to switch functions / loops given certain parameters
Due Date: Oct 11 2020
*/

/* this code works up to 30 seconds for part 1, but I can have a inputted variable instead of hard coding 30 seconds in the first for loop. It shouldn't matter what time is inputted in the for loop, and it should work until the variables cannot store the whole integer calculated from the function */
/* the second function can be set to work at any value (distance) as long as it can be stored by a long double variable type. You can also change the threshold of considering when the baseball is "reaching" the ground by changing the number inside the while loop. */

#include <iostream>
#include <iomanip>
using namespace std;

void gravity_effects () {
    // declaring and initializing variables and stating constant of acceleration. I probably didn't need so much memory associated with each variable, but I thought better safe than sorry, since the numbers can get large depending on how much time the function executes for.
    const double G_ACCELERATION = 9.80665;
    long double distance = 0;
    long double distance_previous = 0;
    long double last_distance = 0;
    
    // headline console printing
    cout << "Time (seconds)      " << "Distance during interval (m)    " << "Total distance (m)     " << endl;
    
    // this loop calculates the distance at a given integer of time, and calculates previous distance based on the current distance and the last distance, before last distance is updated to the current distane for the next loop
    for (int time = 0; time <= 30; time++){
        distance = 0.5 * G_ACCELERATION * pow(time,2);
        distance_previous = distance - last_distance;
        last_distance = distance;
        
        // this block sets the precision of the decimal shown to 3 figures after the decimal
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        
        // This prints out the time, distance travelled in the interval, and the total distance travelled at that time.
        cout << left << setw(20) << time << fixed << setprecision(3) << left << setw(32) << distance_previous << fixed << distance << endl;
    }
}

void set_distance (){
    // declaring and initializing variables and gravitational acceleration constant
    const double G_ACCELERATION = 9.80665;
    long double distance = 15000;
    long double distance_check = 0;
    double t = 0;
    
    //headline console print
    cout << "Time (seconds)      " << "Distance (m)    " << endl;
    
    // this loop uses the double t as the iterator, and stops once the distance travelled (distance_check var) gets within 1000 meters of the required distance (15000).
    while ((distance - distance_check) > 1000){
        distance_check = 0.5* G_ACCELERATION * pow(t,2);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        
        //print the time and the distane travelled.
        cout << left << setw(20) << t << fixed << setprecision(3) << left << setw(32) << distance_check << endl;
        t++;
    }
    
    // the double t2 is set to whenever t is stopped, and then iterates at 0.1 of a second, as directed. This for loop only works as long as the distance travelled is less than the required distance.
    for (double t2 = t ; distance_check < distance; t2 += 0.1 ){
        distance_check = 0.5 * G_ACCELERATION * pow(t2,2);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        
        //prints time, and the distance travelled in the shortened interval
        cout << left << setw(20) << t2 << fixed << setprecision(3) << left << setw(32) << distance_check << endl;
    }
}

int main(){
    gravity_effects();
    set_distance();
}

