#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;

void solve(){
    ll n,m,d;
    cin>>n>>m>>d;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for(ll i = n-1; i>=0; i--){
        string s;
        cin>>s;
        for(int j = 0; j<m; j++){
            if(s[j] == 'X'){
                grid[i][j] = 1;
            }else{
                grid[i][j] = 0;
            }
        }
    }
    //starting string is at grid[0][...]
    vector<vector<ll>> dpPREF0(n, vector<ll>(m, 0));
    vector<vector<ll>> dpPREF1(n, vector<ll>(m, 0));

    //if i get to pos x,y on the grid. I can hold on to y-d - y+d.
    //each new position i can hold onto an extra amount of those
    //so for dp[i][j][0] the thing is oging to be

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(2, 0)));
    //we have two options either, there can be two things held or there can be 1 thing held
    //the amount of ways to get the total ways alone in some reference
    auto getPREF0 = [&](ll i){
        for(int j = 0; j<m; j++){
            dpPREF0[i][j] = dp[i][j][0];
            if(j>0)dpPREF0[i][j] += dpPREF0[i][j-1];
            dpPREF0[i][j]%=MOD;
        }
    };
    auto getPREF1 = [&](ll i){
        for(int j = 0; j<m; j++){
            dpPREF1[i][j] = dp[i][j][1];
            if(j>0)dpPREF1[i][j] += dpPREF1[i][j-1];
            dpPREF1[i][j]%=MOD;

        }
    };
    auto mod = [&](ll x) -> ll{
        return ((x%MOD) + MOD)%MOD;
    };
    for(ll i = 0; i<m; i++){
        //start at the top the amount of ways to get to start
        dp[0][i][0] = grid[0][i]?1:0;
    }
    getPREF0(0);
    //for any dp[i][j][1] we want dp[i][j][1] += dp[i][k][0] where k goes from j-d to j+d (exclude dp=[i][j][0]) (dont overcount)
    for(ll i = 0; i<m; i++){
        //i can also start with something with two hands
        //at any point i can grab this hoe with anotehr hand i need to find the amount of ways to get to the other one with only 1 hand
        if(grid[0][i]) {
            dp[0][i][1] += dpPREF0[0][min(i + d, m - 1)];
            if (i - d - 1 >= 0) {
                dp[0][i][1] -= dpPREF0[0][i - d - 1];
            }
            dp[0][i][1] -= dp[0][i][0];
            dp[0][i][1] = mod(dp[0][i][1]);
        }
    }
    getPREF1(0);
    for(ll i = 1; i<n; i++){
        for(ll j = 0; j<m; j++){
            //dp[i][j][0] =  the amount of ways to get from this one from the bottom ones
            //doesnt matter if its 0 or 1 js as long as its from j- (d-1) to j+(d-1)
            if(grid[i][j]) {
                dp[i][j][0] += dpPREF0[i - 1][min(j + (d - 1), m - 1)];
                if (j - (d - 1) - 1 >= 0) {
                    dp[i][j][0] -= dpPREF0[i - 1][j - (d - 1) - 1];
                }
                dp[i][j][0] += dpPREF1[i - 1][min(j + (d - 1), m - 1)];
                if (j - (d - 1) - 1 >= 0) {
                    dp[i][j][0] -= dpPREF1[i - 1][j - (d - 1) -1];
                }
                dp[i][j][0] = mod(dp[i][j][0]);
            }
            //now the amount of ways to get from dp[j]
        }
        getPREF0(i);
        //get prefix sum of the first 0
        for(ll j = 0; j<m; j++){
            //now claculate how to get from the fact that we have another hold
            if(grid[i][j]) {
                dp[i][j][1] += dpPREF0[i][min(j + d, m - 1)];
                if (j - d - 1 >= 0) {
                    dp[i][j][1] -= dpPREF0[i][j - d - 1];
                }
                dp[i][j][1] -= dp[i][j][0];
                dp[i][j][1] = mod(dp[i][j][1]);
            }
        }

        getPREF1(i);
    }
    ll ans = 0;
    for(int i = 0; i<m; i++){
        ans+=dp[n-1][i][0]%MOD;
        ans+=dp[n-1][i][1]%MOD;
        ans = mod(ans);
    }
    cout<<ans<<'\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
