#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> t(n);
 
    for (int i = 0; i < n; i++) {
        t[i] = {a[i], i};
    }
    sort(t.begin(), t.end());
    vector<int> ans(n);
    vector<pair<int, int>> t2(n);
    for(int i = 0; i<n; i++){
        t2[i] = {t[(i-1)%n>=0?(i-1)%n:n-1].first, t[i].second};
    }
    for(int i = 0; i<n; i++){
        ans[t2[i].second] = t2[i].first;
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
 
}
