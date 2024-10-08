class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;
      //each swap makes 2! so we want ceil of size/2 (thus we do (size + 2-1)/2) aka size+1/2
      //this is becuz if we have like size/2 we have like size + remainder/2 + 1/2 if reaminder is equal to 1 (or for any divisior we do like divsior-1 this is because the same logic)
      //then we add 1+1 and get 2/2
      //gernalizing it we get like 1-m-1(ones we want to add) + m-1 which gets us m....2m-2 which when dividing by m alwayus gets us 1 (not quite 2 becuase its 2m-2 meaning its smaller than 2m and thus gets us 1)
      
    }
};
