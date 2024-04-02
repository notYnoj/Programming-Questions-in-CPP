#include <bits/stdc++.h>
using namespace std;
int t;
const int mxN = 1e5+5;
int low[mxN], high[mxN];
vector<int> graph[mxN];
pair<long long, long long> dfs(int u, int parent){
    long long one = 0, two = 0;
    for(int i: graph[u]) {
        if (i == parent) {
            continue;
        }
        pair<long long, long long> mx = dfs(i, u);
        //one is going to be using low
        //other is going to be using high.
        // one = low u two = high u
        //we can use u as low or hihg
        //since it is as such we can either have the ith child be low or high
        one += max(mx.first + abs(low[u]-low[i]), mx.second + abs(low[u] - high[i]));
        two += max(mx.first + abs(high[u] - low[i]), mx.second + abs(high[u] - high[i]));
    }
    return {one, two};

}
void solve(){
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>low[i]>>high[i];
    }
    for(int i = 1; i<n ;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    auto p = dfs(1, -1);
    cout<< max(p.first, p.second)<<"\n";
    for(int i = 0; i<=n; i++) graph[i].clear();
}
int main(){
    cin>>t;
    while(t--){
        solve();
    }
}
