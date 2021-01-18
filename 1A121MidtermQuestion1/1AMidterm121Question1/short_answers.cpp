/*
Name: Darren Choi
Student Number: 20876806
SYDE 121 Lab: N/A     Assignment: 121 Midterm
File Name: short_answer

I hereby declare that this code, submitted for credit for the course SYDE 121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not knowingly been plagiarized by others.
 
Project: Short answer questions
Purpose:
Due Date: Oct 23, 2020
*/

#include <iostream>
using namespace std;

// QUESTION 1

void part_1a(){
    int test_array[3][4] = {1,2,4,3,5,7,6,8,9};
    cout << test_array[3][1] << " & " << test_array[0][2];
}
// OUTPUT: 0 & 4
// There is no array index [3][1] initialized, so it's value is 0, and array index [0][2] is 4 as it's the third element in the 0 index

void part_1b(int x, int& y, int& z){
    x = --y = z +=4;
    
    int a = 5, b = 2, c = 7;
    part_1b(b, a, c);
    cout << a << b << c;
}
// OUTPUT: 11211
// The overloaded function passes the address of int a and c. x and y are set to z, which then adds four. z is 7, thus 7 + 4 = 11. But, only a and c are passed back as 11, and b is still 2, thus 11211

void part_1c(){
    int darth_vader = 6, darth_maul = 5, darth_sidious = 7;
    int anakin = 6, leia = 7, luke = 7, yoda = 8;
    /*
    if (darth_sidious + darth_maul > yoda || darth_vader + darth_sidious > luke) {
        if (darth_sidious + darth_maul < yoda + anakin && darth_vader + darth_sidious < luke + leia)
            cout << "Jedi win";
        else
            cout << "Sith win!";
    }*/
    
    bool ultimate_winner = false;
    
    ultimate_winner = darth_sidious + darth_maul > yoda || darth_vader + darth_sidious > luke;
    ultimate_winner = ultimate_winner && darth_sidious + darth_maul < yoda + anakin;
    ultimate_winner = ultimate_winner && darth_vader + darth_sidious < luke + leia;
    
    if (ultimate_winner)
        cout << "Jedi win!" << endl;
    else
        cout << "Sith win!" << endl;
}
// OUTPUT: Jedi win!
// The boolean checks either of the first conditions being true. Then, it updates the boolean with needing both conditions being true. They are all true, so thus it prints Jedi win!

void part_1d(){
    int in1 = 20;
    for (;;){
        if ((in1 +=3) > 70){
            break;
        }
        else{
            in1 += 10;
        }
    }
    cout << in1;
}
// OUTPUT: 75
// It adds 3 to in1, so checks 23 > 70 == false, thus adds 10. Add 3 to 33 = 36, false, add 10 = 46. Add 3 to 46 = 49, false, add 10 = 59. Add 3 to 59 = 62, false, add 10 = 72. Add 3 to 72 = 75, TRUE, break the loop, and in1 is now = 75, and is the console output


int main() {
   
}
