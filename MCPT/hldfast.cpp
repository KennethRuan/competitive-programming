#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 1e6+5;
int n, p[mxN], v[mxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++){
        int pa = i, va;
        cin >> va;
        while(pa != 0){
            v[pa] += va;
            pa = p[pa];
        }
    }
    for (int i = 1; i <= n; i++){
        cout << v[i] << "\n";
    }
}