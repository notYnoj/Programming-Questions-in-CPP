class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<int> hsh(2);
        for(int i= 0; i<s.size(); i++){
            if(s[i] == '0'){
                hsh[0]++;
            }else{
                hsh[1]++;
            }
        }
        string t = "";
        while(hsh[1]>1){
            t+="1";
            hsh[1]--;
        }
        for(int i = 0; i<hsh[0]; i++){
            t+='0';
        }
        t+='1';
        return t;
    }
};
//greedily pick the 1s to be at the start then when u only have 1 u need to append to the end so add the rest of the 0s then simply add the 1 to make odd.
