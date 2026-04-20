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
const int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    vvi grid(n, vi(n));
    vvi dp(n, vi(n, 0));
    vector<vector<bool>> found(n, vector<bool>(n, false));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char c;
            cin>>c;
            grid[i][j] = (c == '*'? 0:1);
        }
    }
    dp[0][0] = grid[0][0]; 
    queue<pair<int, int>> bfs;
    bfs.push({0,0});
    while(!bfs.empty()){
        auto cur = bfs.front();
        if(!found[cur.first][cur.second]){
            dp[cur.first][cur.second] += (cur.first - 1 >= 0 ? dp[cur.first-1][cur.second] : 0) % mod;
            dp[cur.first][cur.second] += (cur.second - 1 >= 0 ? dp[cur.first][cur.second-1] : 0) % mod;
            dp[cur.first][cur.second] %= mod;
            if(cur.first + 1 < n){
                bfs.push({cur.first + 1, cur.second});
            }
            if(cur.second + 1 < n){
                bfs.push({cur.first, cur.second + 1});
            }
            if(grid[cur.first][cur.second] == 0) dp[cur.first][cur.second] = 0;
            found[cur.first][cur.second] = true;
        }
        bfs.pop();
    }


    cout<<dp[n-1][n-1]<<endl;
    

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
