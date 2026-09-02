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
    vvi dp(n, vi(n, INT_MAX));
    //make i, j
    for(int i = 0; i<n; i++) dp[i][i] = 1;
    for(int i = 0; i<n-1; i++){
        if(a[i] == a[i+1]) dp[i][i+1] = 1;
        else dp[i][i+1] = 2;
    }
    for(int len = 3; len<=n; len++){
        //2 3 4
        for(int i = 0; i<=n-len; i++){
            
            for(int cut = i; cut<i+len-1; cut++){
                dp[i][i+len-1] = min(dp[i][i+len-1], dp[i][cut] + dp[cut+1][i+len-1]);
            }
            if(a[i] == a[i+len-1]){
                dp[i][i+len-1] = min(dp[i][i+len-1], dp[i+1][i+len-2]);
            }
        }
    }
    cout<<dp[0][n-1];
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
