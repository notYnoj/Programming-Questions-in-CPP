#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+10;
int parent[mxN];
bool s[mxN];
vector<vector<int>> graph(mxN);
bool visited[mxN];
bool dfs(int u, int p){
    if(graph[u].size()!=2){
        return false;
    }
    visited[u] = true;

    bool good = true;
    for(int i: graph[u]){
        if(graph[i].size() != 2){
            return false;
        }
        if(i==p){
            continue;
        }
        if(!visited[i]){
            good &= dfs(i,u);
        }
    }
    return good;
}
int find(int a){
    if(parent[a] ==a){
        return a;
    }else{
        return parent[a] = find(parent[a]);
    }
}
void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    parent[y] = x;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        parent[i] = i;
    }
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a); //WAS GRAPH[B].PUSH_BACK(B) adjkfasdjkfasdjfkaskdjfasdkjfhawlieamndsc mnxbuihw efqw0t84hJ;KJ;kjfha;hsdfpuh
        merge(a,b);
    }
    int ans = 0;
    memset(s,false,sizeof(s));
    for(int i = 1; i<=n; i++){
        if(!s[find(i)]){
            memset(visited, false, sizeof(visited));
            if(dfs(i, -1)){
                ans++;
            }
        }
        s[find(i)] = true;
    }
    cout<<ans;
}
