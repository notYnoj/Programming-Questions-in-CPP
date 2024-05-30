#include <bits/stdc++.h>
#define ll long long
#define stoi stoll
using namespace std;
ll helper1(string s1){
    ll a = 0;
    if(s1.size() == 1){
        for(int i= s1[0]-'0'; i<=9; i++){
            a++;
        }
    }else{
        int n = s1.size();
        if(n == 2){
            for(int i = 11; i<=99; i+=11){
                if(i>=stoi(s1)){
                    a++;
                }
            }
        }else {
                string temp = "";
                string temp2 = "1";
                for(int i = 1; i<n-1; i++){
                    temp+=s1[i];
                    temp2+="0";
                }
                a+=((9-(s1[0]-'0'))*(ll)pow(10, temp.size()));
                a+=(stoi(temp2)-stoi(temp));
                if(s1[0]<s1[n-1]){
                    a--;
            }
        }
    }
    return a;
}
ll helper2(string s1){
    ll a = 0;
        int n = s1.size();
        if(n == 2){
            for(int i = 11; i<=99; i+=11){
                if(i<=stoi(s1)){
                    a++;
                }
            }
        }else {
            string temp = "";
            for(int i = 1; i<n-1; i++){
                temp+=s1[i];
            }
            a+=(((s1[0]-'0')-1)*(ll)pow(10, temp.size()));
            a+=(stoi(temp))+1;
            if(s1[0]>s1[n-1]){
                a--;
            }
        }
    return a;
}
int main(){
    ll l, r;
    cin>>l>>r;
    ll ans = 0;
    string biggest = to_string(r);
    string smallest = to_string(l);
    if(l<10 && r<10){
        for(ll i = l; i<=r; i++){
            ans++;
        }
    }
    else if(biggest.size() ==smallest.size()){
        int n = biggest.size();
        if(n ==2 ){
            for(int i = 11; i<=99; i+=11){
                if(l<=i && i<=r){
                    ans++;
                }
            }
        }else {
            for (int i = smallest[0] - '0' + 1; i < biggest[0] - '0'; i++) {
                ans += ((long long) pow(10, n - 2));
            }
            if (biggest[0] == smallest[0]) {
                string temp = "";
                string temp2 = "";
                for (int i = 1; i < n - 1; i++) {
                    temp += smallest[i];
                    temp2 += biggest[i];
                }
                if (temp == temp2) {
                    int x = biggest[0]-'0';
                    int y = smallest[n-1]-'0';
                    int z = biggest[n-1]-'0';
                    if (y<=x && x<=z) {
                        ans = 1;
                    }
                } else {
                    ans += (stoi(temp2) - stoi(temp) - 1);
                    if (smallest[0] >= smallest[n - 1]) {
                        ans++;
                    }
                    if (biggest[0] <= biggest[n - 1]) {
                        ans++;
                    }
                }
            } else {
                string temp = "";
                string temp1 = "";
                string temp2 = "1";
                for (int i = 1; i < n - 1; i++) {
                    temp += smallest[i];
                    temp1 += biggest[i];
                    temp2 +="0";
                }
                ans += (stoi(temp2)-stoi(temp));
                ans += (stoi(temp1) + 1);
                if (smallest[0] < smallest[n - 1]) {
                    ans--;
                }
                if (biggest[0] > biggest[n - 1]) {
                    ans--;
                }
            }
        }
    }else{
        for(ll i = (ll)smallest.size()+1; i<biggest.size(); i++){
            ans+=(9*(ll)pow(10,i-2));
        }
        ans+=helper1(smallest);
        ans+=helper2(biggest);
    }
    cout<<ans;
 
}
