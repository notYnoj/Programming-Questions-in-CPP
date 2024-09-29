#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int mxN = 2e5+5;
vector<int> graph[mxN];
bool dp[mxN];
int total_leaves = 0, moved = 0;
//dp[i] = true (leave, otherwise its a bud)
//for us to move u to another side
//(always prefered as 2 on remove or not thus we subtract by 1 on the side we place bud).
//u must be bud or we must have moved all original children buds
//we can follow a moved to move pattern
//if we have a parent have a to move then it must be a bu
//however if all children are moved then current becomes to move
//if we have children of 1 be moved then we dont have anything there otehrwise there is 1
//answer = total_leaves <- to_move amount subtracted by moved
void dfs(int u, int p){
    bool done = false;
    bool g = false;
    for(int v: graph[u]){
        if(v!=p){
            done = true;
            dfs(v, u);
            if(dp[v]){
               g= true;
            }
        }
    }
    if(p == -1){
        return;
    }
    if(!done){dp[u] = true; total_leaves++;}
    else{
        if(g){
            dp[u] = false;
            moved++;
        }else{
            dp[u] = true;
            total_leaves++;
        }
    }

}
void solve(){
    total_leaves = 0;
    moved = 0;
    memset(dp, false, sizeof(dp));
    int n;
    cin>>n;
    for(int i =0 ; i<=n; i++){
        graph[i].clear();
    }
    for(int i = 1; i<n; i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, -1);
    bool add_one = true;
    for(int v: graph[1]){
        if(dp[v]){
            add_one = false;
        }
    }
    cout<<(add_one?total_leaves-moved+1:total_leaves-moved)<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
