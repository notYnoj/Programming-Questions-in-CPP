#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+5;
vector<vector<int>> grid(mxN);
//we need to check if we have visited a vertex
bool v[mxN], exhaust[mxN], in[mxN];

vector<vector<int>> ans;
map<pair<int, int>, bool> used;
void dfs(int u, int p){
    in[u] = v[u] = true;
    int last = 0;
    for(const auto& x: grid[u]){
        if(!v[x]) dfs(x,u);
        if(!used[{u,x}] && !used[{x,u}] && (!exhaust[x]||in[x])&& x!=p){
            if(last == 0){
                last = x;
            }else{
                ans.push_back({last, u, x});
                used[{last, u}] = true;
                used[{u,x}] = true;
                last = 0;
            }
        }

    }
    if(last != 0 && p != 0 && !used[{u,p}] && !used[{p,u}]){
        exhaust[u] = true;
        ans.push_back({last,u,p});
        used[{last,u}] = true;
        used[{u,p}] = true;
    }
    in[u] = false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(v, false, sizeof(v));
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }//taking in input

    for(int i = 1; i<=n; i++){
        if(!v[i]) dfs(i, 0);
    }
    cout<<ans.size()<<"\n";
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<3; j++)cout<<ans[i][j]<<' ';
        cout<<'\n';
    }


}
