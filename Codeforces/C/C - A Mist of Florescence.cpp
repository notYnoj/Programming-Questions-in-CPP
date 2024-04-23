#include <bits/stdc++.h>
using namespace std;
char grid[50][50];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> count(4);
    for(int i = 0; i<4; i++){
        cin>>count[i];
    }
    vector<char> temp = {'A', 'B', 'C', 'D'};
    --count[0];
    --count[1];
    for(int i = 0; i<25; i++){
        for(int j = 0; j<50; j++){
            //odd
            grid[i][j] = 'A';
            for(int k = 1; k<4; k++){
                if(count[k] && i % 2 && j%2){
                    count[k]--;
                    grid[i][j] = temp[k];
                    break;
                }
            }
        }
    }
    for(int i = 25; i<50; i++){
        for(int j = 0; j<50; j++){
            //since it starts on an odd make it even
            grid[i][j] = 'B';
            for(int k = 0; k<4; k++){
                if(k != 1 && count[k] && i % 2 == 0 && j%2 == 0){
                    count[k]--;
                    grid[i][j] = temp[k];
                    break;
                }
            }
        }
    }

    cout<<"50 50\n";
    for(int i = 0; i<50; i++){
        for(int j = 0; j<50; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}
