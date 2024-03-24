#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr);
int t;

void solve(){
    ll n, c;
    cin>>n>>c;
    vector<ll> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    ll l = 1;
    ll r = 2147483647;
    while(l<=r){
        ll mid = l + (r-l)/2;
        ll ans = 0;
        for(int i = 0; i<n; i++){
            ans += (arr[i] + 2*mid)*(arr[i]+2*mid);
            if(ans>c){
                break;
            }
        }
        if(ans == c){
            cout<<mid<<"\n";
            break;
        }
        if(ans>c){
            r = mid-1;
        }
        if(ans<c){
            l = mid+1;
        }
    }
}
int main(){
    fastio
    cin>>t;
    while(t--){
        solve();
    }
}
