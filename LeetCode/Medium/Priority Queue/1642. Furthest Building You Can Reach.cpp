class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();
        for(int i = 1; i<n; i++){
            int diff = heights[i] - heights[i-1];
            if(diff>0){
                bricks-=diff;
                pq.push(diff);
                if(ladders==0 && bricks<0){
                    return i-1;
                }
                if(bricks<0){
                    bricks+=pq.top();
                    ladders--;
                    pq.pop();
                }
                
            }
        }
        return n-1;
    }
};
