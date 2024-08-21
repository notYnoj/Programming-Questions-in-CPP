#include <bits/stdc++.h>
using namespace std;
//lol remember that if two things dont have the same thing that doesnt mean that all the children have to be different
//(logic -> i easily found out that odds and evens create primes thus we only have to make sure that odds and evens are different aka we can have all odds be 1 
//and all evens be 2 -> thus when odd connects with even they wont hvae the same however difference by 2 is also prime thus we can js make every other (aka +2) different
//and were done
void solve(){
    int n;
    cin>>n;
    if(n == 1 ){
        cout<<"1\n"<<"1\n";
    }else if( n ==2){
        cout<<"2\n"<<"1 2\n";
    }else if(n == 3){
        cout<<"2\n"<<"1 2 2 \n";
    }else if(n == 4){
        cout<<"3\n"<<
              "1 2 2 3\n";
    }else if(n==5){
        cout<<"3\n"<<
              "1 2 2 3 3\n";
    }else if(n==6){
        cout<<"4\n"<<
              "1 2 2 3 3 4\n";
    }else{
        cout<<4<<'\n';
        for(int i = 1; i<=n; i++){
            if(i%2){
                if(((i-1)/2) % 2){
                    cout<<"1 ";
                }else{
                    cout<<"2 ";
                }
            }else{
                if((i/2) % 2){
                    cout<<"3 ";
                }else{
                    cout<<"4 ";
                }
            }
        }
        cout<<"\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
