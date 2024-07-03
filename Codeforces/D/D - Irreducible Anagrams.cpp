#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

string s;
int n, q, l, r, sum[N][26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = (int)s.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][s[i-1] - 'a']++;
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += (sum[r][i] - sum[l - 1][i] > 0);
        }

        if (l == r || cnt >= 3 || s[l-1] != s[r-1]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
