//"Time Save Robloxian got this in 29 min i got this in 6 "
#include <bits/stdc++.h>
using namespace std;
int gauss(int x){
    return (x*(x+1))/2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k == 0 && n>2){
            cout<<"NO\n";
            continue;
        }
        //if we add a 1 or -1 to a number it will increase by the current amount of -1 or 1
        //if greater than 1
        //choose some a, b
        int x = 0;
        for(int a = 1; a<=n; a++){
            int b = n-a;
            if(gauss(b-1) + gauss(a-1) == k){
                x = a;
                break;
            }


        }
        if(!x){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            int b = n-x;
            for(int i = 1; i<=x; i++){
                cout<<1<<" ";
            }
            for(int i = 1; i<=b; i++){
                cout<<-1<<" ";
            }
            cout<<"\n";
        }

    }
}
