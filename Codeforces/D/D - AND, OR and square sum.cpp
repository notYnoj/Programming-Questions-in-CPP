#include <bits/stdc++.h>
using namespace std;
int log(long long x) {
    return 64 - __builtin_clzll(x) - 1;
}
int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    vector<vector<long long>> hold(20);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
        if(arr[i] != 0){
            int z= log(arr[i]);
            hold[z].push_back(arr[i]);
        }
    }

    long long ans = 0;
    if(n == 1){
        cout<<arr[0]*arr[0];
        return 0;
    }
    for(int i = 0; i<n; i++) ans+= ((long long)arr[i]*arr[i]);
}
