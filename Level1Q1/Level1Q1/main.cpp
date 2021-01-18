/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/A     Assignment: Level 1 Question 1
File Name: Assignment1-Q1

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Practicing inputs and outputs with echoing, and printing ASCII encoded art using cout functions
Purpose: Learning syntax errors when parts of code written are wrong, and how to problem solve the issue
Due Date: Oct 5 2020
*/
#include <iostream>
using namespace std;

// removing > from include directive removes library of functions
// removing int from int main says c++ requires a type specifier for all declarations
// miss spelling main error undefined symbol: _main
// removing ); main ncannot be declared as global variable
// missed ; states expected ; after expression
// miss spelling one 'number of languages' results in use of undeclared identifier
// miss spelling cin results in use of undeclared identifier 'ci' (thinks its a variable)
// omitting << in cout results in parse issue and referencing an overloaded functino could not be resolved or was it meant to be called?
// omitting >> in cin results in expected ; after expression
// omitting { in the first function results in many parse and semantic issues like expected unqualified-id and unknown type name 'cout'
void print_syde () {
    cout <<  "****************************" << endl;
    cout <<" ____ ___  _ ____  _____"<<endl;
    cout <<"/ ___\\  \\/ // _  \\/ __/"<<endl;
    cout <<"|    \\ \\  / | | \\||  \\ " <<endl;
    cout <<"\\___ | / /  | |_/||  /_" << endl;
    cout <<"\\____//_/   \\____/\\____\\" << endl;
    cout << "****************************" << endl;
}

int main () {
    int number_of_languages;
    cout << "Hello, class! \n"
    << "Welcome to C++! \n";
    cout << "How many programming languages have you used before?";
    cin >>  number_of_languages;
    cout << "The value you entered is " << number_of_languages << endl;
    print_syde ();
    return 0;
    
}
