//pretty hard question, hardest one i solved on leetcode so far probably but not the worst, the intution is pretty striaghtfoward
//everything has to be connected to traverse, so make a graph. Union find is the nicest here because of its compactness for time
//though i Think a dfs works too, but esseintally if the size[root] == n then yes its all connected, then we have to connect based off the primes, so we can have a map that has all the primes
//caclulate primes of a number, if a index shares a prime, we merge em. do the usual.
//nice question!, i solved while going to jhons party lmao, coded it when i got home
class Solution {
    //essentially compressing the path to find the representitive (find in union find)
     //essentially compressing the path to find the representitive (find in union find)
    int root(int i, vector<int>& graph){
        return graph[i] == i? i : (graph[i] = root(graph[i], graph));
    }
    void u(int i, int j, vector<int>& graph, vector<int>& size){
        int x = root(i, graph);
        int y = root(j, graph);
        if(x == y){
            //if they are the same root it dont matter
            return;
        }
        if(size[x]<size[y]){
            swap(x,y);
        }
        //point the y node to x now, connecting them y->x
        graph[y] = x;
        //add to x the size of y x<-y
        size[x]+=size[y];
    }
 
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        //find like all the common divisiors
        //then like you can like go through each of them if common divisor
        //they are placed in a connected,
        //if u find one where it isnt then u check the current ones if it can be used else no
        //esseintally if the whole thing is connected then yes
        //otherwise no
        int n = nums.size();
        if(n == 1){
            return true;
        }
        vector<int> graph(n);
        vector<int> size(n);
        for(int i = 0; i<n; i++){
            graph[i] = i;
            size[i] = 1;
        }
        map<int, int> primes;
        for(int i =0 ;i<n; i++){
            int cur = nums[i];
            if(cur == 1){
                return false;
            }
            for(int j = 2; j*j<=cur; j++){
                if(cur % j == 0){
                    if(primes.count(j)){
                        //connects index primes[j] and index i
                        u(i, primes[j], graph, size);
                    }else{
                        primes[j] = i;
                    }
                }
                while(cur % j == 0){
                    cur/=j;
                }
            }
            if(cur>1){
                if(primes.count(cur)){
                    u(i, primes[cur], graph, size);
                }else{
                    primes[cur] = i;
                }
            }
        }
        return size[root(0, graph)] == n;
    }
};
