#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_BITS = 30;
int main(){
    map<pair<ll, ll>, ll> mp;
    auto query = [&](ll a, ll b, int t) -> ll{
        if(t == 1){
            swap(a,b);
        }
        if(mp.find({a,b}) != mp.end()){
            return mp[{a,b}];
        }
        if(a>b){
            swap(a,b);
        }

        cout<<"? "<<a<<' '<<b;
        ll x;
        cin>>x;
        if(x == -2){
            exit(0);
        }
        mp[{a,b}] = x;
        fflush(stdout);
        return x;
    };
    int t = query(0, 0, -2);
    if(t == 0){
        vector<ll> number(30, 0);
        for(int i = 0; i<MAX_BITS; i++){
            ll z = query(1<<i, 0, 0);
            if(z == -1){
                number[i] = 1;
            }else{
                number[i] = 0;
            }
        }
        ll ans = 0;
        for(int i = 0; i<MAX_BITS; i++){
            ans+=number[i]<<i;
        }
        cout<<"! "<<ans<<' '<<ans;
        fflush(stdout);
    }else{
        vector<int> smaller(30);
        vector<int> bigger(30);
        //a is small b is big
        //my logic -> if at any point you get 0 previous bits remain, do the t==0 stuff
      //if == 1 (smaller becomes bigger)
      //check other if bigger is smaller 0,1 (small,big)
      //else if bigger bigger 0,0


      //else 
      //if bigger smaller 1 1
      //else bigger bigger 1 0

    }
}
