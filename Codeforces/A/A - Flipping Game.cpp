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
    //best = total - flip 1s + flip0s
    //flip0s = len - flip1s
    // = total + max that
    //this is longest contigious subarray with max amount
    //either take prev best or oen that ends here
    //only time u dont take is when it is a net negative
    ll total = 0;
    for(int i = 0; i<n; i++) total+=a[i];
    vi b(n); 
    for(int i= 0; i<n; i++) b[i] = (a[i] == 0 ? 1 : -1);
    
    ll prev = b[0];
    ll cur_best = prev;
    for(int i = 1; i<n; i++){
        //use previous or start a new
        prev = max(b[i], prev + b[i]);
        cur_best = max(prev, cur_best);
    }
    cout<<(total+cur_best);
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    t = 1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
