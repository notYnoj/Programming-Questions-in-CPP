#include <bits/stdc++.h>
using namespace std;
const int mxN = 1006;
bool v[mxN];
int ans[mxN], started[mxN];
vector<int> snitch(mxN);
int node = -1;
//if i were to remember anything from this exercise is that nodes can be pointed to by mutliple nodes! it isnt js a straight line
//after realizing this solving was simple tho i got a WA because i didnt realize this
void dfs(int u, int& start){
    v[u] = true;
    int next = snitch[u];
    if(v[next]){
        start = next;
        if(ans[next]>0){
            start = ans[next];
            ans[u] = start;
            return;
        }else{
            node = next;
            ans[u] = u;
            return;
        }
    }else{
        dfs(next, start);
        if(u == node){
            node = -1;
        }
        if(node == -1){
            ans[u] = start;
        }else{
            ans[u] = u;
        }
    }
}

int main(){
    int n;
    cin>>n;

    for(int i = 1; i<=n; i++){
        cin>>snitch[i];
        ans[i] = INT_MIN;
    }

    for(int i = 1; i<=n; i++) {
        int z= -1;
        if(!v[i]) dfs(i, z);
        node = -1;
    }
    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<' ';
    }

}
