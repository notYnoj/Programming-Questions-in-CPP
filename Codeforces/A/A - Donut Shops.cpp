#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a>=c){
            cout<<-1<<" "<<b<<"\n";
        }
        else if(a<=c/b){
            cout<<1<<" "<<"-1\n";
        }else{
            cout<<1<<" "<<b<<"\n";
        }
    }
}
