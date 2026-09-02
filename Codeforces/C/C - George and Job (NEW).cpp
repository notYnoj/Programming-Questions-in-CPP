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
    int n,m,k;
    cin>>n>>m>>k; 
    //m is how far apart our ranges are, k is how many we have
    vvi dp(n, vi(k+1, 0));
    vi a(n);
    cin>>a;
    vi pref(n);
    pref[0] = a[0];
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + a[i];
    }

    dp[m-1][1] = pref[m-1];
    for(int i = m; i<n; i++){
        //ending at i
        for(int j = 1; j<=k; j++){
            //either its u take best from last or u make a new prefix here
            dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + pref[i] - pref[i-m]);
        }
    }
    cout<<dp[n-1][k];
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    t=1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
