#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
const int mxN = 61;
ll dp[mxN][mxN];
void init(){
    //dp[i][k] (1<<i) + k bits
    //if u have any bits and u have 0 k u can only have 0 since all other ones have 1+ bits (n>0 has at least 1 bit set)
    //if u have 0 bits and have any number of k bits since u only have 0 bits u can only have 0 thus its always 1
    for(auto& i : dp) i[0] = 1;
    for(int i = 0; i<mxN; i++) dp[0][i] = 1;
    int combo_l_r = 1;
    for(int i = 1; i<mxN; i++){
        for(int k = 1; k<mxN; k++){
            dp[i][k] += ((dp[i-1][k] + dp[i-1][k-1]) %MOD);  //0s (split it into 0 and 1) 1s
            if(k == i-1) dp[i][k] += (combo_l_r*(combo_l_r-1) % MOD);  //2 if we have like 8 we cant have 3 all the combos in between the left and right if k isnt at leat this then the mid point u cant get tot he left thus its onlyt above
            else if(k>=i) dp[i][k] += ((combo_l_r*combo_l_r)% MOD);
            dp[i][k] %= MOD;
        }
        combo_l_r*=2; // becuz were splitting in half it has to be 2 times more (aka 1<<i/2 splits into 2)
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    ll ans = 0;
    while(true){
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
