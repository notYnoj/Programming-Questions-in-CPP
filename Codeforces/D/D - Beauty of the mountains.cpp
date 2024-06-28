#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<int>> needed(n, vector<int>(m));
        int mon1 = 0, mon2 = 0;
        for(int i = 0;i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        for(int i = 0 ;i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>needed[i][j];
                needed[i][j] == 1?mon1+=grid[i][j]: mon2+=grid[i][j];
            }
        }
        if(k == 1 || mon1 == mon2) cout<<"YES\n";
        else{
            //kxk -check, check will be for wihtout them, with them will be kxk-check
            set<int> check;
            vector<vector<int>> pref(n, vector<int>(m, 0));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    pref[i][j] = needed[i][j];
                    if(i>0){
                        pref[i][j]+=pref[i-1][j];
                    }
                    if(j>0){
                        pref[i][j]+=pref[i][j-1];
                    }
                    if(i>0 && j>0){
                        pref[i][j] -= pref[i-1][j-1];
                    }
                }
            }
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    cout<<pref[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
    }
}
