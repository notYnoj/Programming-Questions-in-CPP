#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = 0;
    map<int, int> mp;
    vector<int> pref(n);
    pref[0] = (s[0]-'0')-1;
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + (s[i]-'0')-1;
    }
    for(int i = 0; i<n; i++){
        if(pref[i] == 0){
            ans++;
            ans+=mp[0];
            mp[0]++;
        }else{
            if(mp.find(pref[i]) != mp.end()){
                ans+=mp[pref[i]];
            }
            mp[pref[i]]++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
