//Headers
#include <bits/stdc++.h>
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
typedef pair<ll, ll> pii;

const int mxn = 2e5+5;
const int mod = 1e9+7;
ll freq[26], ans = 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(freq, 0, sizeof(freq));
    string s;
    cin >> s;
    for (char c:s){
        freq[c-'a']++;
    }
    for (int i = 0; i < 26; i++){
        ans = (ans * (freq[i]+1)) % mod;
    }
    cout << ans << "\n";
}