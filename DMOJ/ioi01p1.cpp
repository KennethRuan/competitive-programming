#include <bits/stdc++.h>
using namespace std;

int x,y,l,b,r,t,v,inp = 0,bit[1025][1025],astrocatuwu;

void update(int x, int y, int v){
    for (int i = x; i < 1025; i += (i&-i)){
        for (int j = y; j < 1025; j += (j&-j)){
            bit[i][j] += v;
        }
    }
}

int query(int x, int y){
    int s = 0;
    for (int i = x; i > 0; i -= (i & -i)){
        for (int j = y; j > 0; j -= (j & -j)) {
            s += bit[i][j];
        }
    }
    return s;
}

int main() {
    memset(bit,0,sizeof(bit[0][0])*1025*1025);
    while (inp != 3) {
        cin >> inp;
//        for (int i = 0; i < 5; i++){
//            cout << i << "step \n";
//            for (int j = 0; j < 5; j++) {
//                cout << bit[i][j] << " ";
//            }
//            cout << "\n";
//        }
        if (inp == 0){
            cin >> astrocatuwu;
        }
        if (inp == 1) {
            cin >> x >> y >> v;
            x++;y++;
            update(x, y, v);
        }
        if (inp == 2) {
            cin >> l >> b >> r >> t;
            l++;b++;r++;t++;
            cout << query(r, t) - query(l - 1, t) - query(r, b - 1) + query(l - 1, b - 1) << "\n";
        }
    }
}