#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6+5;
vector<vector<int>> grid(1001, vector<int>(1001));
int n,m;
bool safe(int x, int y, int i, int j){
    if(0<=x && x<i && 0<=y && y<j && grid[x][y]){
        return true;
    }else{
        return false;
    }
}
//dsu in 2d make each cell into an array.
class dsu{
    public:
    vector<int> depth, parent;
    int n;
    dsu(int n)
    {
        depth.resize(n);
        parent.resize(n);
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            depth[i] = grid[i/m][i%m];
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x]=find(parent[x]);
        }

        return parent[x];
    }
    void Union(int x, int y)
    {
        int a = find(x);
        int b = find(y);
        if (a == b)
            return;
        if (depth[a] < depth[b]) {
            parent[a] = b;
            depth[b] += depth[a];
        }
        else if (depth[b] < depth[a]) {
            parent[b] = a;
            depth[a] += depth[b];
        }
        else
        {
            parent[b] = a;
            depth[a] = depth[a] + depth[b];
        }
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        dsu *dus = new dsu(n * m);
        int dx[4] = {0, 0 , 1, -1};
        int dy[4] = {1, -1, 0,0};
        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    continue;
                }else{
                    ans = max(grid[i][j],ans);
                    for(int z = 0; z<4; z++){
                        int nx = i+dx[z];
                        int ny = j +dy[z];
                        if(safe(nx, ny, n, m)){
                            dus->Union(i*m+j, ((nx)*m)+ny);
                        }
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]>0){
                    int x = dus->depth[dus->find(i*m+j)];
                    ans = max(ans, x);
                }
            }
        }
        cout<<ans<<"\n";

    }
}
