#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 2e3+5; // max col 1e6, max height 3e3
int n, hx,hy,ax,ay, mn = INT_MAX, dp[mxN][mxN];
pii p[mxN];

int dist(int p1, int p2, int ha){
    if (p1 == 0 && ha == 0) return abs(hx-p[p2].first)+abs(hy-p[p2].second);
    if (p1 == 0 && ha == 1) return abs(ax-p[p2].first)+abs(ay-p[p2].second);
    return abs(p[p1].first-p[p2].first)+abs(p[p1].second-p[p2].second);
}

int solve(int hp, int ap){
    int next = max(hp,ap)+1;
    if (next > n) return 0;
    if (dp[hp][ap] != INT_MAX) return dp[hp][ap];
    return dp[hp][ap] = min(solve(next,ap)+dist(hp,next,0),solve(hp,next)+dist(ap,next,1));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> hx >> hy >> ax >> ay;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        p[i] = make_pair(x,y);
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = INT_MAX;
        }
    }
    cout << solve(0,0);
}