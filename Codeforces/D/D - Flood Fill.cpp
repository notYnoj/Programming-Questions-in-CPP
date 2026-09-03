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
    cin>> a;
    vi runs;
    int len = 0;
    for(int i = 0; i<n-1; i++){
        if(a[i] == a[i+1]){
             len++;
        }else{
            runs.pb(a[i]);
        }
    }
    runs.pb(a[n-1]);
    
    vvi dp(runs.size(), vi(runs.size(), INT_MAX));
    
    for(int i = 0; i<runs.size(); i++){ 
        dp[i][i] = 0;
    }
    for(int i = 0; i<runs.size()-1; i++){
        dp[i][i+1] = 1;
    }
    for(int len = 3; len<=runs.size(); len++){
        for(int i = 0; i<=runs.size()-len; i++){
            int r = i+len-1;
            dp[i][r] = min(dp[i+1][r], dp[i][r-1])+1;
            if(runs[i] == runs[r]){
                dp[i][r] = min(dp[i][r], dp[i+1][r-1] + 1);
            }
        }
    }
    cout<<dp[0][runs.size()-1];
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    t =1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}   
