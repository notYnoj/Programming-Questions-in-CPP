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
    const int mod = 998244353;
    int n;
    cin>>n;
    vi a(n-1);
    cin>>a;
    for(int i = 0; i<n-1; i++){
        if(a[i] == n){
            cout<<0<<nl;
            return; 
        }
    }
    vi pref(n), suff(n);
    pref[0] = 1;
    suff[n-1] = 1;
    //2 1  5 1 5
    for(int i = 1; i<n; i++){
        if(pref[i-1] && pref[i-1] <= pref[i]){
            pref[i] = 1;
        }else{
            pref[i] = 0;
        }
    }
    for(int i = n-2; i>=0; i--){
        if(suff[i+1] && a[i]>=a[i+1]){
            suff[i] = 1;
        }else{
            suff[i] = 0;
        }
    }
    ll ans = 0;
    for(int pos_of_max = 0; pos_of_max<n; pos_of_max++){
        if(!(pos_of_max>0 ? pref[pos_of_max-1] : true) || !suff[pos_of_max]) continue;
        if(a[pos_of_max] == a[pos_of_max-1]) continue;
        //can be pos_of_max here
        vi l;
        vi r;
        for(int i = 0; i<pos_of_max; i++){
            l.pb(a[i]);
        }
        for(int i = pos_of_max; i< n-1; i++){
            r.pb(a[i]);
        }
        reverse(all(a)); // build it up
        ll ways = 1;
        ll used = 0;
        ll x = 0, y = 0;
        while(x < l.size() || y < r.size()){
            
        }
    }
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
