#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<vector<int>> grid(n+1);
    vector<int> dsu(n+1);
    iota(dsu.begin(), dsu.end(), 0);
    if(n == 2) cout<<"1 1\n";
    else{
        //all disconnected can be grouped into 1
        // non disconnected must form own
        //all other ones can form own for their own sake
        auto find = [=](int a)->int{
            if(dsu[a] == a){
                return a;
            }else{
                dsu[a] = find(a);
            }
        };
        auto merge = [=](int a, int b){

        };
        for(int i =0; i<n; i++){

        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
