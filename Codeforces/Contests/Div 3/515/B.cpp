//final time 7:04
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
void solve(){
    map<int, vector<int>> mp;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        int a;
        cin >> a;
        mp[a].push_back(i);
    }
    for(auto i: mp){
        if(i.second.size()<2){
            continue;
        }else{
            if(i.second[i.second.size()-1]-i.second[0]>1) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
