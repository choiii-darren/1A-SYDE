//
//  main.cpp
//  ReviewQ8
//
//  Created by Richard Choi on 2020-10-15.
//

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

bool check_if_exists(int my_array[], int ARRAY_SIZE, int value){
    for (int index = 0; index < ARRAY_SIZE; index++){
        if (value == my_array[index]){
            return true;
        }
    }
    return false;
}

void generate_values(int my_array[], const int ARRAY_SIZE){
    int value = 0;
    srand(static_cast<unsigned int> (time(0)));
    for (int index = 0; index < ARRAY_SIZE; index++){
        do {
            value = rand() % 15 + 1;
        } while (check_if_exists(my_array, ARRAY_SIZE, value) == true);
            
        my_array[index] = value;
        
    }
}

void output_values(int my_array[], const int ARRAY_SIZE){
    for (int index = 0; index < ARRAY_SIZE; index++){
        cout << setw(2) << setfill('0') << my_array[index] << endl;
    }
}

int main() {
    const int ARRAY_SIZE = 15;
    srand(static_cast<unsigned int> (time(0)));
    int my_array[ARRAY_SIZE] = {0};
    
    generate_values(my_array, ARRAY_SIZE);
    output_values(my_array, ARRAY_SIZE);
    
}
