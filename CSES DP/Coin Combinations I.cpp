#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
using namespace std;
#include <chrono>
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
template <typename T, T mod> class Mint{
private: 
    T val;
    T modinv(T a, T m) {
        T m0=m, t, q;
        T x0=0, x1=1;
        while (a>1) {
            q = a/m;
            t = m;
            m = a%m;
            a = t;
            t=x0;
            x0=x1-q*x0;
            x1=t;
        }
        if (x1<0) x1 += m0;
        return x1;
    }
public:
    Mint() : val(0){}
    Mint(T val) {
        this->val = val;
        while (this->val < 0) this->val += mod;
        while (this->val >= mod) this->val -= mod;
    }
    //overload +, -, *, 
    friend std::ostream& operator<<(std::ostream& os, const Mint& m) {
        os<<m.val;
        return os;
    }
    Mint operator+(const Mint& other) const{
        return Mint((val + other.val) < 0 ? (val+other.val + mod) : (val + other.val >= mod ? val+other.val - mod : val+other.val));
    }
    Mint operator-(const Mint& other) const{
        return Mint((val - other.val) < 0 ? (val-other.val + mod) : (val - other.val >= mod ? val-other.val - mod : val-other.val));
    }
    Mint operator*(const Mint& other) const{
        return Mint((val*other.val)%mod);
    }
    Mint operator/(const Mint& other) const{
        return Mint(((val * modinv(other.val, mod)) + mod ) % mod);
    }
    Mint& operator+=(const Mint& other){
        val = ((val + other.val) < 0 ? (val + other.val + mod) : (val + other.val >= mod ? val + other.val - mod : val+other.val));
        return *this;
    }
    Mint& operator-=(const Mint& other){
        val = ((val - other.val) < 0 ? (val-other.val + mod) : (val - other.val >= mod ? val-other.val - mod : val-other.val));
        return *this;
    }
    Mint& operator*=(const Mint& other){
        val = (val * other.val)%mod;
        return *this;
    }
    Mint& operator/=(const Mint& other){
        val = ((val * modinv(other.val))+mod)%mod;
        return *this;
    }
    bool operator==(const Mint& other) const {return val==other.val;}
    bool operator!=(const Mint& other) const {return val!=other.val;}
    bool operator>(const Mint& other) const {return val>other.val;}
    bool operator<(const Mint&other) const {return val<other.val;}
    bool operator>=(const Mint&other) const {return val>=other.val;}
    bool operator<=(const Mint&other) const {return val<=other.val;} 
};
#define mint Mint<int, mod>
#define mll Mint<ll, (ll)mod>

const ll mxN = 1e6+5;
const ll mod = 1e9+7;
mll dp[mxN];
int coins[mxN];
ll n,x;
ll ans = 0;

void solve(){
    cin>>n>>x;
    for(ll i = 0; i<n; i++){
        int coin; 
        cin >> coin;
        dp[coin] = mll(1);
        coins[i] = coin;
    }
    sort(coins, coins + n);
    for(ll i = 0; i<=x; i++){
        for(ll j = 0; j<n; j++){
            if(i - coins[j] < 0){
                break;
            }
            dp[i] += (dp[i-coins[j]]); 
            
        }
    }
 
    cout<<dp[x];
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    t = 1;
    while (t--) {
        solve();
    }
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
