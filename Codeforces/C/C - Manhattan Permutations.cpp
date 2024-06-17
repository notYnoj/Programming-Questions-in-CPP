#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        ll max_s = 0;
        int c = 1;
        for (int i = n; i>=1; i--) max_s += abs(i - c++);
        if (k % 2 || k > max_s) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            vector<int> p(n);
            k /= 2;
            iota(p.begin(), p.end(), 1);
            for (int i = 0; k > 0; i++) {
                if (k >= n - 1 - (2 * i)) { //each contribuation provided n-1 then (first one)n-1-stepsx(1 move left aka sutbract by n-1) - stepsx(1 move right 1+ so subtract by 1 less too) steps = i
                    swap(p[i], p[n - 1 - i]);
                    k -= n - 1 - (2 * i);
                } else {
                    swap(p[i], p[i + k]);
                  //if we swap i and i+k the distance between i and k will be 2*(i-k) buy since we already divided by 2 then its good!
                    k = 0;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << p[i] << " ";
            }
            cout << "\n";
        }
    }
}
