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
    vi a(n), b(n);
    cin>>a>>b;
    //like for some combination of numbers
    //we can have -> a ->b 
    //lets say we want to turn a[i] -> b[i]
    //then a[i] ^ k = b[i]
    // -> k = (a[i] ^ b[i])
    // therefore to get to b[i] some comobination of other a must be equal to k
    // but some dont get used when we use it on the operation but only on that operation
    //after some operation every elemetn then becomes a[i] ^ total if not selected or
    // a[i] ^ (total ^ a[i]) = total
    ll v = 0;
    for(int i = 0; i<n; i++) v ^= (a[i] ^ b[i]); //xor of everything we need to get to this one
    vi make(n);
    for(int i =0; i<n; i++){
        make[i] = a[i] ^ v; //we dont xor by this ones contribution since it isnt used we need all of these
    }
    if(v != 0){
        auto it = find(all(make), 0); //make[i] == 0 means a[i] == v  chosen last
        if(it == make.end()){
            cout<<"NO\n"; //we need some element to be the final element
            return;
        }
        *it = v;
    }
    //becuase of the fact that once v is fixed each element is forced to either be a[i]^v or v
    sort(all(make)); //gonna be if possible some permutation of b
    sort(all(b));
    cout<<((make == b) ? "YES\n" : "No\n");
    //if the total xor is constant then you can move the value total xor around between elements
    //
    //x y, ak ^ x
    // x, x^y, ak ^ y
    //y, x^y, ak ^ y
    // y, x, ak
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