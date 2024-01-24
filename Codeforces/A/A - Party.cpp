#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    int cur = 0;
    int n;
    cin>>n;
    int a[2001];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        cur=0;
        int x=a[i]; // dfs up
        while(x != -1)
        {
            x=a[x];
            c++;
        }
        ans=max(ans, c); // max
    }
    cout<<ans+1<<endl; //add 1 because we are intially saying none for the ith person but ith person needs 1 too.
}
