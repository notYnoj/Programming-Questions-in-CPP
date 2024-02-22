#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6+5;
bool a[mxN];
int main() {
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    for(int i = 0; i<n; i++){
        int cur = i+1;
        int p, c;
        cin>>p>>c;
        if(p != -1) {
            graph[p].push_back(cur);
            a[cur] = c;
        }

    }
    vector<int> ans;
    for(int i = 1; i<=n; i++){
      //essentially you can just bfs the children checking if they are all 1 and the og dude is 1 becuase then if all childrne are 1 they will be moved up meaning we dont have to recheck
      //anything (also I love coding during hush and pe the best!) 
        bool trust = true;
        if(!a[i]) {
            trust = false;
        }
        for(int child: graph[i]){
            if(!trust){
                break;
            }
            if(!a[child]){
                trust = false;
            }
        }
        if(trust){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0){
        cout<<-1;
        return 0;
    }
    for(int a: ans){
        cout<<a<<" ";
    }




}
