class Solution {
public:
//basically two priority queues, one keeps tracks of rooms, other keeps tracks of using rooms (cuz then u coudl have like one in 4, but then u get rid of all other ones but it will seem like thers 1 in 0 check other wrong code)
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        priority_queue<int, vector<int>, greater<int>> rooms;
        vector<int> hsh(n, 0);
        int mx = 1;
        sort(meetings.begin(), meetings.end());
        
        for(int i = 0; i<n; i++){
            rooms.push(i);
        }
        for(int i = 0; i<meetings.size(); i++){
            long long cS = meetings[i][0];
            while(!pq.empty() && pq.top().first<=cS){
                int avilable = pq.top().second;
                pq.pop();
                rooms.push(avilable);
            }
            if(rooms.empty()){
                long long e = pq.top().first + meetings[i][1] - meetings[i][0];
                int pos = pq.top().second;
                pq.pop();
                hsh[pos]++;
                pq.push({e, pos});
                mx = max(hsh[pos], mx);
            }else{
                int pos = rooms.top();
                rooms.pop();
                pq.push({meetings[i][1], pos});
                hsh[pos]++;
                mx = max(hsh[pos], mx);
            }
        }
        for(int i = 0; i<n; i++){
            if(hsh[i] == mx){
                return i;
            }
        }
        return -1;
    }
};



/*
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long,long long> >> pq;
        vector<int> hsh(n, 0);
        int mx = 1;
        sort(meetings.begin(), meetings.end());
        pq.push({meetings[0][1], 0});
        hsh[0]++;
        for(int i = 1; i<meetings.size(); i++){
            if(pq.size()<n){
                if(pq.top().first <= meetings[i][0]){
                    int t = 1e7+1;
                    int x;
                    while(!pq.empty() && pq.top().first<=meetings[i][0]){
                        if(t>pq.top().second){
                            t = pq.top().second;
                            x = pq.top().first;
                        }
                        pq.pop();
                    }
                    pq.push({t+meetings[i][1]-meetings[i][0], x});
                    hsh[x]++;
                    mx = max(hsh[x], mx);
                }
            }

            else{
                int nt = pq.top().first;
                int pos = pq.top().second;
                pq.pop();
                pq.push({nt + meetings[i][1]-meetings[i][0], pos});
                hsh[pos]++;
                mx = max(hsh[pos], mx);
            }
        }
        for(int i = 0; i<n; i++){
            if(hsh[i] == mx){
                return i;
            }
        }
        return -1;
    }
};
something like this lol, its logically not a hard question but the crevices are ugh! (staying up til 1am was worth it tho)
*/
