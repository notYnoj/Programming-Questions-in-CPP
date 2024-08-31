class Solution {
public:
    using v = pair<double, int>;
    vector<vector<v>> adj;

    inline void create_adj(int n, vector<vector<int>>& edges, vector<double>& succProb) {
        adj.resize(n);
        int eN = edges.size();
        for (int i = 0; i < eN; i++) {
            int v0 = edges[i][0], v1 = edges[i][1];
            adj[v0].push_back({succProb[i], v1});
            adj[v1].push_back({succProb[i], v0});
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n, 0);
        create_adj(n, edges, succProb);
        priority_queue<v, vector<v>> pq;
       
        pq.push({1.0, start});
        prob[start] = 1.0;

        while (!pq.empty()) {
            auto [cur_prob, i] = pq.top();
            pq.pop();
        //    cout<< i<<","<<cur_prob<<endl;
            for (auto [next_prob, j] : adj[i]) {
                double new_prob = cur_prob * next_prob;
                if (new_prob > prob[j]) {
                    prob[j] = new_prob;
                //    cout<< i<<","<<j<<","<<new_prob<<endl;
                    pq.push({new_prob, j});
                }
            }
        }
        return prob[end];
    }
};
//literally js dijkstras from start to end
