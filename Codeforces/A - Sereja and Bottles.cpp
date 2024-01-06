#include <bits/stdc++.h>
using namespace std;
int n;
array<int, 2> s[100];
 
int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>s[i][0]>>s[i][1];
    }
    int z = 0;
    set<int> use;
    for (int i = 0; i<n; i++) {
        int target = s[i][1];
        for(int j = 0; j<n; j++){
            if(j!=i && s[j][0] == target && use.find(j) == use.end()){
                z++;
                use.insert(j);
            }
        }
 
    }
    cout<<n-z;
}
