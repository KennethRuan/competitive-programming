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

const int mxn = 2e5+5;

int n, lights[25], dp[25];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pii> g;

    for (int & i : dp)
        i = 9999999;
    cin >> n;
    pii lr = {-1, -1};
    int x = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        lights[i] = x;
        if (x == 1){
            if (lr.first == -1) {
                lr.first = i; lr.second = i+1;
            }
            else
                lr.second++;
        }
        else{
            if (lr.first != -1) {
                g.push_back(lr);
                lr.first = -1;
            }
        }
    }
    if (x == 1)
        g.push_back(lr);
//    for (auto &e : g)
//        cout << e.first << " " << e.second << "\n";
    dp[g.size()] = 0;
    for (int i = g.size()-1; i >= 0; i--){
        int ones = 0;
        for (int j = i; j < g.size(); j++){
            int range = g[j].second - g[i].first;
            if (range > 7)
                break;
            ones += g[j].second - g[j].first;
            int t = max(4, range) - ones;

            if (range == 6 && lights[g[i].first + 2] && lights[g[i].first + 3])
                t = 9999999;
            if (range == 7 && lights[g[i].first + 3])
                t = 9999999;

            dp[i] = min(dp[j+1] + t, dp[i]);
        }
    }
    cout << dp[0];
}