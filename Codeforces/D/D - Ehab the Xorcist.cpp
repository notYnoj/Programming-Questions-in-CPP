#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
int main(){
    cin>>n>>k;
    if(!n && !k ){
        cout<<0;
        return 0;
    }
    if(n==k){
        cout<<1<<"\n";
        cout<<n;;
        return 0;
    }
    if(n&1^k&1 || n>k){
        cout<<-1;
        return 0;
    }
    ll t = (k-n)/2;

    ll other = t+n;
    if((t^other) == n){
        cout<<2<<"\n";
        cout<<t<<" "<<other;
        return 0;
    }

    cout<<3<<"\n";
    cout<<t<<" "<<t<<" "<< n;
}
