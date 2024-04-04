#include <bits/stdc++.h>
using namespace std;
long long cases;
long long find(long long cards, long long power){
  //we want max
  //we find this wherever cards = power * (2k-1) (2k-1 as we want k = max [think about it if k = 1, max is 1 just as we like])
  //now we just solve, distrbute power we get cards - power/2*power = k
  //going to have at max cards+power/power*2
  //this is based on the fact that if it starts at pos x (power) + max = 12/ what it climbs by (since it climbs by odd aka 2k+1) u multiply by 2
    long long pssb = (cards+power)/(power*2);
    return pssb;
}
void solve(){
    long long cards, pos;
    cin>>cards>>pos;
    if(pos<=(cards+1)/2) {
        cout << 2 * (pos - 1) + 1 << "\n";
        return;
    }
    //only need even ones as (2k+1) * (2z+1) = 4kz + 2z + 2k + 1 (odd)
    //only need to count the powers of 2 because the other ones are going to have all the other ones
    // ex: 6 is going to be in the 2*3 
    // so only power of 2s aka 2,4,8,16 because if its not then it can be split into odd numbers whihc will be in another row
    //100 <- goes to 99 in odd but if u want like say 46 and u dont know where its going to go the odd number factor will never be bigger than 99
  //simply not possible becuz if it were the smallest other factor 2 would over exceed 100, therefore we know the only important rows are going to be the ones wiht 2^n
  //2^n because then we can have uniqueness for example, 40, 8*5 this cannot be found in any other row becuz 8 is even and 5 hasnt seen (only possibly seen 2,4,6) 8 yet. 
  //also all of 6 will have been used before because again 100/6 = 15 max odd but 15*3<99 so we used it in 2
    long long power = 1;
    while(pos){
        long long o = find(cards, power);
        if(pos<=o){
            if(pos == 1){
                cout<<(power)<<"\n";
            }else{
                long long ans = (power) + ((pos-1)*(power*2));
                cout<<ans<<"\n";
            }
            return;
        }else{
            pos-=o;
        }
        power*=2;

    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>cases;
    while(cases--){
        solve();
    }

}
