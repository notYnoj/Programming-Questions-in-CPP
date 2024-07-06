#include <bits/stdc++.h>

using namespace std;
//i actually didnt get this one however I did get most of the logic, I however didn't see b[i] +i and b[i]-i! 
//next time try playing wiht the equation more and see if it can help
void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &i : b) cin >> i;
    vector<int> pref_mx(n), suff_mx(n);
    for (int i = 0; i < n; ++i) {
        pref_mx[i] = b[i] + i;
        suff_mx[i] = b[i] - i;
    }
    for (int i = 1; i < n; ++i) {
        pref_mx[i] = max(pref_mx[i], pref_mx[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suff_mx[i] = max(suff_mx[i], suff_mx[i + 1]);
    }
    int ans = 0;
    for (int m = 1; m < n - 1; ++m) {
        ans = max(ans, b[m] + pref_mx[m - 1] + suff_mx[m + 1]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
