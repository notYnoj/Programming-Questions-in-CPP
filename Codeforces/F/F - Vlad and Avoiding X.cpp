#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
string s[7];
ll ans;
ll dx[5]={0,1,1,-1,-1},dy[5]={0,1,-1,-1,1};
void dfs(ll sum)
{
    if(sum>=ans)
        return;
    for(ll i=1;i<6;i++)
    {
        for(ll o=1;o<6;o++)
        {
            if(s[i-1][o-1]=='B'&&s[i-1][o+1]=='B'&&s[i+1][o-1]=='B'&&s[i+1][o+1]=='B'&&s[i][o]=='B')
            {
                for(ll l=0;l<5;l++)
                {
                    s[i+dx[l]][o+dy[l]]='W';
                    dfs(sum+1);
                    s[i+dx[l]][o+dy[l]]='B';
                }
                return;
            }
        }
    }
    ans=min(ans,sum);
}
int main()
{
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<7;i++)
            cin>>s[i];
        ans=1e5;
        dfs(0);
        cout<<ans<<"\n";
    }
    return 0;
}

//i had a similar idea but I used recursion, and I messed it up. Use For loops, they are nicer than recursion....
