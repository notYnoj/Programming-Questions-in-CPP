#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    //everything at the end to be as maximum as possible, once u get to the point where ai>aj wahtever we do, make everything minimal
    vector<int> numbers(n);
    for(int i = 0; i<n; i++){
        cin>>numbers[i];
        numbers[i] = abs(numbers[i]);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        int a = 0, b=0;
        for(int j = i-1; j>=0; j--){
            //if i is negative, even if numbers[j] is also negatigve it will be counted
            if(numbers[j]<numbers[i]){
                a++;
            }
        }
        for(int j = i+1; j<n; j++){
            //if i is positve
            if(numbers[j]<numbers[i]){
                b++;
            }
        }
        ans+=min(a,b);
    }
    cout<<ans;
 
}
