#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        int one = 0;
        int two = 0;
        for(int i = 0; i<n; i++) {
            long long b;
            cin >> b;
            int mod = b % 3;
            if (mod == 0) {
                ans++;
            } else if (mod == 1) {
                one++;
            } else {
                two++;
            }
        }
        while(one>=1 && two>=1){
            one--;
            two--;
            ans++;
        }
        ans+=(one/3);
        ans+=(two/3);
        cout<<ans<<"\n";
    }
}
