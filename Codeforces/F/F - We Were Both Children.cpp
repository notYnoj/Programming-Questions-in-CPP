#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr);
int t;
void solve(){
    int n; cin >> n;
    vector<ll> cnt(n + 1, 0), mx(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x <= n) ++cnt[x];
    }
  //if its more than n we can disregard or else we simply go throuhg each of the ones there!
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; j += i) mx[j] += cnt[i];
    }
    cout << *max_element(mx.begin(), mx.end()) << "\n";
}
int main(){
    fastio
    cin>>t;
    while(t--){
        solve();
    }
}

