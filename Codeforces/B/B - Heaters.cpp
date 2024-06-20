#include <bits/stdc++.h>
#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pair<ll,ll>>
using namespace std;

int main(){
    int n,r;
    cin>>n>>r;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<int> heated(n);
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]){
            ans++;
            for(int j = max(0, i-r+1); j<min(n, i+r); j++) heated[j]++;
        }
    }
    int t = *min_element(heated.begin(), heated.end());
    if(t == 0) cout<<-1;
    else {
        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                bool good = false;
                for (int j = max(0, i - r + 1); j < min(n, i + r); j++) {
                    if (heated[j] == 1) {
                        good = true;
                        break;
                    }
                }
                if (!good) {
                    ans--;
                    for (int j = max(0, i - r + 1); j < min(n, i + r); j++) heated[j]--;
                }
            }
        }
        cout << ans;
    }
}
