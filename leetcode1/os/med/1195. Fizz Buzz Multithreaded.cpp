// You have the four functions:

// printFizz that prints the word "fizz" to the console,
// printBuzz that prints the word "buzz" to the console,
// printFizzBuzz that prints the word "fizzbuzz" to the console, and
// printNumber that prints a given integer to the console.
// You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

// Thread A: calls fizz() that should output the word "fizz".
// Thread B: calls buzz() that should output the word "buzz".
// Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
// Thread D: calls number() that should only output the integers.
// Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

// "fizzbuzz" if i is divisible by 3 and 5,
// "fizz" if i is divisible by 3 and not 5,
// "buzz" if i is divisible by 5 and not 3, or
// i if i is not divisible by 3 or 5.
// Implement the FizzBuzz class:

// FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
// void fizz(printFizz) Calls printFizz to output "fizz".
// void buzz(printBuzz) Calls printBuzz to output "buzz".
// void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
// void number(printNumber) Calls printnumber to output the numbers.
 

// Example 1:

// Input: n = 15
// Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
// Example 2:

// Input: n = 5
// Output: [1,2,"fizz",4,"buzz"]
 

// Constraints:

// 1 <= n <= 50


#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FizzBuzz {
private:
    int n;                  // The upper limit of the sequence
    mutex m;                // Mutex to protect shared resources
    condition_variable c;   // Condition variable to coordinate thread execution
    int i;                  // Counter variable to track the current number

public:
    // Constructor to initialize `n` and `i`
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;  // Start from 1
    }

    // Function to print "fizz"
    void fizz(function<void()> printFizz) {
        while (i <= n) {  // Continue until `i` exceeds `n`
            unique_lock<mutex> lock(m);  // Lock the mutex
            // Wait until `i` is a multiple of 3 but not 5
            while (i <= n && ((i % 3) != 0 || (i % 5) == 0)) {
                c.wait(lock);  // Wait until the condition is met
            }
            if (i <= n) {  // Check again to avoid overstepping `n`
                printFizz();  // Print "fizz"
                ++i;  // Move to the next number
            }
            c.notify_all();  // Notify all waiting threads
        }
    }

    // Function to print "buzz"
    void buzz(function<void()> printBuzz) {
        while (i <= n) {  // Loop until `i` exceeds `n`
            unique_lock<mutex> lock(m);  // Lock the mutex
            // Wait until `i` is a multiple of 5 but not 3
            while (i <= n && ((i % 5) != 0 || (i % 3) == 0)) {
                c.wait(lock);  // Wait until the condition is met
            }
            if (i <= n) {  // Check again to avoid exceeding `n`
                printBuzz();  // Print "buzz"
                ++i;  // Move to the next number
            }
            c.notify_all();  // Notify all threads
        }
    }

    // Function to print "fizzbuzz"
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (i <= n) {  // Loop until `i` exceeds `n`
            unique_lock<mutex> lock(m);  // Lock the mutex
            // Wait until `i` is a multiple of both 3 and 5
            while (i <= n && !((i % 3 == 0) && (i % 5 == 0))) {
                c.wait(lock);  // Wait until the condition is met
            }
            if (i <= n) {  // Ensure `i` is within bounds
                printFizzBuzz();  // Print "fizzbuzz"
                ++i;  // Move to the next number
            }
            c.notify_all();  // Notify all threads
        }
    }

    // Function to print the numbers that are not multiples of 3 or 5
    void number(function<void(int)> printNumber) {
        while (i <= n) {  // Loop until `i` exceeds `n`
            unique_lock<mutex> lock(m);  // Lock the mutex
            // Wait until `i` is NOT a multiple of 3 or 5
            while (i <= n && ((i % 5 == 0) || (i % 3 == 0))) {
                c.wait(lock);  // Wait until the condition is met
            }
            if (i <= n) {  // Ensure `i` is within bounds
                printNumber(i++);  // Print the number and increment `i`
            }
            c.notify_all();  // Notify all threads
        }
    }
};





int main() {
    int n = 15;  // Example input
    FizzBuzz fizzBuzz(n);  // Create an instance of FizzBuzz

    // Create threads for each function
    thread t1([&]() { fizzBuzz.fizz([]() { cout << "fizz "; }); });
    thread t2([&]() { fizzBuzz.buzz([]() { cout << "buzz "; }); });
    thread t3([&]() { fizzBuzz.fizzbuzz([]() { cout << "fizzbuzz "; }); });
    thread t4([&]() { fizzBuzz.number([](int x) { cout << x << " "; }); });

    // Join the threads to ensure they complete before exiting
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}