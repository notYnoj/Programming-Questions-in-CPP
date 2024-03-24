#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(nullptr);
using namespace std;
const int mxN = 2e5+1;
int t;
vector<pair<int,int>> adj[mxN];
#define ll long long
ll val[mxN], vis[mxN];
void dfs(int u){
    vis[u] = 1;
    for(auto& v: adj[u]){
        if(!vis[v.first]){
            val[v.first] = val[u] + v.second;
            dfs(v.first);
        }
    }
}
void solve(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        val[i] = 0;
        vis[i] = 0;
        adj[i].clear();
    }
    vector<vector<ll>> hold;
    for(int i= 0; i<m; i++){
        ll a, b, d;
        cin>>a>>b>>d;
        hold.push_back({a,b,d});
        adj[a].push_back({b,-d});
        adj[b].push_back({a,d});
    }
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i = 0; i<m; i++){
        ll a = hold[i][0];
        ll b = hold[i][1];
        ll c = hold[i][2];
        if(val[b] + c != val[a]){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES\n";
    return;

}
int main(){
    fastio
    cin>>t;
    while(t--){
        solve();
    }
}
