#include <bits/stdc++.h>
using namespace std;
//distance travled mod n = meeting point thus travel however there are still a few left thus since 
//we know that the remaining balance is like t+d = 0 mod n thus t = -d thus they must meet all meet 
//after t at the beginning thus keep moving until they meet (use all parts of the puzzle frfr)
int main(){
    auto query1 = [](string to_move) -> vector<string>{
        cout<<"next ";
        for(char c: to_move){
            cout<<c<<' ';
        }
        cout<<endl;
        cout.flush();
        int k;
        cin>>k;

        vector<string> ans;
        for(int i = 0; i<k; i++){
            string kt;
            cin>>kt;
            if(kt == "stop") exit(0);
            ans.push_back(kt);
        }
        return ans;
    };
    int ptr = 0;
    bool br = true;
    while(br){
        ptr++;
        vector<string> ans;
        if(ptr%2  == 0){
            ans = query1("01");
        }else{
            ans = query1("1");
        }
        if(ptr != 1 && ans.size() == 2){
            if(ptr%2){
                ptr++;
                query1("01");
            }
            br = false;
        }
    }
    vector<string> ans = query1("0123456789");
    while(ans.size() != 1){
        ans = query1("0123456789");
    }
    cout<<"done"<<endl;
    cout.flush();
}
