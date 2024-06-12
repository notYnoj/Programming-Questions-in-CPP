#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> graph(n+1);
        for(int i = 0; i<m; i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int y_node = 0;
        int y;
        int x = 1;
        for(int i = 1; i<=n; i++){
            if(graph[i].size() == 1){
                y_node = graph[i][0];
                y = (int)graph[y_node].size()-1;
                break;
            }
        }
        for(int child: graph[y_node]){
            x = max((int)graph[child].size(), x);
        }
        cout<<x<<" "<<y<<"\n";
 
    }
}
