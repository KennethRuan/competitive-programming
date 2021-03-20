//Headers
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mxn = 1e3+5;
const int mxv = 1e6+5;
int n, f[mxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(f, 0, sizeof(f));
    cin >> n;
    vector<int> hf;
    vector<int> lf;
    int mxf = 0, mnf = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }
    for (int i = 1; i <= 1000; i++) {
        if (f[i] > mxf) {
            mnf = mxf;
            mxf = f[i];
            swap(hf, lf);
            hf.clear();
            hf.push_back(i);
        } else if (f[i] == mxf) {
            hf.push_back(i);
        } else if (f[i] > mnf) {
            mnf = f[i];
            lf.clear();
            lf.push_back(i);
        } else if (f[i] == mnf) {
            lf.push_back(i);
        }
    }
    int mx, mn;
    if (hf.size() > 1) {
        mx = mn = hf[0];
        for (int e:hf) {
            mn = min(e, mn);
            mx = max(e, mx);
        }
        cout << mx - mn;
    }
    else {
        mx = mn = lf[0];
        for (int e:lf) {
            mn = min(e, mn);
            mx = max(e, mx);
        }
        cout << max(abs(hf[0] - mn), abs(hf[0] - mx));
    }
}