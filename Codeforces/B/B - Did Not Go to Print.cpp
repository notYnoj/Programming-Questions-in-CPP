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
    string s;
    cin>>s;
    vector<bool> printed(n);
    deque<int> memory;
    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            memory.push_front(i);
        }
        if(s[i] == '2'){
            if(memory.empty()){
                printed[i] = true;
            }else{
                printed[memory.front()] = true;
                memory.pop_front(); 
            }
        }
        if(s[i] == '3'){
            printed[i] = true;
        }
    }
    int ans = 0;
    for(int i = 0; i<n;i++){
        ans+=(!printed[i]);
    }
    cout<<ans<<nl;
    for(int i = 0; i<n; i++){
        if(!printed[i]){
            cout<<i+1<<' ';
        }
        cout<<nl;
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
