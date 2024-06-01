#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
const ll mxN = 1e5+5;
vector<ll> graph[mxN];
ll color[mxN];
ll dp[mxN][2];
//0 == # with black vertex, 1 == # with no black vertex
void dfs(ll root, ll parent){
    dp[root][0] = 0;
    dp[root][1] = 1;
    for(ll child: graph[root]){
        if(parent!=child){
          //dp
            dfs(child, root);
            dp[root][0] *= dp[child][1]; // having #  black miutliply by permu of child!
            dp[root][0] %=MOD;
            dp[root][0] += (dp[root][1]*dp[child][0]); //having none black at root, mtuliply by black onefs of child!
            dp[root][0] %= MOD;
            dp[root][1] *= dp[child][1]; // having no black miutliply bu no black to get more no black!
            dp[root][1] %=MOD;
        }
    }
    if(color[root] == 1){
        dp[root][0] = dp[root][1]; // if we can split here then making it black means we have a black

    }else{
        dp[root][1] += dp[root][0];
        dp[root][1] %=MOD;
    }
}
int main() {
    ll n;
    cin>>n;
    for(ll i = 1; i<n; i++){
        ll t;
        cin>>t;
        graph[i].push_back(t);
        graph[t].push_back(i);
    }
    for(ll i = 0; i<n; i++){
        ll z;
        cin>>z;
        color[i] = z;
    }
    dfs(0, -1);
    cout<<dp[0][0];

}
