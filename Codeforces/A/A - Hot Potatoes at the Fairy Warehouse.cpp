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


void solve(int t){
    
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int r = 0;
    int b = 0;
    int len = 0;
    for(int i = 0; i<2*n; i++){
        //sometimes theres like hotpotoes at the start and end but since its cyclic it cna be bad
        //
        if(s[i] == '0') {
            if(len == 0) continue;
            else{
                int better, worse;
                if(len%2){
                    //5 -> 3 + 2
                    better = len/2+1;
                    worse = len/2;
                }else{
                    //4 -> 3 and 1
                    better = len/2+1;
                    worse = len/2-1;
                }
                if(i%2){
                    r+=better;
                    b+=worse;
                }else{
                    r+=worse;
                    b+=better;
                }
                len = 0;

            } 
        }else{
            len++;
        }
    }
    if(len != 0){
        if(s[0] == '0'){
            int better, worse;
            if(len%2){
                    //5 -> 3 + 2
                better = len/2+1;
                worse = len/2;
            }else{
                    //4 -> 3 and 1
                better = len/2+1;
                worse = len/2-1;
            }
            b+=better;
            r+=worse;
        }else{
            //brb
            //even is same for both odd is red gets -1
            int better, worse;
            if(len%2){
                worse = len/2;
                better = len/2+1;
            }else{
                worse = len/2;
                better = len/2;
            }
            r+=better;
            b+=worse;
        }
    }
    cout<<r << ' '<< b<<nl; 
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    cin>>t;
    while(t--){solve(t);}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
