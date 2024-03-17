#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <cctype>

#include "SortingAlgorithms.h"

using namespace std;

const string CLI_header = "--Sorting# ";

const string program_header = "Shaun's Sorting Algorithm Program";
const string input_header = CLI_header + "Enter a Digit Corresponding to the Algorithm\n" + 
                            CLI_header + "Enter X to Exit the Program";

void DisplayAlgorithms(const pair<int, string> algorithms[]) { // DONE

    for (int i = 0; i < 8; i++) {
            
        cout << CLI_header << "(" << algorithms[i].first << ") " << algorithms[i].second << endl;
    }

    cout << CLI_header << endl;
}

// Command line input system feels sloppy
int GetSortingAlgorithm(const pair<int, string> algorithms[]) { // DONE

    string system_input = "";
    stringstream ss;
    int algorithm_digit = 0;

    cout << CLI_header << "What Sorting Algorithm Would You Like to Use?" << endl;

    DisplayAlgorithms(algorithms);

    cout << input_header << endl;

    cout << CLI_header;

    getline(cin, system_input);
    ss << system_input;

    // Will either equal 0, meaning the input is a character
    // or a digit, meaning the input is a number
    ss >> algorithm_digit;

    if (algorithm_digit == 0);

    else if (algorithm_digit <= 0 || algorithm_digit > 8) {

        do {

            cout << CLI_header << endl;
            cout << CLI_header << "--Invalid Input--" << endl;;
            cout << input_header << endl;

            sleep(1);

            DisplayAlgorithms(algorithms);

            cout << CLI_header;

            system_input.clear();
            ss.clear();

            getline(cin, system_input);
            
            ss << system_input;

            if (!(ss >> algorithm_digit)) {
                
                algorithm_digit = 0;
                break;
            }
        } while (algorithm_digit <= 0 || algorithm_digit > 8);
    }

    // Return ranges from 0 to 8
    return algorithm_digit;
}

void ParseInputData(const string& input_data, vector<int>& container) { // WORKS FOR INTEGERS

    stringstream ss(input_data);
    string temp;

    while (ss >> temp) {

        container.push_back(stoi(temp));
    }
}

void ParseInputIndexs(const string& input_indexs, int& start_index, int& end_index) { // DONE

    stringstream ss(input_indexs);
    string temp;

    ss >> temp;
    start_index = stoi(temp);

    ss >> temp;
    end_index = stoi(temp);
}

void GetDataToSort(vector<int>& container) { // DONE
    
    string input_data = "";

    // Display: What Input Would You Like to Sort (Start w/ Ints, then templatize to add chars, strings, etc.,) - Input of the Same Type
    cout << CLI_header << "What Data Would You Like to Sort? (Integers Only)" << endl;

    cout << CLI_header;
            
    getline(cin, input_data);

    ParseInputData(input_data, container);
}

void GetIndexs(const int container_size, int& start, int& end) { // DONE

    string input_indexs = "";

    cout << CLI_header << "What Indexs Would You Like to Sort?" << endl;

    cout << CLI_header;

    do {

        getline(cin, input_indexs);

        ParseInputIndexs(input_indexs, start, end);

        if (start < 0 || start >= container_size || end < 0 || end >= container_size) {
            
            cout << CLI_header << endl;
            cout << CLI_header << "--Invalid Input--" << endl;
            cout << CLI_header << "The Indexs Must Be Within the Range of the Data" << endl;

            cout << CLI_header;
        }

    } while (start < 0 || start >= container_size || end < 0 || end >= container_size);
 
}

void DisplayContainer(const vector<int>& data) {

    for (int i = 0; i < data.size(); i++) {

        cout << data[i] << " ";
    }

    cout << endl;
    cout << CLI_header << endl;
}

bool ContinueCheck() {

    char continue_program_input = ' ';
    // Ask the User if They Would Like to Continue Using the Program
    cout << CLI_header << "Would You Like to Continue Using the Program? (Y/N)" << endl;

    cout << CLI_header;

    cin >> continue_program_input;

    return (continue_program_input == 'Y' || continue_program_input == 'y');
}

int main() {

    system("clear");

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

    cout << "~~~Welcome To My Sorting Algorithms Program~~~" << endl << endl;
    
    sleep(1);

    do {

        // Determine the Sorting Algorithm to Use
        algorithm_digit = GetSortingAlgorithm(kAlgorithms);

        if (algorithm_digit == 0) {

            continue_program = false;
        } else {

            vector<int> container;
            int start_index = 0, end_index = 0;

            // Clear the Screen
            system("clear");

            // Display the Program Header
            cout << program_header << endl << endl;

            // Display the Name of the Algorithm
            cout << CLI_header << kAlgorithms[algorithm_digit - 1].second << endl << CLI_header << endl;

            GetDataToSort(container);

            cout << CLI_header << endl;

            GetIndexs(container.size(), start_index, end_index);

            cout << CLI_header << endl;

            cout << CLI_header << "Unsorted Input: ";
            DisplayContainer(container);

            // Executes the Sorting Algorithm
            switch (algorithm_digit) {

                case 1: 
                SortingAlgorithms::BubbleSort(container, start_index, end_index);
                break;

                case 2: 
                SortingAlgorithms::InsertionSort(container, start_index, end_index);
                break;
                
                case 3:
                SortingAlgorithms::RecursiveMergeSort(container, start_index, end_index);
                break;
                
                case 4:
                SortingAlgorithms::IterativeMergeSort(container, start_index, end_index);
                break; 
            
                case 5: 
                SortingAlgorithms::HeapSort(container, start_index, end_index);
                break;
            
                case 6:
                SortingAlgorithms::ShellSort(container, start_index, end_index);
                break; 
            
                case 7:
                SortingAlgorithms::QuickSort(container, start_index, end_index);
                break; 
                
                case 8:
                SortingAlgorithms::RadixSort(container, start_index, end_index);
                break; 

                // Default case is handled before the switch statement executes
                default:
                break;
            }

            // Display the Sorted Data
            cout << CLI_header << "Sorted Output: ";
            DisplayContainer(container);

            continue_program = ContinueCheck();
        }

    } while (continue_program);

    cout << CLI_header << "Goodbye" << endl;
        
    return 0;
}