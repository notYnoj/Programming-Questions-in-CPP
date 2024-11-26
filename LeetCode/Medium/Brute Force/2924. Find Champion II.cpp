class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int> bigger;
        for(int i = 0; i<n; i++){
            bigger.insert(i);
        }
        for(int i = 0; i<edges.size(); i++){
            bigger.erase(edges[i][1]);
        }
        if(bigger.size() >1){
            return -1;
        }else{
            return *bigger.begin();
        }
    }
};
