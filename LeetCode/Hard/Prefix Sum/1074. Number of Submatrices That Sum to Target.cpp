class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int row = 0; row < m; row++) {
            for (int col = 1; col < n; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }
      //calculate prefix sum for all rows, 

        int count = 0;

        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = c1; c2 < n; c2++) {
                std::unordered_map<int, int> map;
                map[0] = 1;
                int sum = 0;

                for (int row = 0; row < m; row++) {
                    sum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0); //sinec doing prefix sum we js check the one right behind this gives us the amount from c1-c2
                    count += map[sum - target]; //if == 0 will give 1 if not gives 0
                    map[sum]++; //add 1 to indicate the multiple possible
                }
            }
        }

        return count;
    }
};
