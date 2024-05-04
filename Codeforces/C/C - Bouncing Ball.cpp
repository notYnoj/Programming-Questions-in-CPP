#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--) {
        int n, p, k;
        cin >> n >> p >> k;
        string path;
        cin >> path;
        int x, y;
        cin >> x >> y;
        int ans = 1e9;
        vector<int> dp(n+1, 0);
      //use dp[i] is the amount of time we have if we bounce there
        for (int i = n; i >= p; i--) {
          //where we start at
            dp[i] = (path[i-1] == '1' ? 0 : x);
            if (i + k <= n) {
                dp[i] += dp[i + k];
            }
            ans = min(ans, dp[i] + y * (i - p));
        }

        cout << ans<<"\n";
    }
}
