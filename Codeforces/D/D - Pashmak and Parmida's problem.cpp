
#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6+5;
unordered_map<int, int> fw, bw;
long long fenwick[mxN];
int n;
void update(long long k, long long val){
    for(long long i = k+1; i<=n; i+=(i&(-i))){
        fenwick[i]+= val;
    }
 
}
long long query(int k){
    long long a = 0;
    for(int i = k+1; i>0; i-=(i & (-i))){
        a+= fenwick[i];
    }
    return a;
}
int main(){
 
    cin>>n;
    vector<int> hold(n);
    for(int i = 0;  i<n; i++) cin>>hold[i];
    for(int i = n-1; i>= 0; i--){
        fw[hold[i]]++;
        update(fw[hold[i]], 1);
    }
    long long ans = 0;
    for(int i = 0; i<n; i++){
        update(fw[hold[i]]--, -1);
        bw[hold[i]]++;
        ans+=query(bw[hold[i]]-1);
    }
    cout<<ans<<"\n";
}
