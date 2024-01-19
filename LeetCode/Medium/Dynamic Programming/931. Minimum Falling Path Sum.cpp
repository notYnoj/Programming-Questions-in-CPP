class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();

        for(int i = n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                //a brute force tabulation method, in place so SC = o(1), TC is o(n^2) due to the two for loops
              // simply calculate in place what the smallest possible one is, and once u get to the end return the smallest element in mat[0]
                mat[i][j] += min(mat[i+1][j], min(mat[i+1][max(0,j-1)], mat[i+1][min(n-1,j+1)]));
            }
        }

        return *min_element(mat[0].begin(), mat[0].end());
    }
};
