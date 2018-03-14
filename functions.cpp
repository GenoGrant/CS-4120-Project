// Grant Ferrell
// CS 4120 Project (Assignment 4)
// Chosen Sorts - Insertion and Quick
// Chosen Language - C++

// Includes [File manipulation]
#include <iostream>
#include <iomanip>

// Insertion Sort Function (Phase-1)
void insertionSort(int array[], int size) {
  // Sorting
  for (int i = 1; i < size; i++) {
    int temp = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = temp;
  }
}

// Partition Function (for use with quick sort) [Last Element Pivot]
int partition (int array[], int lower, int upper) {
  // Initial Varibles
  int pivot = array[upper];
  int i = (lower - 1);
  int temp = 0;
  // Sorting
  for (int j = lower; j <= upper- 1; j++) {
    if (array[j] <= pivot) {
      i++;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  temp = array[i + 1];
  array[i + 1] = array[upper];
  array[upper] = temp;
  return (i + 1);
}

// Quick Sort Function (Phase-1) [Inital call with - array, 0, size]
void quickSort(int array[], int lower, int upper) {
  if (lower < upper) {
    // Partition index
    int i = partition(array, lower, upper);
    // Recursive Calls
    quickSort(array, lower, i - 1);
    quickSort(array, i + 1, upper);
  }
}

// Main (Command Line Interpretation) [D - Generation of Data sets, S - Sorting the Data]
int main(int argc, char **argv[]) {
  ;
}