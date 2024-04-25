#include <bits/stdc++.h>
using namespace std;
int v[70000], ans[70000];
int get_bit(int k, int b){
    return (k>>b) & 1;
}

int main(){
    memset(ans, 0, sizeof(ans));
    int n;
    cin>>n;
  // xor of 2 numbers with 1 in between is simplified to the xor of 2 numbers
  // (x^y) ^ (y^z) == x^z
    for(int i = 1; i<n; i++){
        cout<<"XOR "<<1<<" "<<i+1<<endl;
        cin>>v[i];
    }
    pair<int, int> a = {-1,-1};
    map<int, int> hold;
    for(int i = 1; i<n; i++){
        if(!v[i]){
            a = {0, i};
            break;
        }
        if(hold.find(v[i]) != hold.end()){
            a = {hold[v[i]], i};
            break;
        }
        hold[v[i]] = i;
    }
    if(a.first != -1){
        cout<<"AND "<<a.first+1<<" "<<a.second+1<<endl;
        cin>>ans[a.first+1];
        ans[a.second+1] = ans[a.first+1];
        int x = ans[a.second+1];
        for(int i = 1; i<=n; i++){
            if(i == a.second+1 || i == a.first+1) continue;
            for(int bit = 0; bit<17; bit++){
                if(get_bit(x, bit)){
                    if(!(get_bit(v[a.second], bit) ^ get_bit(v[i-1], bit))){
                        ans[i] += (1<<bit);
                    }
                }else{
                    if((get_bit(v[a.second], bit) ^ get_bit(v[i-1], bit))){
                        ans[i] += (1<<bit);
                    }
                }
            }
        }
    }
    //0 1 2 3 4 5 6 7
    //there has to be one that is equal to 1 since its a permutation
    //next we find what number this 0, i are
    //we can check which one has 1 by doing AND with 1 that has the same bit as first one
    if(a.first == -1) {
        int x = -1;
        for (int i = 1; i < n; i++) {
            if(v[i] == 1){
                a = {0, i};
                break;
            }
        }
        for(int i = 1; i<n; i++){
            if((v[i]&1) == 0){
                x = i;
                break;
            }
        }
        int check, i_num;
        cout<<"AND "<< 1<<" "<<1+x<<endl;
        cin>>check;
        cout<<"AND "<<a.first+1<<" "<<a.second+1<<endl;
        cin>>i_num;
        //if we know that the first bit of 0 is 1, i is thus 0
        if((check & 1)){
            ans[a.second+1] = i_num;
            ans[a.first+1] = i_num+1;
        }else{
            ans[a.second+1] = i_num+1;
            ans[a.first+1] = i_num;
        }
        for(int i = 1; i<=n; i++){
            if(i == a.second+1 || i == a.first+1) continue;
            for(int bit = 0; bit<17; bit++){
                if(get_bit(ans[a.first+1], bit)){
                    //1 2 3 4 5 6 7
                    if(get_bit(v[i-1], bit) == 0){
                        ans[i] += (1<<bit);
                    }
                }else{
                    if(get_bit(v[i-1], bit)){
                        ans[i] += (1<<bit);
                    }
                }
            }
        }
    }
//3 2 0 1 i+1 is in i

    cout<<"!";
    for(int i = 1; i<=n; i++){
        cout<<" "<<ans[i];
    }

}

