#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> rows(n);
    vector<int> score(m+1, 0);
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        int cos = 0;
        int a = 0;
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]){
                a++;
            }else{
                cos = max(cos, a);
                a = 0;
            }
        }
        cos = max(a, cos);
        rows[i] = cos;
        score[cos]++;
    }
    int mx = 0;
    for(int i = m; i>=0; i--){
        if(score[i]){
            mx = i;
            break;
        }
    }
    for(int i = 0; i<q; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        grid[a][b] = (grid[a][b]?0:1);
        int temp = 0, cos = 0;
        for(int j = 0 ; j<m; j++){
            if(grid[a][j]){
               temp++;
            }else{
                cos = max(cos, temp);
                temp = 0;
            }
        }
        cos = max(cos, temp);
        score[rows[a]]--;
        rows[a] = cos;
        score[rows[a]]++;
        if(score[mx]){
            mx = max(mx, rows[a]);
        }else{
            if(rows[a]>mx){
                mx = rows[a];
            }else {
                for (int k = mx-1; k>=0; k--){
                    if(score[k]){
                        mx = k;
                        break;
                    }
                }
            }
        }
        cout<<mx<<"\n";
    }

}
