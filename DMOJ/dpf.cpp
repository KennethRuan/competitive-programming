#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mxN = 3e3+5;
int dp[mxN][mxN];
string s,t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    int a = s.length(),b = t.length();
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
//    for (int i = 0; i <= a; i++){
//        for (int j = 0; j <= b; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    string ans;
    while(a > 0 && b > 0){
//        cout << "a " << a << "b " << b << "\n";
        if (s[a-1] == t[b-1]){
            ans = s[a-1] + ans;
            a--;
            b--;
        }
        else if (dp[a-1][b] > dp[a][b-1]){
            a--;
        }
        else{
            b--;
        }
    }
    cout << ans;
}