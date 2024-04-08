#include <bits/stdc++.h>
using namespace std;
const int mxN = 6e6;
vector<int> a[mxN], b[mxN];
int in[mxN], out[mxN];
int ans = 0;
int k = 0;
void dfs2(int u, int parent){
  //jsut brute force it
  //this is a a in[u] and then when it goes out
    in[u] = k;
    k++;
    for(int i: b[u]){
        if(i!=parent){
            dfs2(i, u);
        }
    }
    out[u] = k;
    k++;
}
set<pair<int, int>> s;
//u is a parent (ancestor) of v
bool checked(const pair<int, int>& u, const pair<int, int>& v){
    return u.first<=v.first && v.second<=u.second;
}
void dfs(int u, int parent){
  //check if there is some that can be an ancestor
    pair<int, int> me = {in[u], out[u]};
    pair<int, int> to_remove = {-1,-1};
    bool bad = false;
    auto it = s.lower_bound(make_pair(in[u], INT_MIN));
 
    if(it != s.end() && checked(me, *it)){
        bad = true;
    }
    if(it!=s.begin() && checked(*prev(it), me)){
        to_remove = *prev(it);
    }
    if(!bad){
        if(to_remove.first != -1){
            s.erase(to_remove);
        }
        s.insert(me);
        ans = max(ans, (int)s.size());
    }
    for(int i: a[u]){
        if(i != parent){
            dfs(i, u);
        }
    }
    if(!bad){
        if(to_remove.first != -1){
            s.insert(to_remove);
        }
        s.erase(me);
    }
 
}
void solve(){
    int n;
    cin>>n;
    for(int i = 2; i<=n; i++){
        int x;
        cin>>x;
        a[x].push_back(i);
    }
    for(int i = 2; i<=n; i++){
        int x;
        cin>>x;
        b[x].push_back(i);
    }
    dfs2(1, -1);
    dfs(1, -1);
    for(int i = 0 ;i<=n ; i++){
        a[i].clear();
        b[i].clear();
    }
    cout<<ans<<"\n";
    ans = 0;
    k = 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
