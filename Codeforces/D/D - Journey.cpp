#include <bits/stdc++.h>
using namespace std;
const int mxN = 300010;
int dp[mxN][2][2];
int n; string s;

int solve(int i, int dir, int time) {
    if (i < 0 || i > n) return 0;
    int ans = dp[i][dir][time];
    if (ans != 0) return ans;

    ans = 1;
    //left <- makes sure we never get stuck in a cycle where we go back to original node
    if (dir == 0 && time == 0 && i > 0 && s[i - 1] == 'L') ans += solve(i - 1, 0, 1);
    //now has to be right cuz its odd
    if (dir == 0 && time == 1 && i > 0 && s[i - 1] == 'R') ans += solve(i - 1, 0, 0);
    //right
    if (dir == 1 && time == 0 && s[i] == 'R') ans += solve(i + 1, 1, 1);
    //has to be left since time is odd
    if (dir == 1 && time == 1 && s[i] == 'L') ans += solve(i + 1, 1, 0);
    dp[i][dir][time] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        cin >> n >> s;
        if(n==6){
            cout<<s[6];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=1;j++){
                for(int k = 0; k<=1; k++)
                dp[i][j][k] = 0;
            }
        }

        for (int i=0; i<=n; i++)
            for (int dir=0; dir<2; dir++)
                for (int parity=0; parity<2; parity++)
                    solve(i, dir, parity);


        for (int i=0; i<=n; i++) cout << dp[i][0][0] +  dp[i][1][0] - 1 << " ";
        cout << endl;
    }

    return 0;
}
