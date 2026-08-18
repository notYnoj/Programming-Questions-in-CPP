#include <bits/stdc++.h>

using namespace std;
const long long MOD = 998244353;
template<typename T>
T modinv(T a, T m) {
        T m0=m, t, q;
        T x0=0, x1=1;
        while (a>1) {
            q = a/m;
            t = m;
            m = a%m;
            a = t;
            t=x0;
            x0=x1-q*x0;
            x1=t;
        }
        if (x1<0) x1 += m0;
        return x1;
}

void solve(){
    long long n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];
    //consider i<j
    //a[i] a[j]
    //b[k], b[n]
    //a[i] * b[k] > a[j] * b[n]
    //a[i]/a[j] > b[n]/b[k]
    //n*(n-1) probability of n,k landing at i, j
    //consider allowing a[i] and a[j]
    //E(x) = E(e1) + E(e2)  -> E(e1) = (1 if inversion else 0)/ n*n-1
    vector<long double> aRatios;
    vector<long double> bRatios; 
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            long double ratio = static_cast<long double>(a[i])/a[j];
            aRatios.push_back(ratio);
        }
    }
    for(int i =0 ; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j) continue;
            else{
                long double ratio = static_cast<long double>(b[i])/b[j];
                bRatios.push_back(ratio);
            }
        }
    }
    sort(aRatios.begin(), aRatios.end());
    sort(bRatios.begin(), bRatios.end());
    long long ans = 0;
    for(int i = 0; i<aRatios.size(); i++){
        long double cur_ratio = aRatios[i];
        //cout<<cur_ratio<<' ';
        //need cur_ratio>b[i] find first b[i] such that this is true
        auto it = lower_bound(bRatios.begin(), bRatios.end(), cur_ratio);
        if(it != bRatios.begin()){            
            ans += (it - bRatios.begin());
        }
    }
    cout<< (((ans%MOD) * modinv((n*(n-1)), MOD)) % MOD) <<'\n';


}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
