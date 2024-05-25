#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, d;
    cin>>n>>k>>d;
    long long dp[101][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // have 1, js nothing
    dp[0][1] = 0; // have 0 even if its like d = 1;
    for(int i = 1; i<=n; i++){ // iterate thru path length of N
        for(int j = 1; j<=k; j++){ // iterate thru the new K we add
            if(i-j<0){ // no outta bounds :D
                break;
            }
            if(j<d){
                dp[i][0] += dp[i-j][0]; // not bigger so js slide on up
                dp[i][0] %= mod;
                dp[i][1] += dp[i-j][1];
                dp[i][1] %= mod;
            }else{
                dp[i][1] += dp[i-j][0]; // if bigger than d 0 will now be included
                dp[i][1] += dp[i-j][1];
                dp[i][1] %= mod;
            }
        }
    }
    cout<<dp[n][1];

}
