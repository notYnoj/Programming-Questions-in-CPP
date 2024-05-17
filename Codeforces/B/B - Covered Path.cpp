#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int start, end;
    cin>>start>>end;
    int time, d;
    cin>>time>>d;
    int ans = start + end;
    time-=2;
    if(d ==0){
        ans+= (time)*start;
        cout<<ans;
    }else {
        //we want the final to be as close
        //lets have hte final part be closest to the tallest one
        if(start>end){
            while(end+d<start){
                end+=d;
                ans+= end;
                time--;
            }
        }else{
            while(start+d<end){
                start+=d;
                ans+= start;
                time--;
            }
        }
        if(time%2){
            while(time != 1){
                end+=d;
                start+=d;
                ans+=end;
                ans+=start;
                time-=2;
            }
            ans+=(min(end,start)+d);
        }else{
            while(time){
                end+=d;
                start+=d;
                ans+=end;
                ans+=start;
                time-=2;
            }
        }
        cout<<ans;
    }
}
