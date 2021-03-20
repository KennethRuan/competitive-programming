#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 3e5+5;
const int mm = 1e4+5;
const int sqr = 548;

int n, m, q, nc = 0, idx = 1, blksz, cnt[mm], arr[mn], blk[sqr][101];

int comp[101], ma[mn]; //returns uncompressed value, returns compressed value


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    float thr = sqrt(n)*2;
    blksz = sqrt(n);

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        arr[i] = x;
    }

//    for (int i = 1; i <= m; i++){
//        cout << cnt[i] << " ";
//    }
//    cout << "\n";

    for (int i = 0; i < n; i++){
        int blkidx = i/blksz;
        if (cnt[arr[i]] > blksz){
            if (ma[arr[i]] == 0){
                comp[idx] = arr[i];
                ma[arr[i]] = idx++;
                nc++;
            }
            blk[blkidx][ma[arr[i]]]++;
        }
    }

//    for (int i = 1; i <= nc; i++){
//        for (int blkidx = 0; blkidx < n/blksz; blkidx++) {
//            cout << blk[blkidx][i] << " ";
//        }
//        cout << "\n";
//    }

    cin >> q;
    for (int _ = 0; _ < q; _++){
        int l, r;
        cin >> l >> r;
        l--;r--;
        int range = r-l+1;
        float req = ((float)range)/2;
        bool found = false;

        if (range <= thr){
            float cnt2[m+1];
            memset(cnt2,0,sizeof(cnt2));
            for (int i = l; i <= r; i++){
                cnt2[arr[i]]++;

                if (cnt2[arr[i]] > req) {cout << "yes " << arr[i] << "\n"; found = true; break;}
            }
        }

        else{
            int lblk = l/blksz, rblk = r/blksz;
            for (int x = 1; x <= nc; x++) {
                int amt = 0;
                for (int j = lblk + 1; j < rblk; j++) {
                    amt += blk[j][x];
                }
                for (int j = (lblk + 1) * blksz - 1; j >= l; j--) {
                    if (arr[j] == comp[x]) amt++;
                }
                for (int j = rblk * blksz; j <= r; j++) {
                    if (arr[j] == comp[x]) amt++;
                }

                if ((float) amt > req) {cout << "yes " << comp[x] << "\n"; found = true; break;}
            }
        }
        if (!found) cout << "no\n";
    }
}