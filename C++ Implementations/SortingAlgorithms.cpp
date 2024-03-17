#include "SortingAlgorithms.h"

// ------------------------------------------------------------------------------------------------
// Checking Index Bounds and Data Safety Is Completed Before Execution of Any Algorithm
// ------------------------------------------------------------------------------------------------

// Standard Bubble Sort Algorithm
void SortingAlgorithms::BubbleSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    for (int i = lower_bound; i < upper_bound; i++) {

        for (int j = lower_bound; j < upper_bound; j++) {
            
            if (container[j] > container[j + 1]) {

                swap(container[j], container[j + 1]);
            }
        }
    }
}

// Standard Insertion Sort Algorithm
void SortingAlgorithms::InsertionSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    // Provides the lhs boundary the traversal_index cannot go behind
    int window_slider = lower_bound;

    for (; window_slider <= upper_bound; window_slider++) {

        // Started at the next index that needs to be sorted
        int traversal_index = window_slider;

        // First comparison keeps the traversal index from leaving the lower_bound
		while ((traversal_index > lower_bound) && (container[traversal_index - 1] > container[traversal_index])) {
			
			swap(container[traversal_index - 1], container[traversal_index]);

			--traversal_index;
		}
	}
}

// Standard Recursive Merge Sort Algorithm
void SortingAlgorithms::RecursiveMergeSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    if (lower_bound < upper_bound) {

        int middle_index = (lower_bound  + upper_bound) / 2;

        RecursiveMergeSort(container, lower_bound, middle_index);
        RecursiveMergeSort(container, middle_index + 1, upper_bound);

        Merge(container, lower_bound, middle_index, upper_bound);
    }
}

// Helper Function
void SortingAlgorithms::Merge(vector<int>& container, const int lower_bound, const int middle_index, const int upper_bound) { // UNTESTED

    // Size of the required list of values
    int size = upper_bound - lower_bound + 1;
    int index = 0;

    // Used for copying over elements later
    int lb_copy = lower_bound;

    int* curr_list = new int[size];

    // Bounds of the left sub-array
    int lhs1 = lower_bound, rhs1 = middle_index;

    // Bounds of the right sub-array 
    int lhs2 = middle_index + 1, rhs2 = upper_bound;

    // Merge the 2 sub-arrays until either of the list runs to its last index
    while ((lhs1 <= rhs1) && (lhs2 <= rhs2)) {

        // Assigns the next smallest value in the container
        curr_list[index] = (container[lhs1] < container[lhs2]) ? container[lhs1] : container[lhs2];

        // Increment Indexs
        ++index, ++lhs1, ++lhs2;
    }

    // Retrieve the renaming values in the left sub-array and insert them into the temporary array
    while (lhs1 <= rhs1) {

        curr_list[index] = container[lhs1];

        ++index, ++lhs1;
    }

    // ^^, but for the right sub-array
    while (lhs2 <= rhs2) {

        curr_list[index] = container[lhs2];

        ++index, ++lhs2;
    }

    // Copy over elements
    // POSSIBLE OPTIMIZATION: Do this step whenever a value gets inserted into the temp array, 
    //                        instead of at the very end
    for (int i = 0; i < size; i++) {

        container[lb_copy] = curr_list[i];

        ++lb_copy;
    }


    delete[] curr_list;
}

// Iterative Merge Sort
void SortingAlgorithms::IterativeMergeSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED


    int sorting_length = (upper_bound - lower_bound) + 1;

    // MAIN DIFFERENCE BETWEEN ITERATIVE & RECURSIVE VERSIONS ON MERGESORT
    // The additional memory is only created once during the entire execution of the algorithm
    vector<int> copy_container(sorting_length);

    for (int sub_array_size = 1; sub_array_size <= (sorting_length * 2) - 1; sub_array_size *= 2) {
    // sorting_length * 2 - 1 provides a buffer so the algorithm doesn't stop before all elements have been sorted
    // If the buffer wasn't used, a sub_array_size of 33 would stop at a sorting_length of 32 before sorting the last element
    // I.E. sorting_length eqauling non-power of 2 interger would not sort properly

        int c_container_index = 0, lhs_boundary = 0;

        for (lhs_boundary = lower_bound; lhs_boundary <= upper_bound; lhs_boundary += (sub_array_size * 2)) {

            // Getting the sub-array sorting size and making sure it's inside our given boundary (lower_bound to upper_bound)
            int rhs_boundary = lhs_boundary + sub_array_size - 1;
            int middle = ((lhs_boundary + rhs_boundary) / 2 < upper_bound) ? (lhs_boundary + rhs_boundary) / 2 : upper_bound;

            // Similar to the Merge(), getting the 4 indexes for the 2 sub-arrays
            int lhs1 = lhs_boundary;
            int rhs1 = middle;
            int lhs2 = middle + 1 < upper_bound ? middle + 1 : upper_bound;
            int rhs2 = rhs_boundary < upper_bound ? rhs_boundary : upper_bound;

            // Same comparison and insertion into extra memory code as in Merge()
            while ((lhs1 <= rhs1) && (lhs2 <= rhs2)) {

                copy_container[c_container_index] = (container[lhs1] < container[lhs2] ? container[lhs1] : container[lhs2]);

                ++c_container_index, ++lhs1, ++lhs2;
            }

            // Retrieve the renaming values in the left sub-array and insert them into the copy container
            while (lhs1 <= rhs1) {

                copy_container[c_container_index] = container[lhs1];

                ++c_container_index, ++lhs1;
            }

            // ^^, but for the right sub-array
            while (lhs2 <= rhs2) {

                copy_container[c_container_index] = container[lhs2];

                ++c_container_index, ++lhs2;
            }
        }

        // Copy over the sorted elements into the original array starting from the left hand side boundary
        // And 'Reset' the copy container
        int container_iterator = lhs_boundary;
        for (int i = 0; i < c_container_index; i++) {

            copy_container[container_iterator] = copy_container[i];

            copy_container[i] = 0;

            ++container_iterator;
        }
    }
}

