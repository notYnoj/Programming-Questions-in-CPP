#include <bits/stdc++.h>
#define double long double
using namespace std;
string path;
string taken;
//helper function
double fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>path;
    cin>>taken;
    int pathmap = 0; //position of path
    int takemap = 0; //position of taken
    int c = 0; // question marks
    int n = path.size();
    for(int i = 0; i<n; i++){
      //i dont know why my chromebook messed up tabs but it did
            if(taken[i] == '+') {
                takemap += 1;
            }else if(taken[i] == '?') {
                c++;
            }else {
                takemap -= 1;
            }
            if(path[i] == '+'){
                pathmap+=1;
            }else {
                pathmap -= 1;
            }
        }
    // 
    if((c<abs(pathmap - takemap)) || (c==0 && pathmap != takemap)) {
        cout << 0.000000000000;
        return 0;
    }else if(c == 0 && pathmap == takemap){
        cout<<1.000000000000;
    }else{
        //gotta split it into pos and neg
        int needed = pathmap - takemap;
        int pos = 0;
        int neg = 0;
        float nt = 1;
        for(int i = 0; i<c; i++){
            if(pos+neg>=needed){
                neg--;
            }else{
                pos++;
            }
            nt*=2;
        }
        if(pos+neg != needed){ // if not able to be split return 0, tho it should be possible
            cout<<0.000000000000;
            return 0;
        }
        neg = abs(neg);
        //get the amount of possible correct paths divide by total paths
        double newc = static_cast<double>(fact(c)) / (static_cast<double>(fact(pos)) * static_cast<double>(fact(neg)));
        cout<<setprecision(15); //i love you linnrue <- without this it doesn't work
        cout << newc / nt;

    }


    //esecinally they have to be equal
    //so for any path having ?*n there are n! to make that how many lead to favorable outcomes?
    //combinactorics solution above, dp would be like a dfs + memo where u do the same thing js dfs this and make one where u place +1, -1 dfs, see how many equal if equal add 1 to a counter then divide that counter by n!
    // dfs solution if I dont get lazy 
}
