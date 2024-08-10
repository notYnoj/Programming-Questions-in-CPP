
class Solution {
private:
    bool isMagicSquare(const vector<vector<int>>& grid, int r, int c) {
        vector<int> subgrid;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                subgrid.push_back(grid[r + i][c + j]);
            }
        }

        // Check if all numbers are distinct and between 1 and 9
        vector<int> sortedSubgrid = subgrid;
        sort(sortedSubgrid.begin(), sortedSubgrid.end());
        if (sortedSubgrid != vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9})) {
            return false;
        }

        int sum1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];  
        int sum2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];  
        int sum3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2]; 
        int sum4 = grid[r][c] + grid[r+1][c] + grid[r+2][c];  
        int sum5 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];  
        int sum6 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2]; 
        int sum7 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];  
        int sum8 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];   

        return (sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && 
                sum4 == sum5 && sum5 == sum6 && sum6 == sum7 && sum7 == sum8);
    }

public:
    int numMagicSquaresInside(const vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        // Iterate over all possible 3x3 subgrids
        for (int r = 0; r <= row - 3; ++r) {
            for (int c = 0; c <= col - 3; ++c) {
                if (isMagicSquare(grid, r, c)) {
                    ++count;
                }
            }
        }

        return count;
    }
};
