#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1048576 + 5; //2^20 > 1e6
int n, bit[MAXN], rating[1000005], player[1000005], tot = 1; //rating returns a rating based on player id, player returns a player based on rating
char o;

struct query{
    char op; int x,r,k,ind;
}; query q[1000005];

bool compareRanks(query lhs, query rhs){
    return lhs.r < rhs.r;
}

bool compareInd(query lhs, query rhs){
    return lhs.ind < rhs.ind;
}

void update(int x, int v){
    for (int i = x; i < MAXN; i += (i&-i)){
        bit[i] += v;
    }
}

int query(int k){
    int sum = 0;
    int pos = 0;
    for(int i=20; i>=0; i--)
    {
        if(pos + (1 << i) < MAXN and sum + bit[pos + (1 << i)] < k)
        {
            sum += bit[pos + (1 << i)];
            pos += (1 << i);
        }
    }

    return pos + 1;
}

int main(){
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> q[i].op;
        q[i].ind = i;
        if (q[i].op == 'N' || q[i].op == 'M'){
            cin >> q[i].x >> q[i].r;
        }
        else{
            cin >> q[i].k; q[i].r = 0;
        }
    }
    sort(q,q+n,compareRanks);
    for (int i = 0; i < n; i++){
        q[i].r = i;
    }
    sort(q,q+n, compareInd);
    for (int i = 0; i < n; i++){
        o = q[i].op;
        if (o == 'N'){
            tot++;
            int x = q[i].x,r = q[i].r;
            rating[x] = r;
            player[r] = x;
            update(r,1);
        }
        if (o == 'M'){
            int x = q[i].x,r = q[i].r,oldr;
            oldr = rating[x];
            player[oldr] = 0;
            player[r] = x;
            rating[x] = r;
            update(oldr,-1);
            update(r,1);
        }
        if (o == 'Q'){
            int k = q[i].k, p;
            p = query(tot-k);
            cout << player[p] << "\n";
        }
    }
}