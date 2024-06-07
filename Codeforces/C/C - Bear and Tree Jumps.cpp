#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans = 0;
ll n, k;
const int mxN = 2e6+5;
ll tree_size[mxN], dp[mxN][5];
vector<int> grid[mxN];
ll subtract(ll a, ll b){
    return ((a-b)%k);
}
void dfs(ll cur, ll parent, ll depth){
    tree_size[cur] = dp[cur][depth%k] = 1;
    for(ll i: grid[cur]){
        if(i==parent){
            continue;
        }
        dfs(i, cur, depth+1);
        for(int a = 0; a<k; a++){
            for(int b = 0; b<k; b++){
                ll r = subtract(a+b, 2*depth);
                ll need = subtract(k, r);
                ans+= need*dp[cur][a]*dp[i][b];
            }
        }
        //merge the trees,
        tree_size[cur] += tree_size[i];
        for(int mods = 0; mods<k; mods++){
            dp[cur][mods] += dp[i][mods];
        }
    }
    //increase ans
    ans+=tree_size[cur] * (n - tree_size[cur]);
}
int main(){
    cin>>n>>k;
    for(int i = 0; i<n-1; i++){
        ll a, b;
        cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);

    }
    dfs(1, 0, 0);
    cout<<(ans/k);
}
