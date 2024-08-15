class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> n(3,0);
        for(int i = 0; i<bills.size(); i++){
            if(bills[i] == 5){
                n[0]++;
            }else if(bills[i] == 10){
                if(n[0]<=0){
                    return false;
                }
                n[0]--;
                n[1]++;
            }else{
                if(n[0]>=1 && n[1]>=1){
                    n[0]--;
                    n[1]--;
                    continue;
                }else if(n[0]>=3){
                    n[0]-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
