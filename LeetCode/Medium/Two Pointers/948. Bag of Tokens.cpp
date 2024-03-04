class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0;
        int r = tokens.size()-1;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        while(l<=r){
            if(power>=tokens[l]){
                power-=tokens[l];
                score++;
                l++;
            }else{
                if(l == r){
                    return score;
                }
                if(score>0){
                    score--;
                    power+=tokens[r];
                    r--;
                }else{
                    return 0;
                }
            }
        }
        return score;
    }
};
