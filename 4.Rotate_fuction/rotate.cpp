#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum value of rotation function
int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    long long sum = 0;
    long long rotation = 0;
    
    // Calculate the initial sum and rotation
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        rotation += static_cast<long long>(i) * nums[i]; // Explicit conversion for clarity
    }
    
    long long maxRotation = rotation;
    
    // Iterate through rotations and update maxRotation
    for (int i = n - 1; i >= 1; --i) {
        rotation += sum - static_cast<long long>(n) * nums[i]; // Explicit conversion for clarity
        maxRotation = max(maxRotation, rotation);
    }
    
    return maxRotation;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers for the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    // Output result
    int result = maxRotateFunction(nums);
    cout << "Maximum value of F(0), F(1), ..., F(n-1): " << result << endl;
    
    return 0;
}