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

ll llpow( ll base, ll exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res *= base;
        }
        base *= base;
        exp /= 2;
    }
    return res;
}

void solve(){
    ll a, n;
    cin>>a>>n;
    ll truA = a;
    vi d(n);
    cin>>d;
    sort(all(d));
     if(truA == 0){
        cout<< d[0] <<nl;
        return;
    }
    vi dn;
    while(a > 0){
        int curd = a%10;
        dn.pb(curd);
        a/=10;
    }
    //greedily pick numbers
    //were going to check 11111 * small 11111 (n times) * large and try to build one. 
    // if we ever cant place a number do built number + n times smallest one and n times largest one
    //take the min of all these answers
    auto build = [](int size) -> ll{
        ll res = 0;
        for(int i = 0; i<size; i++){
            res*=10;
            res+=1;
        }
        return res;
    };
    ll shorter = (dn.size() > 1) ? build(dn.size() - 1) * d[1] : d[0];
    ll longer = (d[0] == 0) ? d[1] * llpow(10LL, dn.size()) : build(dn.size() + 1) * d[0];
    ll res = min(abs(truA -longer) , abs(truA - shorter));
    ll ones = build(dn.size());

    ll mn1 = ones * d[0];
    ll mn2 = ones * d[1];
    res = min (res, abs(truA - mn1));
    res = min(res, abs(truA - mn2));
    ll pref = 0;

    for(int i = dn.size() -1 ; i>=0; i--){
        //Place bigger
        if(dn[i] < d[1]){
            ll cand = (dn[i] < d[0]) ? d[0] : d[1];
            ll alt = pref + cand * llpow(10LL, i) + d[0] * build(i);
            res = min(res, abs(truA - alt));
        }
        //place smaller
        if(dn[i] > d[0]){
            ll cand = (dn[i] > d[1]) ? d[1] : d[0];
            //here place
            ll alt = pref + cand* llpow(10LL,i) + d[1] * build(i);
            res = min(res, abs(truA - alt));
        }
        //match
        if(dn[i] == d[1]){
            pref+=d[1] * llpow(10LL, i);

        }else if(dn[i] == d[0]){
            pref+= d[0] * llpow(10LL, i);
        }else{break;}
        if (i == 0) {
            res = min(res, abs(truA - pref));
        }
    }

    cout<<res<<endl;
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
