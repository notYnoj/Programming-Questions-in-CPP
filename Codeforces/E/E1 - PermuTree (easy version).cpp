#include <bits/stdc++.h>
using namespace std;
const int mxN = 5006;
int ans = 0, children[mxN];
vector<int> grid[mxN];
void dfs(int u, int parent){
    bitset<mxN> dp;
  //have children u denote how many children u has.
  //children u = sum(children of all its children)
    dp.set(0);
    for(auto i: grid[u]){
        if(parent != i){
            dfs(i, u );
          //children of u
            children[u] += children[i];
          //move it by i to denote tehre is i children
            dp |= (dp<<children[i]);
        }
    }
    int contrb = 0;
    for(int i = 1; i<=5005; i++){
      //permu yes.
        if(dp[i]) contrb = max(contrb, (i * (children[u]-i)));
    }
    ans+=contrb;
    children[u]++; //so that the node u itself is counted as a child.
}
//chose whether u want left or right to be bigger ykyk
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 2; i<=n; i++){
        int a; cin>>a;
        grid[a].push_back(i);
        grid[i].push_back(a);
    }
    dfs(1, -1);
    cout<<ans;
}
