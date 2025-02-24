#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    ll l,r,G;
    cin>>l>>r>>G;
    //some number A,B between l,r with gcd(a,b) = G
    //given that these numbers gave gcd, G this means that the remaining numbers are coprime
    //so gcd(A/G, B/G,) = 1
    //we also want to maximize this
    ll lB = (l/G) + (l%G == 0?0:1);
    ll hB = (r/G);
    //optimal case is higherBound - lowerBound
    //check the distance r-l-i
    //check lowerBound, higherBound then lowerBound, Higherbound-1 then lowerbound-1 higherBoundt hen lower-1 higher-1 repeat
    for(ll i = (hB-lB); i >=0; i--){
        //we are going thru the distances from biggest to smalelst
        //start at biggest distance minus our current
        //two pointers lB, lb+i then js add 1 between 0 and 
        for(ll j = 0; j<=(hB-lB)-i; j++){
            //pointer left = lb+j, pointer right = lb+i+j
            ll pL = lB+j;
            ll pR = lB+i+j;
            if(gcd(pL, pR) == 1){
                cout<<pL*G<<' '<<pR*G<<'\n';
                return;
            }
        }
    }
    cout<<"-1 -1\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
