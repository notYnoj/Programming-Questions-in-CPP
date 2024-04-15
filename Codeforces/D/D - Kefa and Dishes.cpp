#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[20][20];
//each bit represnts eaten or not
ll dp[(1<<18)][18];
//dp of dishes eaten, and last eaten
int main(){
    ll n,m,z;
    cin>>n>>m>>z;
    vector<ll> dishS(n);
    for(ll i = 0; i<n; i++){
        cin>>dishS[i];
    }
  //each dish i is represented as 1<<i
    for(ll i = 0; i<z; i++){
        ll x,y,c;
        cin>>x>>y>>c;
        --x, --y; // zero index
        a[x][y] = c;
    }
  //base case if we eat dish i then we start at i
    for(ll i = 0; i<n; i++){
        dp[1<<i][i] = dishS[i];
    }
    ll ans = 0;
    for(ll i = 1; i<(1<<n); i++){
        for(ll j = 0; j<n; j++){
            if((i>>j) & 1){//say we js ate dish j
                for(ll k = 0; k<n; k++){ // pick the next dish to eat
                    if(!((i>>k) & 1)){ // if we havent eaten it yet
                        ll e = i | (1<<k); // the new mask
                        ll val = dp[i][j] + dishS[k] + a[j][k]; //last eaten amount + the sat of k + any combo
                        dp[e][k] = max(val, dp[e][k]); // yes
                    }
                }
            }
        }
    }
    for(ll i = 1; i<(1<<n); i++){
        if(__builtin_popcount(i)==m){ // if it has eaten m dishes
            for(ll j = 0 ; j<n; j++){ // say we finish at any of these dishes 
                ans = max(ans, dp[i][j]); // max it
            }
        }
    }
    cout<<ans;
}
