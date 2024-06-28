#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s = "";
    bool append_b = true;
    for(int i = 0; i<n/2; i++){
        if(i %2 == 0){
            append_b = true;
            s+="aa";
        }else{
            append_b = false;
            s+="bb";
        }
    }
    if(s.size() != n){
        if(append_b) s+="b";
        else s+="a";
    }
    assert(s.size() == n);
    cout<<s;

}
