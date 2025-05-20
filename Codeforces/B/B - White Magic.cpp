#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem;
    }
    return os;
}
void solve(int tc){
    int n;
    cin>>n;
    vi a(n);
    for(int&i : a) cin>>i;
   
    //i can have the starting number be my biggest one then i can either have at max
    int numz = 0;
    vi b(n, INT_MAX);
    int far = -1;
    for(int i = 0; i<n; i++){
        if(a[i] == 0){
            numz++;
            if(far == -1 ) far = i;
        }else{
            if(i>0) {
                if(a[i] == 0){
                    b[i]  = b[i-1];
                }else {
                    b[i] = min(a[i], b[i - 1]);
                }
            }else{
                b[i] = a[i];
            }
        }
    }
    if(far == -1){
        cout<<n<<endl;
        return;
    }
    int ans = n;
    ans -= numz;
    //i can have a +1 if the 0 is "good"
    //the zero is "good" when it can be positoned at the start of the array
    if(a[0] == 0){
        ans++;
        cout<<ans<<endl;
        return;
    }else{
        int mx = 0;
        map<int, bool> found;
        for(int i = far; i<n; i++){
            if(a[i] == mx){
                mx++;
            }
            found[a[i]] = true;
        }
        while(found[mx]){
            mx++;
        }
        for(int i = far-1; i>=0; i--){
            if(a[i] == 0){
                continue;
            }
            if(b[i] < mx){
                cout<<ans<<endl;
                return;
            }else{
                if(a[i] == mx){
                    mx++;
                    found[a[i]] = true;
                }
                while(found[mx]){
                    mx++;
                }
                found[a[i]] = true;
            }
        }
        cout<<ans+1<<endl;
    }
    //if the zero found has to the right of it the numbers between 0 1
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve(t);

    }
}
