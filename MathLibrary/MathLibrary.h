// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

// MY CONCLUSIONS
// // extern "C" is used for changing the function linkage to C linkage,
// so now - the user which use this .dll file won't be able to use
// another function with the same name, e.g for a failure:
// extern "C" MATHLIBRARY_API int fibonacci_init(const unsigned long long a, const unsigned long long b, const unsigned long long c);
// 
// unsigned long long - for 64bit return value


// The Fibonacci recurrence relation describes a sequence F
// where F(n) is { n = 0, a
//               { n = 1, b
//               { n > 1, F(n-2) + F(n-1)
// for some initial integral values a and b.
// If the sequence is initialized F(0) = 1, F(1) = 1,
// then this relation produces the well-known Fibonacci
// sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
extern "C" MATHLIBRARY_API void fibonacci_init(
    const unsigned long long a, const unsigned long long b);



// Produce the next value in the sequence.
// Returns true on success and updates current value and index;
// false on overflow, leaves current value and index unchanged.
extern "C" MATHLIBRARY_API bool fibonacci_next();

// Get the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned fibonacci_index();

// Returns the maximum between two integers
extern "C" MATHLIBRARY_API int myMax(int x, int y);

// Returns the minimun between two integers
extern "C" MATHLIBRARY_API int myMin(int x, int y);

// Array QuickSort
// Time complexity - avg of O(nlog(n)), worst case will be n^2
// Space complexity - O(nlog(n))
extern "C" MATHLIBRARY_API void quickSort(int arr[]);

extern "C" MATHLIBRARY_API void mergeSort(int arr[]);