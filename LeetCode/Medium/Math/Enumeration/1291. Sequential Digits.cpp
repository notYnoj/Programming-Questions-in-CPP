class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int i = to_string(low).length();
        int j = to_string(high).length();
        for(int length = i; length<=j; length++){
          //cant be greater than 10 or else will become new number
            for(int i = 1; i+length<=10; i++){
                long long x = 0;
                int temp= i;
                for(int t = length-1; t>=0; t--){
                    x += temp * static_cast<int>(pow(10, t));
                    temp++;
                }
                if(low<=x && x<=high){
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};
