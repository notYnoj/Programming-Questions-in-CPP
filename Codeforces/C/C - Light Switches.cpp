#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    //find min and max it cout this one
    //if we get one where its mroe than it than we cant yk type shit
    vector<bool> comps_found(2*k, false);
    for(int i = 0; i<n; i++){
        int z = a[i]%(2*k);
        int new_z = (z+k)%(2*k);
        if(comps_found[new_z]){
            cout<<"-1\n";
            return;
        }else{
            comps_found[z] = true;
        }
    }
    int mod_final = a[n-1]%(2*k);
    int add = 0;
    for(int i = 1; i<k; i++){
        if(comps_found[(mod_final+i)%(2*k)]){
            add = i;
        }
    }
    int ans = a[n-1]+add;
    for(int i =0; i<n; i++){
        if(((ans-a[i])/k)%2){
            cout<< -1<<'\n';
            return;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
