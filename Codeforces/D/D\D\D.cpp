#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<ll>
using namespace std;
const int mxN = 2e5 + 5;
vi graph[mxN];
ll d[mxN][2]; // d[node][0] = even, d[node][1] = odd
bool visited[mxN][2];
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec){
    for (const auto& elem : vec){
        os << elem;
    }
    return os;
}
void solve(int tc){
    ll n,m,l;
    cin>>n>>m>>l;
    for (int i=0; i<=n; i++){
        graph[i].clear();
        d[i][0]=d[i][1]=INT_MAX;
        visited[i][0]=visited[i][1]=false;
    }
    vi moves(l);
    int smallodd = INT_MAX;
    for (int i = 0; i < l; i++){
        cin>>moves[i];
        if(moves[i] % 2){
            smallodd = min(smallodd, (int)moves[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    queue<pair<ll, int>> bfs;
    d[1][0] = 0;
    visited[1][0] = true;
    bfs.push({1, 0});
    while (!bfs.empty()) {
        auto [n, p] = bfs.front();
        bfs.pop();
        for (auto i : graph[n]) {
            int np = 1 - p;
            if (!visited[i][np]) {
                visited[i][np] = true;
                d[i][np] = min(d[i][np], d[n][p] + 1);
                bfs.push({i, np});
            }
        }
    }
    string ans = "";
    int totz = accumulate(moves.begin(), moves.end(), 0);
    for (int i=1; i<=n; i++) {
        if (totz%2) {
            if (d[i][0]<=(totz-smallodd) || d[i][1]<=totz) {
                ans += '1';
            } else {
                ans += '0';
            }
        } else {
            if (d[i][0]<=totz || d[i][1]<=(totz-smallodd)) {
                ans += '1';
            } else {
                ans += '0';
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
}
