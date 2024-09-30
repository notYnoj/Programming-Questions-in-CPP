#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int bad = 0;
        if(l%2 == 0){
            bad++;
            bad+=(r-l)/4;
        }else {
            bad += (r - l + 1) / 4;
        }
        int tot = (r-l+1);

        cout<<((tot-bad)/3)<<'\n';
    }
}
