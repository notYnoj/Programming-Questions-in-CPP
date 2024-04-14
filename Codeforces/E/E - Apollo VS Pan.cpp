#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
      //fix j
      //then we can simply add up all the infleunce on the asnwer for the and and or for each bit of j
        cin>>n;
        vector<ll> arr(n);
        vector<ll> bits(61);
        for(int i = 0; i<n; i++){
            ll a;
            cin>>a;
            arr[i] = a;
            for(int bit = 0; bit<=60; bit++){
                if((a>>bit) & 1){
                    bits[bit]++;
                }
            }
        }
        ll ans = 0;
        for(int j = 0; j<n; j++){
            ll curj = arr[j];
            ll outa = 0, outo = 0;
            for(int bit = 0; bit<60; bit++){
                if((curj>>bit) & 1){
                    outa += (((1LL<<bit)%mod) * bits[bit])%mod;
                    outo += (((1LL<<bit)%mod)  * n) % mod;
                }else {
                    outo += (((1LL<<bit)%mod)  * bits[bit]) % mod;
                }
                outa %= mod;
                outo %= mod;
            }
            ans += (outa*outo) % mod;
            ans = ans% mod;
        }
        cout<<ans<<"\n";
    }
}
