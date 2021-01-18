/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: 2     Assignment:2 Question 1
File Name: Assignment2Q1

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Takes a prime number input, then computes and prints all prime numbers less than or equal to the entered value. It will indicate if the prime is palindromic and if the sum of the digits is odd
Purpose: Learning to use and practice compound loops.
Due Date: Oct 11, 2020
*/

/* I tested 5, 15, 40, and 150, and I checked with a google search which primes were under 150.
 The code should work for numbers that can be contained within the integer variable storage for values
*/
#include <iostream>
using namespace std;

void prime_printing () {
    
    // this code sets the number which the program prints out primes and checks the listed conditions
    int upper_bound = 0;
    while (upper_bound < 2){
        cout << "Input the upper bound for which the program iterates up to" << endl;
        cin >> upper_bound;
    }
    
    // this loop iterates through all of the numbers less than the entered upper bound
    for (int index = 2; index <= upper_bound ; index++){
        
        // The nature of my code changes each variable to check conditions. Thus, I re-initialize the variables each loop to reset the conditions.
        int index1 = index;
        int reverse_digit;
        int reverse = 0;
        int index2 = index;
        int sum_digit = 0;
        int sum_of_digits = 0;
        bool is_prime = true;
        
        // This loop checks whether the number in the current loop (index) is prime, by iterating through the values up to half of the index
        for (int check = 2; check <= index / 2; ++check) {
            if (index % check == 0) {
                is_prime = false;
                break;
}}
        
        // if the number is prime, it'll print the number and checks the condiitons on the prime printed
        if (is_prime){
            cout << index << endl;
            
            // this do-while loop reverses the current prime and tests if the reverse is the same as the current, and prints if it's true
            do {
                    reverse_digit = index1 % 10;
                    reverse = (reverse * 10) + reverse_digit;
                    index1 = index1 / 10;
                } while (index1 != 0);
            if (index == reverse)
                cout << "This prime is palindromic" << endl;
            
            // this block breaks down the index into each digit, adds it up, and checks if the sum of digits in the index is odd. If so, it states so.
            do {
                sum_digit = index2 % 10;
                sum_of_digits = sum_of_digits + sum_digit;
                index2 = index2 / 10;
            } while (index2 != 0);
            if (sum_of_digits % 2 == 1)
                cout << "This sum of the digits in this prime is odd" << endl;
        }
         }
     }


int main () {
    prime_printing();
}
