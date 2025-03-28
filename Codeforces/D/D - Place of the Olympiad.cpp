//github: https://github.com/notYnoj
#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
void solve(){
    //we want it to be like 1 0 1 0 until it gets too big so if all the odd numbers (becuz odd will always be greater)
    /* it can be good and can be of length l
     * */
    ll n,m,k;
    cin>>n>>m>>k;
    ll best = k/n;
    ll rem = k%n;
    ll l = 1;
    ll r = m;
    ll ans = INT_MAX;
    while(l<=r){
        ll mid = (r+l)/2;
        //we are currently looking at mid
        ll posb = (m/(mid+1));
        //we need to subtract one for each space we give a posb;
        ll real = n*posb*mid;
        //left over ones
        real+=(m%(mid+1))*n;
        if(k<=real){
            r = mid-1;
            ans = min(ans, mid);
        }else{
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
