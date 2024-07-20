#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
ll modInverse(ll a, ll m) {
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.erase(it, a.end());
    int l = 0;
    int r = m - 1;
    ll ans = 0;
    ll cur = 1;
    if (r >= a.size()) {
        cout << "0\n";
        return;
    }
    int nt = (int)a.size();
    while(a[l]+m<=a[r] && r<nt){
        l++;
        r++;
    }
    for (int i = l; i <= r; i++) {
        cur = (cur * mp[a[i]]) % MOD;  // Modified this line
    }
    ans = (ans + cur) % MOD;
    while (r < nt) {
        r++;
        if(r == nt){
            break;
        }
        cur = (cur * mp[a[r]]) % MOD;  
        while(a[l]+m<=a[r] && l<r) {
            cur = (cur * modInverse(mp[a[l]], MOD)) % MOD;  
            l++;
        }
        if(r-l+1<m){
            continue;
        }
        if(r-l+1>m){
            cur = (cur * m) % MOD;  
        }
        ans = (ans + cur) % MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
