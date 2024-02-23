class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // grid
        vector<vector<pair<int, int>>> grid(n);
        for (const auto& flight : flights) {
            int from = flight[0], to = flight[1], price = flight[2];
            grid[from].emplace_back(to, price);
        }
        
        // Dijkstra's
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // Structure of pq element: {price, city, stops}
        pq.push({0, src, -1}); // Push source with price 0 and -1 stops (testcase 1)
        
        // memo or else TLE
        unordered_map<int, unordered_map<int, int>> memo;
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int price = top[0], city = top[1], stops = top[2];
            
            if (city == dst) return price; // If destination reached return price
            
            if (stops < k) { // dont go over k
                for (const auto& neighbor : grid[city]) {
                    int nextCity = neighbor.first, nextPrice = neighbor.second;
                  //if there is nothing in our memo, or if its smaller
                    if (memo[nextCity][stops + 1] == 0 || memo[nextCity][stops + 1] > price + nextPrice) {
                        memo[nextCity][stops + 1] = price + nextPrice;
                        pq.push({price + nextPrice, nextCity, stops + 1});
                    }
                }
            }
        }
        
        return -1; // If destination not reached
    }
};
//not too bad of a question 6:41 not the worst not the best! got a TLE though which slowed me down :/
