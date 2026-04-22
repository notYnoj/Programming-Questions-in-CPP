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
const int mxN = 1e6+2;
ll dp[mxN][2];
const int mod = 1e9+7;
 
void precomp(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    //0 = previous are not connected, 1 = previous are connected
    //at any point u have the ability to extend the previous 1, create or create a new row
    for(int i = 2; i<mxN; i++){
        //2* becuz u have the option to connect them vertically or not connect them
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) %mod;
        //u can only connect them if they are not connected or connect the top ones
        dp[i][1] = (dp[i-1][0]+2*dp[i-1][1]) % mod;
    }
}
void solve(){
 
    int n;
    cin>>n;
    cout<<((dp[n][0] + dp[n][1]) % mod)<<'\n';
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    precomp();
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
