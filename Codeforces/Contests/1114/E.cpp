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
    cin>>n;
    vi a(n);
    cin>>a;
    //consider like a[i] - a[i-1] = b[i]
    //b = a[1], a[2]- a[1], a[3] - a[2]
    //if we add all of these up at any given index we get that pref(b from 1-j) = a[j]
    //therefore if at the end we have prefix is not at least 1 then we know we cant make it
    //even if rearranged we have communitiative property of addition so its ok
    //next we say that at any point the lexigropahic smallest thing to do is
    //construct it greedily and laways select the point that gives us p >= 1
    ll p = accumulate(all(a), 0LL);
    if(p<1){
        cout<<-1<<nl;
        return;
    }
    ll build = 0;
    multiset<ll> choose(all(a));
    vi ret(n);
    for(int i = 0; i<n; i++){
        //build + x >= 1 -> 1- build<=x is best
        auto it = choose.lower_bound(1-build);
        build+=*it;
        ret[i] = build;
        choose.erase(it);
    }
    cout<<ret<<nl;

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