#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<ll> arr(n);
    vector<ll>sum(n+1);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        sum[i+1] = sum[i] + arr[i];
    }
    vector<vector<ll>> dp(k+1, vector<ll> (n+1, 0));
    for(int i = 1; i<k+1; i++){
        for(int j = 1; j<n+1; j++){
            int len = i*m;
            if (len <= j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + sum[j] - sum[j - m]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
 
    cout << dp[k][n];
}

/*
Initial Wrong Solution TLE (USE PREFIX SUM<- hurt the time by alot LOL AND LOOPS):

#include <bits/stdc++.h>
using namespace std;
int n, y, z;
//So basically you are given an array of integers (n) and you can have at most y integeres with z pairs and u try to maximize the sum of these
int dfs(const vector<int>& nums, int pos, int pairs, map<pair<int, int>, int> memo){
    if(pos>=nums.size()-y+1 || pairs == 0){
        return 0;
    }
    if(memo.find({pos, pairs}) != memo.end()){
        return memo[{pos, pairs}];
    }
    int include = 0;
    int exclude = dfs(nums, pos+1, pairs, memo);
    for(int i = 0; i<y; i++){
        if (pos + i < nums.size()) {
            include += nums[pos + i];
        }
    }
    include+= dfs(nums, pos+y, pairs-1, memo);
    int res = max(include, exclude);
    memo[{pos, pairs}] = res;
    return res;
}
int main() {
    cin>>n>>y>>z;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    map<pair<int, int>, int> memo;
    int g = dfs(nums, 0, z, memo);
    cout<<g;
}

*/
