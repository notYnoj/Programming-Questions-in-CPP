#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;
    
namespace IO {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        for (const auto& elem : vec) {
            os << elem<<" ";
        }
        return os;
    }
}
using namespace IO;

int main(){
    int n,k,q;
    string s;
    cin>>n>>k>>s>>q;
    vi ans(n+1, 0);
    vvi dp(n+2, vi(k, n));
    
    for(int i = n-1; i>=0; i--){
        dp[i] = dp[i+1]; //i wnat to make sure that at any point afterwards i always go to the left mostest
         //update to have the left most pos 
        int mx = *max_element(dp[i].begin(), dp[i].end()); //best way to get there is thru this
        ans[i] = 1+ans[mx]; //add 1 to that
        dp[i][s[i]-'a'] = i;
    }
    
    while(q--){
        string a;
        cin>>a;
        int p = -1;
        for(int i = 0; i<a.size(); i++){
            p = dp[p+1][a[i]-'a'];
        }
        cout<<ans[p]<<endl;
    }
}
