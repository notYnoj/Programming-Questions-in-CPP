#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> mp;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0, j=1; j<n; i++, j++){
        string a = "";
        a+=s[i];
        a+=s[j];
        mp[a]++;
    }
    int a = 0;
    string t;
    for(auto i: mp){
        if(i.second>a){
            a = i.second;
            t = i.first;
        }
    }
    cout<<t;
}
