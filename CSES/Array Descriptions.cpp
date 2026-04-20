#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
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

ll mod = 1e9+7;
//if its a 0 it can be any of the numbers 
void solve(){
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll i = 0 ; i<n; i++){
        cin>>a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    if(a[0] == 0){
        for(ll i = 0; i<m; i++){
            dp[0][i] = 1;
        }
    }else{
        dp[0][a[0]-1] = 1;
    }
    for(ll i = 1; i<n; i++){
        if(a[i] == 0){
            //then if im trying to get a number m,
            for(ll pos = 0; pos < m; pos++){
                //2 1 2 3
                dp[i][pos] = dp[i-1][pos] + (pos+1 < m? dp[i-1][pos+1] : 0) + (pos -1 >= 0 ? dp[i-1][pos-1] : 0);
                dp[i][pos] %= mod;
            }
        }else{
            dp[i][a[i] - 1] = dp[i-1][a[i] - 1 ] + (a[i] < m ? dp[i-1][a[i]] : 0) + (a[i]-2 >= 0 ? dp[i-1][a[i]-2] : 0);

            dp[i][a[i]-1] %= mod;
        }
    }

    cout<<accumulate(all(dp[n-1]), 0LL)%mod<<endl;

    
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    t = 1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
