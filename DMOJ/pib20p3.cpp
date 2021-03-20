#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int bit[100005];

void update(int k, int v) {
    for (int i = k; i < 100005; i += i & -i)
        bit[i] += v;
}


void update(int l, int r, int v) {
    update(l, v);
    update(r + 1, -v);
}


ll query(int k) {
    ll s = 0;
    for (int i = k; i > 0; i -= i & (-i))
        s += bit[i];
    return s;
}

int main(){
    ll q;
    int lr = 0;
    int lbr = 0;
    memset(bit,0,sizeof(bit));
    cin >> q;
    for (int i = 0; i < q; i++){

        int op;
        cin >> op;

        if (op == 1){
            lr++;
            lbr = lr;
            update(lbr,lr,1);
        }

        if (op == 2){
            lr++;
            update(lbr,lr,1);
        }

        if (op == 3){
            int x;
            cin >> x;
            cout << query(x) % 2 << "\n";
        }

//        cout << "\n";
//        cout << "op " << op;
//        cout << "\n";
//        for (int i = 0; i < 32; i++) cout << bit[i] << " ";
    }
}