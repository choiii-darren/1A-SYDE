//
//  main.cpp
//  ReviewQ9Leetcode
//
//  Created by Richard Choi on 2020-10-17.
//

#include <iostream>
#include <array>
#include <vector>
using namespace std;

int check_direction (double my_array[], int array_size) {
    for (int index = 0; index < array_size; index++){
        if (my_array[index] < my_array[index + 1]){
            return 1;
                }
        else if (my_array[index] > my_array[index + 1]){
            return -1;
                }
        else
            continue;
            }
    return 0;
        }

void verify (){
    double my_array[] = {1.0,2.0,2.0,3.0};
    int array_size = sizeof(my_array)/sizeof(my_array[0]);
    bool isMonotonic = true;
    

   
    
    if (check_direction(my_array, array_size) == 1){
        for (int index2 = 0; index2 < array_size - 1; index2++){
            if (my_array[index2] > my_array[index2 + 1]){
                isMonotonic = false;
                break;
                    }
                }
            }

    if (check_direction(my_array, array_size) == -1){
        for (int index3 = 0; index3 < array_size - 1; index3++){
            if (my_array[index3] < my_array[index3 + 1]){
                isMonotonic = false;
                break;
                    }
                }
            }
    if (isMonotonic)
        cout << "It is monotonic";
    else
        cout << "It is not monotonic";
     }

int main() {
    verify();
}
