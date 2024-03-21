#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int main(){
    int t;
    cin>>t;
    while(t--){
    cin>>a>>b>>c;
    if(((a+b)>=10) || ((a+c)>=10) || ((b+c)>=10)){
        cout << "YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
}
}
//simply check all 3 pairs.
