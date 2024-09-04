class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& o) {
        map<pair<int, int>, bool> mp;
        for(int i = 0; i < o.size(); i++){
            mp[{o[i][0], o[i][1]}] = true; 
        }
        int x = 0;
        int y = 0;
        int ans = 0;
        int d = 0;  // direction: 0 = North, 1 = East, 2 = South, 3 = West
        for(int i = 0; i < commands.size(); i++){
            int mov = commands[i];
            if(mov == -1){
                d = (d + 1) % 4;
            } else if(mov == -2){
                d = (d + 3) % 4;  // Instead of d -= 1, we do d + 3 % 4 to handle negative mod
            } else {
                if(d == 0){  // North
                    for(int j = 1; j <= mov; j++){
                        if(mp[{x, y + 1}]){
                            break;
                        }
                        y++;
                    }
                }
                else if(d == 1){  // East
                    for(int j = 1; j <= mov; j++){
                        cout<<x+j<<' '<<y<<'\n';
                        if(mp[{x + 1, y}]){
                            cout<<"HERE";
                            break;
                        }
                        x++;
                    }
                }
                else if(d == 2){  // South
                    for(int j = 1; j <= mov; j++){
                        if(mp[{x, y - 1}]){
                            break;
                        }
                        y--;
                    }
                }
                else if(d == 3){  // West
                    for(int j = 1; j <= mov; j++){
                        if(mp[{x - 1, y}]){
                            break;
                        }
                        x--;
                    }
                }
            }
            ans = max(ans, x * x + y * y);
        }
        return ans;
    }
};
