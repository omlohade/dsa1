// Problem statement
// Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.

// You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.

// For Example:
// Bubble Sort implementation for the given array:  {6,2,8,4,10} is shown below :-

#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    bool swapped = false;
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
                swapped = true;
            }
        }
        if(swapped==false) break;
    }
    
}

//time complexity: O(n^2)
//space complexity: O(1)




