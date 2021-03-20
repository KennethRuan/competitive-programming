#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 2e5+5;
const int mod = 998244353;
const int logn = 17;

int n, b[mxn], r[mxn], l[mxn];
pii a[mxn];
map<int,int> skip;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++){
        int x;
        cin >> x;
        a[i] = {x,i};
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a, a+n+1);
    sort(b, b+n);
    for (int i = 0; i < n+1; i++){
        skip[a[i].second] = i;
    }
    int msf = 0;
    for (int i = 0; i < n; i++){
        l[i] = max(msf, max(a[i].first-b[i],0));
        msf = l[i];
    }
    msf = 0;
    for (int i = n; i > 0; i--){
        r[i-1] = max(msf, max(a[i].first-b[i-1],0));
        msf = r[i-1];
    }
//    for (int i = 0; i < n; i++)
//        cout << l[i] << " ";
//    cout << "\n";
//    for (int i = 0; i < n; i++)
//        cout << r[i] << " ";
//    cout << "\n";


    for (int i = 0; i <= n; i++){
        cout << max(l[skip[i]-1],r[skip[i]]) << " ";
    }
}