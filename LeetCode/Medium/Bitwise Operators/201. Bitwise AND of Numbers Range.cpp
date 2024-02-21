class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // Find the common prefix, as all the numbers in the range are going to have this prefix (the suffix are going to be different)
        while (left != right) {
            left >>= 1;
            cout<<left<<" ";
            right >>= 1;
            shift++;
        }
        //shift left a bit to make sure that its the oirignal big number as in if we get two 1s we get 3 but it shouldnt cuz it should have some 0.
        return left << shift;
    }
};
