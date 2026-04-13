#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void solve(){
    int n, x;
    if (!(cin >> n >> x)) return;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= x; i++) {
            dp[i] += dp[i - coin];
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }
    
    cout << dp[x] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
