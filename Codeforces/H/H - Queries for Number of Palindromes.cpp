#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define nl '\n'
#include <chrono>
using namespace std;
int t;
// Everything Else thats new :D
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T> p){
    os<<p.first<<' '<<p.second<<endl;
    return os;
}
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << ' ';
    }
    return os;
}


template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec){
    //of size n
    for(T& elem: vec){
        is>>elem;
    }
    return is;
}


void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int q;
    cin>>q;
    vvb dp(n, vector<bool>(n, 0));
    for(int i = 0; i<n; i++){
        dp[i][i] = 1;
    }
    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
        }
    }
    for(int len = 3; len<=n; len++){
        for(int l = 0; l <= n-len; l++){
            int r = l + len - 1;
            if(s[l] == s[r]){
                dp[l][r] = dp[l+1][r-1];
            }
        }
    }

    vvi pref(n, vi(n, 0));
    pref[0][0] = dp[0][0];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0) continue;
            else{
                pref[i][j] = dp[i][j] + (i>0 ? pref[i-1][j]: 0) + (j > 0 ? pref[i][j-1] : 0) - (i>0 && j>0 ? pref[i-1][j-1] : 0);
            }
        }
    }
    auto query = [&](int l, int r) -> ll{
        ll ans = 0;
        //add pref[r][r] - pref[l][r] - pref[r][l] + pref[l][l]
        ans = pref[r][r] - (l>0 ? pref[l-1][r] : 0) - (l > 0 ? pref[r][l-1] : 0) + (l>0 ? pref[l-1][l-1] : 0);
        return ans;

    };
    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(l,r)<<nl;
    }
    //for any query we want the rectangle where pref[l][l] down to pref[r][r]
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    t = 1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
