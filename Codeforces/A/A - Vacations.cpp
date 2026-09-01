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
    vvi dp(n, vi(3, INT_MAX)); //0 = rest today, 1 = contest tdoay, 2 = workout today
    if(a[0] == 0){
        dp[0][0] = 1;
    }else if(a[0] == 1){
        dp[0][1] = 0;
    }else if(a[0] == 2){
        dp[0][2] = 0;
    }else{
        dp[0][1] = 0;
        dp[0][2] = 0;
    }

    for(int i = 1; i<n; i++){
        if(a[i] == 0){
            for(int j = 0; j<3; j++){
                dp[i][0] = min(dp[i-1][j] + 1, dp[i][0]);
            }
        }else if(a[i] == 1){
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][0] = dp[i-1][1] + 1;
        }else if(a[i] == 2){
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][0] = dp[i-1][2]+1;
        }else{
            //never have to take a rest today
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][0] = min(dp[i-1][1] + 1, dp[i-1][2]+1);
        }
    }
    ll ans = INT_MAX;
    for(int i = 0; i<3; i++){
        ans = min(ans, dp[n-1][i]);
    }
    cout<<ans<<nl;

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
