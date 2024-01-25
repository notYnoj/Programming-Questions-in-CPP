class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size()+1; 
        int m = text2.size()+1;
        int dp[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = 0;
            }
        }//esecinally work backwards and choose if equal add 1 to the current longest subsequence, or if not js choose the current biggest one for [i][j]
        for(int i = text1.size()-1; i>=0; i--){
            for(int j = text2.size()-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
