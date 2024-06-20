//final time 4:36
#include <bits/stdc++.h>
#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pair<ll,ll>>
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int tz = (arr[0]%2);
    for(int i =1; i<n; i++){
        if ((arr[i]%2) != tz){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
