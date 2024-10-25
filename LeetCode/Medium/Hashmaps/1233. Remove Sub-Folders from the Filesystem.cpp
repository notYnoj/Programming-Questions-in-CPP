class Solution {
    unordered_set<string>xx;
    bool prefixFnd(string&a){
        if(!xx.size())return true;
        string x="";
        int i=1;
        while(i<a.size()){
            x+='/';
           while(i<a.size()&&a[i]!='/'){
            x+=a[i];
           i++;
           }
           if(xx.count(x))return false;// if there is a path with that prefix return false 
           i++;
        }
        return true; // if there is no path fnd with any of prefixes return true
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>res;
        sort(folder.begin(),folder.end(),[](string&a,string&b){return a.size()<b.size();});
        for(int i = 0; i<folder.size(); i++){
            cout<<folder[i]<<' ';
        }
        for(auto&a:folder){
            if(prefixFnd(a)){res.push_back(a);
            xx.insert(a);
            }
        }
        return res;
    }
};
