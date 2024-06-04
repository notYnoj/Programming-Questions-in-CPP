#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    if(!(k%2)){
        cout<<"NO";
    }else {
        if (k == 1) {
            cout << "YES\n";
            cout<<"2 1\n";
            cout<<"1 2";
        } else {
            cout << "YES\n";
            int nodes = 4*k-2;
            int edges = 2*((k-1)*(k-1)+(k-1)/2);
            edges+= (2*(k-1)+1);
            cout<<nodes<<" "<< edges<<"\n";
            cout << 1 << " " << 2 << "\n";
            for (int i = 0; i < k - 1; i++) {
                cout << 1 << " " << i + 3 << "\n";
                for (int j = k + 2; j <= 2 * k; j++) {
                    cout << i + 3 << " " << j << "\n";
                }
            }
            for (int i = k + 2; i <= 2 * k; i += 2) {
                cout << i << " " << i + 1 << "\n";
            }
            int starting_node = 2 * k;
            for (int i = starting_node; i < starting_node + k - 1; i++) {
                cout << 2 << " " << i + 1 << "\n";
                for (int j = starting_node + k ; j <= starting_node + 2 * k -2; j++) {
                    cout << i + 1 << " " << j << "\n";
                }
            }
            for (int i = starting_node + k; i <= starting_node + 2 * k -2; i += 2) {
                cout << i << " " << i + 1 << "\n";
            }
        }
    }
}
