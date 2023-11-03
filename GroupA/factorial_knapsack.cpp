#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int profit, weight;
};
bool compare(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double maxValue = 0.0;
    for (Item item : items) {
        if (W == 0) break;
        if (item.weight <= W) {
            maxValue += item.profit;
            W -= item.weight;
        } else {
            maxValue += (double)item.profit * W / item.weight;
            break;
        }
    }
    return maxValue;
}
int main() {
    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;
    }
    double result = fractionalKnapsack(W, items);
    cout << "Maximum value: " << result << endl;
    return 0;
}


// Enter knapsack capacity: 50
// Enter the number of items: 3
// Enter profit and weight for item 1: 60 10
// Enter profit and weight for item 2: 100 20
// Enter profit and weight for item 3: 120 30
// Maximum value: 240
