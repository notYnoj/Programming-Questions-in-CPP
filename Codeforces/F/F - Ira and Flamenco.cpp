#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long choose(int n, int r){
    long long sum = 1;
    for(int i = 1; i <= r; i++){
        sum = sum * (n - r + i) / i;
    }
    return sum;
}
void solve(){
    long long ans = 0;
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    set<int> st(a.begin(), a.end());
    cout<<ans<<"\n";
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
