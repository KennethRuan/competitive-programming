#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 0;
int n;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int li[] = {100, 50, 20, 10, 5, 2, 1};

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll cnt[] = {0,0,0,0,0,0,0};
        ll num, tot = 0;
        cin >> num;
        for (int j = 0; j < 7; j++) {
            ll peepoo = num / li[j];
            if (peepoo > 0) {
                num %= li[j];
                cnt[6 - j] = peepoo;
                tot += peepoo;
            }
        }
        cout << tot << "\n";
        for (ll i: cnt){
            cout << i << " ";
        }
        cout << "\n";
    }
}