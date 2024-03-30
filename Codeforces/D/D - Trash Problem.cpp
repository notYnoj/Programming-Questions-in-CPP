#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin>>n>>q;
    set<ll> piles;
    multiset<ll> distances;
    auto add = [&](ll x){
        auto i = piles.insert(x);
        auto it = i.first;
        if(next(it) != piles.end() && it != piles.begin()){
            distances.erase(distances.find(*next(it) - *prev(it)));
        }
        if(next(it) != piles.end()){
            distances.insert(*next(it) - *it);
        }
        if(it != piles.begin()){
            distances.insert(*it - *prev(it));
        }
    };
    auto del = [&](ll x){
        auto it = piles.find(x);
        if(next(it) != piles.end()){
            distances.erase(distances.find(*next(it) - *it));
        }
        if(it != piles.begin()){
            distances.erase(distances.find(*it - *prev(it)));
        }
        if(next(it) != piles.end() && it != piles.begin()){
            distances.insert(*next(it) - *prev(it));
        }
        piles.erase(x);
    };
    for(int i = 0; i<n; i++){
        ll x;
        cin>>x;
        add(x);
    }
    if(distances.empty()){
        cout<<0<<"\n";
    }else {
        ll temp = *prev(piles.end()) - *piles.begin() - *prev(distances.end());
        cout << temp << "\n";
    }
    for(int i = 0; i<q; i++){
        ll x, b;
        cin>>b>>x;
        if(b){
            add(x);
        }else{
            del(x);
        }
        if(distances.empty()){
            cout<<0<<"\n";
        }else {
            ll ans = *prev(piles.end()) - *piles.begin() - *prev(distances.end());
            cout << ans << "\n";
        }
    }
}
