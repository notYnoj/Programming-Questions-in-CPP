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
    int ans = 0;
    vector<int> ans2;
    auto bfs = [&](int start){
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(visited[cur]){
                continue;
            }
            visited[cur] = true;
            if(grid[cur].empty()){
                cout<<1<<'\n';
                cout<<n;
                return 0;
            }
            int ptr = 0;
            int sz = grid[cur].size();
            auto cur_vector = grid[cur];
            for(int i =0; i<n; i++){
                if(ptr<sz&&cur_vector[ptr] == i){
                    ptr++;
                    continue;
                }
                while(cur_vector[ptr]<i){
                    ptr++;
                }
                
            }
        }

    };

    vector<bool> seen(n, false);
    for(int i = 0; i<n; i++){
        if(!seen[find(i)]){
            bfs(i);
        }
    }
    vector<bool> found2(n, false);
    for(int i = 0; i<n; i++){
        if(!found2[find(i)]){
            ans++;
            ans2.push_back(sizes[find(i)]);
        }
    }
    cout<<ans<<'\n';
    for(int i =0; i<ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }
}