void SortingAlgorithms::HeapSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    // Creates a MAX HEAP in place then pops the root off and places it at the end of the subarray

    // Treats the container as a binary tree
    // Uses the lower_bound as the first 'root' index
    
    // Build the first itertions of the MAX HEAP
    for (int current_index = lower_bound; current_index < upper_bound; current_index++) {
        
        Heapify(container, current_index, upper_bound);
    }

    // Extract elements from the heap one by one
    for (int i = upper_bound - 1; i >= lower_bound; i--) {
        
        // Move current root to the end
        swap(container[lower_bound], container[i]);

        // Call heapify on the reduced heap
        Heapify(container, lower_bound, i);
    }
}

// Implement the bounds chekcing 
void SortingAlgorithms::Heapify(vector<int>& container, const int current_index, const int upper_bound) { // UNTESTED

    int largest = current_index; 
    int left_child = 2 * current_index + 1; 
    int right_child = 2 * current_index + 2; 

    // If left child is larger than root
    if (left_child < upper_bound && container[left_child] > container[largest])
        largest = left_child;

    // If right child is larger than largest 
    if (right_child < upper_bound && container[right_child] > container[largest])
        largest = right_child;

    // If largest is not root
    if (largest != current_index) {
        
        swap(container[current_index], container[largest]);

        Heapify(container, largest, upper_bound);
    }
}

void SortingAlgorithms::ShellSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    // Starting with a gap size of half the containter
    // Decrementing the gap sizes using Sedgewick's optimization
    for (int gap = upper_bound / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2)) {

        for (int unsorted = gap + lower_bound; unsorted < upper_bound + 1; unsorted++) {

            int nextItem = container[unsorted];

            int j = unsorted;

            // Standard comparison and bounds checking
            for (; (j >= gap) && (nextItem < container[j - gap]) && (j - gap >= lower_bound) && (j >= lower_bound); j -= gap) {

                container[j] = container[j - gap];
            }

            container[j] = nextItem;
        }
    }
}

void SortingAlgorithms::QuickSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    static const int kQSMinSize = 12;

    // Sorting is faster when Insertion Sort is used on smaller sized subarrays
    if (upper_bound - lower_bound < kQSMinSize) {

        InsertionSort(container, lower_bound, upper_bound);
        return;
    } else {

        int pivot_index = Partition(container, lower_bound, upper_bound);

        // Breaking down the container into smaller subarrays
        QuickSort(container, lower_bound, pivot_index - 1);
        QuickSort(container, pivot_index + 1, upper_bound);
    }
}

// Helper Functions
int SortingAlgorithms::Partition(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    bool done = false;
	int pivot_value = FindPlacePivot(container, lower_bound, upper_bound);

    // First index of the subarray is set in F.P.P(), already sorted
	int index_from_left = lower_bound + 1;    

    // Last two index of the subarray are the pivot and a value greater than the pivot, I.E. already sorted
    int index_from_right = upper_bound - 2;   

    // Sort current sub-array
    while (!done) {

        while (container[index_from_left] < pivot_value) {

            index_from_left++;
        }
        while (container[index_from_right] > pivot_value) {

            index_from_right--;
        }

        if (index_from_right > index_from_left) {
            
            swap(container[index_from_left], container[index_from_right]);

			index_from_left++;
			index_from_right--;

        } else {

            done = true;
        }
    }

    // Place the pivot value in the correct location
    swap(container[index_from_left], container[upper_bound - 1]);
	
	int pivot_index = index_from_left;

	return pivot_index;
}

int SortingAlgorithms::FindPlacePivot(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    // Uses the average of the first, middle and last index as the pivot value
    int middle_index = (lower_bound + upper_bound) / 2;

    if (container[lower_bound] > container[upper_bound]) {

        swap(container[lower_bound], container[upper_bound]);
    }

    if (container[middle_index] > container[upper_bound]) {

        swap(container[middle_index], container[upper_bound]);
    } 

	if (container[lower_bound] > container[middle_index]) {

        swap(container[lower_bound], container[middle_index]);
    }

    int pivot_value = container[middle_index]; 

    swap(container[middle_index], container[upper_bound - 1]);

    return pivot_value;
}

// RADIX
void SortingAlgorithms::RadixSort(vector<int>& container, const int lower_bound, const int upper_bound) { // UNTESTED

    // Find the maximum number to know the number of digits
    int max = container[lower_bound];

    for (int i = lower_bound + 1; i < upper_bound; i++) {

        if (container[i] > max) {

            max = container[i];
        }
    }

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {

        CountingSort(container, lower_bound, upper_bound, exp);
    }
}

// Helper Function
void SortingAlgorithms::CountingSort(vector<int>& container, const int lower_bound, const int upper_bound, const int exp) { // UNTESTED

    int output[upper_bound - lower_bound]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = lower_bound; i < upper_bound; i++) {

        count[(container[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++) {

        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = upper_bound - 1; i >= lower_bound; i--) {

        output[count[(container[i] / exp) % 10] - 1] = container[i];
        count[(container[i] / exp) % 10]--;
    }

    // Copy the output array to container[], so that container[] now contains sorted numbers according to current digit
    for (i = lower_bound; i < upper_bound; i++) {

        container[i] = output[i - lower_bound];
    }
}