#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin >> n;

        vector<long long> ans(n);
        long long pref = 0;
        set<long long> s;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> ans[i];
            pref+=ans[i];
            if(s.find(ans[i]) != s.end()) ok = false;
            s.insert(ans[i]);

        }
      //two options can we move htem around or not
        if(n == 1){
            cout<<"NO\n";
          //if we cant js move them aroudn then we can make all 1s into 2s and all n>1 into 1; 
        }else {
            long long z = 0;
            for (int i = 0; i < n; i++) {
                z += ans[i] == 1 ? 2 : 1;
            }
            cout << (pref>=z ? "YES\n" : "NO\n");

        }
    }
}
