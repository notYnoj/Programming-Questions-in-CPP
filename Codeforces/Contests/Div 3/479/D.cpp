#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> dfs(ll node, map<ll, ll> mp, ll z, vector<ll>cur){
    if(z == 0){
        return cur;
    }
    //behind can either be *3 or /2
    ll pos1 = node*3;
    ll pos2 = node/2;
    vector<ll> a;
    vector<ll> b;
    if(mp[pos1]>0){
        mp[pos1]--;
        cur.push_back(pos1);
        a = dfs(pos1, mp, z-1, cur);
        mp[pos1]++;
        cur.pop_back();
    }
    if(mp[pos2]>0){
        mp[pos2]--;
        cur.push_back(pos2);
        a = dfs(pos2, mp, z-1, cur);
        mp[pos2]++;
        cur.pop_back();
    }
    return (a.empty()? b: a);
}
int main(){
    ll n;
    cin>>n;
    map<ll ,ll> mp;

    for(ll i = 0; i<n; i++){
        ll a;
        cin>>a;
        mp[a]++;
    }
    ll root = 0;
    for(auto i: mp){
        if(mp.find(i.first*2LL) == mp.end() && mp.find((i.first%3LL==0?i.first:-3LL)/3LL) ==mp.end()){
            root = i.first;
            break;
        }
    }

    vector<ll> a = dfs(root, mp, n-1, {root});

    for(ll i = n-1; i>=0; i--){
        cout<<a[i]<<" ";
    }
}
