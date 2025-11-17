#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvs vector<vector<string>>
#define vs vector<string>


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
    //so for each one we have a path of like 2n+2k where n,k are some integers. you can also just do like n*k becuase everything inside cant be good
    //we simply can't make 1 contianing ones. Everything else is doable tho (as long as we don't go to that)
    int n,k;
    cin>>n>>k;
    vvs ans(n, vs(n, "DNE"));
    int need = n*n-k;
    if(need == 1){
        cout<<"No\n";
        return;
    }
    //inf loop;
    if(need == 0){
        for(int i = 0; i<n; i++){
            for(int j= 0; j<n; j++){
                if(ans[i][j] == "DNE"){
                    ans[i][j] = "D";
                }
            }
        }
        cout<<"Yes\n";
        for(auto& row: ans){
            for(auto& i: row){
                cout<<i;
            }
            cout<<"\n";
        }
        return;
    }
    ans[0][0] = "R";
    ans[0][1] = "L";
    need-=2;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(need == 0){
                break;
            }else{
                if(ans[i][j] == "DNE"){
                    if(i == 0){
                        ans[i][j] = "L";
                    }else{
                        ans[i][j] = "U";
                    }
                    need--;
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j= 0; j<n; j++){
            if(ans[i][j] == "DNE"){
                ans[i][j] = "D";
            }
        }
    }
    cout<<"Yes\n";
    for(auto& row: ans){
        for(auto& i: row){
            cout<<i;
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
