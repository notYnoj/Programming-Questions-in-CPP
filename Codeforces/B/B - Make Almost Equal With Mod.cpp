#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<int>>
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vi a(n);
    bool e = false, o =false;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]%2){
            o = true;
        }else{ e= true;
        }
    }
    if(e && o){
        cout<<2<<endl;
    }else{
        sort(all(a));
      
        ll g;
        vi b;
        for(ll i = 0; i<n-1; i++){
            b.pb(a[i+1]-a[i]);
        }
        for(ll i = 0; i<n-1; i++){
            if(i == 0){
                g= b[i];
            }else{
                g = gcd(g, b[i]);
            }
        }
        cout<<g*2<<endl;
        /*for(int i = 0; i<n; i++){
            cout<<(a[i]%(g*2))<<' ';
        }*/
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}
