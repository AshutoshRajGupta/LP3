#include <iostream>
using namespace std;
int fibonacciIterative(int n) {
    if (n <= 1)
        return n;

    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; ++i) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
// Recursive Fibonacci function
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
int main() {
    int n;
    cout<<"Enter the number of numbers"<<endl;
    cin>>n;
    cout << "Fibonacci(" << n << ") using iterative method: " << fibonacciIterative(n) << endl;
    cout << "Fibonacci(" << n << ") using recursive method: " << fibonacciRecursive(n) << endl;
    return 0;
}
