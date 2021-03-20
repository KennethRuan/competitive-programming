#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull bit[251][251][251];
int stal[251][251][251];

void update(int x, int y, int z, int v){
    for (int i = x; i < 251; i += (i&-i)){
        for (int j = y; j < 251; j += (j&-j)){
            for (int k = z; k < 251; k += (k&-k)){
                bit[i][j][k] += v;
            }
        }
    }
}

ull query(int x, int y, int z){
    ull s = 0;
    for (int i = x; i > 0; i -= (i & -i)){
        for (int j = y; j > 0; j -= (j & -j)) {
            for (int k = z; k > 0; k -= (k & -k)) {
                    s += bit[i][j][k];
            }
        }
    }
    return s;
}

int main(){
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, q;
    ull sum = 0;
    char c;
    cin >> n;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> c;
        if (c == 'C'){
            int x,y,z,l;
            cin >> x >> y >> z >> l;
            update(x,y,z,l-stal[x][y][z]);
            stal[x][y][z] = l;
        }
        if (c == 'S'){
            int x1,y1,z1,x2,y2,z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            sum += query(x2,y2,z2) - query(x1-1,y2,z2) - query(x2,y1-1,z2) - query(x2,y2,z1-1) + query(x2,y1-1,z1-1) + query(x1-1,y2,z1-1) + query(x1-1,y1-1,z2) - query(x1-1,y1-1,z1-1);
        }
    }
    cout << sum;
}