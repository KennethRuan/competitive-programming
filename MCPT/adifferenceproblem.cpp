#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e3+5;
int bit[MAXN][MAXN], n, q;

// note: x is row y is col

void update(int x, int y, int v) {
    for (int i = x; i < MAXN; i += i & -i){
        for (int j = y; j < MAXN; j += j & -j){
            bit[i][j] += v;
        }
    }
}


void update(int x1, int y1, int x2, int y2, int v) {
    update(x1, y1, v);
    update(x2+1, y1, -v);
    update(x1, y2+1, -v);
    update(x2 + 1, y2 + 1, v);
}

ll query(int x, int y) {
    ll s = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            s += bit[i][j];
        }
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < q; i++){
        int op;
        cin >> op;
        if (op == 1){
            int x1,y1,x2,y2,v;
            cin >> x1 >> y1 >> x2 >> y2 >> v;
            update(x1,y1,x2,y2,v);
        }
        if (op == 2){
            int x, y;
            cin >> x >> y;
            cout << query(x,y) << "\n";
        }
    }

}