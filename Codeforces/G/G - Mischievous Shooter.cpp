#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int cases;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    bool t = false;
    int ncopy = n;
    int mcopy = m;
    if(n>m){
        //make n the smaller one, n rows and m cols
        swap(n,m);
        t = true;

    }
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i<ncopy; i++){
        for(int j = 0; j<mcopy; j++){
            char c;
            cin>>c;
            if (t) grid[j][i] += c=='#';
            else grid[i][j] += c=='#';

        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 1; j<m; j++){
            grid[i][j] += grid[i][j-1];
        }
    }
    //at each point calculate the max based on for directions
    //now that we have them all at thsi point we can js use manahttem shi
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int cur = 0;
            //calculate right down
            for(int z = 0; i+z<n && z<=k; z++){
                cur+=grid[i+z][min(j+k-z,m-1)] - (j? grid[i+z][j-1] :0);
            }
            ans = max(cur, ans);
            cur = 0;
            //now right up
            for(int z = 0; i-z>=0 && z<=k; z++){
                cur+=grid[i-z][min(j+k-z,m-1)] - (j? grid[i-z][j-1] :0);
            }
            ans = max(cur, ans);
            cur = 0;
            //left down
            for(int z = 0; i+z<n && z<=k; z++){
                int x = i+z;
                cur+= grid[x][j] - (j-k+z-1>=0? grid[x][j-k+z-1]:0);
            }
            ans = max(cur, ans);
            cur = 0;
            //and left up
            for(int z = 0; i-z>=0 && z<=k; z++){
                cur+=grid[i-z][j] - (j-k+z-1>=0? grid[i-z][j-k+z-1] : 0);
            }
            ans = max(ans, cur);

        }
    }
    cout<<ans<<"\n";

}
int main() {
    fastio //im scared tle without this lol
    cin>>cases;
    while(cases--){
        solve();
    }
}
