#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 2e5+5;
const int mm = 2e5+5;
const int sqr = 448;

int n, m, q, nc = 0, idx = 1, blksz, cnt[mm], arr[mn], blk[sqr][1342];

int comp[1342], ma[mn]; //returns uncompressed value, returns compressed value


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    float thr = sqrt(n)*3;
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
        int l, r, pieces = 0;
        cin >> l >> r;
        l--;r--;
        int range = r-l+1;
        float req = ((float)range)/3;

        if (range <= thr){
            float cnt2[m+1];
            memset(cnt2,0,sizeof(cnt2));
            for (int i = l; i <= r; i++){
                cnt2[arr[i]]++;

                if (cnt2[arr[i]] >= req*2){ pieces += 2; cnt2[arr[i]] -= req*2;}
                else if (cnt2[arr[i]] >= req) { pieces++; cnt2[arr[i]] -= req;}

                if (pieces >= 2) break;
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

                if ((float) amt >= req*2) pieces += 2;
                else if ((float) amt >= req) pieces++;

                if (pieces >= 2) break;
            }
        }
        if (pieces >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}