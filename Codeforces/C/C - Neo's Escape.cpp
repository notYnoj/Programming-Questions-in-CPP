#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pqI priority_queue<ll,vector<ll>, greater<int>>
#define pqD priority_queue<ll>
using namespace std;
template<typename Tval>
ostream& operator<<(ostream& os, const vector<Tval>& vec) {
		for (const auto& elem : vec) {
				os << elem << " ";
		}
		return os;
}
class Compare {
public:
		bool operator()(pii a, pii b)
		{
				if (a.first < b.first) {
						return true;
				}
				else if (a.first == b.first
								 && a.second > b.second) {
						return true;
				}

				return false;
		}
};
void solve(){
	int n;
	cin>>n;
	//i need to do this in o(N) or o(nlogn)
	//if i sort all things i must do n^2logn
	vi a(n);
	priority_queue<pii, vector<pii>, Compare> pq;
	map<int, int> mp;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		pq.push({a[i], i});
		mp[i] = false;
	}
	int ans = 0;
	while(!pq.empty()){
		auto top = pq.top();
		pq.pop();
		int i = top.second;
		if(mp[i]) continue;
			int r = i;
			int l = i;
			while(r<n){
				if(a[i] == a[r]){
					r++;
				}else{
					break;
				}
			}
			while(l>=0){
				if(a[i] == a[l]){
					l--;
				}else{
					break;
				}
			}
			l++;
			r--;
			if(mp[l-1] || mp[r+1]){
				//continue;
			}else{
				ans++;
			}
			for(int nt = l; nt<=r; nt++){
				mp[nt] = true;
			}
	}
	cout<<max(1,ans)<<endl;	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

