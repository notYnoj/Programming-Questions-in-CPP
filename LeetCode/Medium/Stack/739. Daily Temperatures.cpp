class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        int n = tmp.size();
        vector<int> res(n, 0);
        stack<int> stack;
        stack.push(0);
      //push stack when find oen that is bgiger than than the top calculate otherwise push it again.
        for(int i = 1; i<n; i++){
            if(tmp[i]>tmp[stack.top()]){
                while(!stack.empty() && tmp[i]>tmp[stack.top()]){
                    int temp = stack.top();
                    stack.pop();
                    res[temp] = i-temp;
                }
            }
            stack.push(i);
        }
        return res;
    }
};
