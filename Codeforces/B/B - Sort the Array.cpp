#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    vector<long long> v1(n);
    vector<long long> v2(n);
    int l = -1;
    int r = -1;
    for(int i = 0; i<n; i++){
        cin>>v1[i];
        v2[i] = v1[i];
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i<n; i++){
        if(v1[i]!=v2[i]){
            if(l==-1) {
                l = i;
            }else{
                r = i+1;
            }
        }
    }
    reverse(v2.begin()+l, v2.begin()+r);
    for(int i = 0; i<n; i++){
        if(v2[i] != v1[i]){
            cout<<"no";
            return 0;
        }
    }
    if(l == -1 and r == -1){
        cout<<"yes"<<endl;
        cout<<1<<" "<< 1;
        return 0;
        
    }
    cout<<"yes"<<endl;
    cout<<l+1<<" "<< r;
 
}
