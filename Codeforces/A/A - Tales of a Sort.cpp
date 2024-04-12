#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            cin >> ans[i];
        }
        int a = 0;
        for (int i = 0; i < n - 1; i++) {
            if (ans[i] > ans[i + 1])a = max(a, ans[i]);
        }
        cout << a<<"\n";
    }
}
