#include <bits/stdc++.h>
using namespace std;
int nodes, edges;
const int mxN = 3e5+5;
int a[mxN], b[mxN];
struct Node{
    int u,v,w;
    bool operator <(const Node& x ) const{
        return w<x.w;
    }
}graph[mxN];

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin>>nodes>>edges;
    for(int i = 1; i<=edges; i++){
        cin>>graph[i].u>>graph[i].v>>graph[i].w;
    }
    sort(graph+1, graph+edges+1);
    int temp = 1;
    int ans = 0;
    for(int i = 1; i<=edges; i++){
        a[i] = b[graph[i].u];
        if(graph[i].w != graph[i+1].w){
            for(int j = temp; j<=i; j++){
                b[graph[j].v] = max(b[graph[j].v], a[j]+1);
                ans = max(b[graph[j].v], ans);
            }
            temp = i+1;
        }
    }
    cout<<ans;
}

//basically we have a tree make sure its greater, by making sure that graph.[i].w != graph[i+1].w 
//before that tho we make sure to make a[i] equal to the current b[graph[i].u] aka the lenght of the path of the parent
// then when its not equal we say that the child is equal to the max of the childs path and the parents (j) path + 1
//then set temp=i+1 to not make it n^2
//cout ans
