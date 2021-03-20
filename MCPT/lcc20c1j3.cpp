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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 3e5+5;
const int mod = 1e6+7;
const int logn = 17;

map<string, string> a;
map<string, string> b;
int n, q;

void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        string name, num;
        cin >> name >> num;
        a[name] = num;
        b[num] = name;
    }
    for (int i = 0; i < q; i++){
        string op, x;
        cin >> op;
        cin >> x;
        if (op == "phone"){
            cout << a[x] << "\n";
        }
        else{
            cout << b[x] << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}