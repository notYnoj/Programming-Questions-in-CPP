#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> add;
        int n,d;
        cin>>n>>d;
            add.push_back(1);
            //if its written at least 3 times or if d = 3 or d = 6 or d = 9
            if(n>=3 || d%3 == 0){
                add.push_back(3);
            }
            //only if divsible by 5
            if(d == 5){
                add.push_back(5);
            } 
            //if u add a number by a divisible by 6 its divisible by 7
            //thus if its 3! or more its good since this is the first 6
            if(d == 7 || n>=3){
                add.push_back(7);
            }
            //sum is divisble by 9
            //either we have a number written by a factor of 9 aka 3 *3 aka 6! is divsible by 9
            //or we have 3! and divsible by 3 or d%9 == 0
            if(n>=6 || d%9 == 0 || (n>=3 && d%3 == 0)){
                add.push_back(9);
            }
            for(int i: add){
                cout<<i<<' ';
            }
            cout<<'\n';
        }

}
