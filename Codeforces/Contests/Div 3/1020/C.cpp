
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    vector<int> b(n);
    for(auto&i : a) cin>>i;
    for(auto& i : b) cin>>i;
    if (all_of(b.begin(), b.end(), [](int i) { return i == -1; })) {
        int mn = *min_element(all(a));
        int mx = *max_element(all(a));
        // mx<=t<=mn+x
        int amnt = mn+x-mx+1;
        cout<<max(0, amnt)<<endl;
    }else{
        int tz = 0;
        for(int i = 0; i<n; i++){
            if(b[i] != -1){
                tz = a[i] + b[i];
                break;
            }
        }
        for(int i = 0; i<n; i++){
            if(b[i] == -1){
                int needed = tz - a[i];
                if(needed>x || needed<0){
                    cout<<0<<endl;
                    return;
                }
            }else{
                if(tz != (a[i] + b[i])){
                    cout<<0<<endl;
                    return;
                }
            }
        }
        cout<<1<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
