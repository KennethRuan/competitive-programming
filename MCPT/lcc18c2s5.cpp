#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 1e5+5;
int n, q, idx = 0, bit[mxN];
vector<int> g[mxN];
struct p{
    int nChild, s, ind;
}; p emp[mxN];

void update(int k, int v){
    for (int i = k; i < mxN; i += i & -i){
        bit[i] += v;
    }
}

int query(int x){
    int s = 0;
    for (int i = x; i > 0; i -= i & -i){
        s += bit[i];
    }
    return s;
}

int dfs(int node){
    int sum = 0;
    emp[node].ind = n-idx;
    idx++;
    update(emp[node].ind,emp[node].s);
    for (int i: g[node]){
        sum += dfs(i) + 1;
    }
    return emp[node].nChild = sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int b,s;
    cin >> b >> s;
    emp[1].s = s;
    for (int i = 2; i <= n; i++){
        cin >> b >> s;
        g[b].push_back(i);
        emp[i].s = s;
    }
    dfs(1);
//    cout << "\n";
//
//    for (int i = 1; i <= n; i++){
//        cout << emp[i].nChild << " ";
//    }
//    cout << "\n";
//    for (int i = 1; i <= n; i++){
//        cout << emp[i].s << " ";
//    }
//    cout << "\n";
    cin >> q;
    for (int i = 0; i < q; i++){
        char op;
        cin >> op;
        if (op == 'q'){
            int a;
            cin >> a;
            int node = emp[a].ind;
//            cout << node << " " << emp[a].nChild << "\n";
            cout << query(node) - query(node-emp[a].nChild-1) << "\n";
        }
        else{
            int a, s;
            cin >> a >> s;
            int node = emp[a].ind;
            update(node,s-emp[a].s);
            emp[a].s = s;
        }
    }
}