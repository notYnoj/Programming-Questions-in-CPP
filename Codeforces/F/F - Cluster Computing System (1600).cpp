#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vi l(n+1);
    vi r(n+1);
    l[0] = r[n] = 0;
    for(ll i = 0; i < n; i++){
        l[i+1] = gcd(l[i], a[i]);
    }
    for(ll i = n-1; i>=0; i--){
        r[i] = gcd(r[i+1], a[i]);
    }
    ll ans = 0;
    for(ll i = 0; i<n-1; i++){
        ans+= min(l[i+1], r[i]);
    }
    cout<<ans<<endl;
}
