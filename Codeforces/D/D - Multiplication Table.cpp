#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
ll n,m,k;
//if we built the array, find what pos mid will be at if greater than k we know it cant lie to the right so make high our new mid, basic binary search
ll smaller(ll x){
    //its going to best the smallest of x/i <- at 1 goes from 1,2,3,4,5,6... 2 goes up by 2 and whatnot so x lies at x/i, but we want min of the current cols m
    ll amountlessthanx = 0;
    //go thru each row
    for(ll i = 1; i<=n; i++){
        //check which is samller the amount x/i or m
        amountlessthanx += min(x/i,m);
    }
    return amountlessthanx;
}
int main(){
    fastio
    cin>>n>>m>>k;
    //gotta use bs, cant use bruteforce
    //check for the lowest
    ll low = 1;
    ll high = n*m;
    while(low<high){
        ll mid = low+(high-low)/2;
        if(k>smaller(mid)){
            low = mid+1;
        }else{
            high = mid;
        }
    }
    cout<<low;
}
