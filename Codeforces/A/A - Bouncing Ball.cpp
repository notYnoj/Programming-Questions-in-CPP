#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, p, k;
  cin >> n >> p >> k;
  p--;
  string a;
  int x, y;
	cin >> a;
  cin >> x >> y;
  vector<int> dp(n, INT_MAX);
  int ans = INT_MAX;
  for (int i = n - 1; i >= p; i--) {
    if ((i + k) >= n) {
      if (a[i] == '0'){
        dp[i] = x;
		}else{
        dp[i] = 0;
			}
    } else {
      dp[i] = dp[i + k] + (a[i] == '0' ? x : 0);
    }
		if(i-p>=0)ans = min(ans, dp[i] + (y) * (i - p));

  }
 
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
