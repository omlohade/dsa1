// Problem statement
// You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1. Write a function to sort this array/list. Think of a solution which scans the array/list only once and don't require use of an extra array/list.

// Note:
// You need to change in the given array/list itself. Hence, no need to return or print anything. 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^5
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 0 1 1 0 1 0 1
// Sample Output 1:
// 0 0 0 1 1 1 1
// Sample Input 2:
// 2
// 8
// 1 0 1 1 0 1 0 1
// 5
// 0 1 0 1 0
// Sample Output 2:
// 0 0 0 1 1 1 1 1
// 0 0 0 1 1 


void sortZeroesAndOne(int input[], int size)
{
    //Write your code here
    int left =0;
    int right = size-1;

    while(left<right){
        

        if(input[left]==0){
            left++;
        }

        else if(input[right] == 1){
            right--;
        }
       

        else if(input[left] == 1 && input[right] == 0 ){
            swap(input[left],input[right]);
            left++;
            right--;
        }
    }

}