#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin>>t;
    while(t--){
        int respones;
        cin>>respones;
        vector<vector<int>> xy;
        for(int i = 0; i<respones; i++){
            int a, b;
            cin>>a>>b;
            xy.push_back({b,a,i+1});
        }
        sort(xy.begin(), xy.end());
        int r = respones-1;
        for(int i = r; i>=0; i--){
            if(xy[i][1]<=10){
                cout<<xy[i][2]<<"\n";
                break;
            }
        }
    }
}
//sort find the best then cout
