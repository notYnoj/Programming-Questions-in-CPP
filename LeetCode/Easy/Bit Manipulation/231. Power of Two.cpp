class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long i = 1;
        while(i<n){
            i = i*2;
        }
        if(i == n) return true;
        return false;
    }
};
//first sol while loop - 0:15, beats 39%
//basically if we make sure that the -1 is not equal to any that means that it was a power of 2 1 + x amount of zeros = true if we subtract one we get 0 x amount of 1s therefore we can use and
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
          return false; //(wrong without)
        }else{
          return !(n&(n-1));
        }
    }
};
//second sol bit manipulation - 1:01, beats 100%

