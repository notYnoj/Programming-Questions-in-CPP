class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // first convert graph to adjacency list representation
        vector<vector<pair<int, int>>> graph(n); // i-th nodes will have graph[i] neighbors
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], distance = edge[2];
            graph[node1].emplace_back(node2, distance);
            graph[node2].emplace_back(node1, distance);
        }

        auto get_number_of_neighbors_in_distance = [&](int source) -> int {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;
            queue.emplace(0, source); // distance to node itself is 0
            set<int> visited;

            while (!queue.empty()) {
                auto [distance_to_this_node, cur_node] = queue.top();
                queue.pop();
                if (!visited.count(cur_node)) {
                    visited.insert(cur_node);
                    for (const auto& [neighbor, distance] : graph[cur_node]) {
                        int distance_from_source = distance_to_this_node + distance;
                        if (distance_from_source <= distanceThreshold) { // ensure that we're allowed to go to this node
                            queue.emplace(distance_from_source, neighbor);
                        }
                    }
                }
            }
            // actually you can return visited.size() and with math there will be nothing wrong but actually we have visited.size() - 1 neighbors since we're not neighbor of ourselves
            return visited.size() - 1;
        };

        int minimum_number = n;
        int res = -1;

        for (int source = 0; source < n; ++source) {
            int neighbors = get_number_of_neighbors_in_distance(source);
            // we iterate source from smaller to bigger this ensures that we choose node with greater value if they have equal number of neighbors
            if (neighbors <= minimum_number) {
                minimum_number = neighbors;
                res = source;
            }
        }

        return res;
    }
};
