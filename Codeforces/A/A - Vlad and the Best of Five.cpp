#include <bits/stdc++.h>
using namespace std;
int t;
void solve(){
    string s;
    cin>>s;
    int arr[2] = {0};
    for(int i = 0; i<5; i++){
        if(s[i] == 'A'){
            arr[0]++;
        }else{
            arr[1]++;
        }
    }
    char b = arr[1]>arr[0]?'B':'A';
    cout<<b<<"\n";
}
int main(){
    cin>>t;
    while(t--){
        solve();
    }
}
