#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int dp[1505][1505],gr[1505][1505],ml = 0,n;

int dfs(int i, int j){
    if (dp[i][j] > -1) return dp[i][j];
    dp[i][j] = 0;
    dp[i][j] = max(
            (i-1 >= 0 && gr[i-1][j] < gr[i][j]) ? dfs(i-1,j)+1:0, max(
            (i+1 < n && gr[i+1][j] < gr[i][j]) ? dfs(i+1,j)+1:0,max(
                    (j-1 >= 0 && gr[i][j-1] < gr[i][j]) ? dfs(i,j-1)+1:0,
                    (j+1 < n && gr[i][j+1] < gr[i][j]) ? dfs(i,j+1)+1:0)));
    return dp[i][j];
}

int main() {
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> gr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ml = max(ml, dfs(i, j));
        }
    }
    cout << ml;
}