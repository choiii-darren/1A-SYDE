//
//  main.cpp
//  ReviewQ6
//
//  Created by Richard Choi on 2020-10-15.
//

#include <iostream>
using namespace std;

void input_values(int& entry_count){
    while (entry_count <= 0){
        cout << "How many entries will be entered?" << endl;
        cin >> entry_count;
    }
}

bool processing_values(int entry_count, double& minimum, double& maximum, double& mean_value){
    double current_value = 0;
    double sum_of_values = 0;
    
    for (int entry = 0; entry < entry_count; entry++){
        bool min_check = false;
        bool max_check = false;
        cout << "Enter the current value" << endl;
        cin >> current_value;
        
        min_check = entry == 0 || current_value < minimum;
        if (min_check){
            minimum = current_value;
        }
        
        max_check = entry == 0 || current_value > maximum;
        if (max_check){
            maximum = current_value;
        }
        
        sum_of_values += current_value;
        
        
    }
    
    mean_value = sum_of_values / entry_count;
    
    return true;
}

void outputting_values(double minimum, double maximum, double mean_value){
    cout << "The minimum value is " << minimum << endl;
    cout << "The maximum value is " << maximum << endl;
    cout << "The mean value is " << mean_value << endl;
    
}

void executing_functions (){
    int entry_count = 0;
    double minimum = 0, maximum = 0, mean_value = 0;
    
    input_values(entry_count);
    processing_values(entry_count, minimum, maximum, mean_value);
    outputting_values(minimum, maximum, mean_value);
}

int main() {
    executing_functions();
    
}
p
