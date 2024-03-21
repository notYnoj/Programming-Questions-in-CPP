#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> s;
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            s.insert(a);
        }
        cout<<s.size()<<"\n";
    }
}
//basically since we have n copies we can always js get the best path choosing the smallest at i then 2nd smallest at i+1... 
//so we js need to find the size of the unique integers
//we use set!
