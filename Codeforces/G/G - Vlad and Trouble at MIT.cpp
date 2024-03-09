#include <bits/stdc++.h>
using namespace std;
int cases;
void solve(){
    int vertex;
    cin>>vertex;
    vector<int> graph(vertex+1);
    for(int i = 2; i<=vertex; i++){
        cin>>graph[i];
    }
    string s;
    cin>>s;
    s = "X"+s;
    //csp csp
    vector<vector<int>> dp(vertex+1, vector<int>(2, 0));
    for(int i = vertex; i>=1; i--){
        //dp[i][0] allows music
        //dp[i][1] doesn't allow music
        //
        if(s[i] == 'S'){
            dp[i][1] = 1e5+5;
            //there is no cost of allwoing music here. (there is no music in the first place)_
        }
        if(s[i] == 'P'){
            dp[i][0] = 1e5+5;
            //there is no cost of not allwoing music in this
            //(there is music in the first place)
        }
        dp[graph[i]][0]+=min(dp[i][0], dp[i][1]+1);
        dp[graph[i]][1]+=min(dp[i][1], dp[i][0]+1);
    }
    cout<<min(dp[1][0], dp[1][1])<<"\n";
 
}
int main(){
    cin>>cases;
    while(cases--){
        solve();
    }
}
