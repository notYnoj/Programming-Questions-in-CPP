//lol done during cshs
#include <bits/stdc++.h>
using namespace std;
int c;
int a;
char ch;
string s;
void solve(){
    cin>>a;
    cin>>ch;
    cin>>s;
    if(ch == 'g'){
        cout<<0<<"\n";
        return;
    }
    int pos = -1;
    int gpos = -1;
    int cloest = -1;
    //max variable
    int t = 0;
    for(int i = 0; i<a;){
        //looping back if need be
        if(s[i] == 'g' && cloest==-1){
            cloest = i;
        }
        //if at ch go until u find one
        if(ch == s[i]){
            pos = i;
            i++;
            while(i<a) {
                if (s[i] == 'g') {
                    gpos = i;
                    if(cloest==-1){
                        cloest = i;
                    }
                    break;
                }
                i++;
            }
        }
        t = max(t, gpos-pos);
        i++;
    }
  //if we gotta loop back around
    if(pos>gpos){
        t = max(t, (a-pos)+cloest);
    }
    cout<<t<<"\n";

}
int main() {
    cin>>c;
    while(c--){
        solve();
    }
}
