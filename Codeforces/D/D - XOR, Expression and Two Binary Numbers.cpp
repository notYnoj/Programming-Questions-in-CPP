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
    ll n,k;
    cin>>n>>k;
    string a, b;
    cin>>a>>b;
    long long ans;
    long long a_cont = 0;
    long long b_cont = 0;
    long long xor_cont = 0;
    long long ret;
    for(int i = 0; i<n; i++){
        if(a[i] == '1'){
            a_cont++;
        }
        if(b[i] == '1'){
            b_cont++;
        }
        if(a[i] != b[i]){
            xor_cont++;
        }
    }

    if(k%2){
        //
        long long factor = ((1LL<<static_cast<long long>(k))+1)/3;
        ret = a_cont*(n-a_cont) * factor + b_cont*(n-b_cont) * factor + xor_cont*(n-xor_cont) * factor;
    }else{
        long long factor = ((1LL<<static_cast<long long>(k)) + 2)/3;
        ret = a_cont*(n-a_cont) * factor + b_cont*(n-b_cont) * factor + xor_cont*(n-xor_cont) * (factor-1);

    }

    cout<<ret<<nl;
//the main idea here was that the only 3 numbers that will ever be present is a xor b, a, and b thus we only need to count the contributions of these numbers
//this is because notice that a xor b will be the number in the middle then the next operations yields a xor (a xor b) which gives b and b xor (a xor b)
//and this ultimately gives just these number will be present, since a xor b creates (axorb) number and operations with a xor b give the other number, there will be an equal amount of numbers
//using number theory we see that 2^(2k+1) + 1 will always  be divisibkle by 3 (i.e. 2 * 2^2k mod 3 -> 2 * 4^k mod 3 -0> 2 * 1^k mod 3 -> 2 mod 3 + 1 = divsible by 3
//then we see even is always 2 mod 3 through a similar argument. Thus the only one that will be one less is xor cont since it goes second in operations.
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
