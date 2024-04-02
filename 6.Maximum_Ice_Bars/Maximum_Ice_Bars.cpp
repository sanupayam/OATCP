#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end()); 
    int ice_cream_bars = 0;
    for (int cost : costs) {
        if (cost <= coins) {
            coins -= cost;
            ice_cream_bars++;
        } else {
            break; 
        }
    }
    return ice_cream_bars;
}

int main() {
    int n;
    cout << "Enter the number of ice cream bars: ";
    cin >> n;

    vector<int> costs(n);
    cout << "Enter the costs of the ice cream bars: ";
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    int coins;
    cout << "Enter the number of coins the boy has: ";
    cin >> coins;

    cout << "Maximum number of ice cream bars the boy can buy: " << maxIceCream(costs, coins) << endl;

    return 0;
}

