#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll mn = 1e5+5;
int n, mxCnt, pno, pnt, cent, dias[mn], ans = 0, ans2 = 0;
bool found = false;
vector<int> g[mn], path;

void dfs(int node, int p, int we){
    if (we > mxCnt){
        mxCnt = we;
        pno = node;
    }
    for (int i: g[node]){
        if (i == p) continue;
        dfs(i, node, we+1);
    }
}

void dfs2(int node, int p, int we){
    if (we > mxCnt){
        mxCnt = we;
        pnt = node;
    }
    for (int i: g[node]){
        if (i == p) continue;
        dfs2(i, node, we+1);
    }
}

bool dfs3(int node, int p, int we){
    bool inc = false;
    if (we == mxCnt && !found){ inc = true; found = true;}
    for (int i: g[node]){
        if (i == p) continue;
        if(dfs3(i, node, we+1)) inc = true;
    }
    if (inc) path.push_back(node);
    return inc;
}

int dfs4(int node, int p){
    dias[node] = 1;
    for (int i: g[node]){
        if (i == p) continue;
        dias[node] = max(dias[node], dfs4(i,node)+1);
    }
    return dias[node];
}

void dfs5(int node, int p){
    ans++;
    vector<int> visit;
    int longest = 0;
    for (int i: g[node]){
        if (i == p) continue;
        if (dias[i] > longest){
            visit.clear();
            longest = dias[i];
            visit.push_back(i);
        }
        else if(dias[i] == longest){
            visit.push_back(i);
        }
    }
    if (node == cent){
        if (g[node].size() < 3){
            for (int i: g[node]){
                dfs5(i, node);
            }
        }
        else if (visit.size() < 3){
            int longest1 = 0, longest2 = 0, longest3 = 0;
            for (int i: g[node]){
                if (dias[i] >= dias[longest1]){
                    longest3 = longest2;
                    longest2 = longest1;
                    longest1 = i;
                }
                else if (dias[i] >= dias[longest2]){
                    longest3 = longest2;
                    longest2 = i;
                }
                else if (dias[i] >= dias[longest3]){
                    longest3 = i;
                }
            }
            if (longest1 != 0) dfs5(longest1, node);
            if (longest2 != 0 && dias[longest2] != dias[longest3]) dfs5(longest2,node);
        }
    }
    else{
        if (visit.size() <= 1){
            for (int i: visit){
                dfs5(i, node);
            }
        }
    }
}

void dfs6(int node, int p){
    ans2++;
    vector<int> visit;
    int longest = 0;
    for (int i: g[node]){
        if (i == p) continue;
        if (dias[i] > longest){
            visit.clear();
            longest = dias[i];
            visit.push_back(i);
        }
        else if(dias[i] == longest){
            visit.push_back(i);
        }
    }
    if (node == cent){
        if (g[node].size() < 3){
            for (int i: g[node]){
                dfs6(i, node);
            }
        }
        else if (visit.size() < 3){
            int longest1 = 0, longest2 = 0, longest3 = 0;
            for (int i: g[node]){
                if (dias[i] >= dias[longest1]){
                    longest3 = longest2;
                    longest2 = longest1;
                    longest1 = i;
                }
                else if (dias[i] >= dias[longest2]){
                    longest3 = longest2;
                    longest2 = i;
                }
                else if (dias[i] >= dias[longest3]){
                    longest3 = i;
                }
            }
            if (longest1 != 0) dfs6(longest1, node);
            if (longest2 != 0 && dias[longest2] != dias[longest3]) dfs6(longest2,node);
        }
    }
    else{
        if (visit.size() <= 1){
            for (int i: visit){
                dfs6(i, node);
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    mxCnt = 0;
    dfs(1,0,1);
    mxCnt = 0;
    dfs2(pno, 0, 1);
    dfs3(pno, 0, 1);
//    cout << pno << "\n";
//    for (int i: path){
//        cout << i << " ";
//    }
//    cout << "\n";
    cent = path.at(mxCnt/2);
    dfs4(cent, 0);
    dfs5(cent, 0);

    if(path.size() % 2 == 0){
        cent = path.at(mxCnt/2-1);
        dfs4(cent, 0);
        dfs6(cent, 0);
    }
//    cout << cent << "\n";
//    for (int i = 1; i <= n; i++){
//        cout << dias[i] << " ";
//    }
//    cout << "\n";

    cout << max(ans,ans2);
}