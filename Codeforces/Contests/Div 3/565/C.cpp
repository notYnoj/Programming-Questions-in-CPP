#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<6){
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
        }
        cout<<n;
    }else{
        vector<int> hold(n);
        map<int, int> ch;
        ch[4] = 0;
        ch[8] = 1;
        ch[15] = 2;
        ch[16] = 3;
        ch[23] = 4;
        ch[42] = 5;
        vector<vector<int>> dp(n, vector<int>(6));
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            hold[i] = ch[a];
            if(hold[i] == 0){
                dp[i][0] = 1;
            }
        }
        for(int i = 1; i<n; i++){
            int cur = hold[i];
            for(int j = 0; j<6; j++){
                dp[i][j] += dp[i-1][j];
            }
            if(cur>0 && dp[i][cur-1]>0){
                dp[i][cur-1]--;
                dp[i][cur]++;
            }
        }
        int ans = (n-(dp[n-1][5]*6));
        cout<<ans;
    }
}
//didnt have time for the full contest as i was doing math with linnrue :D
//however i still have roughly an hour and 45 minutes left so i hope i can complete the final 3 problems! if not I'll post my sol in the single folder
