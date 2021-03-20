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
int n, m;
bool visited[mxv];
vector<pii> val[mxv];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(visited, 0, sizeof(visited));

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int x;
            cin >> x;
            val[x].push_back({i, j});
        }
    }
    deque<pii> q;
    q.push_back({n,m});
    while (!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop_front();

        if (cx == 1 && cy == 1){
            cout << "yes";
            return 0;
        }

        int t = cy * cx;
        if (!visited[t]) {
            for (pii v: val[t]){
                q.push_back({v});
            }
            visited[t] = true;
        }
    }
    cout << "no";
}