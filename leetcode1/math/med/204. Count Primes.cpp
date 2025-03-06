
// Given an integer n, return the number of prime numbers that are strictly less than n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
 

// Constraints:

// 0 <= n <= 5 * 106


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // If n is less than 2, there are no primes
        if (n < 2) return 0;

        // Step 1: Create a boolean array to mark primes
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        // Step 2: Apply Sieve of Eratosthenes
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 3: Count prime numbers
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        
        return count;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    cout << "Primes less than 10: " << sol.countPrimes(10) << endl; // Output: 4
    cout << "Primes less than 0: " << sol.countPrimes(0) << endl;  // Output: 0
    cout << "Primes less than 1: " << sol.countPrimes(1) << endl;  // Output: 0
    cout << "Primes less than 20: " << sol.countPrimes(20) << endl; // Output: 8
    
    return 0;
}

