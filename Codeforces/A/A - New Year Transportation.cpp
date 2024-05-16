#include <bits/stdc++.h>
using namespace std;
int t;
const int mxN = 3e4+5;
bool a[mxN];
void dfs(const vector<vector<int>>& grid, int u){
    a[u] = true;
    for(auto i: grid[u]){
        dfs(grid, i);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>t;
    vector<vector<int>> grid(n+1);
    for(int i = 1; i<=n-1; i++){
        int x;
        cin>>x;
        grid[i].push_back(i+x);
    }
    dfs(grid, 1);
    cout<<(a[t]?"YES":"NO");
}
