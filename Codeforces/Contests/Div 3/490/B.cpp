#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string t;
    cin>>t;
    vector<int> divisors;
    for(int i = 1; i<=sqrt(n); i++){
        if(n%i == 0){
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());
    auto last = unique(divisors.begin(), divisors.end());

    // Erase the extra characters
    divisors.erase(last, divisors.end());
    for(int i: divisors){
        reverse(t.begin(), t.begin() + i);
    }
    cout<<t;
}
