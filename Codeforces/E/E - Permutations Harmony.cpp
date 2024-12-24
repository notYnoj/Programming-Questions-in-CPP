#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    //we have m rows in our matrix
    //the first is just 1,2,3,4...n
    vector<int> initial(n);
    for(int i =0 ; i<n; i++){
        initial[i] = i+1;
    }
    //total = n(n+1)/2 * m 
    //per col = n+1/2*m since n cols

    //if 1 and 1 good other wise 1 + m>1 bad
    //or if m == 1 also bad
    if(n == 1 || m == 1){
        if(n == m){
            cout<<"Yes"<<'\n';
            cout<<1<<'\n';
            return;
        }else{
            cout<<"No\n";
            return;
        }
    }
    if(n%2 == 0 && m%2 == 1){
        cout<<"No\n";
        return;
    }
    vector<vector<int>> total, begins;
    begins.push_back(initial);
    total.push_back(initial);
    if(m%2){
        //if m isnt divisble by 2 we know that n has to be odd
        vector<int> sub1(n);
        vector<int> swapper(n);
        //here it should be n+1 and n+1/2 to keep it even 
        // 1 2 3 4 5 6 .. n
        // n+1/2, 
        // n, 
        //if we add 1 we can only subtract 1
        //we should subtract by 1 on every row half of the time
        // but if we js keep them stagnant and not changing then it isn't a permutation
        // thus we have to change everything but onyl subtrcat once at a time
        // so we shoudl swap em around and subtract 1 from 1 vector
        // becuz lets say we swap up then we will have n-1 and then n+1/2 on the bottom
        //then we have n+1/2-1 n-1 thus there will never be duplicates 
        //this also works cuz im adding 1 subtracting 1 so difference is 0 (whatever is at the end doesnt matter itll be equal) as long as its above 0
        //which i believe it is since everything we have is above n/2 and were only subtract that many times since first one doesnt subtract anything js in case i subtract with row n+1/2
        //since that one wont get subtracted first
        //(lol this whole logic was js from the 3 3 test case and examining it thanks testcase!)
        /*WA: 
        input:
        n = 3 m = 3:
        output:
        1 2 3 
        2 2 1 sub1
        3 2 2 swapper
        */
       // i cant subtract from bigger one first lol
        for(int i = 0; i<n; i+=2){
            sub1[i] = n - (i/2);
            swapper[i] = (n+1)/2 -(i/2);
        }
        for(int i = 1; i<n; i+=2){
            sub1[i] = (n/2) - (i/2);
            swapper[i] = n - (i/2);
        }
        total.push_back(sub1);
        total.push_back(swapper);
        begins.push_back(sub1);
        begins.push_back(swapper);
    }else{
        vector<int> other(n);
        for(int i = 0; i<n; i++){
            other[i] = n+1-initial[i];
        }
        total.push_back(other);
        begins.push_back(other);
    }


    do{
        if(total.size() >= m){
            break;
        }
        vector<int> cur(n);
        //need n+1 becuz m*n+1/2 or n+1 per every 2 rows 
        for(int i = 0; i<n; i++){
            cur[i] = n+1 - initial[i];
        }
        if(cur>initial){
            bool used = false;
            for(auto i: begins){
                if(cur == i || initial == i){
                    used = true;
                    break;
                }
            }
            if(used){
                continue;
            }
            total.push_back(cur);
            total.push_back(initial);
        }


    }while(next_permutation(initial.begin(), initial.end()));
    if(total.size() != m){
        cout<<"No\n";
        return;
        
    }
    cout<<"Yes\n";
    for(vector<int> i: total){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}