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
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int zero = 3;
    int one = 1;
    int three = 1;
    int two = 2;
    int five = 1;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0 && zero>0){
            zero--;

        }
        if(arr[i] == 1 && one>0){
            one--;
            max(one, 0);
        }
        if(arr[i] == 3 && three>0){
            three--;
            max(three, 0);
        }
        if(arr[i] == 2&& two>0){
            two--;
            max(two, 0);
        }
        if(arr[i] == 5&& five>0){
            five--;
            max(five, 0);
        }
        if(!zero && !one && !three && !two && !five){
            cout<<(i+1)<<'\n';
            return;

        }
    }
    cout<<0<<"\n";
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
