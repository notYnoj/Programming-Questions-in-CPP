#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        while (n % 5LL == 0LL) {
            ans += 3LL;
            n /= 5LL;
        }
        while (n % 3LL == 0LL) {
            ans += 2LL;
            n /= 3LL;
        }
        while (n % 2LL == 0LL) {
            ans++;
            n /= 2LL;
        }
        if (n == 1LL) {
            cout << ans<<"\n";
        } else {
            cout << -1LL<<"\n";
        }
    }
}
