
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count = 0;
    int pref = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '1'){
            pref++;
        }
    }
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '0'){
            count++;
        }else{
            count--;
        }
        count+=pref;
    }
    cout<<count<<'\n';
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
