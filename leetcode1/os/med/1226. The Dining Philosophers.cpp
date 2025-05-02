// Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.

// Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.

// Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.

// Design a discipline of behaviour (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.



// The problem statement and the image above are taken from wikipedia.org

 

// The philosophers' ids are numbered from 0 to 4 in a clockwise order. Implement the function void wantsToEat(philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork) where:

// philosopher is the id of the philosopher who wants to eat.
// pickLeftFork and pickRightFork are functions you can call to pick the corresponding forks of that philosopher.
// eat is a function you can call to let the philosopher eat once he has picked both forks.
// putLeftFork and putRightFork are functions you can call to put down the corresponding forks of that philosopher.
// The philosophers are assumed to be thinking as long as they are not asking to eat (the function is not being called with their number).
// Five threads, each representing a philosopher, will simultaneously use one object of your class to simulate the process. The function may be called for the same philosopher more than once, even before the last call ends.

 

// Example 1:

// Input: n = 1
// Output: [[4,2,1],[4,1,1],[0,1,1],[2,2,1],[2,1,1],[2,0,3],[2,1,2],[2,2,2],[4,0,3],[4,1,2],[0,2,1],[4,2,2],[3,2,1],[3,1,1],[0,0,3],[0,1,2],[0,2,2],[1,2,1],[1,1,1],[3,0,3],[3,1,2],[3,2,2],[1,0,3],[1,1,2],[1,2,2]]
// Explanation:
// n is the number of times each philosopher will call the function.
// The output array describes the calls you made to the functions controlling the forks and the eat function, its format is:
// output[i] = [a, b, c] (three integers)
// - a is the id of a philosopher.
// - b specifies the fork: {1 : left, 2 : right}.
// - c specifies the operation: {1 : pick, 2 : put, 3 : eat}.
 

// Constraints:

// 1 <= n <= 60



#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

// ----------- Semaphore Class Implementation ----------- //
class Semaphore {
private:
    mutex mtx;                      // Mutex to protect the critical section
    condition_variable cv;         // Condition variable to block/wake threads
    int count;                     // Number of available resources

public:
    // Constructor to initialize the count
    Semaphore(int init = 1) : count(init) {}

    // Wait operation (P): acquire the semaphore
    void wait() {
        unique_lock<mutex> lock(mtx);
        // Wait until count > 0, then decrement it
        cv.wait(lock, [this]() { return count > 0; });
        --count;
    }

    // Signal operation (V): release the semaphore
    void signal() {
        unique_lock<mutex> lock(mtx);
        ++count;         // Increment count to indicate resource is available
        cv.notify_one(); // Wake one waiting thread
    }
};

// ----------- Dining Philosophers Implementation ----------- //
class DiningPhilosophers {
private:
    Semaphore* forks[5];  // Array of semaphore pointers representing the forks
    mutex m;              // Mutex to protect fork picking logic

public:
    // Constructor: create a semaphore for each fork
    DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            forks[i] = new Semaphore(1);  // Each fork is initially available
        }
    }

    // Destructor: free allocated memory for semaphores
    ~DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            delete forks[i];  // Clean up to prevent memory leaks
        }
    }

    // Core logic executed when a philosopher wants to eat
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;               // Left fork index
        int right = (philosopher + 1) % 5;    // Right fork index (circular table)

        // Lock this section to avoid race conditions while picking forks
        unique_lock<mutex> lock(m);

        // Wait until both forks are available
        forks[left]->wait();   // Acquire left fork
        forks[right]->wait();  // Acquire right fork

        // Unlock the section to let other philosophers check for forks
        lock.unlock();

        // Pick the left and right forks (as per the LeetCode output format)
        pickLeftFork();
        pickRightFork();

        // Eat the spaghetti 🥣
        eat();

        // Put down both forks
        putLeftFork();
        putRightFork();

        // Release both forks so other philosophers can use them
        forks[left]->signal();
        forks[right]->signal();
    }
};

// ----------- Main Function for Testing ----------- //













