#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e9+5;
long long dp[mxn];
int main(){
    memset(dp, 0, sizeof(dp));
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int mn = INT_MAX;
    int mx = 0;
    map<int, vector<int>> mp;
    for(int i = 0; i<n; i++){
        int a = arr[i];
        dp[a] = dp[a-1]+1;
        if(dp[a]>1) {
            vector<int> aaa = mp[a - 1];
            aaa.push_back(a);
            mp[a] = aaa;
        }else{
            mp[a] = {a};
        }
        mn = min(a, mn);
        mx = max(a, mx);
    }
    int t = 0;
    int nod = 0;
    for(int i = mn; i<=mx; i++){
        if(dp[i]>t){
            t = dp[i];
            nod = i;
        }
    }
    cout<<t<<"\n";
    for(int i: mp[nod]){
        cout<<i<<" ";
    }
}
