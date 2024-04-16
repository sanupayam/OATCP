#include <iostream>
#include <vector>

using namespace std;

int calculateHammingDistance(vector<int>& numbers) {
    int distance = 0;
 
    for (int pos = 0; pos < 32; pos++) {
        int ones = 0, zeros = 0;
        
        for (int i = 0; i < numbers.size(); i++) {
            if ((numbers[i] >> pos) & 1) {
                ones++;
            } else {
                zeros++;
            }
        }
        
        distance += ones * zeros;
    }
    
    return distance;
}

int main() {
    // Read the number of integers
    int numIntegers;
    cin >> numIntegers;
    
    // Read the integers into a vector
    vector<int> numbers(numIntegers);
    for (int i = 0; i < numIntegers; i++) {
        cin >> numbers[i];
    }
    
    // Calculate 
    int hammingDistance = calculateHammingDistance(numbers);
    
    // Print
    cout << hammingDistance << endl;

    return 0;
}
