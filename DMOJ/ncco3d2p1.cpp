#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 5e4+5;
const int mod = 1e9+7;
const int logn = 16;
int n, q, lg[mxn+1], mn[mxn][logn], mx[mxn][logn];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        mn[i][0] = mx[i][0] = x;
    }
    for (int i = 2; i < mxn; i++){
        lg[i] = lg[i/2]+1;
    }

    for (int j = 1; j <= lg[n]; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j-1))][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j-1))][j - 1]);
        }
    }

//    for (int j = 0; j <= lg[n]; j++){
//        for (int i = 0; i < n; i++){
//            cout << mn[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout <<"Max\n";
//    for (int j = 0; j <= lg[n]; j++){
//        for (int i = 0; i < n; i++){
//            cout << mn[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        int j = lg[b-a+1];
        int lb = min(mn[a][j], mn[b-(1<<j)+1][j]);
        int ub = max(mx[a][j], mx[b-(1<<j)+1][j]);
        cout << ub - lb << "\n";
    }

}