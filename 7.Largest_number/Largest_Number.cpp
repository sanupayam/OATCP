#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
    vector<string> numStrings;
    
    for (int num : nums) {
        numStrings.push_back(to_string(num));
    }

    sort(numStrings.begin(), numStrings.end(), compare);

    if (numStrings[0] == "0") {
        return "0";
    }

    string result = "";
    for (string numStr : numStrings) {
        result += numStr;
    }

    return result;
}

int main() {
    vector<int> nums1 = {12, 23, 13, 45, 8, 92}; // Example 1
    cout << "Example 1 Output: " << largestNumber(nums1) << endl;

    vector<int> nums2 = {18, 27, 93, 86, 43, 98, 101, 202}; // Example 2
    cout << "Example 2 Output: " << largestNumber(nums2) << endl;

    return 0;
}
