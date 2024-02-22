//coding during ap chem now :D
#include <bits/stc++.h>
using namespace std;

long long solve() {
    long long n;
    cin >> n;
    vector<long long> dp(10);

    if (n < 10)
        return (n * (n + 1) / 2);

    long long t = log10(n);
    long long power = static_cast<long long>(pow(10, t));
    long long left = n / power;
    dp[0] = 0;
    dp[1] = 45;

    // dp for all 10s
    for (int d = 2; d <= t; d++) {
        dp[d] = dp[d - 1] * 10 + 45 * static_cast<long long>(pow(10, d - 1));
    }
    //for 1-42 one theres like 1x10 2x10 3x10 gauss then theres 1+ cuz zero indexed of left mod power of left and finally theres the ones so its dp[t]
    long long ans = left * dp[t] + ((left - 1) * left / 2) * power + left * (1 + n % power);
    // Calculate the sum of digits for the remaining part iteratively
    while (power > 0) {
        long long remaining_part = n % power;
        if (remaining_part < 10) {
            ans += (remaining_part * (remaining_part + 1) / 2);
            return ans;
        }
        power /= 10;
        t--;
        left = remaining_part / power;
        //do it again
        ans += left * dp[t] + ((left-1) * left / 2) * power + left * (1 + remaining_part % power);
        n = remaining_part;
    }

    return ans;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
//pretty common question, I actually knew the solution before this thanks to cses
//originally I did not know how to do this but did end up getting the 10s part logic just not exactly how to do it
