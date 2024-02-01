#include <bits/stdc++.h>
using namespace std;
 
int r, s, p;
const int mxN = 105;
double dp[mxN][mxN][mxN];
 
int main() {\
  //fastio
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> s >> p;
  //base case there will always be a prob that [r][s][p] are alive
    dp[r][s][p] = 1.0;
 //for each case i*j probability of duel happening*og prob / total caases
    for (int i = r; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            for (int k = p; k >= 0; k--) {
                if (i > 0 && j > 0)
                    dp[i][j-1][k] += dp[i][j][k] * i * j / (i * j + j * k + k * i);
                if (j > 0 && k > 0)
                    dp[i][j][k-1] += dp[i][j][k] * j * k / (i * j + j * k + k * i);
                if (k > 0 && i > 0)
                    dp[i-1][j][k] += dp[i][j][k] * k * i / (i * j + j * k + k * i);
            }
        }
    }
 
    double rprob = 0.0;
    double sprob = 0.0;
    double pprob = 0.0;
 //ones where only r or s or p survive
    for (int i = 1; i < mxN; i++) {
        rprob += dp[i][0][0];
        sprob += dp[0][i][0];
        pprob += dp[0][0][i];
    }
 //include this, Thanks linnrue!
    cout << fixed << setprecision(12);
    cout << rprob << " " << sprob << " " << pprob;
 
    return 0;
}
