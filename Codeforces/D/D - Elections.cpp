#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> c(n); // Votes for each candidate
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    int p = 0;
    vector<int> d = c; 
    
    d[0] += m;
    int y = *max_element(c.begin(), c.end()); // Maximum votes in original c
    int z = max_element(d.begin(), d.end()) - d.begin(); // Index of candidate with max votes in d
    
    for (int j = 0; j < n; ++j) {
        if (j == z) {
            cout << 0 << " ";
            p += c[j];
            continue;
        }
        
        if (c[j] + p + m >= y) {
            cout << j << " "; //get rid of everythiong before it so it can get the buffs
        } else {
            cout << j + 1 << " "; // if there is something bigger than it aka Y we can remove Y and add them to the current one and then we are always good
        }
        p += c[j]; // remove the previous one before
    }
    
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

