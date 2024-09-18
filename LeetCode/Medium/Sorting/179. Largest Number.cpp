bool compare(string s,string t){
    return s+t>t+s;
}
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string>cont;
        for(int i:nums) 
            cont.push_back(to_string(i));
        sort(cont.begin(),cont.end(),compare);
        string r;
        for(int i=0;i<cont.size();i++)
                r+=cont[i];
        if(r[0]=='0') 
            return "0";
        return r;
        
        
    }
};
