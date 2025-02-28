// Problem statement
// Selection sort is one of the sorting algorithms that works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted region of the array.

// You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.

// For Example:
// Selection Sort implementation for the given array:  {29,72,98,13,87,66,52,51,36} is shown below :-


#include <bits/stdc++.h> 
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    // Outer loop iterates through each element in the array
    for(int i = 0; i < n - 1; i++) {
        
        // Assume the minimum element is at index i
        int minIndex = i;

        // Inner loop finds the minimum element in the unsorted part
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {  // If a smaller element is found
                minIndex = j;  // Update the minIndex
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        swap(arr[minIndex], arr[i]);  
    }
}


//time complexity: O(n^2)
//space complexity: O(1)


