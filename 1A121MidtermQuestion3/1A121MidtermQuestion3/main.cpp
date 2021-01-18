/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/a      Assignment: 121 Midterm
File Name: control_flow

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Enter a number and print out numbers that are between the first two encountered 7's from the right of the number
Purpose: test control flow
Due Date: Oct 23, 2020
*/

#include <iostream>
#include <cmath>
using namespace std;

// five test cases:
// two sevens from the beginning: 1723457 EXPECTED: 2345 OUTPUT: 2345
// a seven following a seven: 1012377 EXPECTED: 0 OUTPUT: 0
// only one seven: 1035697 EXPECTED: 103569 OUTPUT: 103569
// a seven not at beginning: 1702765 EXPECTED: 2 OUTPUT: 2
// if no seven is found: 1234568 EXPECTED: 0 OUTPUT: 0

void input(int& value){
    //gets a input > 1000000 and changes the outside variable
    while (value <= 1000000){
        cout << "Input a number greater than 1000000" << endl;
        cin >> value;
    }
}

void processing(int value, int& recorded) {
    //initialize variable to transform, iterate and check conditions
    int value1 = value;
    int check_digit;
    int index = 0;
    bool recording = false;
    
    // this do while loop checks whether theres a seven, and initializes the "Recording" of the digits after it encounters a seven
    do{
        check_digit = value1 % 10;
        if (check_digit == 7){
            recording = true;
        }
        value1 = value1 / 10;
    } while (recording == false && value1 != 0);
    
    // initializes only if it records
    while (recording == true){
        // checks if the digit right after the first seven, and if so, breaks the loop immediately, otherwise, it adds the seven to the recorded variable and makes the answer wrong.
        if (value1 % 10 == 7){
            break;
        }
        
        // a recording of the answer, and must multiply by the power of 10 depending on the unit place it was found. ex, ones place is 10^0, tens place is 10^1, hundreds place is 10^2, and so forth, using index to iterate through exponent
        recorded += value1 % 10 * pow(10, index);
        index++;
        
        //prepares value for next digit, and checks that the number has not ended, if so, it breaks the loop and stops adding numbers to the recorded variable
        value1 = value1 / 10;
        if (value1 == 0){
            break;
        }
    }
}
    
void output(int value, int recorded){
    // takes inputted values and outputs them.
    cout << "The inputted value is " << value << endl;
    cout << "The numbers within the first two 7's from the right are " << recorded << endl;
}

void execute(){
    int value = 0;
    int recorded = 0;
    input(value);
    processing(value, recorded);
    output(value, recorded);
}

int main() {
    execute();
}
