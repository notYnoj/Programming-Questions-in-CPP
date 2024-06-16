//i wasnt able to get this during the contest time!
//this was a really tricky parity question that I wasn't able to think about!
//i was thinking abt somehow using dsu to find the ones connected in a "bunch" then if its in a bunch ignore it 
//but how do we find where we should bunch :( for example if we have a node connected by 1-1-3, we coudlc onnected the first node and it connected 1-1 however the 3 children of the second 1 would each get 1 which would not work for n/2
//make sure to remmeber n/2 is parity of up to n (if ends on even its equal if ends on odd even = n/2 odd = n/2+1 but still falls in n/2 so were good!) 
#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+5;
vector<vector<int>> graph(mxN);
int visited[mxN];
vector<int> evens, odds;
void bfs(int p, int u){
    queue<pair<int,int>> q;
    q.push({p,u});
    int i = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        visited[cur.first] = true;
        if(cur.second%2) {
            odds.push_back(cur.first);
        }
        else {
            evens.push_back(cur.first);

        }
        for(int z: graph[cur.first]){
            if(!visited[z]){
                q.push({z,cur.second+1});
                visited[z] = true;
            }
        }
    }
}
void solve(){
    int n, m;
    cin>>n>>m;
    for(int i =1; i<=n; i++) visited[i] = false;
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1,0);
    if(odds.size()>evens.size()){
        cout<<evens.size()<<"\n";
        for(int i = 0; i<evens.size(); i++){
            cout<<evens[i]<<" ";
        }
    }else{
        cout<<odds.size()<<"\n";
        for(int i = 0; i<odds.size(); i++){
            cout<<odds[i]<<" ";
        }
    }
    odds.clear();
    evens.clear();
    for(int i = 1; i<=n; i++){
        graph[i].clear();
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    //chose current node + parent(s) + child or current node + child and children
    //
}
