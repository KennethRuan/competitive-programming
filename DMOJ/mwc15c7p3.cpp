#include <bits/stdc++.h>
using namespace std;

int n,m,s,l,r,z;
bool visited[1048581];
int dp[1048581];

void bfs(int st) {
    int temp, mo;
    deque<int> q;
    q.push_back(st);
    dp[st] = 0;
    while(!q.empty()) {

        st = q.front();
        q.pop_front();
        mo = dp[st];
        visited[st] = false;

        int a = mo+s;
        if(a <= m) {
            for (int j = 0; j < n; j++) {
                temp = st ^ (1 << (n - j - 1));

                if(dp[temp] > a){
                    dp[temp] = a;
                    if(!visited[temp]){
                        visited[temp] = true;
                        q.push_back(temp);
                    }
                }

            }
        }

        a = mo+l;
        if (a <= m) {
            int lm = (st & (1 << (n - 1))) >> (n - 1);
            temp = st & ~(1 << (n - 1));
            temp = temp << 1;
            temp |= lm;

            if(dp[temp] > a){
                dp[temp] = a;
                if(!visited[temp]){
                    visited[temp] = true;
                    q.push_back(temp);
                }
            }
        }
        a = mo+r;
        if (a <= m) {
            temp = st;
            int rm = st & 1;
            temp = temp >> 1;
            temp |= rm << (n - 1);

            if(dp[temp] > a){
                dp[temp] = a;
                if(!visited[temp]){
                    visited[temp] = true;
                    q.push_back(temp);
                }
            }
        }

        a = mo+z;
        if (a <= m) {
            temp = ~st & ((1 << n) - 1);
            if(dp[temp] > a){
                dp[temp] = a;
                if(!visited[temp]){
                    visited[temp] = true;
                    q.push_back(temp);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> s >> l >> r >> z;
    string inp;
    int ma = 0,ans = 0;
    memset(visited,0,sizeof(visited));
    for(int i = 0;i < 1048581;i++){
        dp[i] = INT_MAX;
    }
    cin >> inp;

    for (int j = 0; j < n; j++){
        if(inp[j] == 'B'){
            ma |= (1 << (n-j-1));
        }
    }

    visited[ma] = true;
    bfs(ma);
    for (int i:dp){
        if (i <= m){
            ans++;
        }
    }
    cout << ans;
}