#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n;
const int MOD = 1e9+7;
int a[1005];

int main() {
    fastio
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    //dp is going to have [i][j] ends at index i and has sum j
    vector<vector<ll>> dp(n+1, vector<ll>(20005, 0));
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        int current = a[i-1];
        //dp[i][j] += dp[i][j-x] and x = current + 10000 becuz we essentially can add or subtract right so
        //we can like find the needed j+10000 its like adding this current to the substring that has current+10000
        //aka that has some value x
        //make it in bounds with the j+current
        for(int j = -10000; j+current<=10000; j++){
            int zcur = j+current+10000;
            //basically its the current number
            int needed = j+10000;
            //what we need before in the dp to make it this current number i-1
            dp[i][zcur] += (dp[i-1][needed])%MOD;
        }
        for(int j = 10000; j-current>=-10000; j--){
            //same idea js subtract
            int zcur = j-current+10000;
            int needed = j+10000;
            dp[i][zcur] += (dp[i-1][needed]) % MOD;
        }
        //base case down here to avoid accidentally saying that there is one
        //for the first case without actually doing it
        //you can always saying that it
        dp[i][current+10000] = (dp[i][current+10000] +1) %MOD;
        dp[i][-current+10000] = (dp[i][-current+10000]+1)%MOD;
        ans = (ans+dp[i][10000]) %MOD;
    }
    ans %=MOD;
    cout<<ans;

}
//told that we have max 10000 by math that means minimum must be -10000 (negate all makes -10000) so the boundaries are [-10000,10000] by adding 10000 
// we can make sure that we dont have any negatives in our dp as that would be very bad (u cant have a negative column)
