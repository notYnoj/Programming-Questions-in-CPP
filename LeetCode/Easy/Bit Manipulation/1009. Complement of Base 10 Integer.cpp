class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int x = log2(n);
        long long z = pow(2, x+1);
        return (n^(z-1));
    }
};
