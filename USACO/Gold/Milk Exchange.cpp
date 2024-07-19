#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i =0; i<n; i++) cin>>arr[i];
    vector<ll> times(n+10, 0);
    rotate(arr.begin(), next(min_element(arr.begin(), arr.end())), arr.end());
    vector<ll> stk;
    //keep it increasing thus when it isnt increasing (aka there is a downward that means nothign will spill otherwise something def spills)
    for(ll i = n-1; i>=0; i--){
        while(stk.size()>=2 && arr[stk.back()]>arr[i]){
            ll front = stk.back();
            ll second = stk[stk.size()-2];
            stk.pop_back();
            ll val_to_add = arr[front] - arr[second];
            ll start_time = second - front;
            ll end_time = second - i;
            times[start_time] += val_to_add;
            times[end_time] -= val_to_add;
        }
        stk.push_back(i);
    }
    while(stk.size()>=2){
            ll front = stk.back();
            ll second = stk[stk.size()-2];
            stk.pop_back();
            ll val_to_add = arr[front] - arr[second];
            ll start_time = second - front;
            ll end_time = second + 1;
            times[start_time] += val_to_add;
            times[end_time] -= val_to_add;
    }
    ll total = accumulate(arr.begin(), arr.end(), 0LL); //0LL made me get this wrong ................
    for(int i =1; i<=n; i++){
        times[i] = times[i] + times[i-1];
        //cout<<times[i]<<" ";
        total -= times[i];
        //times is goingt o have how much is going to spill at each moment
        cout<<total<<"\n";
    }

}
