#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<int>> needed(n, vector<int>(m));
        int mon1 = 0, mon2 = 0;
        for(int i = 0 ;i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        for(int i = 0 ;i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>needed[i][j];
                if(needed[i][j] == 1?mon1+=grid[i][j]: mon2+=grid[i][j]);
            }
        }
        
    }
}
