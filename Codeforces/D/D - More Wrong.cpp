#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;

    cin>>n;
    map<array<int, 2>, int> hold;
    auto query = [&](int l, int r) -> int{
        if(r-l<=1){
            return 0;
        }
        if(hold.find({l,r}) != hold.end()) return hold[{l,r}];
        cout<<"?"<<" "<<l+1<<" "<< r<<endl;
        int n;
        cin>>n;
        return hold[{l,r}] = n;
    };
    auto bigger = [&](int x, int y) -> int{
        //if both 0 then its
        //1 and 1 then we know that y+1>x
        int t = query(x, y);
        int z = query(x, y+1);
        return t == z;
    };

    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        ans[i] =i;
    }
    while(ans.size()>1){
        int m = n;
        int z = -1;
        for(int i = 0; i<int(ans.size())-1 ;i++){
            if(ans[i+1]-ans[i]<m){
                m = ans[i+1] - ans[i];
                z = i;
            }
        }
        int t = bigger(ans[z], ans[z+1]);
        ans.erase(ans.begin()+z+!t);
    }
    cout<<"! "<<ans.front()+1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
