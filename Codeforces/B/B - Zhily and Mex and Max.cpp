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
    vi final(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i] < n) final[a[i]]+=1;
    }
    //brute force where mx is at teh start then mex sequence
    //brute force case where mex sequence first then max
    //rest of the items can be arranged however
    ll mex = 0;
    for(int i = 0; i<n; i++){
        if(final[i] > 0){
            mex = i+1;
        }else{
            break;
        }
    }

    ll mx = *max_element(all(a));
    if(mx >= n){
        //6 0 1 2 3 
        //add max * n + mex * (n-1-mex items) + build mex 
        cout<<(mx*n + (n - 1 - mex) * mex + ((mex + 1) * mex/2))<<nl;
    }else{
        //max is a part of the mex sequence
        //try max * building
        //place final 
        //1 0 1 -> 3
        ll leftover_term, chain_term;
        if(mex - 1 == mx){
            leftover_term = (n - mex) * mex;
            chain_term = (mex-1)*mex/2 + 1;
        } else {
            leftover_term = (n - 1 - mex) * mex;
            chain_term = (mex+1)*mex/2;
        }
        ll ans1 = mx*n + leftover_term + chain_term;
        ll ans2 = mex * mex + (n-mex) * (mx+mex);
        cout<<max(ans1, ans2)<<nl;
    }

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
