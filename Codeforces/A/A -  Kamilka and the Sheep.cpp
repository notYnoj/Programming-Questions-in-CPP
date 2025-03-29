#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++) cin>>arr[i];
        cout<<*max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end())<<'\n';
    }
}
