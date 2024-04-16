#include <iostream>
#include <vector>

using namespace std;

int countSubgrids(vector<vector<int>>& grid) {
    int size = grid.size();
    int subgridCount = 0;
    
    for(int row1 = 0; row1 < size; row1++) {
        for(int row2 = row1 + 1; row2 < size; row2++) { 
            int commonColorCount = 0;
            
            for(int col = 0; col < size; col++) { 
                if (grid[row1][col] == 1 && grid[row2][col] == 1) {
                    commonColorCount++;
                }
            }
            
            subgridCount += ((commonColorCount - 1) * commonColorCount) / 2;
        }
    }
    return subgridCount;
}

int main() {
    // Input size of the grid
    int size;
    cout << "Enter the size of the grid: ";
    cin >> size;
    
    // Input grid elements
    cout << "Enter the grid elements (0 or 1):" << endl;
    vector<vector<int>> grid(size, vector<int>(size, 0));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Calculate the number of subgrids
    int subgridCount = countSubgrids(grid);
    
    // Output the result
    cout << "Number of subgrids with the same color in two rows: " << subgridCount << endl;

    return 0;
}
