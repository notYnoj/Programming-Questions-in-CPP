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
void solve(){
    ll n;
    cin>>n;
    vi a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vi r(n);
    for(int i = n-1; i>=0; i--){
        if(i == n-1){
            r[i] = a[i];
        }else{
            r[i] = a[i]+r[i+1];
        }
    }
    ll ans = a[0]-r[0];
    ll front = a[0];
    for(int i = 1; i<n; i++){
        ans = max(ans, front - r[i]+a[i]);
        front+=abs(a[i]);
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