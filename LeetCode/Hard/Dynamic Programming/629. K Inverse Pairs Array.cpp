class Solution {
public:
 int mod =1000000007;


    int kInversePairs(int n, int k) {

        int dp[1001][1002] = {0};

        dp[0][0] =1;

        for(int i=1;i<=n;i++)
        {
           long int val=0;
           
            for(int j=0;j<=k;j++)
            {
               val+=dp[i-1][j];
                if(j>=i)
                {
                    val-=dp[i-1][j-i];
                }
            dp[i][j]=val%mod;
            }
        }
        return dp[n][k];
     
    }
};
