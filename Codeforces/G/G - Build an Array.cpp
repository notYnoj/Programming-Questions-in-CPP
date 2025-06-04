#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
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
/*namespace IO {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        for (const auto& elem : vec) {
            os << elem << " ";
        }
        return os;
    }
}
using namespace IO;
//for macos^^
*/


void solve(){
    int n, k;
    cin>>n>>k;
    vi a(n);
    vi b(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    for(int i = 0; i<n; i++){
        while(!(b[i] & 1)){
            b[i]>>=1;
        }
    }

    //we can find the ops starting at the left and at the right
    auto ops = [&](int index, int neighbor) -> ll{
        if(neighbor == -1){
            return a[index]/b[index];
        }
        ll psb = a[index]/b[index];
        if(b[neighbor] == b[index]){
            if(a[index]>a[neighbor]){
                psb-=(2*a[neighbor]/b[neighbor]);
                psb++;
            }
            return psb;
        }else{
            return psb;
        }

    };
    //2 1 4 
    //4 + 
    vi pref(n+1, 0);
    vi suff(n+1, 0);
    for(int i = 0; i<n-1; i++){
        pref[i+1] = pref[i] + ops(i, i+1);
    }
    for(int i = n-1; i>0; i--){
        suff[i-1] = suff[i] + ops(i, i-1); 
    }
   

    for(int i = 0; i<n; i++){

        ll psb2 = ops(i, -1) + suff[i] + pref[i];
        if(psb2>=k){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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
