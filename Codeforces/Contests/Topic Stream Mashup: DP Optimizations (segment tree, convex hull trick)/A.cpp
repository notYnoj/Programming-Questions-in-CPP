#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MXN = 2e5 + 5;

int t[4 * MXN]; 
vector<int> pref(MXN, 0), dp(MXN, 0);

//min tree, build it
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = INF;
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

// update a pos in the segment tree
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

// query the minimum in [l, r]
int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm)),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<pair<int, int>> constraints(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) cin >> constraints[i].first >> constraints[i].second;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    build(1, 1, n);
    dp[1] = 0;
    update(1, 1, n, 1, dp[1] - pref[0]);
    for (int i = 2; i <= n; ++i) {
        int l = constraints[i].first, r = constraints[i].second;
        int mn = query(1, 1, n, l, r);
        dp[i] = mn + pref[i];
        update(1, 1, n, i, dp[i] - pref[i - 1]); // Update the tree with value for next time pref[i] -pref[j -1] + dp[j] is our formula so pref[j-1] will be sub here
    }
    for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
    cout << endl;
    return 0;
}
