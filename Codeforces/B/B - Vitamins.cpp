//bit mask dp lolz]
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<pair<ll, ll>> hold;
    ll dp[n+1][8];
    for(int i = 0; i<n; i++){
        string s;
        ll k;
        cin>>k>>s;
        ll a = 0;
        for(char ch: s){
            a+=1<<(ch-'A');
        }
        hold.push_back({a, k});
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<8; j++){
            dp[i][j] = 1000000000000;
        }
    }
    dp[0][hold[0].first] = hold[0].second;
    //fisrt = ABC second = cost
    for(int i = 1; i<n; i++){
        ll cur_mask = hold[i].first;
        ll cost = hold[i].second;
        dp[i][cur_mask] = min(dp[i][cur_mask], cost);
        for(int mask= 0; mask<8; mask++){//new mask
            dp[i][mask|cur_mask] = min(dp[i][mask|cur_mask],cost+dp[i-1][mask]);
            dp[i][mask] = min(dp[i][mask], dp[i-1][mask]);
        }
    }


    cout<<(dp[n-1][7] == 1000000000000?-1:dp[n-1][7]);
}
