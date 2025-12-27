#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;
    
// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
const ll INF = 1'000'000'000'000LL;
void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    if(y == 1){
        cout<<-1<<endl;
        return;
    }
    //we need to do the opposite. Final position is k we need to go backwards.
    //the way i see this is
    //k <- final step
    for(ll i = 0; i<x;){
        //start by implemnting basic action in groups
        ll p = (k-1)/(y-1);
        //until what k can we do this?
        if(p == 0){break;}
        ll fk = (p+1)*(y-1)+1;
        ll actions = (fk-k+p-1)/p;
        actions = min(x-i, actions); 
        k+=(actions*p);
        if(k>INF){
            cout<<-1<<endl;
            return;
        }
        i+=actions;
    }
    cout<<(k>INF?-1:k)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
