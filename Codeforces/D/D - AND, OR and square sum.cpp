#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> hold(n);
    for(int i = 0; i<n; i++) cin>>hold[i];
    vector<vector<int>> digits(n, vector<int>(20));
    sort(hold.begin(), hold.end());
    vector<vector<int>> mp(20);
    for(int i = n-1; i>=0; i--){
        for(int digit = 0; digit<20; digit++){
            if(hold[i]>>digit & 1LL){
                digits[i][digit]++;
                mp[digit].push_back(i);
            }
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int bit = 19; bit>=0; bit--){
            if(digits[i][bit] == 0 && !mp[bit].empty()){
                int cur = mp[bit].back();
                mp[bit].pop_back();
                if(i<cur){
                    continue;
                }
                digits[cur][bit] = 0;
                digits[i][bit] = 1;
            }
        }
    }
    vector<ll> ans(n);
    for(int i =0; i<n; i++){
        for(int digit = 0; digit<20; digit++){
            ans[i] += digits[i][digit]<<digit;
        }
    }
    ll a = 0;
    for(ll i: ans){
        a+=(i*i);
    }
    cout<<a;
}
