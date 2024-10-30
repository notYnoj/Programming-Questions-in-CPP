#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    long long Gar = 0;
    for(long long i = 0; i<n; i++){
        cin>>arr[i];
        Gar = __gcd(Gar, arr[i]);
    }
    for(long long i = 0; i<n; i++){
        arr[i]/=Gar;
    }
    long long mc = 0;
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        long long cur = arr[i];
        for(long long j = 0; j<n; j++){
            cur = min(cur, __gcd(mc, arr[j]));
        }
        mc = cur;
        if(mc == 1){
            ans+=(n-i);
            break;
        }else{
            ans+=mc;
        }
    }



    cout<<ans*Gar<<"\n";
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
