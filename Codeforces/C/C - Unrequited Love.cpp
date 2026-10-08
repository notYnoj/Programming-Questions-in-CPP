#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define nl '\n'
#include <chrono>
using namespace std;
int t;
// Everything Else thats new :D
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T> p){
    os<<p.first<<' '<<p.second<<endl;
    return os;
}
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << ' ';
    }
    return os;
}


template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec){
    //of size n
    for(T& elem: vec){
        is>>elem;
    }
    return is;
}


void solve(){
    int n;
    cin>>n;
    vi a(n);
    cin>>a;
    unordered_map<ll, ll> mp;
    vi b(n, -LLONG_MAX);
    for(int i = 0; i<n-4; i++){
        int x = a[i] + a[i+2] - a[i+4];
        b[i] = x;
        mp[x]++;
    }

    ll ans = 0;

    for(int i = 0; i<n-4; i++){
        int c = max(0LL, mp[b[i]] - (b[i] == b[i]) - (b[i] == b[i+2]) - (b[i] == b[i+4]) - (i-2>-1 ? b[i-2] == b[i] : 0) - (i-4 >-1 ? b[i-4] == b[i] : 0));
        ans+=c;
    }
    ans/=2;
    cout<<ans<<nl;

}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    cin>>t;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
