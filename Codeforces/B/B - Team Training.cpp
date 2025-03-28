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
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    //is there any time i want to add an extra member to a team, no?
    int team = 0;
    int totz = 1;
    for(int i = n-1; i>=0; i--){
        if(arr[i]*totz>=x){
            team++;
            totz = 1;
        }else{
            totz++;
        }
    }
    cout<<team<<'\n';
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
