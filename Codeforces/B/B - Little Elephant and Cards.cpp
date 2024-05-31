#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
  //we dont even need hold lol 
    //had it in my submission was thinking of ideas and forgot to remove this vector<pair<int, int>> hold;
  //count to count the total amount
    map<int, int> count;
    int needed;
  //needed = ceil(n/2)
    if(n%2){
        needed = (n/2)+1;
    }else{
        needed = (n/2);
    }
  //how many are on the left aka rightside up
    map<int, int> left;
    bool ok = false;
    int temp = 0;
    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        count[a]++;
        if(a!=b) count[b]++;
        temp = max(temp, count[a]);
        temp = max(temp, count[b]);
        left[a]++;
      //count
    }
//if can do then its good!
    if(temp>=needed){
        ok = true;
    }

    if(ok){
        vector<int> check;
        for(auto i = count.begin(); i!=count.end(); i++){
            if(i->second>=needed){
                check.push_back(i->first);
            }
        }
      //find all the possible ones place into check
        int ans = INT_MAX;
        for(int i: check){
          //go thru check 
            int x = left[i];
            if(x>=needed){
              //if greater ans = 0 immeaditely
                ans = 0;
                break;
            }else{
              //else its the minimum of needed-x and the current ans.
                ans = min(ans, needed-x);
            }
        }
        cout<<ans;

    }else{
      //cout -1 if not good
        cout<<-1;
    }



}
