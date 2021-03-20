//Headers
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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 3e5+5;
const int mod = 1e6+7;
const int logn = 17;

int f[10], n;

void solve(){
    cin >> n;
    double tot = 0, cor = 0;
    for (int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        tot += a;
        cor += a * (b/100);
    }
    cout << (int) round(cor/tot*100);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}