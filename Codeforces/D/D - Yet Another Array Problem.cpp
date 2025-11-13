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
/*namespace IO {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        for (const auto& elem : vec) {
            os << elem << " ";
        }
        return os;
    }
}
using namespace IO;
//for macos^^
*/
ll gcd(ll a, ll b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    bool hasOdd = false;
    ll ans = LLONG_MAX;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        ll tb = 2;
        if(ans == 2) continue; 
        while(gcd(a[i], tb) != 1){
            tb++;
        }
        ans = min(tb, ans);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
