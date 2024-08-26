#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e9+1;
ll formula(ll ai, ll bi, ll n){
    ll start = ai*n;
    ll dif = bi*(n*(n-1))/2;
    return start-dif;
}
void solve(){
    ll ans = 0;
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i = 0; i<n; i++ ) cin>>a[i];
    for(ll i= 0; i<n; i++) cin>>b[i];
    ll low = 0;
    ll high = mxN;
  //binary searching the answer! were seeing which numbers we can take and up to what point we can take it!
    while(low+1<high){
        ll mid = (low+high)/2;
        ll amnt_taken = 0;
        for(int i = 0; i<n; i++){
            if(a[i]-mid>=0) amnt_taken+= (((a[i]-mid)/b[i])+1);
        }
        if(amnt_taken>=k){
            low = mid;
        }else{
            high = mid;
        }
    }
    ll counter = 0; 
    for(int i = 0; i<n; i++){
        if(a[i]-low>=0){
            ll take = ((a[i]-low)/b[i])+1;
            ans+=formula(a[i], b[i], take);
            counter+=take;
        }
    }
  //remove the smallest ones
    ans-=((long long)max(0LL,counter-k)*low);
    cout<<ans<<"\n";


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
