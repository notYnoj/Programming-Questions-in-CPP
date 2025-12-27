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
    string w;
    cin>>w;
    int ans = 0;
    if(w[0] == 'u'){
        ans++;
        w[0] = 's';
    }
    if(*--w.end() == 'u'){
        ans++;
        w[w.size()-1] = 's';
    }
    for(int i = 0; i<w.size()-1; i++){
        if(w[i] == 'u' && w[i+1] != 's'){
            w[i+1] = 's';
            ans++;
        }
    }
    cout<<ans<<endl;
        
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}