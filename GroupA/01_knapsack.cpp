#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int N = wt.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int w = W; w >= wt[i]; w--) {
            // Check if it's beneficial to include the current item
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int main() {
    int items, capacity;
    cout << "Enter the number of items: ";
    cin >> items;

    vector<int> profit(items);
    vector<int> weight(items);

    // Input profit and weight for each item
    for (int i = 0; i < items; i++) {
        cout << "Enter profit for item " << (i + 1) << ": ";
        cin >> profit[i];
        cout << "Enter weight for item " << (i + 1) << ": ";
        cin >> weight[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int result = knapSack(capacity, weight, profit);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
