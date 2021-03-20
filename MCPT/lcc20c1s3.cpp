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

const int mxn = 1e5+5;
const int mxm = 1e5+5;
const int mod = 1e6+7;
const int logn = 17;

int n, m;
ll check[mxm];
pii val[mxn];
vector<pii> vals;

pii conv1(string ipp){
    string blk = "";
    vector<string> blks;
    ll num1 = 0, num2 = 0;
    for (int i = 0; i < ipp.length(); i++){
        if (ipp[i] == '.' || ipp[i] == '-') {
            blks.push_back(blk);
            blk = "";
        }
        else{
            blk += ipp[i];
        }
    }
    blks.push_back(blk);
    for (int i = 0; i < 4; i++){
        num1 += stoi(blks[i]) * pow(256,(3-i));
    }
    for (int i = 4; i < 8; i++){
        num2 += stoi(blks[i]) * pow(256,(7-i));
    }
    return {num1, num2};
}

ll conv2(string ipp){
    string blk = "";
    vector<string> blks;
    ll num1 = 0;
    for (int i = 0; i < ipp.length(); i++){
        if (ipp[i] == '.' || ipp[i] == '-') {
            blks.push_back(blk);
            blk = "";
        }
        else{
            blk += ipp[i];
        }
    }
    blks.push_back(blk);
    for (int i = 0; i < 4; i++){
        num1 += stoi(blks[i]) * pow(256,(3-i));
    }
    return num1;
}

void solve(){
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        val[i] = conv1(x);
//        cout << val[i].first << " " << val[i].second << "\n";
    }

    for (int i = 0; i < m; i++){
        string x;
        cin >> x;
        check[i] = conv2(x);
//        cout << check[i] << "\n";
    }
    sort(check, check+m);
    sort(val, val+n);
    
    stack<pii> s;
    s.push(val[0]);
    for (int i = 1; i < n; i++){
        pii top = s.top();
        if (top.second < val[i].first)
            s.push(val[i]);
        else if (top.second < val[i].second){
            top.second = val[i].second;
            s.pop();
            s.push(top);
        }
    }

    while (!s.empty()){
        vals.push_back(s.top());
        s.pop();
    }
    sort(vals.begin(), vals.end());
    vals.push_back({9999999999,9999999999});

//    for (int i = 0; i < vals.size(); i++)
//        cout << vals[i].first << " " << vals[i].second << "\n";
    int ind = 0, ans = 0;
    for (int i = 0; i < m; i++){
        while (check[i] > vals[ind].second){
            ind++;
        }
        if (check[i] >= vals[ind].first && check[i] <= vals[ind].second){
            ans++;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}