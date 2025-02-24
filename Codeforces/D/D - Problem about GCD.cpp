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
    ll lowerBound = (l/G) + (l%G == 0?0:1);
    ll higherBound = (r/G);
    //optimal case is higherBound - lowerBound
    if(lowerBound == higherBound){
        if(lowerBound == 1) {
            cout << lowerBound*G<< " " << higherBound*G<< '\n';
        }else{
            cout<< -1<< ' '<< -1<< '\n';
        }
        return;
    }
    //check lowerBound, higherBound then lowerBound, Higherbound-1 then lowerbound-1 higherBoundt hen lower-1 higher-1 repeat
    while(lowerBound<higherBound){
        //check case 1
        if(gcd(lowerBound, higherBound) == 1){
            cout<<lowerBound*G<<' '<<higherBound*G<<"\n";
        }
        if(gcd(lowerBound, higherBound-1) == 1){
            cout<<lowerBound*G<<' '<<(higherBound-1)*G<<"\n";
        }
        if(gcd(lowerBound+1, higherBound) == 1){
            cout<<(lowerBound+1)*G<<' '<<(higherBound)*G<<"\n";
        }
        lowerBound+=1;
        higherBound-=1;
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
