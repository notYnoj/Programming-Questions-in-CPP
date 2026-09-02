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

const int mxN = 1e5+10;
ll totz[mxN] = {};
void solve(){
    int n;
    cin>>n;
    vi a(n);
    cin>>a;
    for(int i = 0; i<n; i++){
        totz[a[i]]+=a[i];
    }
    vvi dp(mxN, vi(2, 0)); //0 is dont take this number, 1 is take this number
    for(int i = 1; i<mxN; i++){

        dp[i][0] = max(dp[i-1][0], dp[i-1][1]); //can take or not take from previous for some reason why u would not take 2 in a row doesnt make sense but its oki
        dp[i][1] = max(dp[i][1], dp[i-1][0] + totz[i]);
    }
    cout<<max(dp[mxN-1][1], dp[mxN-1][0]);

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
