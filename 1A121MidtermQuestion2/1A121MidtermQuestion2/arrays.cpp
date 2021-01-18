/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/A     Assignment: 121 Midterm
File Name: arrays

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Iterate values in a sequence until the next value is less than the current value
Purpose:
Due Date: Oct 23, 2020
*/

#include <iostream>
#include <ctime>
using namespace std;

// QUESTION 2

void part_2a(){
    // I hard coded and initialized the sequence of numbers, use the boolean to check whether the loop continues, and the index is the iterating variable to iterate and print the array until the condition breaks, which is when the current index is greater than the next index
    int sequence1[20] = {1, 5, 10, 10, 5};
    int sequence2[20] = {6, 3, 6, 6, 10, 8, 9};
    int sequence3[20] = {7, 8, 4, 3, 4, 1, 6, 0};
    int index = 0;
    bool continue_loop = false;
    
    // the do loop prints the first number, and then checks if the first number is less than the second number.
    do {
        cout << sequence3[index] << " ";
        if (sequence3[index] < sequence3[index+1]){
            continue_loop = true;
            index++;
        }
        else
            continue_loop = false;
    } while (continue_loop);
}
// SEQUENCE ONE OUTPUT: 1 5 10
// In sequence one, the second number is greater than the first so it continues the loop until the third number 10, is equal to the fourth number 10. Importance: can iterate until it hits an equal number

// SEQUENCE TWO OUTPUT: 6
// Second number is less than first, so it prints first number and changes continue_loop to false to break the do while loop
// Importance: can still print the first number when the second number is already less than the first number

// SEQUENCE THREE OUTPUT: 7 8
// Third number is less than second, so it stops after printing the second number
// Importance: Can iterate and print, and still break when finding the next index is less than the current index



int main() {
    part_2a();
}
