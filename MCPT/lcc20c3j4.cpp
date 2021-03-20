//Headers
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int mxn = 2e5+5;

int n, m, k, ans = 0, psa[mxn], arr[mxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(arr, 0, sizeof(arr));
    memset(psa, 0, sizeof(psa));
    cin >> n >> m >> k;
    for (int i = 1; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    int i = 1, j = 1;
    while (j <= n){
        while (arr[j] <= m && j < n)
            j++;
        while (i <= j){
            int r = min(i+k-1, j);
            ans = max(ans, psa[r] - psa[i-1]);
            i++;
        }
        j++;
    }
    j--;
    while (i <= j){
        int r = min(i+k-1, j);
        ans = max(ans, psa[r] - psa[i-1]);
        i++;
    }
    cout << ans;
}