#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> hold(3, INT_MAX);
        for(int i = 0; i<n; i++){
            string s;
            int t1;
            cin>>t1>>s;
            if(s == "01"){
                hold[0] = min(hold[0],t1);
            }else if(s == "10"){
                hold[1] = min(hold[1], t1);
            }else if(s == "11"){
                hold[2] = min(hold[2], t1);
            }
        }
        if(hold[0] == INT_MAX || hold[1] == INT_MAX){
            if(hold[2] == INT_MAX){
                cout<<-1<<"\n";
            }else{
                cout<<hold[2]<<"\n";
            }
        }else{
            cout<<min(hold[0]+hold[1], hold[2])<<"\n";
        }
    }
}
