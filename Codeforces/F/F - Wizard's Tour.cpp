#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+5;
vector<vector<int>> grid(mxN);
//we need to check if we have visited a vertex
bool v[mxN], exhaust[mxN], in[mxN];

vector<vector<int>> ans;
map<pair<int, int> bool> used;
void dfs(int u, int p){
    in[u] = v[u] = true;
    for(const auto& x: grid[u]){
        if(!v[x]){
            dfs(int x, int u);
        }

    }
    //
}
int main(){
    memset(v, false, sizeof(v));
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }//taking in input

    for(int i = 0; i<n; i++){
        if(!v[i]) dfs(i, -1);
    }

    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<3; j++)cout<<ans[i][j]<<' ';
        cout<<'\n';
    }


}
