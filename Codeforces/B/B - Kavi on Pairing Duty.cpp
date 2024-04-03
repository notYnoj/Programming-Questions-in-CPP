#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int mxN = 1e6+5;
int dp[mxN];
int main(){
    int n;
    cin>>n;
  //esseintally we look at the divisors first where they are all equal.
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = i+i; j<=n; j+=i){
            dp[j]++;
        }
    }
  //then we look at the things in (if it is greater than n ) between and thus it must be the other dp[i], the things in between.
    int a = 1;
    for(int i = 1; i<=n; i++){
        dp[i] = (dp[i] + a) %mod;
        a = (a+ dp[i]) % mod;
    }

    cout<<dp[n];


}
