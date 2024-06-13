#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> mp;
    vector<int> dp(n, 0);
    dp[0] = 1;
    mp[arr[0]] = 1;
    int s = arr[0];
    for (int i = 1; i < n; i++) {
        int a = arr[i];
        mp[a] = mp[a-1]+1;
        if(dp[i-1]<mp[a]){
            s =a;
            dp[i] = mp[a];
        }else{
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n - 1] << "\n";
    vector<int> at;
    for(int i = 0; i<n; i++){
        if(arr[i] == s-dp[n-1]+1){
            at.push_back(i+1);
            s++;
        }
    }
    for (int i: at) {
        cout << i << " ";
    }
}
