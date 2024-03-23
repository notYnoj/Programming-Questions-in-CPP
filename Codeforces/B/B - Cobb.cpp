#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;

int main(){
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n+1);
        for(int i = 1; i<=n; i++){
            cin>>arr[i];
        }
        int l = max(1, n - (2*k));
        ll ans = -1e12;
        for(ll i = l; i<=n; i++){
            for(ll j = i+1; j<=n; j++){
                ll q = i * j - k * (arr[i] | arr[j]);
                ans = max(ans,  q);
            }
        }
        cout<<ans<<"\n";
    }

}
//math brute force.
