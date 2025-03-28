//github: https://github.com/notYnoj
#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
void solve(){
    int n;
    cin>>n;
    //if it has a cyclic shift
    /* for there to be a cyclic shift some number + a shift number = its original number
     * 1 2 3 4 5
     * 1 3 5 2 4
     */
    if(n%2 == 0){
        cout<< -1<<"\n";
        return;
    }
    vector<int> ans(n);
    int plays = 0;
    for(int i = 0; i<n; i++){
        ans[i] = (i+1 + plays++) % n;
        if(ans[i] == 0){
            ans[i] = n;
        }
    }
    cout<<ans<<'\n';
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
