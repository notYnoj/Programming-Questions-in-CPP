#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
      //bitmask dp
        vector<vector<ll>> dp(n, vector<ll>(64));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<64; j++){
                dp[i][j] = 0LL;
            }
        }
        vector<int> hold(n);
        for(int i = 0; i<n; i++){
            cin>>hold[i];
            dp[i][hold[i]] = 1;
        }
        for(int i = 1; i<n; i++){
            int num = hold[i];
            for(int mask = 0; mask<64; mask++){
                dp[i][num&mask] += dp[i-1][mask];
                dp[i][num&mask] %=mod;
                dp[i][mask] += dp[i-1][mask]; //push everything foward to (not taking it)
                dp[i][mask] %= mod;
            }
        }
        ll ans =0;
        for(int i = 0; i<64; i++){
            if(__builtin_popcount(i) == k){
                ans+=dp[n-1][i];
                ans%=mod;
            }
        }
        cout<<ans<<"\n";
    }
}
