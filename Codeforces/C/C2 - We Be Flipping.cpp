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
    /* The operation we are given is pick a positive integer at pos i
    then make every index at 0 - i negative. we want to maximize the sum at the end
     */
     //the core idea is that we can make any prefix 0-i positive by appplying an operation on i+1 given that 0-i is a completely negated array
    //this can happen when we move right to left and flip if its positive
    //so what we get is an array with abs(0-i) + -ai+1 + ai+2 ...
    //find the max greedily
    ll mx = accumulate(all(a), 0LL);
    vi pre(n);
    pre[0] = abs(a[0]);
    for(int i = 1; i<n; i++){
        pre[i] = pre[i-1] + abs(a[i]);
    }
    vi suf(n);
    suf[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        suf[i] = suf[i+1] + a[i];
    }
    int idx = -1;

    for(int i = 0; i<n; i++){
        if(a[i] > 0){
        if(i == 0){
            if(mx < suf[i+1] - a[i]){
                mx = suf[i+1] -a[i];
                idx = i;
            }
        }else if(i == n-1){
            if(mx < pre[i-1] - a[i]){
                mx = pre[i-1] - a[i];
                idx = i;
            }

        }else{
            if(mx < pre[i-1] - a[i] + suf[i+1]){
                mx = pre[i-1] - a[i] + suf[i+1]; 
                idx = i;
            }
        }
    }
    }
    vi ops;
    if(idx != -1){
    int parity = 1;
    for(int i = idx-1; i>= 0; i--){
        if(a[i] * parity > 0){
            ops.pb(i + 1);
            parity *= -1;
        }
    }
     ops.pb(idx + 1);
}

    cout<<ops.size()<<nl;
    cout<<ops;
    
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