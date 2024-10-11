class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> looking_for = times[targetFriend];
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<int, vector<int>, greater<int>> seats;
        int ans = 0;
        for(int i = 0; i<times.size(); i++){
            seats.push(i);
        }
        for(auto i: times){
            int start = i[0];
            int end = i[1];
            while(!pq.empty()&&start>=pq.top().first){
                seats.push(pq.top().second);
                pq.pop();
            }
            if(start == looking_for[0] && end == looking_for[1]){
                return seats.top();
            }else{
                pq.push({end, seats.top()});
                seats.pop();
            }
        }

        return ans;
    }
};
