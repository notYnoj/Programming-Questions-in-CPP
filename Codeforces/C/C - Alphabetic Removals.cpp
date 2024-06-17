#include <bits/stdc++.h>
using namespace std;
const int mxN = 4e5+5;
bool bad[mxN];
int main(){
    memset(bad, false, sizeof(bad));
    int n,k;
    cin>>n>>k;
    if(n==k){
        cout<<"";
    }else {
        string s;
        vector<pair<int, int>> z;
        cin>>s;
        for(int i = 0; i<n; i++){
            z.push_back({s[i]-'a', i});
        }
        sort(z.begin(), z.end());
        for(int i = 0; i<k; i++){
            bad[z[i].second] = true;
        }
        string nt = "";
        for(int i = 0; i<n; i++){
            if(!bad[i]) nt+=s[i];
        }
        cout<<nt;
 
 
    }
}
