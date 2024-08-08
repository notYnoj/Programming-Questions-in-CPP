#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+5;
int par[mxN], sizes[mxN];
bool visited[mxN];
vector<int> grid[mxN];
int find(int a){
    if(par[a] == a){
        return a;
    }else{
        return par[a] = find(par[a]);
    }
}
void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x<y){
        sizes[x] += sizes[y];
        par[y] = x;
    }else{
        sizes[y]+=sizes[x];
        par[x] = y;
    }
}
void dfs(int u, int p, set<int>& cur){
    for()
}
int main(){
    memset(visited, false, sizeof(visited));
    int n,m;
    cin>>n>>m;
    for(int i =0; i<n; i++){
        par[i] = i;
        sizes[i] = 1;
    }
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    set<int> s;
    dfs(0, -1, s);
    int a = 0;
    vector<int> b;
    vector<bool> seen(n, false);
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            cout<<1<<'\n';
            cout<<n;
            return 0;
        }else{
            if(!seen[find(i)]){
                a++;
                b.push_back(sizes[find(i)]);
                seen[find(i)] = true;
            }
        }
    }
    cout<<a<<"\n";
    sort(b.begin(), b.end());
    for(int i = 0; i<b.size(); i++){
        cout<<b[i]<<' ';
    }
}
