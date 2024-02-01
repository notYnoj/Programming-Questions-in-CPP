#include <bits/stdc++.h>
using namespace std;
int w, b;
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> w >> b;
    vector<vector<double>> dp(w + 1, vector<double>(b + 1, 0));

    // Base case: if there are no black mice left, the princess wins immediately
    for (int i = 1; i <= w; i++) {
        dp[i][0] = 1.0;
    }

    // Base case: if there are no white mice left, the dragon wins immediately
    for (int j = 0; j <= b; j++) {
        dp[0][j] = 0.0;
    }

    // Fill in the DP array
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= b; j++) {
            // If the princess draws a white mouse, she wins immediately
            dp[i][j] += (double) i / (i + j);

            // If the princess draws a black mouse, calculate the probability of dragon winning (one where white jumps, and one where black jumps)
            if (j >= 3) {
                dp[i][j] += (double) j / (i + j) * ((double) (j - 1) / (i + j - 1)) * ((double) (j - 2) / (i + j - 2)) *
                            dp[i][j - 3];
            }
            if (j >= 2) {
                dp[i][j] += ((double) j / (i + j)) * ((double) (j - 1) / (i + j - 1)) * ((double) i / (i + j - 2)) *
                            dp[i - 1][j - 2];
            }
        }
    }

    cout << fixed << setprecision(9) << dp[w][b];
}
