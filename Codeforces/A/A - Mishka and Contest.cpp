#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    int l = 0;
    int r = n-1;
    int ans = 0;
    bool check = false;
    for(int i = 0; i<n; i++){
        if(arr[i]>k){
            l = i;
            check = true;
            break;
        }
        ans++;
    }
    if(!check){
        cout<<ans;
    }else{
    for(int i = r; i>l; i--){
        if(arr[i]>k) {
            break;
        }
        ans++;
    }

    cout<<ans;
}
}
