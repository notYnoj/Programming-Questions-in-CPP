#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
const int mxN = 150010;
vector<ll> grid[mxN];
ll parent[mxN], c[mxN];
ll gauss(ll a){
    return (a*(a-1)/2);
}
ll get(ll a){
    if(parent[a] == a){
        return a;
    }else{
        return parent[a] = get(parent[a]);
    }
}
void merge(ll a, ll b){
    int x= get(a);
    int y = get(b);
    if(x == y){
        return;
    }else{
        c[x] += c[y];
        parent[y] = x;
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        parent[i]=i;
        c[i] = 1;
    }
    for(int i = 0; i<m; i++){
        ll a,b;
        cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
        merge(a,b);
    }
    bool check = true;
    map<ll, ll> mp;
    for(ll i = 1; i<=n; i++){
        mp[get(i)] += grid[i].size(); //handshaking lemma 
    }

    for(ll i = 1; i<=n; i++){
        ll a = get(i); // get the amount of edges in this undirected graph
        ll g = gauss(c[a]); //for it to be good u have to have all of them connected to one another, x-y y-z y-a then x and z must also connected to a and x and z must connect
        if((mp[a]/2) != g){
            check = false;
            break;
        }
    }
    if(check){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}
