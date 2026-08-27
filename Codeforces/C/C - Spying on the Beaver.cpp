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
    vvi tree(n);
    for(int i = 0; i<n-1; i++){
        int a;
        cin>>a; 
        a--;
        tree[i+1].pb(a);
        tree[a].pb(i+1);
    }
    //
    int m;
    cin>>m;
    vi nodes;
    for(int i = 0; i<m; i++){
        int a; 
        cin>>a;
        nodes.pb(a);
    }
    sort(all(nodes)); 
    cout<<m-1<<' ';
    //always skips 1 if found if not then its not there and we dont have to worry abt it
    for(int i = 1; i<m; i++){
        cout<<nodes[i]<<" ";
    }
    cout<<nl;


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
