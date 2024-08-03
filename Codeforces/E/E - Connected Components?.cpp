#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+5;
int par[mxN], sizes[mxN];
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
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n);
    for(int i = 0; i<n; i++){
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
    auto bfs = [&](){
        vector<int> visited(n);

    };

    int ans = 0;
    vector<int> ans2;
    vector<int> seen(n);
    for(int i = 0; i<n; i++){

    }

}
