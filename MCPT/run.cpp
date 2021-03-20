#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 1e5+5;
int n,m,k, g[MAXN];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    if (k > n){
        cout << "NO";
        return 0;
    }
    if ((n-1) % m != 0){
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i++){
        cin >> g[i];
        if (i % m == 0 && g[i] == 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}