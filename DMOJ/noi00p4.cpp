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
const int mxm = 1e5+5;
const int mod = 1e6+7;
const int logn = 17;
const int bias = 1e5;

int ans = 1;

struct node{
    struct node *c[26];
    bool end;
};

struct node *getNode(){
    auto *pNode = new node;
    pNode -> end = false;
    for (auto & i : pNode->c)
        i = nullptr;
    return pNode;
}

void insert(struct node *root, string key){
    struct node *crawl = root;
    for (int i = 0; i < key.length(); i++){
        int ind = key[i] - 'A';
        if (!crawl->c[ind]) {
            crawl->c[ind] = getNode();
            ans++;
        }
        crawl = crawl->c[ind];
    }
    crawl->end = true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string word;
    struct node *root = getNode();
    while (!cin.eof()){
        cin >> word;
        insert(root, word);
    }
    printf("%i", ans);
    return 0;
}