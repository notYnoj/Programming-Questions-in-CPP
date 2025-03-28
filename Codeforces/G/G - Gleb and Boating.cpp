#include <bits/stdc++.h>
using namespace std;
void solve(){
    int s,k;
    cin>>s>>k;
    if(s%k == 0){
        cout<<k<<'\n';
        return;
    }
    if(s>k*k){
        cout<<max(1, k-2)<<'\n';
        return;
    }
    //otherwise we don't know so let's do dp and jsut find until its good
    //it has to be under k*k
    vector<bool> dp(s+1, false);
    dp[0] = 1;
    bool dir = true;
    //true is forward
    for(int i = k; i>=1; i--){
        vector<bool> ndp(s+1, false);
        if(dir){
            for(int j = i; j<=s; j++){
                ndp[j] = dp[j-i] | ndp[j-i];
            }
            dir = false;

        }else{
            for(int j = s-i; j>=0; j--){
                ndp[j] = dp[j+i] | ndp[j+i];
            }
            dir = true;
        }
        dp = ndp;
        if(dp[s]){
            cout<<i<<'\n';
            return;
        }
    }
    cout<<1<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
