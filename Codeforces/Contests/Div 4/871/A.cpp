#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--) {
        string s = "codeforces";
        string s1;
        cin >> s1;
        int ans = 0;
        for(int i = 0; i<10; i++){
            if(s1[i] != s[i]) ans++;
        }
        cout<<ans<<'\n';
    }

}
