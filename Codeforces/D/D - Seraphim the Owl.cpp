//2 solutions this time :D Linnrue's dp solution first (o(n) + ~45 min solve + 186ms :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        vector<long long> b(n);
        vector<vector<long long>> dp(n, vector<long long>(2));

        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }
        for(int j = 0; j < n; j++) {
            cin >> b[j];
        }

        dp[n-1][0] = min(a[n-1], b[n-1]);
        for(int j = n-2; j >= 0; j--) {
            dp[j][0] = dp[j+1][0] + min(a[j], b[j]);
        }

        if(m < n) {
            dp[m-1][1] = dp[m][0] + a[m-1];
        } else {
            dp[m-1][1] = a[m-1];
        }

        for(int j = m-2; j >= 0; j--) {
            dp[j][1] = min(dp[j+1][1], dp[j+1][0] + a[j]);
        }

        cout << dp[0][1] << endl;
    }

}

//Now mine Greedy Solution (o(n) + 10:48 solve + 186 ms)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
 
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(n);
 
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        ll ans = 0;
        for(ll i = n-1; i>=0; i--){
            if(m>i){
                if(a[i]<=b[i]){
                    ans+=a[i];
                    break;
                }else{
                    ll ptr = i-1;
                    ll to_beat = a[i];
                    ll cur = b[i];
                    ll new_best = LLONG_MAX;
                    bool good = false;
                    while(ptr>=0){
                        if(ptr == 0){
                            cur += a[ptr];
                            if(cur<to_beat){
                                good = true;
                                new_best = min(new_best, cur);
                            }
                        }
                        if((cur+a[ptr])<to_beat){
                            new_best = min(new_best, cur+a[ptr]);
                            cur+=b[ptr];
                            good = true;
                        }else{
                            cur+=b[ptr];
                            if(cur>=to_beat){
                                break;
                            }
                        }
                        ptr--;
                    }
                    ans+=(good?new_best:to_beat);
                    break;
                }
            }else {
                ans += min(a[i], b[i]);
            }
        }
        cout<<ans<<'\n';
    }
}
