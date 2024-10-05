#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
  //js use long long bro
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(long long i = 0; i<n; i++) cin>>a[i];
        long long sum = 0;
        for(long long i = 0; i<n-2; i++) sum+=a[i];
        a[n-2]-=sum;
        cout<<(long long)a[n-1] - a[n-2]<<'\n';
    }
}
