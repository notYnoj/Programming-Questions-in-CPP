#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define nl '\n'
#include <chrono>
using namespace std;
int t;
// Everything Else thats new :D
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T> p){
    os<<p.first<<' '<<p.second<<endl;
    return os;
}
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << ' ';
    }
    return os;
}


template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec){
    //of size n
    for(T& elem: vec){
        is>>elem;
    }
    return is;
}


void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    //find max compressible lenghts
    vector<char> ch;
    vi len;
    for (int i=0; i<n; i++) {
        if (!ch.empty() && ch.back() == s[i]) len.back()++;
        else{ 
            ch.push_back(s[i]); 
            len.push_back(1);
        }
    }
    int m = ch.size();
    int best = m;
    //if we have a run of 1 we can delete it or merge it with the next one
    for (int j = 1; j + 1 < m; j++) {
        if (len[j]== 1) best = min(best, ch[j - 1]==ch[j + 1]?m-2:m-1);
    }
    cout <<best<<nl;
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    cin>>t;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}