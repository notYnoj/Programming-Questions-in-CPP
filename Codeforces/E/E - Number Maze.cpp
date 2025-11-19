#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>

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
vvvi ans(3);
void pre(){
    vvi a = {{1,2}, {1,2,3}, {1,2,3,4}};
    for(int i = 0; i<3; i++){
        do{
            ans[i].pb(a[i]);
        } while(next_permutation(a[i].begin(), a[i].end()));

    }
}

void solve(){
    string n;
    cin>>n;
    int nt,m;
    cin>>nt>>m;
    nt--;
    m--;

    int A = 0;
    int B = 0;
    if(n == "12"){
        string a;
        string b;
        for(int i = 0; i<ans[0][nt].size(); i++){
            a+=to_string(ans[0][nt][i]);
        }
        for(int i = 0; i<ans[0][m].size(); i++){
            b+=to_string(ans[0][m][i]);
        }
        for(int i = 0; i<2; i++){
            if(a[i] == b[i]) A++;
        }
        B = 2-A;
    }else if(n == "123"){
        string a;
        string b;
        for(int i = 0; i<ans[1][nt].size(); i++){
            a+=to_string(ans[1][nt][i]);
        }
        for(int i = 0; i<ans[1][m].size(); i++){
            b+=to_string(ans[1][m][i]);
        }
        for(int i = 0; i<3; i++){
            if(a[i] == b[i]) A++;
        }
        B = 3-A;
    }else{
        string a;
        string b;
        for(int i = 0; i<ans[2][nt].size(); i++){
            a+=to_string(ans[2][nt][i]);
        }
        for(int i = 0; i<ans[2][m].size(); i++){
            b+=to_string(ans[2][m][i]);
        }
        for(int i = 0; i<4; i++){
            if(a[i] == b[i]) A++;
        }
        B = 4-A;
    }
    cout<<A<<"A"<<B<<"B"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t;
    cin>>t;
    while(t--) solve();
}
