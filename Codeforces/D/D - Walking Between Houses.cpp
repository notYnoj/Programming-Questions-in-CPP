#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll houses,moves,steps;
    cin>>houses>>moves>>steps;
    if(((houses-1)*moves)<steps || moves>steps){
        cout<<"NO";
    }else{
        cout<<"YES\n";
        ll cur = 1;
        bool check = true;
        while(check){
            ll needed = moves-1;
            moves--;
            if(steps-houses+1 <= needed ){
                ll a = steps - needed;
                if(cur == 1){
                    cur = 1+a;
                    cout<<cur<<" ";
                }else{
                    cur = houses-a;
                    cout<<houses-a<<" ";
                }
                for(int i = 0; i<needed; i++){
                    if(cur < houses){
                        cout<<cur+1<<" ";
                        cur++;
                    }else{
                        cout<<cur-1<<" ";
                        cur--;
                    }
                }
                check = false;
            }else{
                cout<<(cur == 1 ? houses:1)<<" ";
                if(cur == 1){
                    cur = houses;
                }else{
                    cur = 1;
                }
                steps-=houses-1;
            }
        }

    }
}
