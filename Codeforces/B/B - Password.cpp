#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6+5;

int KMParr[mxN];
string s;
void KMP() {
    //kmp, if words repeat so does the array increasing, for KMP the distance u move is len - arr[len];
    KMParr[0] = 0;
    int temp = 0;
    for (int i = 1; i < s.size(); i++) {
        while (temp != 0 && s[i] != s[temp]) {
            temp = KMParr[temp - 1]; <- this is needed
        }
        if (s[i] == s[temp]) {
            temp++; <- if equal add 1 becuase it equals prefix
            KMParr[i] = temp;
        }else{
            KMParr[i] = 0; <- if nothing equals prefix reset it to be able to shift by all of len
        }
        //you know we are shifting by something but how much? well if we get everything correct up to some point then if the final part has something equal to the prefix yk we have to check there!, len of array (what u got correct, - equivalent suffix is where the equivalent suffix begins, when u shfit)
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
