/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/A     Assignment: Level 1 Question 2
File Name: Assignment1-Q1

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Calculating and converting values from input to outputs of fahrenheit, miles, and a value in $
Purpose: Practice using const's and inputs to create formulas and precision outputs
Due Date: Oct 5, 2020
*/
#include <iostream>
using namespace std;

void celsius_fahrenheit_calculator () {
    //declare most variables and constants for the conversion
    double celsius = 0;
    const double CELS_FAHR_MULTIPLICATION = 1.8;
    const int CELS_FAHR_ADDITION = 32;
    
    // input of the temperature in celsius
    cout << "Input the temperature in Celsius" << endl;
    cin >> celsius;
    
    //these 3 lines set the precision of the decimal to two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    
    // set variable fahrenheit to the formula needed to convert celsius to fahrenheit
    double fahrenheit = celsius * CELS_FAHR_MULTIPLICATION + CELS_FAHR_ADDITION;
    
    // Echo the input in celsius and output it's conversion in fahrenheit
    cout << celsius << " in Celsius is " << fahrenheit << " in Fahrenheit" << endl;
}
void kilometers_miles_calculator () {
    // declare the variables used and the constant for hte conversion
    double kilometers = 0;
    const double KILO_MILE_MULTIPLICATION = 1.609;
    
    // input of the distance in kilometers
    cout << "Input the distance in kilometers" << endl;
    cin >> kilometers;
    
    // calculation of miles from kilometers
    double miles = kilometers / KILO_MILE_MULTIPLICATION;
    
    //these 3 lines set the precision of the decimal
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    
    // echoes input of kilometers and outputs miles calculated from kilometers
    cout << kilometers << " in kilometers is " << miles << " in miles" << endl;
}

void total_value () {
    //declaring variables and constants of the values of the coins assigned
    int quarters = 0;
    int loonies = 0;
    int toonies = 0;
    const int QUARTERS_VALUE = 25;
    const int LOONIES_VALUE = 100;
    const int TOONIES_VALUE = 200;
    
    // getting input of how many coins of each type there are
    cout << "How many toonies do you have?" << endl;
    cin >> toonies;
    cout << "How many loonies do you have?" << endl;
    cin >> loonies;
    cout << "How many quarters do you have?" << endl;
    cin >> quarters;
    
    // calculating the sum of the value in cents, then using division and mod operators to get the dollars and cents value respectively.
    int sum_cents = quarters * QUARTERS_VALUE + loonies * LOONIES_VALUE + toonies * TOONIES_VALUE;
    int dollar_value = sum_cents / 100;
    int cent_value = sum_cents % 100;
    
    // outputting the calculated sum
    cout << "Your total is $" << dollar_value << "." << cent_value << " dollars." << endl;
}
int main () {
    celsius_fahrenheit_calculator();
    kilometers_miles_calculator();
    total_value ();
}
