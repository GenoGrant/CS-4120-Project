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
#include <assert.h>

// Prototypes
void generateSets(std::string, int);
void insertionSort(int [],int);
void quickSort(int [], int, int);

// Globals for the Number of Comparisons
int numComparInsert = 0, numComparQuick = 0;

// Generate Datasets Function (Complete)
void generateSets(std::string fileName, int size) {
  // Inital Varibles
  std::ofstream inFile;
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
    inFile << "."; // States end of Set
    inFile << "\n"; // Seperates sets by line
  }
  // Close File
  inFile.close();
}

// Insertion Sort Function (Complete)
void insertionSort(int array[], int size) {
  // Sorting
  for (int i = 1; i < size; ++i) {
    int temp = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      --j;
      ++numComparInsert; // Increment Comparisons
    }
    ++numComparInsert; // Increment Comparisons
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
    ++numComparQuick; // Increment Comparisons
  }
  temp = array[i + 1];
  array[i + 1] = array[upper];
  array[upper] = temp;
  return (i + 1);
}

// Quick Sort Function (Complete) [Inital call with - array, 0, size - 1]
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
int main(int argc, char* argv[]) {
  // Read in Arguments
  if (argv[1] == "D") {
    // Call Generate Values function
    generateSets("insertionSets.txt", 1000);
    generateSets("quickSets.txt", 50000);
  }
  else if (argv[1] == "S") {
    // Sorts Data using functions
    // Inital Varibles
    std::ofstream inFile;
    std::ifstream outFile;
    std::string line, format, output;
    std::string insertionOutput[10], quickOutput[10];
    int dataSetInsertion[1000], dataSetQuick[50000];
    int start = 0, temp = 0;
    double cpuTime;
    std::clock_t clockStart;

    // I for 10 sets of 1k
    outFile.open("insertionSets.txt"); // Open File
    if (outFile.is_open()) {
      for (int i = 1; i <= 10; ++i) {
        getline(outFile, line);
        // Seperates Data to be Inserted into arrays
        for (int j = 0, z = 0; line.substr(start, j) == "." && z == 1000; ++j) {
          if (line.substr(j, j) == ",") {
            // Insert steps
            temp = stoi(line.substr(start, j - 1));
            dataSetInsertion[j] = temp;
            ++z;
            start = j + 1;
          }
        }
        clockStart = std::clock();
        insertionSort(dataSetInsertion, 1000); // Sort Data
        // Calculate CPU time
        cpuTime = (std::clock() - clockStart) / (double)CLOCKS_PER_SEC;
        // Write info to a std::string! use (+) for concate'
        output = "I," + std::to_string(i) + ",1000," + std::to_string(numComparInsert) 
          + "," + std::to_string(cpuTime) + ",1000000"; // Worst Case is big O n^2
        // Add std::string to Output Array
        insertionOutput[i] = output;
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
     // Seperates Data to be Inserted into arrays
        for (int j = 0, z = 0; line.substr(start, j) == "." && z == 50000; ++j) {
          if (line.substr(j, j) == ",") {
            // Insert steps
            temp = stoi(line.substr(start, j - 1));
            dataSetQuick[j] = temp;
            ++z;
            start = j + 1;
          }
        }
        clockStart = std::clock();
        quickSort(dataSetQuick, 0, 49999); // Sort Data
        // Calculate CPU time
        cpuTime = (std::clock() - clockStart) / (double)CLOCKS_PER_SEC; 
        // Write info to a std::string! use (+) for concate'
        output = "Q," + std::to_string(i) + ",50000," + std::to_string(numComparQuick) 
          + "," + std::to_string(cpuTime) + ",2500000000"; //Worst Case is Theta n^2
        // Add std::string to Output Array
        quickOutput[i] = output;
      }
    }
    else {
      assert(outFile.is_open());
    }
    outFile.close();
    // Write Output arrays to File [seperated with commas and lines]
    inFile.open("Excel_Data.txt"); // Open File
    // Write Insertion
    for (int i = 1; i <= 10; ++i) {
      inFile << insertionOutput[i];
      inFile << "\n";
    }
    // Write Quick
    for (int i = 1; i <= 10; ++i) {
      inFile << quickOutput[i];
      inFile << "\n";
    }
    inFile.close();
  }
  else {
    // Do nothing
  }
  return 0;
}