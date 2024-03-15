#include "SortingAlgorithms.h"

// ------------------------------------------------------------------------------------------------
// Checking Index Bounds and Data Safety Is Completed Before Execution of Any Algorithm
// ------------------------------------------------------------------------------------------------

// Standard Bubble Sort Algorithm
void SortingAlgorithms::BubbleSort(vector<int>& container, const int lower_bound, const int upper_bound) {

    for (int i = lower_bound; i < upper_bound; i++) {

        for (int j = lower_bound; j < upper_bound; j++) {
            
            if (container[j] > container[j + 1]) {

                swap(container[j], container[j + 1]);
            }
        }
    }
}

// Standard Insertion Sort Algorithm
void SortingAlgorithms::InsertionSort(vector<int>& container, const int lower_bound, const int upper_bound) {

    // Provides the lhs boundary the traversal_index cannot go behind
    int window_slider = lower_bound;

    for (; window_slider <= upper_bound; window_slider++) {

        // Started at the next index that needs to be sorted
        int traversal_index = window_slider;

        // Keeps the traversal index from leaving the lower_bound
		while ((traversal_index > lower_bound) && (container[traversal_index - 1] > container[traversal_index])) {
			
			swap(container[traversal_index - 1], container[traversal_index]);

			--traversal_index;
		}
	}
}

// Standard Recursive Merge Sort Algorithm
void SortingAlgorithms::RecursiveMergeSort(vector<int>& container, const int lower_bound, const int upper_bound) {

    if (lower_bound < upper_bound) {

        int middle_index = (lower_bound  + upper_bound) / 2;

        RecursiveMergeSort(container, lower_bound, middle_index);
        RecursiveMergeSort(container, middle_index + 1, upper_bound);

        Merge(container, lower_bound, middle_index, upper_bound);
    }
}

// Helper Function
void SortingAlgorithms::Merge(vector<int>& container, const int lower_bound, const int middle_index, const int upper_bound) {

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


    delete curr_list;
}

// Iterative Merge Sort
void SortingAlgorithms::IterativeMergeSort(vector<int>& container, const int lower_bound, const int upper_bound) {


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

// Heap Sort

void SortingAlgorithms::ShellSort(vector<int>& container, const int lower_bound, const int upper_bound) {

    // Starting from...
    for (int gap = upper_bound / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2)) {

        for (int unsorted = gap + lower_bound; unsorted < upper_bound + 1; unsorted++) {

            int nextItem = container[unsorted];

            int j = unsorted;

            for (; (j >= gap) && (nextItem < container[j - gap]) && (j - gap >= lower_bound) && (j >= lower_bound); j -= gap) {

                container[j] = container[j - gap];
            }

            container[j] = nextItem;
        }
    }
}

void SortingAlgorithms::QuickSort(vector<int>& container, const int lower_bound, const int upper_bound) {

    static const int kQSMinSize = 12;

    // Sorting is faster when Insertion Sort is used on smaller sized subarrays
    if (upper_bound - lower_bound < kQSMinSize) {

        InsertionSort(container, lower_bound, upper_bound);
        return;
    } else {

        int pivot_index = Partition(container, lower_bound, upper_bound);

        QuickSort(container, lower_bound, pivot_index - 1);
        QuickSort(container, pivot_index + 1, upper_bound);
    }
}

// Helper Functions
int SortingAlgorithms::Partition(vector<int>& container, const int lower_bound, const int upper_bound) {

    bool done = false;
	int pivot_value = FindPlacePivot(container, lower_bound, upper_bound);

	int index_from_left = lower_bound + 1;    
    int index_from_right = upper_bound - 2;   

    // Sort current chunck of container
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

    swap(container[index_from_left], container[upper_bound - 1]);
	
	int pivot_index = index_from_left;

	return pivot_index;
}

int SortingAlgorithms::FindPlacePivot(vector<int>& container, const int lower_bound, const int upper_bound) {

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


