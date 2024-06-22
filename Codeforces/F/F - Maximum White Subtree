#include <bits/stdc++.h>
#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pair<ll,ll>>
using namespace std;
const int mxN = 2e5+5;
int up[mxN], down[mxN], color[mxN];
vector<int> grid[mxN];
void dfs1(int u, int p){
    down[u] = (!color[u]?-1:1);
    for(int node: grid[u]){
        if(node == p){
            continue;
        }
        dfs1(node, u);
        down[u] = max(down[u], down[u] + down[node]);
    }
}
//up[u] = max(up[u], down[parent] - down[u])
void dfs2(int u, int p){
    if(p!=-1)up[u] = max(up[u], (up[p]+(!color[p]?-1:1)));
    if(p!=-1)up[u] = max(up[u], max(up[p], 0)+down[p]-max(0,down[u]));
    for(int node: grid[u]){
        if(node!=p) {
            dfs2(node, u);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>color[i];
    }
    for(int i = 0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    dfs1(0, -1);
    memset(up, 0, sizeof(up));
    dfs2(0, -1);

    
        for (int i = 0; i < n; i++) {
            cout << (up[i] + down[i]) << " ";
        }
}
