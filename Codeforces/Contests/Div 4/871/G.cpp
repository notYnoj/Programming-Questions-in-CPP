#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using ll = long long;

const int MX = 1000005;
ll row[MX];
ll dp[MX];
ll st[3000], en[3000];

void pre() {
    ll t, i, j;
    t = 0;
    for (i = 1; i <= 2023; ++i) {
        st[i] = t+1;
        en[i] = t+i;
        for (j = st[i]; j <= en[i]; ++j) {
            if (j >= MX) return;
            row[j] = i;
        }
        t = en[i];
    }
}

ll common(ll x, ll y) {
    if (x == y) return x;

    x -= row[x];
    x+=1;
    y -= row[y];
    if (x == y) return x;

    return -1;
}

ll solve(ll n) {
    if (n <= 0) return 0;

    ll& curr = dp[n];
    if (curr != -1) return curr;

    ll r, x, y;
    bool tx;
    r = row[n];
    x = n-r; //left
    y = n-r+1;//right
    tx = 0;

    curr = n*n; //cur num
    if ((x >= 1) && (row[x] == r-1)) {
        curr += solve(x); //solve for left
        tx = 1;
    }
    if (row[y] == r-1) {
        curr += solve(y); //solve for y
      //if we solved for x then we must subtract the commons between x and y
        if (tx) curr -= solve(common(x, y));
    }

    return curr;
}

int main() {
    FAST;
    memset(dp, -1, sizeof(dp));
    pre();
    dp[1] = 1;
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}
