#include <iostream>

using namespace std;

int main() {

    const int kBubble = 1, kInsertion = 2, kRMerge = 3, kIMerge = 4, 
              kHeap = 5, kShell = 6, kQuick = 7, kRadix = 8;

    const int kExitProgram = 9;
    
    int algorithm_digit = 0;
    bool continue_program = true;

    const string program_header = "Shaun's Sorting Algorithm Program";

    cout << "~~~Welcome To My Sorting Algorithms Program~~~" << endl;

    while (continue_program == true) {

        cout << "What Sorting Algorithm Would You Like to Use?" << endl;

        cout << "(1) Bubble Sort" << endl;
        cout << "(2) Insertion Sort" << endl;
        cout << "(3) Merge Sort (Recursive)" << endl;
        cout << "(4) Merge Sort (Iterative)" << endl;
        cout << "(5) Heap Sort" << endl;
        cout << "(6) Shell Sort" << endl;
        cout << "(7) Quick Sort" << endl;
        cout << "(8) Radix Sort" << endl;

        cout << "Enter A Digit Corresponding To The Algorithm or X to Exit the Program: " << endl;
    
        // If the cin fails, input is assumed to be a character and the program exits
        if (!(cin >> algorithm_digit)) { 

            continue_program = false;
        } else {

            // Clear the Screen
            // Display the Name of the Algorithm
            // Display: What Input Would You Like to Sort (Start w/ Ints, then templatize to add chars, strings, etc.,) - Input of the Same Type
            // Check if Data Is all the same type
            // Allow User To Input the Data
            // Display: What Are the Bound of The Sorted Input - Begining and End Indexes
            // Check if the bounds make sence given the length of the data
            // 


            switch (algorithm_digit) {

            case kBubble: 


            case kInsertion: 
            

            case kRMerge:
            

            case kIMerge: 
           

            case kHeap: 
        

            case kShell: 
        

            case kQuick: 
            

            case kRadix: 
            
            default: // Invalid Input
    
            cout << "Undefined Input Please Try Again."; // Wait a Couple Seconds, display the list again
            break;
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