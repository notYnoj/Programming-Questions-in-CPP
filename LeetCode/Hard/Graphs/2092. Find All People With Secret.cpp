class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> graph(n);
        //attempt to queue this from the starting node FirstPerson
        //if the pair.first(time) is greater than he will recieve the secret then we can queue
        //it up
        for(int i = 0; i<meetings.size(); i++){
            int child = meetings[i][0];
            int parent = meetings[i][1];
            int time = meetings[i][2];
            graph[child].push_back({time, parent});
            graph[parent].push_back({time, child});
        }
        vector<bool> has(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, firstPerson});
        q.push({0,0});
        vector<int> ans;

        while(!q.empty()){
            auto i = q.top();
            q.pop();
            int time = i.first;
            int parent = i.second;
            //already dfs them
            if(has[parent]){
                continue;
            }
            has[parent] = true;
            for(auto child: graph[parent]){
                if(child.first>=time){
                    q.push({child.first, child.second});
                }
            }
        }
        for(int i= 0; i<n; i++){
            if(has[i]){
                ans.push_back(i);
            }

        }
        return ans;


    }
};
