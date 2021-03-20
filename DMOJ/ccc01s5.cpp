//Headers
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int mxn = 45;
int m, n, ak;
int ind[mxn];
string aaa, bbb, a[mxn], b[mxn];

bool solve(int am, int bm, int ae, int be, int k){
    if (am == ae && bm == be && k > 0) {
        ak = k;
        return true;
    }
    if (am != ae && bm != be)
        return false;
    if (k == m-1)
        return false;

    for (int i = 0; i < n; i++){
        aaa = aaa.substr(0, ae) + a[i];
        bbb = bbb.substr(0, be) + b[i];

        int tam = am, tbm = bm;

        while (tam < aaa.length() && tbm < bbb.length()){
            if (aaa[tam] == bbb[tbm]) {
                tam++;
                tbm++;
            }
            else break;
        }
        if (solve(tam, tbm, aaa.length(), bbb.length(), k+1)) {
            ind[k] = i;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if (solve(0,0,0,0,0)){
        cout << ak << "\n";
        for (int i = 0; i < ak; i++)
            cout << ind[i] + 1 << "\n";
    }
    else{
        cout << "No solution.";
    }
}