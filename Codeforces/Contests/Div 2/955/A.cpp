#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int x1, y1, x2, y2;
        cin>>x1>>x2>>y1>>y2;
        if(x1<x2){
            if(x1<=x2 && y1>=y2){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }else{
            if(x2<=x1 && y2>=y1){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }
    }
}
