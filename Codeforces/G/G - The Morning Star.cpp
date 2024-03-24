#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr);
int t;
void solve(){
    map<ll, ll> xpos, ypos, pos, neg;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int x,y;
        cin>>x>>y;
        xpos[x]++;
        ypos[y]++;
        pos[x-y]++;
        neg[x+y]++;
    }
  //+1 slope , -1 slope, x cords and y cords
  //k pos (k-1 other chocies for star)
    ll ans = 0;

    for(auto& x: xpos){
        ans+= x.second*(x.second-1);
    }
    for(auto& x: ypos){
        ans+= x.second*(x.second-1);

    }
    for(auto& x: pos){
        ans+= x.second*(x.second-1);

    }
    for(auto& x: neg){
        ans+= x.second*(x.second-1);

    }
    cout<<ans<<"\n";

}

int main(){
    fastio
    cin>>t;
    while(t--){
        solve();
    }
}
