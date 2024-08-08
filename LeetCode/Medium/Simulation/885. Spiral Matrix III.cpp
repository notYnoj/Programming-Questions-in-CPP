class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int i, int j) {
        vector<vector<int>> ans;
        int amnt = rows*cols;
        //once right/left, once up/down
        int sz = 1;
        int direction = 0;
        while(ans.size()!=amnt){
            int copy = sz;
            if(direction == 0){
                while(sz--){
                    if(i<rows && j<cols && i>=0 && j>=0){
                        ans.push_back({i,j});
                    }
                    j++;

                }
                sz = copy;
                while(sz--){
                    if(i<rows && j<cols && i>=0 && j>=0){
                        ans.push_back({i,j});
                    }
                    i++;
                }
                direction = 1;
                
            }else{
                while(sz--){
                    if(i<rows && j<cols && i>=0 && j>=0){
                        ans.push_back({i,j});
                    }
                    j--;A

                }
                sz = copy;
                while(sz--){
                    if(i<rows && j<cols && i>=0 && j>=0){
                        ans.push_back({i,j});
                    }
                    i--;
                }
                direction = 0;
            }
            sz = ++copy;
        }
        return ans;
    }
};
