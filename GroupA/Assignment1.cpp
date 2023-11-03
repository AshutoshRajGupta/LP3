#include <iostream>
using namespace std;
class FibonacciCalculator {
public:
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

    int fibonacciRecursive(int n) {
        if (n <= 1)
            return n;
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
};

int main() {
    FibonacciCalculator fibonacciCalculator;
    int n;
    cout << "Enter the number of numbers: ";
    cin >> n;
    cout << "Choose the method to calculate Fibonacci: " << endl;
    cout << "1. Iterative method" << endl;
    cout << "2. Recursive method" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Fibonacci(" << n << ") using iterative method: " << fibonacciCalculator.fibonacciIterative(n) << endl;
            break;
        case 2:
            cout << "Fibonacci(" << n << ") using recursive method: " << fibonacciCalculator.fibonacciRecursive(n) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
}
