// Suppose we have a class:

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

// Note:

// We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
// Example 2:

// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 

// Constraints:

// nums is a permutation of [1, 2, 3].


#include<bits/stdc++.h>
using namespace std;

class Foo {
public:
    mutex m;
    condition_variable cv;
    int turn ;
    Foo() {
        turn =1;
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn =2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock <mutex> lock(m);
        while(turn!=2){
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn =3 ;
        cv.notify_all();

    }

    void third(function<void()> printThird) {
        unique_lock <mutex> lock(m);
        while(turn!=3){
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
       
        cv.notify_all();

    }
};

int main() {
    Foo foo;
    thread t1([&]() { foo.first([]() { cout << "first"; }); });
    thread t2([&]() { foo.second([]() { cout << "second"; }); });
    thread t3([&]() { foo.third([]() { cout << "third"; }); });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
// Output: firstsecondthird

