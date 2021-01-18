/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/A     Assignment: Level 1 Question 4
File Name: Level1Q4

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Calculating pi to a set precision, and calculating the length of the hypotenuse
Purpose: Practice loops and using new math functions, notably power and sqrt
Due Date: Oct 5 2020
*/
#include <iostream>
#include <cmath>
using namespace std;

void calc_pi (){
    //declaring variables with some preset values to allow for later manipulation when getting the final value of pi
    int precision_value = 0;
    double pi_value = 1;
    double exponential_pi = 0;
    double final_value = 4;
    
    // inputting precision of pi
    cout << "Input the degre of precision you desire for the value of pi" << endl;
    cin >> precision_value;
    
    // this loop keeps adding all the values until we've hit the desired precision of pi
    for (int entry = 1; entry <= precision_value; entry++){
        exponential_pi = pow(-1 ,entry )/(2*entry + 1);
        pi_value += exponential_pi;
    }
    
    // this calculates and prints the final value
    final_value *= pi_value;
    cout << final_value;
}

void hypotenuse () {
    // declaring variables for use
    double base = 0;
    double perpendicular = 0;
    
    // getting the input of the base and its perpendicular length
    cout << "Input the base of the triangle." << endl;
    cin >> base;
    cout << "Input the perpendicular of the triangle." << endl;
    cin >> perpendicular;
    
    // calculate powers first, then I don't need to make a compound operator for the hypotenuse double
    int powers = pow(base,2) + pow(perpendicular,2);
    double hypotenuse = sqrt(powers);
    
    //outputs the length of the hypotenuse
    cout << "The length of the hypotenuse is " << hypotenuse << endl;
}
    
int main () {
    calc_pi();
    hypotenuse();
}
