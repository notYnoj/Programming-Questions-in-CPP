#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll nCk(int n, int r){
    ll a = 1;
    for(int i = n; i>n-r; i--){
        a*=i;
    }
    for(int i = 2; i<=r; i++){
        a/=i;
    }
    return a;
}
int main(){
    int n,k;
    cin>>n>>k;
    ll a = 1;
    if(k>=2) a+=nCk(n, 2);
    if(k>=3) a+=nCk(n,3)*2;
    if(k>=4) a+= nCk(n, 4)*9;
    cout<<a;
 
}
