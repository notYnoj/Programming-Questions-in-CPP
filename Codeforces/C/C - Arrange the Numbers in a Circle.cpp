#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#include <chrono>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vi a(n);
        ll ans = 0;
        ll ones = 0;
        for(ll i = 0; i<n; i++){ 
            cin>>a[i];
            if(a[i] == 1) ones++;
            else ans+=a[i];
        }
        if(ans + ones < 3){
            cout<<0<<nl;
        }else{
            if(ones == n-1){
                ll rem = ans/2;
                ans+=min(rem, ones);
            }else{
                for(ll i = 0; i<n; i++){
                    if(a[i] > 1){
                        ans += min((ll)(a[i]/2 - 1), ones);
                        ones-=(a[i]/2 - 1);
                        ones = max(0ll,ones);
                    }
                }
            }
            cout<<ans<<nl;
        }
    }
}