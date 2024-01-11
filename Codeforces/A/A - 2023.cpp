#include <bits/stdc++.h>
using namespace std;
int t;
void solve(){
    //y numbers missing, y numbers that multiply to req
    int x, y;
    cin>>x>>y;
    long long pro = 1;
    for(int i = 0; i<x; i++){
        int z;
        cin>>z;
        if(z == 0) {
            cout << "NO";
            return;
        }
        pro*=z;
    }
    if(2023%pro != 0) {
        cout << "NO";
        return;
    // lol dont laugh i didnt realize that i could js do all 1s until i looked back and saw no sort of restraint.
    }else{
        int req = 2023/pro;
        if(req<1){
            cout<<"NO";
            return;
        }
        if(y == 1){
            cout<<"YES"<<endl;
            cout<<req;
        }else if(y == 2){
            cout<<"YES"<<endl;
            cout<<1<<" "<< req;
        }else{
            cout<<"YES"<<endl;
            for(int i = 1; i<y; i++){
                cout<<1<<" ";
            }
            cout<<req;
        }

    }
}
int main() {
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}
