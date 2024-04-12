#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
int arr[mxN];
int n, k;
bool check(int needed, int cur, int i){
    if(i == n){
        return false;
    }
    if(arr[i]>=needed){
        return true;
    }

    int a = needed - arr[i];
    if(a>cur){
        return false;
    }else{
        return check(needed-1, cur-a, i+1);
    }
}
int search(int i){
    int l = arr[i];
    int r = arr[i]+k;
    while(l<r){
        int mid = (l+r)/2+1;
        if(check(mid, k, i)){
            l = mid;
        }else{
            r = mid-1;
        }
    }
    return l;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        cin >>n>>k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int mx = 0;
        for(int i = 0; i<n-1; i++){
            mx = max(mx, search(i));
        }
        mx = max(arr[n-1], mx);
        cout<<mx<<"\n";
    }

}
