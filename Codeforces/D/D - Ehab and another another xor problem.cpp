```cpp
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
        if(t == 1){
            (x==1?x = -1:x=1);
        }
        mp[{a,b}] = x;
        fflush(stdout);

        return x;
    };
    int t = query(0, 0, -2);
    if(t == 0){
        vector<ll> number(30, 0);
        ll new1 = 0;
        for(int i = 0; i<MAX_BITS; i++){
            //thats why my spidey senses were going off lol i knew somethign was wrong here
            ll z = query((new1+(1LL<<i)), new1, 0);
            if(z == -1){
                number[i] = 1;
                new1+=1LL<<i;
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
        return 0;
    }else{
        vector<ll> smaller(30);
        vector<ll> bigger(30);
        for(int bit = 29; bit>=0; bit--){
            ll cur_sum = 0;
            ll cur_bigger_sum = 0;
            for(ll i = 29; i>bit; i--){
                cur_sum+=(smaller[i]<<i);
                cur_bigger_sum+=(bigger[i]<<i);
            }
            cur_sum+=1<<bit;

            ll cur = query(cur_sum, cur_bigger_sum, t);
            if(cur == 0) {
                smaller[bit] = 0;
                bigger[bit] = 1;
                cur_bigger_sum+=1LL<<bit;
                for(int i = bit-1; i>=0; i--){
                    ll z = query(cur_sum+(1LL<<i), cur_bigger_sum,t);
                    if(z == -1){
                        bigger[i] = smaller[i] =  1;
                        cur_sum+=1LL<<i;
                        cur_bigger_sum+=1LL<<i;
                    }else{
                        bigger[i] = smaller[i] = 0;
                    }
                }
                break;
            }
            cur_sum -= 1<<bit;
            cur_bigger_sum+=1<<bit;
            ll new_cur = query(cur_sum, cur_bigger_sum, t);
            if(new_cur == 0) {
                cur_sum+=1LL<<bit;
                smaller[bit] = 1;
                bigger[bit] = 0;
                for(int i = bit-1; i>=0; i--){
                    ll z = query(cur_sum+(1LL<<i), cur_bigger_sum,t);
                    if(z == -1){
                        bigger[i] = smaller[i] =  1;
                        cur_sum+=1LL<<i;
                        cur_bigger_sum+=1LL<<i;
                    }else{
                        bigger[i] = smaller[i] = 0;
                    }
                }
                break;
            }
            if(cur == 1){
                if(new_cur == 1){
                    
                }else{

                }
            }else{
                if(new_cur == 1){

                }else{

                }
            }
        }
        //a is small b is big
        //my logic -> if at any point you get 0 previous bits remain, do the t==0 stuff
        //if == 1 (smaller becomes bigger)
        //check other if bigger is smaller 0,1 (small,big)
        //else if bigger bigger 0,0


        //else
        //if bigger smaller 1 1
        //else bigger bigger 1 0
        ll a = 0;
        ll b = 0;
        for(int i = 0; i<MAX_BITS; i++){
            a+=smaller[i]<<i;
            b+=bigger[i]<<i;
        }
        if (t == 1) {
            swap(a, b);
        }
        cout<<"! "<<a<<' '<<b;
        fflush(stdout);
    }
}```
