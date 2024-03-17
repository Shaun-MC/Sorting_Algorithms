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

void DisplayAlgorithms(const pair<int, string> algorithms[]) {

    for (int i = 0; i < 8; i++) {
            
        std::cout << "(" << algorithms[i].first << ") " << algorithms[i].second << endl;
    }
}

void DisplaySortedInput(const vector<int>& data) {

    for (int i = 0; i < data.size(); i++) {

        std::cout << data[i] << " ";
    }

    std::cout << endl;
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

    const string program_header = "Shaun's Sorting Algorithm Program";
    const string input_header = "Enter A Digit Corresponding To The Algorithm or X to Exit the Program:";
    const string CLI_header = "--Sorting# ";

    int algorithm_digit = 0;
    bool continue_program = true;

    std::cout << "~~~Welcome To My Sorting Algorithms Program~~~" << endl;

    do {

        std::cout << "What Sorting Algorithm Would You Like to Use?" << endl;

        DisplayAlgorithms(kAlgorithms);

        std::cout << "Enter A Digit Corresponding To The Algorithm or X to Exit the Program: " << endl;

        std::cout << CLI_header;

        std::cin >> algorithm_digit;

        // If the cin fails, input is assumed to be a character and the program exits
        if (!(std::cin >> algorithm_digit)) { 

            continue_program = false;
        } else if (algorithm_digit <= 0 || algorithm_digit > 8) {

            do {

                std::cout << "Invalid Input. " << input_header << endl;

                DisplayAlgorithms(kAlgorithms);

                std::cout << CLI_header;

                if (!(std::cin >> algorithm_digit)) {

                    continue_program = false;
                }
            } while (algorithm_digit <= 0 || algorithm_digit > 8 || continue_program == false);
        }

        if (continue_program) {

            string sorting_input = "";
            int start_index = 0, end_index = 0;
            char continue_program_input = ' ';

            // Clear the Screen
            system("cls");

            // Display the Program Header
            std::cout << program_header << endl;

            // Display the Name of the Algorithm
            std::cout << kAlgorithms[algorithm_digit].second << endl;

            // Display: What Input Would You Like to Sort (Start w/ Ints, then templatize to add chars, strings, etc.,) - Input of the Same Type
            std::cout << "What Data Would You Like to Sort? (Integers Only)" << endl;
           
            // Check if Data Is all the same type - eventually check the data
            std::cin >> sorting_input;

            // Get the beginning and ending indexes of the input data
            std::cout << "What Are the Bounds of the Sorted Input? (Start and End Indexes)" << endl;

            std::cin >> start_index >> end_index;

            // Create a vector of the input data
            vector<int> data;

            ParseInput(sorting_input, data);

            // Executes the Sorting Algorithm
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

                // Default case is handled before the switch statement executes
                default:
                break;
            }

            // Display the Sorted Data
            DisplaySortedInput(data);

            // Ask the User if They Would Like to Continue Using the Program
            std::cout << "Would You Like to Continue Using the Program? (Y/N)" << endl;

            std::cout << CLI_header;

            std::cin >> continue_program_input;

            if (continue_program_input == 'N' || continue_program_input == 'n') {

                continue_program = false;
            }
        }

    } while (continue_program);

    std::cout << "Thank You For Using My Sorting Algorithms Program!" << endl;
        
    return 0;
}