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



const ll mxN = 2e5+5;
ll dp[mxN];
vvi graph;
map<ll, set<ll>> dir;

void dfs(ll u, ll p) {
    for(const auto& node: graph[u]){
        if(node == p) continue;
        if (dir.find(u)!=dir.end() && dir[u].count(node)){}
        else dp[0] += 1;
        dfs(node, u);
    }
}

void fill_dp(ll u, ll p) {
    if (p!=-1) {
        if (dir.find(p)!=dir.end() && dir[p].count(u)) dp[u] = dp[p]+1;
        else dp[u] = dp[p]-1;
    }
    
    for(const auto& node: graph[u]){
        if(node == p) continue;
        fill_dp(node, u);
    }
}

void solve(){
    ll n;
    cin>>n;
    graph.resize(n);
    for(ll i = 0; i<n-1; i++){
        ll l, r;
        cin>>l>>r;
        l--;
        r--;
        graph[r].pb(l);
        graph[l].pb(r);
        dir[l].insert(r);
    }

    dfs(0, -1);
    fill_dp(0, -1);
    
    ll ans = INT_MAX;
    for(ll i = 0; i<n; i++) ans = min(ans, dp[i]);
    
    cout << ans << endl;
    for(ll i = 0; i<n; i++) dp[i]==ans && cout << i+1 << " ";
    cout << endl;
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
