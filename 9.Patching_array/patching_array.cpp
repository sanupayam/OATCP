#include <iostream>
#include <vector>
using namespace std;

int minPatches(vector<int>& nums, int n) {
    long long missing = 1;
    int patches = 0, i = 0;
    
    while (missing <= n) {
        if (i < nums.size() && nums[i] <= missing) {
            missing += nums[i];
            i++;
        } else {
            missing += missing;
            patches++;
        }
    }
    
    return patches;
}

int main() {
    // Input the sorted integer array nums
    vector<int> nums;
    int num;
    char choice;
    cout << "Enter the sorted integer array nums (enter 'x' to stop): ";
    while (cin >> num) {
        nums.push_back(num);
        cout << "Continue? (y/n): ";
        cin >> choice;
        if (choice == 'x')
            break;
    }

    // Input the integer n
    int n;
    cout << "Enter the integer n: ";
    cin >> n;

    // Calculate and output the minimum number of patches required
    cout << "Minimum patches required: " << minPatches(nums, n) << endl;

    return 0;
}
