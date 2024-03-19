#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cout << "Enter the size of array a[]: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size for array a[]. Please enter a positive integer." << endl;
        return 1;
    }

    long int a[n];
    cout << "Enter " << n << " integers for array a[]: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the size of array b[]: ";
    cin >> m;

    if (m <= 0) {
        cout << "Invalid size for array b[]. Please enter a positive integer." << endl;
        return 1;
    }

    long int b[m];
    map<int, int> mp;
    cout << "Enter " << m << " integers for array b[]: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }

    int cnt = 0;

    sort(b, b + m); 

    for (int i = 0; i < n; i++) {
        
        int lower = lower_bound(b, b + m, a[i] - 1) - b;
        
        if (lower < m && b[lower] == a[i] - 1)
            cnt++;

        int upper = lower_bound(b, b + m, a[i] + 1) - b;
        
        if (upper < m && b[upper] == a[i] + 1)
            cnt++;
    }

    cout << "Result: " << cnt % MOD << endl;

    return 0;
}
