#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> dp(n), a(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
    dp[n-1] = a[n-1];
    for(int i = n-2; i>= 0; i--){
        if(i+a[i]>=n) dp[i] = a[i];
        else dp[i] = a[i]+dp[i+a[i]];
    }

    cout<<*max_element(dp.begin(), dp.end())<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}
