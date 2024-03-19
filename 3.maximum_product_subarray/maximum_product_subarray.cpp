#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0)
                currentSum = 0;
        }

        return maxSum;
    }
};

int main() {
    // Input the size of nums1 and elements
    int n1;
    cout << "Enter the size of nums1: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter " << n1 << " integers for nums1:\n";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }


    // Initialize Solution object
    Solution sol;
    
    // Output results
    int result1 = sol.maxSubArray(nums1);
   
    
    // Print results
    cout << "Maximum sum of a subarray in nums1: " << result1 << endl;
  
    
    return 0;
}
