//
//  main.cpp
//  ReviewQ7
//
//  Created by Richard Choi on 2020-10-15.
//

#include <iostream>
#include <ctime>
using namespace std;

void increment_array() {
    // declare and initialize
    int unsorted_data[100] = {0};
    int entry_count = 0;
    srand(time(0));
    
    cout << "How many integers under 20 will be entered?" << endl;
    cin >> entry_count;
    
    for (int entry = 0; entry < entry_count; entry++){
        int current_entry = 0;
        cout << "What integer will be entered?" << endl;
        cin >> current_entry;
        unsorted_data[entry] = current_entry + rand() % 100;
    }
    
    //step2 output sorted array results
    for (int index = entry_count; index > 0; index--){
        cout << unsorted_data[index] << endl;
    }
    
}

void bubble_swap_array(){
    bool is_sorted = false;
    int unsorted_data[10] = {10, 12, 4, 8, 14, 16, 2, 8, 9, 9};
    
    //step1 apply bubble sort
    while (is_sorted == false){
        bool swap_performed = false;
        for (int index = 0; index < 10; index++){
            if (unsorted_data[index] > unsorted_data[index + 1]){
                int temp = unsorted_data[index];
                unsorted_data[index] = unsorted_data[index + 1];
                unsorted_data[index + 1] = temp;
                swap_performed = true;
            }
        }
        is_sorted = !swap_performed;
    }
    for (int index = 0; index < 10; index++){
        cout << unsorted_data[index] << endl;
    }
}

int main() {
    increment_array();
    bubble_swap_array();
}
