#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 2e5+5;
const int sqr = 448;

int n, q, arr[mn], blk[sqr][mn], blksz = 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    blksz = sqrt(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        int blkidx = i / blksz;
        for (int j = 1; j < sqrt(arr[i]); j++){
            if (arr[i] % j == 0){
                blk[blkidx][j]++;
                blk[blkidx][arr[i]/j]++;
            }
        }
        if (pow((int) sqrt(arr[i]),2) == arr[i]){
            blk[blkidx][(int) sqrt(arr[i])]++;
        }
    }
    for (int i = 0; i < q; i++){
        int op;
        cin >> op;
        if (op == 1){
            int l,r,x, ans = 0;
            cin >> l >> r >> x;
            l--;r--;
            int lblk = l/blksz, rblk = r/blksz;
            for (int j = lblk + 1; j < rblk; j++){
                ans += blk[j][x];
            }
            for (int j = (lblk+1)*blksz-1; j >= l; j--){
                if (arr[j] % x == 0) ans++;
            }
            for (int j = rblk*blksz; j <= r; j++){
                if (arr[j] % x == 0) ans++;
            }
            cout << ans << "\n";
        }
        else{
            int u, v;
            cin >> u >> v;
            u--;
            int ublk = u / blksz;
            for (int j = 1; j < sqrt(arr[u]); j++){
                if (arr[u] % j == 0){
                    blk[ublk][j]--;
                    blk[ublk][arr[u]/j]--;
                }
            }
            if (pow((int) sqrt(arr[u]),2) == arr[u]){
                blk[ublk][(int) sqrt(arr[u])]--;
            }
            arr[u] = v;
            for (int j = 1; j < sqrt(v); j++){
                if (v % j == 0){
                    blk[ublk][j]++;
                    blk[ublk][v/j]++;
                }
            }
            if (pow((int) sqrt(arr[u]),2) == arr[u]){
                blk[ublk][(int) sqrt(arr[u])]++;
            }
        }
    }
}