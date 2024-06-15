#include <bits/stdc++.h>
using namespace std;
const int mxN = 4e6+5;
int arr[mxN], need[mxN];
bool IsPrime[mxN];
 
void SieveOfEratosthenes(vector<int>& primes)
{
    memset(IsPrime, true, sizeof(IsPrime));
 
    for (int p = 2; p * p < mxN; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < mxN; i += p)
                IsPrime[i] = false;
        }
    }
 
    for (int p = 2; p < mxN; p++)
        if (IsPrime[p])
            primes.push_back(p);
}
 
int div(int n) {
    for (int i = n / 2; i >= 1; i--){
        if (n % i == 0) {
            return i;
        }
    }
    return -1;
}
 
int main(){
    //works?
    vector<int> primes;
    SieveOfEratosthenes(primes);
    int n;
    cin>>n;
    vector<int> ans;
    int a = 2*n;
    for(int i = 0; i<a; i++){
        cin>>arr[i];
    }
    int t = n;
    sort(arr, arr+a);
    for(int i = a-1; i>=0; i--){
        if(t==0){
            break;
        }
        if(!IsPrime[arr[i]]){
            if(need[arr[i]] <= 0) {
                ans.push_back(arr[i]);
                need[div(arr[i])]++;
                t--;
            }else{
                need[arr[i]]--;
            }
        }else{
            need[arr[i]]--;
        }
    }
    //we have the challenge of finding the nth prime.
    //if we can find this nth prime. then we can add one to the need
    for(int i = 0; i<a; i++){
        if(t==0){
            break;
        }
        if(IsPrime[arr[i]]){
            if(arr[i]<=199999 && need[arr[i]] < 0 && need[primes[arr[i]-1]] < 0){
                ans.push_back(arr[i]);
                need[arr[i]]++;
                need[primes[arr[i]-1]]++;
                t--;
            }
        }
    }
    for(int i: ans){
        cout<<i<<" ";
    }
 
}
