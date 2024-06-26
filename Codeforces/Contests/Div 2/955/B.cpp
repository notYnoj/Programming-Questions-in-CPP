#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        int mod = x%y;
        if((y-mod)>k){
            cout<<(x+k)<<"\n";
        }else{
            k-=(y-mod);
            x+=(y-mod);
            while(x%y == 0){
                x/=y;
            }
            bool done = false;
            while(x!= 1){
                int n_mod = x%y;
                if((y-n_mod)>k){
                    cout<<(x+k)<<"\n";
                    done = true;
                    break;
                }else{
                    k-=(y-n_mod);
                    x+=(y-n_mod);
                    while(x%y == 0){
                        x/=y;
                    }
                }
            }
            if(done){
                continue;
            }
            x= x+ (k%(y-1));
            cout<<x<<"\n";
        }
    }
}
