#include <bits/stdc++.h>
using namespace std;
int t;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> grid (n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char a;
            cin>>a;
            a=='0'?grid[i][j] = 0: grid[i][j] = 1;
        }
    }
    string s;
    bool check = true;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == 1){
              //if u ever get to a 1, theres always gonna be a triangle or nah check the conditions given for a triangle
                if(i+1<n&&grid[i+1][j] == 1) {
                    if (j - 1 >= 0 && grid[i + 1][j - 1]) {
                        s = "TRIANGLE";
                    } else {
                        s = "SQUARE";
                    }
                }else{
                    s = "TRIANGLE";
                }
            }
            if(s == "TRIANGLE" || s == "SQUARE"){
                check = false;
                break;
            }
        }
        if(!check){
            break;
        }
    }
    cout<<s<<"\n";
}
int main(){
    cin>>t;
    while(t--){
        solve();
    }
}
