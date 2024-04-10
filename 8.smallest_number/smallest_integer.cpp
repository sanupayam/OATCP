#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    int k;
    cin >> num >> k;
    
    // corner case
    if (num.size() == k) {
        cout << "0\n";
        return 0;
    }

    string ans = "";
    int removedDigits = 0;

    for (char c : num) {
        while (!ans.empty() && ans.back() > c && removedDigits < k) {
            ans.pop_back();
            removedDigits++;
        }
        ans.push_back(c);
    }

    // Remove remaining digits if needed
    while (removedDigits < k) {
        ans.pop_back();
        removedDigits++;
    }

    // Remove leading zeros
    int nonZeroIndex = 0;
    while (nonZeroIndex < ans.size() && ans[nonZeroIndex] == '0') {
        nonZeroIndex++;
    }
    ans = (nonZeroIndex == ans.size()) ? "0" : ans.substr(nonZeroIndex);

    cout << ans << "\n";
    
    return 0;
}

