#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ans = 0;
        ++m;
        //first n XOR x = k
        //n XOR k = x
        // find some k in which xor n is outside of m
        if(n>=m){
            cout<<"0\n";
        }else {
            for (int bit = 30; bit >= 0 && m > n; bit--) {
                if ((m >> bit & 1) == 1 && !(n >> bit & 1)) {
                    ans+=1<<bit;
                    n+=1<<bit;
                }
            }
            cout << ans<<"\n";
        }
    }
}
