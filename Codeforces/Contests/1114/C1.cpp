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
    string a,b;
    cin>>a>>b;
    //01010
    //0011 -> 1001 or 1100 -> 0110
    if(n<3){
        if(a == b){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }else{
        array<int, 2> az{};
        array<int, 2> bz{};
        for(int i = 0; i<n; i++){
            if(i%2){
                if(a[i] == '1'){
                    az[0]++;
                }
                if(b[i] == '1'){
                    bz[0]++;
                }
            }else{
                if(a[i] == '1'){
                    az[1]++;
                }
                if(b[i] == '1'){
                    bz[1]++;
                }
            }
        }
        if( az[0]== bz[0] && az[1] == bz[1]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
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