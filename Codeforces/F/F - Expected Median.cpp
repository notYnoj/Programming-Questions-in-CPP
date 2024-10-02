#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 1e6; // Adjust this based on problem constraints
vector<ll> fact(maxN + 1), invFact(maxN + 1);
ll modInverse(ll a, ll mod) {
    ll result = 1, power = mod - 2;
    while (power) {
        if (power & 1) result = result * a % mod;
        a = a * a % mod;
        power >>= 1;
    }
    return result;
}
// Function to compute factorials and inverse factorials
void precomputeFactorials(int mod) {
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[maxN] = modInverse(fact[maxN], mod);
    for (int i = maxN - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }
}

// Function to calculate the modular inverse of 'a' under modulo 'MOD' using Fermat's Little Theorem


// nCk function using precomputed factorials and inverse factorials
ll nCk(ll n, ll k, ll mod) {
    if (k > n) return 0;
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll zr = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) ones++;
        else zr++;
    }

    ll total = nCk(n, k, MOD);
    ll nec = (k + 1) / 2;
    if (ones < nec) {
        cout << 0 << '\n';
        return;
    }

    if (zr < nec) {
        cout << total % MOD << '\n';
    } else {
        ll bads = 0;
        for (ll i = nec; i <= min(k, zr); i++) {
            ll kChooseZrs = nCk(zr, i, MOD);
            ll kChooseOnes = nCk(ones, k - i, MOD);
            bads = (bads + kChooseZrs * kChooseOnes % MOD) % MOD;
        }

        ll ans = (total - bads) % MOD;
        ans = (ans + MOD) % MOD;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials and inverse factorials
    precomputeFactorials(MOD);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
