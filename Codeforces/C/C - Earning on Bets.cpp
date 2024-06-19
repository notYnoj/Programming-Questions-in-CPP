#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        ll min_ele = *min_element(arr.begin(), arr.end());
        ll l = 1;
        ll r = 1e9;
        ll ans = -1;
        vector<ll> ans111;
        while(l<=r){
            ll mid = (l+r)/2;
            bool tz = true;
            ll tnn = min_ele*mid;
            ll tnm = 0;
            for(int i = 0; i<n; i++){
                ll cur = tnn/arr[i];
                if(tnn%arr[i]) cur+=1;
                tnm+=(cur);
                ans111.push_back(cur);
            }
            if(tnm<tnn){
                tz= false;
            }
            if(tz){
                l = mid+1;
            }else{
                ans = mid*min_ele;
                break;
            }
        }
        if(ans == -1) {
            cout << -1;
        }else{
            for(ll& i: ans111) cout<<i<<" ";
        }
        cout<<'\n';
    }

}
