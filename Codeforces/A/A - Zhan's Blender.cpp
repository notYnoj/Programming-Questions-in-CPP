#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        int z = ceil(((double)n/(double)min(m,k)));
        cout<<z<<"\n";
    }
}
