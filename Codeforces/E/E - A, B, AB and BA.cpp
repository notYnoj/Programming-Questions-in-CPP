#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,ab,ba,totz;
vector<string> stk_even, stk_odd;
string s;
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
//o(n) sol
//true for ab
//false for ba
//partition the string based on max amopunt of a 
//the amount of ba's and ab's we can get rid of is
//ababa

//abab
//ab ba ab ba

//if its odd it isnt strict (the beginning character is gonna be the partition)
//so odd substrings are special and can use either ab or ba
//even substrings are bad and should be priortized
void P(string& i){
    //odd can use either and then be partioned based on the first letter (that is optimal, all other ones should js be normal)
    if(i.size()%2){
        if(totz>(i.size()/2)){
            totz-=(i.size()/2);
            if(i[0] == 'a'){ //i need to partion somewhere
                a--;
            }else{
                b--;
            }
            i = "";
        }else{
            int can_take = totz*2;
            while(can_take>0){
                i.pop_back();
                can_take--;
            }
            totz = 0;
        }
    }
    //priortize even
    else{
        //attempt a perfect get first
        while(!i.empty()){
            if(i.back() == 'b'){
                if(ab<=0){
                    break;
                }
                ab--;
                i.pop_back();
                i.pop_back();
            }else{
                if(ba<=0){
                    break;
                }
                ba--;
                i.pop_back();
                i.pop_back();
            }
        }
        //then try the other one by taking away 1 a and 1 b we can use the other one
        //
        if(!i.empty()){
            a--;
            b--;
            i.pop_back();
            char op = i.back();
            i.pop_back();
            //grab the other 2 drops
            while(!i.empty()){
                if(op == 'a'){
                    if(ba<=0){
                        break;
                    }
                    ba--;
                    i.pop_back();
                    i.pop_back();
                }else{
                    if(ab<=0){
                        break;
                    }
                    ab--;
                    i.pop_back();
                    i.pop_back();
                }
            }
        }
    }
}
//ABABBAABBAAB
//1 1 0 
/*(AB(AB*/
void solve(){
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cin>>a>>b>>ab>>ba;
    stk_odd.clear();
    stk_even.clear();
    //if there is an odd number of things and a and b are bad then its bad
    //also if the sum is less than the string length its bad
    if((a+b+(2*ab)+(2*ba)) < s.length()){
        cout<<"NO\n";
        return;
    }
    string cur = "";
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(cur.back() == s[i]){
            if(cur.size()%2){
                stk_odd.push_back(cur);
            }else{
                stk_even.push_back(cur);
            }
            cur = s[i];
        }else{
            cur+=s[i];
        }
    }
    if(cur.size()%2){
        stk_odd.push_back(cur);
    }else{
        stk_even.push_back(cur);
    }
    sort(stk_even.begin(), stk_even.end(), [&](string&a, string&b) ->bool{
        return a.size()<b.size();
    });
    sort(stk_odd.begin(), stk_odd.end(), [&](string&a, string&b) -> bool{
        return a.size()<b.size();
    });
    
    for(string i: stk_even){
        P(i);
        if(!i.empty()){ //if my two drops aint enough
            a-=(i.size()/2);
            b-=(i.size()/2); //(brute force this hoe)
        }
    }
    totz = ab+ba;
    for(string i: stk_odd){
        P(i);
        if(i!=""){ //if my two drops aint enough
            assert(i.size()%2);
            if(i[0] == 'a'){
                a--;
            }else{
                b--;
            }
            a-=(i.size()/2);
            b-=(i.size()/2);
        }
    }
    if(a<0 || b<0){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
    /*
    aabbaa 
    at any point we can disregard letters that are not followed directly after or before a letter of opposite
    they must be indviduals
    otherwise we will have something that looks like this
    abba (is possible)
    (ab)(ba) (b) (is not possible)
    (a)(b)(ba)(b)
    no matter where we use our (ab)s or (ba)s they don't matter?
    if I use it at the start at the end portion i have to use a b
    if i use it at teh end i have to use it not at the start and use up an a and b
    thus using them as we find them is always optimal?
    check if there is any aa bb
    split down here
    ababa
    it can be (a)baba 
    ab(a)ba(a
    so it can be everything but the bad one
    if its odd it has to be that + 1 extra (from a or b)
    if i have no b make ab ab
    ab ba
    if i break out a b its bad
    break out the previous one
    if i break out a an A
    in an even one i need to break out a B
    do the longest ones firsT?

    */
    
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }   
}

/*

B/B/BA/AB/BA/A/AB/B/BA/A/A

6 6 
BBAAABABBABBAAABBBA

5 6 1 3


*/
