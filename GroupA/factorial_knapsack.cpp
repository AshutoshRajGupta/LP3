#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio() const {
        return static_cast<double>(value) / weight;
    }
};

int main() {
    int n, maxWeight;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter the weights and values of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio() > b.ratio();
    });
    double totalValue = 0.0;
    for (const Item& item : items) {
        double fraction = min(1.0, static_cast<double>(maxWeight) / item.weight);
        maxWeight -= fraction * item.weight;
        totalValue += fraction * item.value;
        cout << "Quantity of item with weight " << item.weight << " and value " << item.value << ": " << fraction * item.weight << endl;
    }
    cout << "The total profit is " << totalValue << endl;
    return 0;
}



// output

// Enter the number of items: 7
// Enter the weights and values of each item:
// 1 5 
// 3 10
// 5 15
// 4 7
// 1 8
// 3 9
// 2 4
// Enter the maximum weight of the knapsack: 15
// Quantity of item with weight 1 and value 8: 1
// Quantity of item with weight 1 and value 5: 1
// Quantity of item with weight 3 and value 10: 3
// Quantity of item with weight 5 and value 15: 5
// Quantity of item with weight 3 and value 9: 3
// Quantity of item with weight 2 and value 4: 2
// Quantity of item with weight 4 and value 7: 0
// The total profit is 51
