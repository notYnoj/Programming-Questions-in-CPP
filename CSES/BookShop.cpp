#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
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
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    vector<int> dp(x+1, INT_MIN);
    dp[x] = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j <= x-price[i]; j++){
            dp[j] = max(dp[j], dp[j+price[i]] + pages[i]);
        }

    }

    cout<<*max_element(all(dp));

}
int main(){
    t = 1;
    while(t--){solve();}
    return 0;
}
