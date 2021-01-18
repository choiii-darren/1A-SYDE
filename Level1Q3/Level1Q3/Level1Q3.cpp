/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/A     Assignment:Level 1 Additional Practice Question 3
File Name: Level1Q3

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Checking conditions for a value, iterating values within a range that fit conditions, and using a while loop to prompt for input within a certain range.
Purpose: Practice using boolean conditions and loops.
Due Date: Oct 5 2020
*/

#include <iostream>
using namespace std;

void check_target () {
    //declare input variable
    int target = 0;
    
    //set target variable to the input
    cout << "Input a number greater than 5000, with the third digit from the right being 3, the second digit from the right being even, and is divisible by 10" << endl;
    cin >> target;
    
    //breaking down target variable into the parts needed to check
    int check_3 = target / 100 % 10;
    int check_even = target / 10 % 2;
    int check_10 = target % 10;
    
    //boolean keeps track if all of the parts keep true; if one fails, it's false
    bool is_valid = target > 5000 && check_3 == 3;
    is_valid = is_valid && check_even == 0;
    is_valid = is_valid && check_10 == 0;
    
    //if boolean is true, outputs true statement, if not, false statement
    if (is_valid)
        cout << "The number is valid." << endl;
    else
        cout << "The number is not valid." <<endl ;
    }

void first_5_entries() {
    //declare limiting variable
    int valid_count = 0;
    
    //for loop sets condition for entry <= 10000 and has not printed catalogued 5 values, and set incremental value to 3 in entry.
    for (int entry = 0;entry<=10000 && valid_count < 5;entry += 3){
        
        //The boolean checks the conditions of divisible by 2 or 3, and 11
        bool is_valid_entry = entry % 2 == 0 || entry % 3 == 0;
        is_valid_entry = is_valid_entry && entry % 11 == 0;
        
        //if boolean is true, it prints the entry
        if (is_valid_entry == true){
            cout << entry << endl;
            ++valid_count;
        }}}

void check_number_value () {
    //declare initializing variable
    int entry = 15;
    //while loop determines if the inputted value can break the loop
    while (entry <1 || entry > 10){
        cout << "Input a number between 1 and 10" << endl;
        cin >> entry;
    }
    cout << "The entry value is " << entry << endl;
}

int main() {
    check_target();
    first_5_entries();
    check_number_value();
}
