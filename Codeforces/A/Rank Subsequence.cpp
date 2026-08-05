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
    //22 22 1 0
    //22 22 1 1
    //33 33 1 2
    //44 44 1 3
    //55 55 1 4
    vector<vi> hold;
    for(int i = 0; i<n; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        hold.pb({a,b,c,d});
    }
    int ans =-1;
    for(int k = n; k>=0; k--){
        //build it greedily and just select the first one that can go here
        int idx = 0;
        int idx2 = 0; 
        while(idx2 < n && idx < k){
            int right = k - idx; //if its placed this will be the right
            int l = hold[idx2][0];
            int r = hold[idx2][1];
            int u = hold[idx2][2];
            int v = hold[idx2][3];
            if((idx+1<l || idx+1>r) && (right < u || right>v)){
                idx++; 
            }
            idx2++;
        }
        if(idx == k){
            cout<<idx<<nl;
            return;
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
