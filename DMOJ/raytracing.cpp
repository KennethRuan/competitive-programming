#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8193;
int bit[MAXN][MAXN];
int heights[MAXN];
int n = 0, q, h, o;

void update(int x, int y, int v){
    for (int i = x; i < MAXN; i += (i&-i)){
        for (int j = y; j < MAXN; j += (j&-j)){
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

int main(){
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> h;
        update(i+1,h+1,1);
        heights[i+1] = h+1;
    }
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> o;
        if (o == 1){
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            cout << query(r+1,b+1) - query(r+1,a) - query(l,b+1) + query(l,a) << "\n";
        }
        if (o == 2){
            int x, y;
            cin >> x >> y;
            update(x+1,heights[x+1],-1);
            update(x+1,y+1,1);
            heights[x+1] = y+1;
        }
    }
}