#include <bits/stdc++.h>
using namespace std;
const int mxN = 5005;
int dp[mxN][mxN][2];
vector<int> graph[mxN];
int c[mxN];
int d[mxN];
int cnt[mxN];
void dfs(int u) {
  //0 bought, 0 spent
    dp[u][0][0] = 0;
  //dont get coupon
    dp[u][1][0] = c[u];
  //get coupon
    dp[u][1][1] = c[u] - d[u];
    cnt[u] = 1;
    for (int v: graph[u]) {
        //tree dfs -> use all the previously calculated u values first (aka cnt[u] then the j) 
        dfs(v);
        for (int i = cnt[u]; i >= 0; i--) {
            for (int j = 0; j <=cnt[v]; j++) {
                dp[u][i+j][0] = min(dp[u][i+j][0], dp[u][i][0] + dp[v][j][0]);
                dp[u][i+j][1] = min(dp[u][i+j][1], dp[u][i][1] + min(dp[v][j][1], dp[v][j][0]));
            }
        }
      //number of nodes found.
        cnt[u] += cnt[v];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,budget;
    cin>>n>>budget;
    cin>>c[1]>>d[1];
    for(int i = 2; i<=n ;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graph[z].push_back(i);
        c[i] = x;
        d[i] = y;
    }
    for(int i = 0; i<=n; i++){
        for(int j =0; j<=n; j++){
            for(int k = 0; k<2; k++){
                dp[i][j][k] = 1e9+7;
            }
        }
    }


    //find max that has <=budget

    dfs(1);
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(min(dp[1][i][0],dp[1][i][1])<=budget){
            ans = max(ans, i);
        }
    }
    cout<<ans;
}
