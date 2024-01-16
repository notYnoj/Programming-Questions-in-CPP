#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN = 2e5;
int n;
ar<int, 2> a[mxN];
int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i][0]>>a[i][1];
    }
    //sort them based duration shortest first
    sort(a, a+n);
    ll t =0;
    ll ans = 0;
    for(int i = 0; i<n; i++){
      //time elapsed variable
        t+=a[i][0];
        ans+=a[i][1]-t;
    }
    cout<<ans;
 
}
