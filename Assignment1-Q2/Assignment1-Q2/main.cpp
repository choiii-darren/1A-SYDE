
#include <iostream>
using namespace std;

/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: 1     Assignment:1 Question 1
File Name: Assignment1-Q1

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Dividing an inputted weight into smaller set weights.
Purpose: Split the weight up into 125, 75, 42, 15, and 1 unit weights
Due Date: Sept 25 2020
*/

// (last - first + 1) = n
// I have to calculate the number of terms, n using the formula above.
// I then plug in the formula, substituting for known values, declare a variable equal to that equation.
// this function calculates the sum of the hard coded values
void sum_function () {
    int n1 = (500 - 1 + 1);
    int n2 = (2020 - 5 + 1);
    int n3 = (32000 - 42 + 1);
    int one_five_hundred = n1 / 2 * (2 * 1 + (n1 - 1));
    int fifty_twenty_twenty = n2 / 2 * (2 * 5 + (n2 - 1)) ;
    double forty_two_thirty_two_thousand = n3 / 2.0 * (2 * 42 + (n3 - 1));
    
    // this function prints the results of the sums of the arithmetic sequences
    // im checking the output with the summation notation on my calculator
    cout << "The sum of numbers from 1 to 500 is " << one_five_hundred << "\n";
    cout << "The sum of numbers from 5 to 2020 is " << fifty_twenty_twenty << "\n";
    cout << "The sum of numbers from 42 to 32000 is " << forty_two_thirty_two_thousand << "\n";
    
    // this function calculates the value of n for the sum of a arithmetic sequence and outputs it
    int lower_bound;
        cout << "Input the lower bound";
        cin >> lower_bound;
    int higher_bound;
        cout << "Input the higher bound";
        cin >> higher_bound;
    int range_n = higher_bound  - lower_bound + 1;
    int calculate_sum = range_n / 2 * (2 * lower_bound + (range_n - 1));
    cout << "The sum of numbers between " << lower_bound << " and " << higher_bound << " is " << calculate_sum;
}

int main () {
    sum_function();
}
