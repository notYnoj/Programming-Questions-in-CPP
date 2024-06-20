//final time was 1:35 and then I went to go shower
//Will update with F.cpp when i finish it later today! (after starbucks interview! lets hope i get it)
#include <bits/stdc++.h>
#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pair<ll,ll>>
using namespace std;
const int mxN = 2024;
int arr[mxN];
int l,r;
bool good(int x){
    return l<=x && x<=r; //check if we add 1 cuz its good
}
int main(){
    int n,h;
    cin>>n>>h>>l>>r;
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));
    dp[0][0] = 0;
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+= arr[i];
      //classic dp question 
      //twist is j is a little hard to find
      //j is how many times weve used the -1
      //thus we can find the current hour and check if thats good (depending on how many -1 weve done) (since time is always going to be added by every a[i]
      //we can find the sum and then js subtract by all possible j (and then mod becuz its days) and then dp from there!
        for(int j = 0; j<=n; j++){
          if(j>i){
            break; //we cant have more j
          }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + good((sum-j)%h)); //dont use 1 for the current one
            if(j<n){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + good((sum-j-1)%h)); //use 1 for the current 1
            }
        }
    }
    cout<<*max_element(dp[n].begin(), dp[n].end());
}
