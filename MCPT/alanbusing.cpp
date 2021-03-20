#include <bits/stdc++.h>

using namespace std;
int N,M,x,y;
vector<int> graph[5005];
int main() {
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin>>x>>y;
    for(int i : graph[x]){
        for(int j : graph[i]){
            if(j==y){
                cout<<"yay! no complaint.\n";
                return 0;
            }
        }
        if(i==y){
            cout<<"yay! no complaint.\n";
            return 0;
        }
    }
    cout<<"aww man! whiny Alan.\n";
    return 0;
}