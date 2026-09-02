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

const int mod = 998244353; 


const int MAXN = 1e6+10;
ll fact[MAXN], inv_fact[MAXN];

ll pw(ll b, ll e){  
    ll r = 1;
    //b^13 = b^8 * b^4 * b^1
    while(e > 0){
        if(e & 1) r = r * b % mod;
        b = b * b % mod; //goes up by powers of two
        e >>= 1;
    }
    return r;
}

void init_fact(){
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i % mod;

    //consider waht like a^-1 is
    //a^p-1 congruent to 1 mod p -> a* a^p-2  = 1 and so a^p-2 is our inverse
    inv_fact[MAXN-1] = pw(fact[MAXN-1], mod - 2);

    //((i-1)!)^-1 = (i!)^-1 * i
    for(int i = MAXN-1; i >= 1; i--)
        inv_fact[i-1] = inv_fact[i] * i % mod;
}

ll nCk(ll n, ll k){
    return ((fact[n] * inv_fact[k] % mod )* inv_fact[n-k]) % mod;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi runs; 
    int len = 1;
    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i+1]){
            len++;
        }else{
            runs.pb(len);
            len =1;
        }
    }
    runs.pb(len);
    ll zeroes = 0;

    ll ones = 0;
    for(int i =0 ; i<runs.size(); i++){
        if(i%2){
            ones+=runs[i];
        }else{
            zeroes+=runs[i];
        }
    }
    //zeroes_groups = ((len+1)/2)
    //ones = len/2
    //ans = (zeroes-1)C (zGroup-1) * (ones-1) C (oGroup-1)
    ll zGroup = (runs.size()+1)/2;
    ll oGroup = runs.size()/2;
    ll ans = (zeroes == 0 ? 1 : nCk(zeroes-1, zGroup-1))* (ones == 0 ? 1 : nCk(ones-1, oGroup-1));
    ans%=mod;
    cout<<ans<<nl;
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    init_fact();
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
