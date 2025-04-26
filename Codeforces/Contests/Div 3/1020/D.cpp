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
    int n,m;
    cin>>n>>m;
    int start = 0;
    vector<int> a(n);
    vector<int> b(m);
    for(int &i : a) cin>>i;
    for(int &i : b) cin>>i;

    vector<int> pref(m,INT_MAX);
    vector<int> suff(m,INT_MAX);
    int ptr = 0;
    for(int i = 0; i<n; i++){
        if(ptr<m && a[i] >= b[ptr]){
            pref[ptr] = i;
            ptr++;
        }
        if(ptr == m){
            cout<<0<<endl;
            return;
        }
    }

    int ptr2 = m-1;
    for(int i = n-1; i>=0; i--){
        if(ptr2>=0 && a[i]>=b[ptr2]){
            suff[ptr2] = i;
            ptr2--;
        }
        if(ptr < 0){
            cout<<0<<endl;
            return;
        }
    }
    int ans = INT_MAX;
    if(suff[0] == INT_MAX && suff[1] != INT_MAX){
        ans = min(ans, b[0]);
    }
    if(pref[m-2] !=INT_MAX && pref[m-1] == INT_MAX){
        ans = min(ans, b[m-1]);
    }

    for(int i = 1; i<m-1; i++){
        if(pref[i-1] == INT_MAX || suff[i+1] == INT_MAX){
            continue;
        }
        if(pref[i-1] < suff[i+1]){
            ans = min(ans, b[i]);
        }
    }
    cout<<(ans == INT_MAX?-1:ans)<<endl;

    //we can choose to ignore either of the ones within the array


    //the backs must not touch so

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
