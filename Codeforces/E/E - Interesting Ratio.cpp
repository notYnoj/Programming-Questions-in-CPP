//github: https://github.com/notYnoj
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e7 + 5;
vector<bool> o(MAXN, true);
vector<int> ans(MAXN, 0);
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
void sieve() {
    o[0] = o[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (o[i]) {
            //multiples under i^2 have already been marked
            for (int j = i*i; j < MAXN; j += i) {
                o[j] = false;
            }
        }
    }
}
void solve() {
    /*so its going to be like lcm*gcd = ab
     * ab/gcd/gcd = P
     * we gotta find one suhc that a prime * some gcd = ab or
     * let a = i*sum
     * let b = i*sum1
     * then i*sum * i *sum1 / i^2 = P
     * so sum * sum1 = P
     * js fin them such that this is true
     * */
    for (int i = 1; i < MAXN; i++) {
        for (int j = 2; j* i < MAXN; j++) {
            if (o[j]) {
                if (i < j* i) {
                    ans[j*i]++;
                }
            }
        }
    }
    for (int i = 1; i < MAXN; i++) {
        ans[i] += ans[i - 1];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    solve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}
