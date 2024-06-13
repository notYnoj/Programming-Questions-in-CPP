#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int t = 0;
    if(k==0){
        if(a.front()-1>=1){
            cout<<1;
            return 0;
        }else{
            cout<<-1;
            return 0;
        }
    }
    for(int i = 0; i<n;){
        t++;
        while(i+1<n && a[i] == a[i+1]){
            t++;
            i++;
        }
        if(t > k){
            cout<<-1;
            return 0;
        }
        else if(t==k){
            cout<<a[i];
            return 0;
        }else{
            i++;
        }
    }
    if(t==k){
        cout<<a.back();
    }else{
        cout<<-1;
    }
}
