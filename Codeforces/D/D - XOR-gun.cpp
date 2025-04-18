#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int& a: A){
        cin>>a;
    }
    // if a,b,c have the same biggest bit then it wont be good
    //bit 1 bit 1 bit 2 bit 2 bit 3 bit 3
    if(n>60){
        cout<<1<<"\n";
    }else{
        vector<int> prefxor(n);
        prefxor[0] = A[0];
        for(int i = 1; i<n; i++){
            prefxor[i] = prefxor[i-1]^A[i];
        }
        //it can be any number to the right xor anything
        int ans = INT_MAX;
        for(int R = 1; R<n; R++){
            for(int L = R-1; L>=0; L--){
                int l3 = (L>0?prefxor[L-1]:0)^prefxor[R];
                for(int L2 = R+1; L2<n; L2++){
                    int r3 = prefxor[L2] ^ prefxor[R];
                    if(l3>r3){
                        ans = min(ans, (R-L + L2-R-1));
                    }
                }
                for(int R2 = L-1; R2>=0; R2--){
                    int l4 = prefxor[L-1] ^ (R2>0?prefxor[R2-1]:0);
                    if(l4>l3){

                        ans = min(ans, (R-L + L-R2-1));
                    }
                }
            }
        }

        cout<<(ans == INT_MAX?-1:ans);
    }
}
