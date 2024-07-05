#include <bits/stdc++.h>
using namespace std;
const int mxN = 2505;
int dsu[mxN], found[mxN];
int find(int a){
    if(dsu[a] == a){
        return a;
    }else{
        return dsu[a] = find(dsu[a]);
    }
}
void combine(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x<y){
        dsu[y] = x;
    }else{
        dsu[x] = y;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i =0 ; i<n*m; i++){
        dsu[i] = i;
        found[i] = 0;
    }
    vector<vector<char>> grid(n, vector<char> (m));
    bool check = false;
    bool check2 = false;
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'G'){
                check = true;
            }
            if(grid[i][j] == 'B'){
                check2 = true;
            }
        }
    }
    if(check&&(grid[n-1][m-1] == 'B' || (n>1 && grid[n-2][m-1] == 'B') ||( m>1&& grid[n-1][m-2] == 'B') || (m>1 && n>1 && grid[n-2][m-2] == 'B'))){
        cout<<"NO\n";
        return;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'G'){
                if(i+1<n){
                    if(grid[i+1][j] == 'B'){

                        cout<<"NO\n";
                        return;
                    }
                    if(grid[i+1][j] == 'G'){
                        combine(((i+1)*m+j), (i*m+j));
                    }
                }
                if(i-1>=0){
                    if(grid[i-1][j] == 'B'){

                        cout<<"NO\n";
                        return;
                    }
                    if(grid[i-1][j] == 'G'){
                        combine(((i-1)*m+j), (i*m+j));
                    }
                }
                if(j+1<m){
                    if(grid[i][j+1] == 'B'){

                        cout<<"NO\n";
                        return;
                    }
                    if(grid[i][j+1] == 'G'){
                        combine(((i)*m+j+1), (i*m+j));
                    }
                }
                if(j-1>=0){
                    if(grid[i][j-1] == 'B'){

                        cout<<"NO\n";
                        return;
                    }
                    if(grid[i][j-1] == 'G'){
                        combine(((i)*m+j-1), (i*m+j));
                    }
                }
            }
            if(grid[i][j] == 'B'){
                if(i+1<n){
                    if(grid[i+1][j] == 'G'){ cout<<"NO\n";  return;}
                    if(grid[i+1][j] != 'B') grid[i+1][j] = '#';;

                }
                if(j+1<m){
                    if(grid[i][j+1] == 'G'){ cout<<"NO\n";  return;}
                    if(grid[i][j+1] != 'B') grid[i][j+1] = '#';;

                }
                if(i-1>=0){
                    if(grid[i-1][j] == 'G'){ cout<<"NO\n"; return;}
                    if(grid[i-1][j] != 'B') grid[i-1][j] = '#';;

                }
                if(j-1>=0){
                    if(grid[i][j-1] == 'G'){ cout<<"NO\n";
                        return;}
                    if(grid[i][j-1] != 'B') grid[i][j-1] = '#';;
                }
            }
        }
    }

    auto bfs = [&](int start) -> bool {
        queue<pair<int, int>> q;
        int y = start % m;
        int x = start / m;
        q.push({x, y});
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[x][y] = true;

        while (!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            if (currX == n-1 && currY == m-1) return true;

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                    !visited[newX][newY] && grid[newX][newY] != '#'){
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                    found[find(newX*m + newY)] = 1;
                }
            }
        }

        return false;
    };
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(grid[i][j] == 'G' && !found[find((i*m+j))]){
                if(!bfs(find(i*m+j))){

                    cout<<"NO\n";
                    return;
                }
                found[find(i*m+j)] = 1;
            }
        }
    }
    cout<<"YES\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
