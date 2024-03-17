#include <iostream>
#include <sstream>
#include <vector>

#include "SortingAlgorithms.h"

using namespace std;

void ParseInput(const string& input, vector<int>& data) {

    string temp = "";
    stringstream parse(input);

    while (parse >> temp) {

        data.push_back(stoi(temp));
    }
}

int main() {

    const pair<int, string> kAlgorithms[] = {
        {1, "Bubble Sort"},
        {2, "Insertion Sort"},
        {3, "Merge Sort (Recursive)"},
        {4, "Merge Sort (Iterative)"},
        {5, "Heap Sort"},
        {6, "Shell Sort"},
        {7, "Quick Sort"},
        {8, "Radix Sort"}
    };
    
    int algorithm_digit = 0;
    bool continue_program = true;

    const string program_header = "Shaun's Sorting Algorithm Program";

    cout << "~~~Welcome To My Sorting Algorithms Program~~~" << endl;

    while (continue_program == true) {

        cout << "What Sorting Algorithm Would You Like to Use?" << endl;

        for (int i = 1; i <= 8; i++) {
            
            cout << "(" << i << ") " << kAlgorithms[i].second << endl;
        }

        cout << "Enter A Digit Corresponding To The Algorithm or X to Exit the Program: " << endl;
    
        // If the cin fails, input is assumed to be a character and the program exits
        if (!(cin >> algorithm_digit)) { 

            continue_program = false;
        } else if (algorithm_digit <= 0 || algorithm_digit > 9) {

            while (algorithm_digit <= 0 || algorithm_digit > 9) { // 

                cout << "Invalid Input. Please Enter a Digit Between 1 and 8 or X to Exit the Program: " << endl;

                cin >> algorithm_digit;
            }
        } else
        
        {

            string sorting_input = "";
            int start_index = 0, end_index = 0;

            // Clear the Screen
            system("cls");

            // Display the Program Header
            cout << program_header << endl;

            // Display the Name of the Algorithm
            cout << kAlgorithms[algorithm_digit].second << endl;

            // Display: What Input Would You Like to Sort (Start w/ Ints, then templatize to add chars, strings, etc.,) - Input of the Same Type
            cout << "What Data Would You Like to Sort? (Integers Only)" << endl;
           
            // Check if Data Is all the same type - eventually check the data
            cin >> sorting_input;

            // Display: What Are the Bound of The Sorted Input - Begining and End Indexes
            cout << "What Are the Bounds of the Sorted Input? (Start and End Indexes)" << endl;

            cin >> start_index >> end_index;

            // Create a vector of the input data
            vector<int> data;

            ParseInput(sorting_input, data);

            switch (algorithm_digit) {

            case 1: 
            SortingAlgorithms::BubbleSort(data, start_index, end_index);
            break;

            case 2: 
            SortingAlgorithms::InsertionSort(data, start_index, end_index);
            

            case 3:
            SortingAlgorithms::RecursiveMergeSort(data, start_index, end_index);
            break;
            

            case 4:
            SortingAlgorithms::IterativeMergeSort(data, start_index, end_index);
            break; 
           
            case 5: 
            SortingAlgorithms::HeapSort(data, start_index, end_index);
            break;
        
            case 6:
            SortingAlgorithms::ShellSort(data, start_index, end_index);
            break; 
        
            case 7:
            SortingAlgorithms::QuickSort(data, start_index, end_index);
            break; 
            
            case 8:
            SortingAlgorithms::RadixSort(data, start_index, end_index);
            break; 

            case kExitProgram:
            continue_program = false;
            break;

            // Default case is handled before the switch statement execute
        }

        }

    }

    switch (algorithm_digit) {

        case 1: 
        // Bubble Sort

        case 2: 
        // Insertion Sort

        case 3:
        //Merge Sort (Recursive)

        case 4:
        //Merge Sort (Iterative)

        case 5:
        // Heap Sort

        case 6:
        // Shell Sort

        case 7:
        // Quick Sort

        case 8:
        // Radix Sort

        default:
        // Invalid Input

        cout << "Undefined Input Please Try Again."; // Wait a Couple Seconds, display the list again
    }

    int test = 0;

    cout << "TEST: ";
    cin >> test;

    cout << test << endl;
}