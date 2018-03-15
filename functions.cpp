// Grant Ferrell
// CS 4120 Project (Assignment 4)
// Chosen Sorts - Insertion and Quick
// Chosen Language - C++

// Includes [File manipulation]
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

// Generate Datasets Function (Phase-1)
void generateSets(string fileName, int size) {
  // Inital Varibles
  ofstream inFile;
  inFile.open(fileName);
  // Seed to current Time
  srand(time(NULL));
  // Generate size numbers x10
  for (int i = 1; i <= 10; ++i){
    for (int i = 1; i <= size; ++i) {
    // Numbers are generated up to size of array and Send numbers to File
    inFile << rand() % size;
    inFile << ","; // Splits Data
    }
    inFile << "\n"; // Seperates sets by line
  }
  // Close File
  inFile.close();
}

// Insertion Sort Function (Phase-1)
void insertionSort(int array[], int size) {
  // Sorting
  for (int i = 1; i < size; ++i) {
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
  for (int j = lower; j <= upper- 1; ++j) {
    if (array[j] <= pivot) {
      ++i;
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
  // Read in Arguments
  if (argv[1] == "D") {
    // Call Generate Values function
    generateSets("insertionSets.txt", int 1000);
    generateSets("quickSets.txt", int 50000);
  }
  else if (argv[1] == "S") {
    // Sorts Data using functions
    // Inital Varibles
    ofstream inFile;
    ifstream outFile;
    string line, format;
    string insertionOutput[10], quickOutput[10];
    int dataSetInsertion[1000];

    // I for 10 sets of 1k
    outFile.open("insertionSets.txt"); // Open File
    if (outFile.is_open()) {
      for (int i = 1; i <= 10; ++i) {
        getline(outFile, line);
        // Create an array
        // Sort the array
        // Get Number of Comparisons
        // Compute Average CPU time
        // Write info to a String! use (+) for concate'
      }
    }
    else {
      assert(outFile.is_open());
    }
    outFile.close();
    // Q for 10 sets of 50k
    outFile.open("quickSets.txt"); // Open File
    if (outFile.is_open()) {
      for (int i = 1; i <= 10; ++i) {
        getline(outFile, line);
        // Create an array
        // Sort the array
        // Get Number of Comparisons
        // Compute Average CPU time
        // Write info to a String! use (+) for concate'
      }
    }
    else {
      assert(outFile.is_open());
    }
    outFile.close();
    // Write Output arrays to File [seperated with commas and lines]
    inFile.open("Excel_Data.txt"); // Open File
    for (int i = 1; i <= 10; ++i){
      
    }
  }
  else {
    // Do nothing
  }
  return 0;
}