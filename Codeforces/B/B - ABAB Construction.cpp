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
    //ABABA
    int n;
    string s;
    cin>>n;
    cin>>s;
    //I start with a string of length n where it is -> ABABA...
    //I need to figure out if my given string s can be made from this
    if(s[0] == 'b' && n % 2){
        cout<<"NO"<<endl;
        return;
    }
    //can take only a = 0, take only b = 1, take both 2
    if(s.size()%2)s = s.substr(1, n-1);
    for(int i = 0; i<s.size(); i+=2){
        if(s[i] != '?' && s[i] == s[i+1]){
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

