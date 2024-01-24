#include <bits/stdc++.h>
using namespace std;
int n;
int M = 2e5+1;
//down[i] + totalUpwards - up[i] = the amount needed to be reversed
//this is because for any pos, i u are reversing the ones that are going down above it (at pos i), and we are reversing any that go up below it, however the up at pos i DONT need to be reversed
vector<vector<pair<int, int>>> graph(M); //graph maps 
vector<int> up(M);
vector<int> down(M);
int total = 0;
vector<int> ans(M);
void dfs(int child, int parent){
    for(auto n: graph[child]){
        int adj = n.first;
        int direction = n.second;
        if(adj == parent){
            continue;
        //depending on pos caluclate how many are going down at adj, from child
        }if(direction == 0){
            down[adj] = down[child]+1; 
            up[adj] = up[child];
        }else{
            up[adj] = up[child]+1;
            down[adj] = down[child];
        }
        dfs(adj,child);
        if(direction==1){
            total++; // total going up
        }
    }
}
int main() {
    cin>>n;
    int MX = 1e9+7;
    for(int i = 0; i<n-1; i++){
        int start, end;
        cin>>start>>end;
        graph[start].push_back({end,0}); // 0 == down
        graph[end].push_back({start,1}); // 1 == up

    }
    dfs(1,-1); //-1 as 1 has no parent
    for(int i = 1; i<=n; i++){
        ans[i] = down[i] + total - up[i];
        MX = min(MX, ans[i]);
    }
    cout<<MX<<"\n";
    for(int i = 1; i<=n; i++){
        if(ans[i] == MX){
            cout<<i<<" ";
        }
    }

}
