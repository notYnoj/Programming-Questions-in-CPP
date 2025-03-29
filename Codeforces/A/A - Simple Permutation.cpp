#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e5+5;
vector<bool> o(mxN+5, true);
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
void sieve(){
    o[0] = false;
    o[1] = false;
    for(ll i = 2; i<mxN; i++){
        if(o[i]) {
            for (ll j = i * i; j < mxN; j += i) {
                o[j] = false;
            }
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> prem(n);
    vector<bool> used(n+1, false);
    used[0] = true;
    //pref[i]/i = P
    //n/6  0 1,2,3,4,5
    //we want the first n/3 numbers to be prime
    //gauss rainbows 1 = P 2 = P+P-1 3 = P+P-1+P+1
    ll P;
    for(ll i = n/6+1; i<n; i++){
        if(o[i]){
            P = i;
            break;
        }
    }
    ll needed = n/3;
    ll plays = 0;
    for(ll i = 0; i<needed; i++){
        //P, P-1, P+1, P-2,
        if(i%2){
            prem[i] = P-(++plays);
        }else{
            prem[i] = P+plays;
        }
        used[prem[i]] = true;
    }
    ll ptr2 = 0;
    for(ll i = needed; i<n; i++){
        while(used[ptr2]){
            ptr2++;
        }
        prem[i] = ptr2++;
    }
    cout<<prem<<'\n';
}
int main(){
    int t;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
}
