// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

// DLL internal state variables:
static unsigned long long previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;               // Current seq. position

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
void fibonacci_init(
    const unsigned long long a,
    const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b; // see special case when initialized
}

// Produce the next value in the sequence.
// Returns true on success, false on overflow.
bool fibonacci_next()
{
    // check to see if we'd overflow result or position
    if ((ULLONG_MAX - previous_ < current_) || (UINT_MAX == index_))
    {
        return false;
    }

    // Special case when index == 0, just return b value
    if (index_ > 0)
    {
        // otherwise, calculate next sequence value
        previous_ += current_;
    }
    std::swap(current_, previous_);
    ++index_;
    return true;
}

// Get the current value in the sequence.
unsigned long long fibonacci_current()
{
    return current_;
}

// Get the current index position in the sequence.
unsigned fibonacci_index()
{
    return index_;
}

// Returns the maximum between two integers
 int myMax(int x, int y) {
    if (x - y > 0) return x;
    return y;
}

// Returns the minimun between two integers
 int myMin(int x, int y) {
    if (x - y < 0) return x;
    return y;
}

 // Array QuickSort
 void quickSort(int arr[]) {
     qSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
}

 int partition(int arr[], int start, int end)
 {

     int pivot = arr[start];

     int count = 0;
     for (int i = start + 1; i <= end; i++) {
         if (arr[i] <= pivot)
             count++;
     }

     int pivotIndex = start + count;
     std::swap(arr[pivotIndex], arr[start]);

     int i = start, j = end;

     while (i < pivotIndex && j > pivotIndex) {

         while (arr[i] <= pivot) {
             i++;
         }

         while (arr[j] > pivot) {
             j--;
         }

         if (i < pivotIndex && j > pivotIndex) {
             std::swap(arr[i++], arr[j--]);
         }
     }

     return pivotIndex;
 }

 void qSort(int arr[], int start, int end)
 {
     if (start >= end)
         return;

     int p = partition(arr, start, end);

     qSort(arr, start, p - 1);

     qSort(arr, p + 1, end);
 }

 //=================================// 

 void merge(int array[], int const left, int const mid,
     int const right)
 {
     auto const subArrayOne = mid - left + 1;
     auto const subArrayTwo = right - mid;

     // Create temp arrays
     auto* leftArray = new int[subArrayOne],
         * rightArray = new int[subArrayTwo];

     // Copy data to temp arrays leftArray[] and rightArray[]
     for (auto i = 0; i < subArrayOne; i++)
         leftArray[i] = array[left + i];
     for (auto j = 0; j < subArrayTwo; j++)
         rightArray[j] = array[mid + 1 + j];

     auto indexOfSubArrayOne
         = 0, // Initial index of first sub-array
         indexOfSubArrayTwo
         = 0; // Initial index of second sub-array
     int indexOfMergedArray
         = left; // Initial index of merged array

     // Merge the temp arrays back into array[left..right]
     while (indexOfSubArrayOne < subArrayOne
         && indexOfSubArrayTwo < subArrayTwo) {
         if (leftArray[indexOfSubArrayOne]
             <= rightArray[indexOfSubArrayTwo]) {
             array[indexOfMergedArray]
                 = leftArray[indexOfSubArrayOne];
             indexOfSubArrayOne++;
         }
         else {
             array[indexOfMergedArray]
                 = rightArray[indexOfSubArrayTwo];
             indexOfSubArrayTwo++;
         }
         indexOfMergedArray++;
     }
     // Copy the remaining elements of
     // left[], if there are any
     while (indexOfSubArrayOne < subArrayOne) {
         array[indexOfMergedArray]
             = leftArray[indexOfSubArrayOne];
         indexOfSubArrayOne++;
         indexOfMergedArray++;
     }
     // Copy the remaining elements of
     // right[], if there are any
     while (indexOfSubArrayTwo < subArrayTwo) {
         array[indexOfMergedArray]
             = rightArray[indexOfSubArrayTwo];
         indexOfSubArrayTwo++;
         indexOfMergedArray++;
     }
     delete[] leftArray;
     delete[] rightArray;
 }

 // begin is for left index and end is
 // right index of the sub-array
 // of arr to be sorted */
 void mSort(int arr[], int const begin, int const end)
 {
     if (begin >= end)
         return; // Returns recursively

     auto mid = begin + (end - begin) / 2;
     mSort(arr, begin, mid);
     mSort(arr, mid + 1, end);
     merge(arr, begin, mid, end);
 }

 void mergeSort(int arr[]) {
     mSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
 }