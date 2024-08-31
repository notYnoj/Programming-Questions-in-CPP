#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int mxN = 2e5+5;
vector<int> graph[mxN];
int dp[mxN];
int total_leaves = 0, moved = 0;
//for us to move u to another side
//(always prefered as 2 on remove or not thus we subtract by 1 on the side we place bud).
//u must be bud or we must have moved all original children buds
//we can follow a moved to move pattern
//if we have a parent have a to move then it must be a bud
//however if all children are moved then current becomes to move
//if we have children of 1 be moved then we dont have anything there otehrwise there is 1
//answer = total_leaves <- to_move amount subtracted by moved
bool dfs(int u, int p){
    dp[u] = 0;

}
void solve(){
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, -1);


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
