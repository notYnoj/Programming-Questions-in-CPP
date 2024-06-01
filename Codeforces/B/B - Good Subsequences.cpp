#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
int dp[maxN];
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    int ans = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        int t = 0;
        for(int j = 2; j*j<=a[i]; j++){
            if(a[i] % j == 0){
                t = max(t, dp[j]);//factors get the max if we place it next to it
                t = max(t, dp[a[i]/j]);
            }
        }
        for(int j = 1; j*j<=a[i]; j++){
            if(a[i] % j == 0){
                dp[j] = max(dp[j], t+1);
                dp[a[i]/j] = max(dp[a[i]/j], t+1);
            }
        }
    }
    cout<<*max_element(dp, dp+maxN);
}
