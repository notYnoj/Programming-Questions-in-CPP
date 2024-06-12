#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int i;
        cin>>i;
        int ans = 0;
        int length = 0;
        for(int j = 0;j<i; j++){
            int t;
            cin>>t;
            if(t == 0) length++;
            else length = 0;
            ans = max(length, ans);

        }
        cout<<ans<<"\n";

    }
}
