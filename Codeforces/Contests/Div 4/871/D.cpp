#include <bits/stdc++.h>
using namespace std;
bool recur(int a, int m){
    bool can = false;
    if(a == m){
        return true;
    }
    if(a%3 == 0){
        can = recur(a/3, m);
        if(can == true){
            return true;
        }
        can = recur(2*a/3, m);
    }
    return can;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n==m){cout<<"YES\n"; continue;}
        if(n%3 !=0){
            cout<<"NO\n";
        }else {
            int pile1 = n/3;
            if(pile1==m||recur(pile1, m)){
                cout << "YES\n";
                continue;
            }
            int pile2 = 2*n/3;
            if(pile2==m||recur(pile2,m)) {
                cout <<"YES\n";
                continue;
            }
            cout<<"NO\n";
        }
    }
}
