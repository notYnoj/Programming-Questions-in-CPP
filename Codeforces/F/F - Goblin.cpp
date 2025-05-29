#include <bits/stdc++.h>
#define ll long long
using namespace std;
class DSU{
public:
    vector<ll> size;
    vector<ll> parent;
    DSU(int n){
        size.resize(n);
        parent.resize(n);
        for(ll i = 0; i<n; i++){
            size[i] = 1LL;
            parent[i] = i;
        }
    }
    int find(int x){
        return(parent[x] == x? x: parent[x] = find(x));
    }
    void merge(ll x, ll y){
        ll xp = find(x);
        ll yp = find(y);
        if(x>y){
            swap(x,y);
        }
        size[xp] += size[yp];
        parent[yp] = parent[xp];
    }
};

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    //110
    //000
    //011
    vector<vector<int>> dp(n, vector<int>(3,0));
    if(s[0] == '0'){
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = n-1;
    }else{
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 0;
    }
    for(int i = 1; i<n; i++){
        if(s[i] == '0'){
            dp[i][0] = i;
            dp[i][1] = 0;
            dp[i][2] = n-1-i;
            dp[i][0]+= (dp[i-1][0] + dp[i-1][1]); //at this point i can everything above and on
            dp[i][1] = 0; //at this point i can get nothing since i cant go from here
            dp[i][2] += dp[i-1][2]; //i can just get everything underneatht he previous one too
        }else{
            dp[i][0] = 0;
            dp[i][1] = 1;
            dp[i][2] = 0;
            dp[i][1] += (dp[i-1][2]);
 // i can everything below i-1 (since i-1 is higher), nothing else
        }
    }
  
    //01
    //10
    //above below?
    //000(what does this have access to) 1 0000 (what does this have access to)
    //11 0 111 (this only has access to the below of the previous one)
    //above has access to the above of previous 0
    //below has access to below of previous number
    //

    //have access: some n numbers at 
    // at every 0 we get an additional 
    //1010010
    //0110010
    //0000010
    //0011010
    //0010110
    //0010000
    //0010011
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
