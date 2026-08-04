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
    int n,k;
    cin>>n>>k;
    if(k > n-2){
        cout<<"-1\n";
        return;
    }
    if(k == 0){
        for(int i = 0; i<n; i++){
            cout<<(i%2 == 1 ? '1' : '0');
        }
        cout<<nl;
        return;
    }
    //otherwise its possible
    string ret = "";
    for(int i = 0; i<n/2; i++){
        ret+='0';
    }
    while(ret.size() < n){
        ret+='1';
    }
    //n-2 total - k is how many iterations we have to do to get there
    int add0 = 0;
    int add1 = 0;
    for(int i = 0; i< (n-k-2); i++){
        if(i%2){
            add1++;
        }else{
            add0++;
        }
    }
    ret = "";
    if(add0 > add1){
        int add0sHere = n/2 - add0;
        int add1sHere = (n - n/2) - add1;
        for(int i = 0; i<add0sHere; i++){
            ret+='0';
        }
        for(int i = 0; i<add1sHere; i++){
            ret+='1';
        }
        for(int i = 0; i<(add0 + add1);i++){
            if(i%2){
                ret+='1';
            }else{
                ret+='0'; 
            }
        }
    }else{
        for(int i = 0; i<(add0 + add1);i++){
            if(i%2){
                ret+='1';
            }else{
                ret+='0'; 
            }
        }
        int add0sHere = n/2 - add0;
        int add1sHere = (n - n/2) - add1;
        for(int i = 0; i<add0sHere; i++){
            ret+='0';
        }
        for(int i = 0; i<add1sHere; i++){
            ret+='1';
        }
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
