#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  //essenitally the min cant become better js check every number and the one before it and max the ans
    ll t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        vector<ll> arr(a);
        for(int i = 0;  i<a; i++){
            ll q;
            cin>>q;
            arr[i] = q;
        }
        ll ans = 0;
        
        for(int i = 1; i<a; i++){
            ans = max(ans, arr[i]*arr[i-1]);
        }
        cout<<ans<<"\n";

    }
}
