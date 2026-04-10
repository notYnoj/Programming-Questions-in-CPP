#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
using namespace std;
int t;
// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem;
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
class DSU{
public:
    vector<ll> size;
    vector<ll> parent;

    DSU(int n){
        size.resize(n);
        parent.resize(n);
        for(ll i = 0; i < n; i++){
            size[i] = 1LL;
            parent[i] = i;
        }
    }

    ll getSize(int i){
        return size[find(i)];  
    }
    ll find(int x) {
    // You need to call find on the PARENT, not on x again!
        return (parent[x] == x ? x : parent[x] = find(parent[x])); 
    }
    void merge(ll x, ll y){
        ll xp = find(x);
        ll yp = find(y);
        if(xp == yp) return;
        size[xp] += size[yp];
        parent[yp] = xp;  
    }

    int unique(){
        vector<int> found(parent.size(), 0);
        int count = 0;
        for(int i = 0; i < parent.size(); i++){
            int root = find(i);  
            if(!found[root]){
                count++;
                found[root] = true;
            }
        }
        return count;
    }
    void debug(){
        cout<<parent;
    }

};

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    //the left most digit will always be something of its own
    DSU dsu(n);
    int start = -1;
    int curmX = -1;
    for(int i = 0; i<n; i++){
        if(start == -1){
            start = a[i];
            curmX = a[i];
            continue;
        }
        if((a[i] > a[i-1] && a[i] == a[i-1] +1) || (a[i] <= a[i-1] && start < a[i] && curmX >= a[i])){
            dsu.merge(i, i-1);
            curmX = max(curmX, a[i]);
        }else{
            //we create start as new
            start = a[i];
            curmX = a[i];
        }
        //if its within teh range of (start - max] we can do it or if its +1 from the previous one
    }
    int c = dsu.unique();
    cout<<c<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
}
