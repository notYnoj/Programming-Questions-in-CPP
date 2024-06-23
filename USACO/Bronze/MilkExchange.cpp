#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<ll> arr(n+1);
    arr[n] = 0;
    for(ll i = 0; i<n; i++) cin>>arr[i];
    vector<bool> nulls(n+1, false);
    nulls[n] = true;
    bool can = false;
    if(s[0] == 'L' && s[n-1] == 'R') nulls[0] = nulls[n-1] = can = true;

    for(int i = 1; i<n; i++){
        if(s[i] == 'L' && s[i-1] == 'R') nulls[i] = nulls[i-1] = can =  true;
    }
    ll ans = 0;
    ll start = 0;
    while(nulls[start]){
        ans+=arr[start];
        start++;
    }
    ll pref = 0;
    if(!can) cout<<accumulate(arr.begin(), arr.end(), 0LL);
    else {
        ll t = 0;
        if(s[0] == s[n-1] && !nulls[0] &&!nulls[n-1]){
            while(s[n-1] == s[0] && !nulls[n-1]){
                t+=arr[n-1];
                n--;
            }

        }
        s+='E';
        ll cur = true;
        for(ll i = start; i<n; i++){
            if(nulls[i]){
                ans+= arr[i];
                if(cur)pref+=t;
                ans+=max(pref-m, 0LL);
                pref = 0;
                cur = false;
            }else{
                if(nulls[i+1]||s[i] == s[i+1]){
                    pref+= arr[i];
                }else{
                    pref+=arr[i];
                    if(cur == true) pref+=t;
                    ans+=max(pref-m, 0LL);
                    pref = 0;
                    cur = false;
                }
            }
        }
        ans+=max(pref-m, 0LL);
        cout<<ans;
    }


}
