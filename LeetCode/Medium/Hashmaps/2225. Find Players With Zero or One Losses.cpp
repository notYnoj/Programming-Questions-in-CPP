class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer(2);
        map<int, int> won; //losses* map is also ordered so no need to sort at the end.
        for(int i = 0; i<matches.size(); i++){
            if(won.find(matches[i][0]) == won.end() ){
                won[matches[i][0]] = 0; // if its not in the map set equal to 0 becuz it is its first victory
            }
            won[matches[i][1]]++; // add 1 loss to the loser
        }
        for(auto it = won.begin(); it!=won.end(); it++){
            if(it->second == 0){
                answer[0].push_back(it->first); // if == 0, push_back the player
            }else if(it->second == 1){
                answer[1].push_back(it->first); // if == 1 push_back the player
            }
        }
        return answer;
    }
};
