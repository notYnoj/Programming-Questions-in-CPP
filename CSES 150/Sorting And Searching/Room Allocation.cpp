#include<bits/stdc++.h>
using namespace std;
const int mxN = 2e5;
int n;
array<int,3> a[mxN];
int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i][1]>>a[i][0];
        a[i][2] = i;
    }
    sort(a,a+n);
    set<array<int,2>> s;
    int ans[mxN];
    for(int i = 0; i<n; i++){
      //find the first one to give it to if doens't works give them a new room
        auto it = s.lower_bound({a[i][1]});
        if(it!=s.begin()) {
            --it;
            ans[a[i][2]] = (*it)[1];
            s.erase(it);
        }else{
            ans[a[i][2]] = s.size();
        }
        s.insert({a[i][0], ans[a[i][2]]});
    }
    cout<<s.size()<<endl;
    for(int i = 0; i<n; i++){
        cout<<ans[i]+1 << " ";
    }
