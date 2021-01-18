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
// declaring constants to divide the weight down later and getting input for the weight to divide
void weight_calculating () {
    int ONE_HUNDRED_TWENTY_FIVE = 125;
    int SEVENTY_FIVE = 75;
    int FORTY_TWO = 42;
    int FIFTEEN = 15;
    int ONE = 1;
    int weight;
        cout << "Input a weight value to compute" ; //inputs weight
        cin >> weight  ; // can also set weight = 2048, which is step 1
    
    // calculating the number of each weight.
    int weight_125 = weight / ONE_HUNDRED_TWENTY_FIVE;
    int weight_125_remainder = weight % ONE_HUNDRED_TWENTY_FIVE;
    int weight_75 = weight_125_remainder / SEVENTY_FIVE;
    int weight_75_remainder = weight_125_remainder % SEVENTY_FIVE;
    int weight_42 = weight_75_remainder / FORTY_TWO;
    int weight_42_remainder = weight_75_remainder % FORTY_TWO;
    int weight_15 = weight_42_remainder / FIFTEEN;
    int weight_15_remainder = weight_42_remainder % FIFTEEN;
    int weight_1 = weight_15_remainder / ONE;
    
    // this returns the number of weights values in order
    cout << "Number of 125 weights is " << weight_125 << endl;
    cout << "Number of 75 weights is " << weight_75 << endl;
    cout << "Number of 42 weights is " << weight_42 << endl;
     cout << "Number of 15 weights is " << weight_15 << endl;
     cout << "Number of 1 weights is " << weight_1 << endl;
}

int main () {
    weight_calculating();
}


