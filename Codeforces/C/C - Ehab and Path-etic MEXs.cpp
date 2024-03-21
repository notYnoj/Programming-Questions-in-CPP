#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5+5;
vector<int> graph[mxN];
int u[mxN], v[mxN], ans[mxN];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nodes;
    cin>>nodes;
    for(int i  = 1; i<nodes; i++){
        cin>>u[i]>>v[i], u[i]--, v[i]--;
        graph[u[i]].push_back(i);
        graph[v[i]].push_back(i);
    }
    for(int i = 0; i<nodes; i++){
        if(graph[i].size()<=2){
            continue;
        }
        memset(ans,-1,4*nodes);
        for(int j =0; j<3; j++){
            ans[graph[i][j]] = j;
        }
        for(int k = 1, j = 3; k<nodes; k++){
            if(ans[k]<0){
                ans[k] = j++;
            }
            cout<<ans[k]<<"\n";
        }
        return 0;
    }
    for(int i = 1; i<nodes; i++){
        cout<<i-1<<"\n";
    }
}
//esseintally what we do here is for anyone that is less than equal 2 it is always js gonna be node-1 (check 3)
//otherwise we know that the first point where there is 3 or more that is esseintally where we can "root" our tree to get this 3
//then we find all the other ones and if it is -1 js do -1;
