#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mxN = 1e5+5;
ll a[mxN], b[mxN];
ll find(ll x){
    if(a[x] == x){
        return x;
    }else{
        return a[x] = find(a[x]);
    }
}
void merge(ll x, ll y){
    x = find(x);
    y = find(y);
    if(x == y){
        return;
    }
    a[x] = y;
    b[y]+=b[x];
}
bool lucky(ll n){
    if (n == 0){
        return true;
    }else{
        if(n%10 == 4 || n%10 == 7){
            return lucky(n/10);
        }else{
            return false;
        }
    }
}

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(ll i = 1; i<=n; i++){
        a[i] = i;
        b[i] = 1;
    }
    for(int i = 1; i<n; i++){
        ll p,c,v;
        cin>>p>>c>>v;
        if(!lucky(v)){
            merge(p,c);
        }
    }
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        ll t = n-b[find(i)];
        ans+=t*(t-1);
    }
    cout<<ans;
}
//why?

