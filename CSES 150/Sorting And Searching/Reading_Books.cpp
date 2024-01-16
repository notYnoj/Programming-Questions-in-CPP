#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN = 2e5;
int n;
ll a[mxN];
int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    //sort the number of books
    sort(a, a+n);
    ll total = 0;
    for(int i = 0; i<n-1; i++){
        total+=a[i];
    }
    //greedily pick the total up to the biggest element or the prefix sum of 0-n-2
    if(total<a[n-1]){
        cout<<a[n-1]*2;
    }else{
        cout<<total+a[n-1];
    }

}
 
