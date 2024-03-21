#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin>>t;
    while(t--){
        vector<vector<char>> grid(8, vector<char>(8));
        for(int i = 0; i<8 ;i++){
            for(int j = 0; j<8; j++){
                cin>>grid[i][j];
            }
        }
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                if(grid[i][j] != '.'){
                    string s;
                    s+=grid[i][j];
                    if(i != 7) {
                        while (grid[++i][j] != '.') {
                            s += grid[i][j];
                            if (i == 7) {
                                break;
                            }
                        }
                    }
                    cout << s << "\n";
                }
            }
        }
    }
}
//just make sure not to go outta bounds and ur good!
