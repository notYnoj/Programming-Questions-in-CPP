#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
using namespace std;
    
// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
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
    int n;
    cin>>n; 
    //a is the integer array, b is the cost
    vi a(n), b(n);
    cin>>a;
    cin>>b;

    map<ll, ll> dp;
    /*We want a to not have any decreasing places. That is we Want for all ai 0<=i<n ai<=ai+1
      But we also want to minimze the cost of this. The cost to change a number within the vector is equal to b[i]
      This is equivalent to finding the heaviest increasing subsequence t (since total price s (sum(b)) - t = min we have to change)
      To do this we notice how the cost of changing a sequence ending at a pos v can cost a
      so like subsequence ending at v = max cost a
      to add on to this we want to find such that
      v < a[i] then add a+b[i]
      Then for any things in this if a[i] < vi.first and a+b[i] > vi.second we can delete vi since it will always be favorable to take a[i] (smaller ending point and more weight)
      */
    dp[0] = 0LL;
    dp[a[0]] = b[0];
    for(int i = 1; i<n; i++){
        ll cur = a[i];
        auto tz = dp.lower_bound(cur);
        if(tz != dp.end() && tz->first == cur){
            dp[cur] = tz->second + b[i];
        }else{
            --tz; //find the next lowest element =
            ll bz = tz->second + b[i];
            dp[cur] = bz;
        }
        ll temp = dp[cur];
        auto it = dp.find(cur);
        while(it != dp.end()){
            if(it->first != cur && it->second <= temp){
                it = dp.erase(it);
            } else {
                it++;
            }
        }
    }
    ll mxSum = 0;
    for(auto it = dp.begin(); it != dp.end(); it++){
        mxSum = max(mxSum, it -> second);
    }
    cout<< accumulate(b.begin(), b.end(), 0LL) - mxSum << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
