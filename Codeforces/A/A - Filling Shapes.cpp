#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    int n;
    cin>>n;
    if(!(n%2)){
        cout<<((int)pow(2,n/2));
    }else{
        cout<<0;
    }
}
