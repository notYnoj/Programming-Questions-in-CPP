#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6+5;

int KMParr[mxN];
string s;
void KMP() {
    KMParr[0] = 0;
    int temp = 0;
    for (int i = 1; i < s.size(); i++) {
        while (temp != 0 && s[i] != s[temp]) {
            temp = KMParr[temp - 1];
        }
        if (s[i] == s[temp]) {
            temp++;
            KMParr[i] = temp;
        }else{
            KMParr[i] = 0;
        }
    }
}
int main(){
    cin>>s;
    KMP();
    int n = s.size();
    int a = KMParr[n-1];
    int b = KMParr[a-1];
    if(a == 0){
        cout<<"Just a legend";
        return 0;
    }else{

        for(int i = 1; i<n-1; i++){
            if(a==KMParr[i]){
                b=a;
            }
        }
        if(b == 0){
            cout<<"Just a legend";
        }else{
            cout<<s.substr(0, b);
        }
    }

}
