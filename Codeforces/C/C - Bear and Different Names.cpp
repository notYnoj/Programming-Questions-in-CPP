#include <bits/stdc++.h>
using namespace std;
int n,k;
void generate(vector<string>& strings){
    int a = 0;
    int b = 1;
    while(strings.size()<n){
        if(b%26 == 0){
            b = 0;
            a++;
        }
        string s = "";
        char first = toupper(a + 'a');
        char second = b+'a';
        b++;
        s+=first;
        s+=second;
        strings.push_back(s);
    }
}
int main(){
    cin>>n>>k;
    vector<bool> hold(n, true);
    for(int i = k-1; i<n; i++){
        string s;
        cin>>s;
        s=="YES"?hold[i] = true: hold[i] = false;
    }
    vector<string> strings;
    generate(strings);
    for(int i =0; i<n; i++){
        if(!hold[i]){
            strings[i] = strings[i-k+1]; //it wont ever affect anything otehr than endpoiints use endpoints thus
        }
    }
    for(string s: strings){
        cout<<s<<" ";
    }
}
