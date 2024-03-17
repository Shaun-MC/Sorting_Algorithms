#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>
#include <span>

using namespace std;

class SortingAlgorithms {

 public:

  static void BubbleSort(vector<int>& container, const int lower_bound, const int upper_bound);

  static void InsertionSort(vector<int>& container, const int lower_bound, const int upper_bound);

  static void RecursiveMergeSort(vector<int>& container, const int lower_bound, const int upper_bound);

  static void IterativeMergeSort(vector<int>& container, const int lower_bound, const int upper_bound);

  static void HeapSort(vector<int>& container, const int lower_bound, const int upper_bound);

  static void ShellSort(vector<int>& container, const int lower_bound, const int upper_bound);

  static void QuickSort(vector<int>& container, const int lower_bound, const int upper_bound);

  static void RadixSort(vector<int>& container, const int lower_bound, const int upper_bound);

 private:
 
  // HELPER FUNCTIONS

  // Used in RecursiveMergeSort()
  static void Merge(vector<int>& container, const int lower_bound, const int middle_index, const int upper_bound);

  // Used in HeapSort()
  static void Heapify(vector<int>& container, const int current_index, const int upper_bound);

  // Used in QuickSort()
  static int Partition(vector<int>& container, const int lower_bound, const int upper_bound);
  static int FindPlacePivot(vector<int>& container, const int lower_bound, const int upper_bound);

  // Used in RadixSort()
  static void CountingSort(vector<int>& container, const int lower_bound, const int upper_bound, const int exp);
};

#endif