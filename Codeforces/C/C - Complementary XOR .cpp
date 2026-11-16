#include <bits/stdc++.h>
#include <chrono>

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define nl '\n'

using namespace std;

int t;

// Everything Else thats new :D
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T> p) {
    os << p.first << ' ' << p.second << endl;
    return os;
}

template <typename T>  // custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << ' ';
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    // of size n
    for (T& elem : vec) {
        is >> elem;
    }
    return is;
}

void solve() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    vi c(n);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        if (c[i] != c[i - 1]) {
            cout << "no\n";
            return;
        }
    }

    if (n == 1 && s1[0] == '1' && s2[0] == '1') {
        cout << "no\n";
        return;
    }

    /*
        000000
        000000
        we can simply go about and turn off runs, if we ever turn off
        an extra amount we just take one of the runs turn it off
    */
    if (c[0] == 0) {
        // 00
        // 00
        int prev = 0;
        vector<pair<char, int>> ps;

        for (int i = 1; i < n; i++) {
            // for all runs of 1s greater than len 1 we can do it in two steps
            // otherwise they need another one
            // for any runs of 1 length 1 just grab the next one
            // and then apply it on the next one
            if (s1[i] != s1[i - 1]) {
                ps.push_back({s1[i - 1], i - prev});
                prev = i;
            }
        }

        ps.push_back({s1[n - 1], n - prev});

        int start = 0;
        vector<pair<int, int>> moves;

        for (auto run : ps) {
            if (run.first == '1') {
                if (run.second == 1) {
                    if(start + run.second >= n){
                        //11
                        //00
                        moves.push_back({start-1, start-1});
                        moves.push_back({start-1, start});
                    }else{
                        moves.push_back({start, start + run.second});
                        moves.push_back({start + run.second,
                                     start + run.second});
                    }
                } else {
                    moves.push_back({start, start + run.second - 2});
                    moves.push_back({start + run.second - 1,
                                     start + run.second - 1});
                }
            }
            start += run.second;
        }

        cout << "Yes\n"<<moves.size()<<nl;
        for (auto move : moves) {
            cout << move.first + 1 << ' ' << move.second + 1 << nl;
        }
    } else {
        int prev = 0;
        vector<pair<char, int>> ps;

        for (int i = 1; i < n; i++) {
            // for all runs of 1s greater than len 1 we can do it in two steps
            // otherwise they need another one
            // for any runs of 1 length 1 just grab the next one
            // and then apply it on the next one
            if (s1[i] != s1[i - 1]) {
                ps.push_back({s1[i - 1], i - prev});
                prev = i;
            }
        }
        ps.push_back({s1[n - 1], n - prev});


        int zereos = 0;
        int ones = 0;
        for (int i = 0; i < ps.size(); i++) {
            if (ps[i].first == '0') {
                zereos++;
            } else {
                ones++;
            }
        }

        vector<pair<int, int>> moves;
        int start = 0;
        if (ones % 2) {
            for (auto run : ps) {
                if (run.first == '1') {
                    moves.push_back({start, start + run.second - 1});
                }
                start += run.second;
            }
        } else {
            //1111
            //0000
            //
            if(ones == 0){
                moves.push_back({0, n-1});
                moves.push_back({0,0});
                moves.push_back({1, n-1});
                
            }
            else if(zereos % 2 == 0){
                for (auto run : ps) {
                    if (run.first == '0') {
                        moves.push_back({start, start + run.second - 1});
                    }
                    start += run.second;
                }
                moves.push_back({0, n - 1});
            }else{
                for(auto run: ps){
                    if (run.first == '0') {
                        moves.push_back({start, start + run.second - 1});
                    }
                    start += run.second;
                }
                moves[moves.size()-1].first -= 1;
                int end = moves[moves.size()-1].first;
                moves.push_back({end, end});
                moves.push_back({0, n - 1});
            }
        }

        cout << "Yes\n"<<moves.size()<<nl;
        for (auto move : moves) {
            cout << move.first + 1 << ' ' << move.second + 1 << nl;
        }
    }
}

int main() {
#ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
#endif

    cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
#endif
}
