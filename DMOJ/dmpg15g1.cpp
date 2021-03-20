#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;

    cin >> x;
    string grid[x];
    int psa[x+1][x+1];
    int m = 0;
    memset(psa,0,sizeof(psa));

    for (int i = 0; i < x; i++){
        cin >> grid[i];
        for (int j = 0; j < x; j++){
            if (grid[i][j] == '#') {
                psa[i + 1][j + 1] = 1 + psa[i + 1][j] + psa[i][j + 1] - psa[i][j];
            }
            else {
                psa[i + 1][j + 1] = psa[i + 1][j] + psa[i][j + 1] - psa[i][j];
            }
        }
    }

//    for (int i = 0; i < x; i++){
//        cout << grid[i] << endl;
//    }
//
//    for (int i = 0; i < x+1; i++){
//        for (int j = 0; j < x+1; j++){
//            cout << psa[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i = 1; i < x; i++){
        for (int j = 1+i; j < x+1; j++){
            for (int k = 1+i; k < x+1; k++) {
                int a = psa[j-i-1][k] + psa[j][k-i-1] - psa[j-i-1][k-i-1];
                if (psa[j][k] - a  == psa[j-1][k-1] - psa[j-i][k-1] - psa[j-1][k-i] + psa[j-i][k-i]){
                    m = i;
//                    cout << "row " << j << " col " << k << " size " << i << " x's " << a << endl;
                }
            }
        }
    }
    cout << m;
}