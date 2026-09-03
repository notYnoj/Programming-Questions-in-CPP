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

//try to add min or max at the end notice that we can either add it after processing whas to teh right (min) or after processing wahts to left (max) this is dp state
void solve(){
    int n;
    cin>>n;
    vi a(n);
    cin>>a;
    sort(all(a));
    vvi dp(n, vi(n, INT_MAX));
    for(int i = 0; i<n; i++){
        dp[i][i] = 0; //it itself is 0
    }
    for(int len = 2; len<=n; len++){
        for(int i = 0; i<=n-len; i++){
            int l = i;
            int r = i + len - 1;
            dp[l][r] = a[r] - a[l] + min(dp[l+1][r], dp[l][r-1]);
            
        }
    }
    cout<<dp[0][n-1];

}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    int t = 1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
