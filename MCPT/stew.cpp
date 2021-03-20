#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+5;

int ans = 0, n, k, a[mxn], psa[mxn];

int main() {
    scanf("%d %d",&n,&k);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + a[i];
    }
    int mnt = INT_MAX;
    int ans = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        int mnc = a[i + k - 1] - a[i];
        if (mnc < mnt) {
            mnt = mnc;
            ans = psa[i + k - 1] - psa[i - 1];
        } else if (mnc == mnt) {
            ans = psa[i + k - 1] - psa[i - 1];
        }
    }
    printf("%d", ans);
}