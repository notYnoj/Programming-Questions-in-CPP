#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> grid(4, vector<bool>(4, false));
vector<pair<int, int>> ans;
void solve_col(){
    if(grid[0][0]){
        ans.push_back({3,1});
        grid[0][0] = false;
    }else{
        ans.push_back({1,1});
        grid[0][0] = true;
    }
}
void solve_row(){
    int check = true;
    for(int i = 0; i<3; i++){
        if(!grid[i][2]){
            check = false;
            grid[i][2] = true;
            ans.push_back({i+1,3});
            break;
        }
    }
    if(check){
        for(int i = 0; i<4; i++){
            grid[i][2] = false;
        }
        ans.push_back({4,3});
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '0'){
            solve_col();
        }else{
            solve_row();
        }
    }
    for(auto i: ans){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}
