#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_BITS = 30;
int main(){
    auto query = [&](ll a, ll b, int t) -> ll{
        if(t == 1){
            swap(a,b);
        }

        cout<<"? "<<a<<' '<<b;
        ll x;
        cin>>x;
        if(x == -2){
            exit(0);
        }
        if(t == 1 && x!=0){
            (x==1?x = -1:x=1);
        }
        fflush(stdout);

        return x;
    };
    int t = query(0, 0, -2);
    if(t == 0){
        vector<ll> number(30, 0);
        ll new1 = 0;
        for(int i = 0; i<MAX_BITS; i++){
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
        bool change = false;
        for(int bit = MAX_BITS; bit>=0; bit--){
            ll cur_sum = 0;
            ll cur_bigger_sum = 0;
            for(ll i = 29; i>bit; i--){
                cur_sum+=(smaller[i]<<i);
                cur_bigger_sum+=(bigger[i]<<i);
            }
            //changing it if bigger changes
            (!change?cur_sum+=(1<<bit):cur_bigger_sum+=(1<<bit));
            ll cur = query(cur_sum, cur_bigger_sum, t);

            if(cur == 0) {
                (!change? smaller[bit] = 0:smaller[bit] =1 );
                (!change? bigger[bit] = 1:bigger[bit] = 0);
                (!change?cur_bigger_sum+=1LL<<bit:cur_sum+= 1LL<<bit);
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
            (!change?cur_bigger_sum+=(1<<bit):cur_sum+=(1<<bit));
            ll new_cur = query(cur_sum, cur_bigger_sum, t);
            assert(new_cur != 0);
            //calm luh notebook
            if(cur == 1){
                if(new_cur == 1){
                    (!change?bigger[bit] = 1:bigger[bit]=0);
                    (!change?smaller[bit] = 0:smaller[bit] = 1);
                    change = !change;
                }else{
                    bigger[bit] =0;
                    smaller[bit] = 0;
                }
            }else{
                if(new_cur == 1){
                    (!change?bigger[bit] = 1:bigger[bit]=0);
                    (!change?smaller[bit] = 0:smaller[bit] = 1);
                }else{
                    bigger[bit] =1;
                    smaller[bit] = 1;
                }
            }
        }

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
}
