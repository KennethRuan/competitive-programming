#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mn = 1e5+5;

struct node{
    ll l, r, sum, presum, sufsum, maxsum;
} seg[4*mn];
ll n, q, a;

void pushUp(ll id){
    ll l = 2*id+1, r = 2*id+2;
    seg[id].sum = (seg[l].sum + seg[r].sum);
    seg[id].presum = max(seg[l].presum, seg[l].sum + seg[r].presum);
    seg[id].sufsum = max(seg[r].sufsum, seg[r].sum + seg[l].sufsum);
    seg[id].maxsum = max(seg[id].presum,max(seg[id].sufsum,max(seg[l].maxsum,max(seg[r].maxsum,seg[l].sufsum+seg[r].presum))));
}

void build(ll l, ll r, ll id){
    seg[id].l = l;
    seg[id].r = r;
    if(l==r){
      //  cout << id << " ";
        cin >> a;
        seg[id].sum = a;
        seg[id].presum = a;
        seg[id].sufsum = a;
        seg[id].maxsum = a;
        return;
    }
    ll mid = (seg[id].l + seg[id].r)/2;
    build(l,mid,2*id+1);
    build(mid+1,r,2*id+2);
    pushUp(id);
}

void update(ll l, ll r, ll val, ll id) {
    if (seg[id].l == l && seg[id].r == r && l == r) { //full overlap and root node
        seg[id].sum = val;
        seg[id].presum = val;
        seg[id].sufsum = val;
        seg[id].maxsum = val;
        return;
    }
    ll mid = (seg[id].l + seg[id].r) / 2;
    if (r <= mid)update(l, r, val, 2 * id+1);
    else if (l > mid) update(l, r, val, 2 * id + 2);
    else {
        update(l, mid, val, 2 * id+1);
        update(mid + 1, r, val, 2 * id + 2);
    }
    pushUp(id);
}

node query(ll l, ll r, ll id) { 
    node result; 
    result.sum = result.presum = result.sufsum = result.maxsum = INT_MIN; 
  
    if (seg[id].l == l && seg[id].r == r) 
        return seg[id];
  
    ll mid = (seg[id].l + seg[id].r) / 2; 
  
    if (r <= mid) 
        return query(l, r, 2 * id + 1); 

    if (l > mid) 
        return query(l, r, 2 * id + 2); 
  
    node left = query(l, mid, 2 * id + 1);
    node right = query(mid + 1, r, 2 * id + 2); 
  
    result.sum = (left.sum + right.sum);
    result.presum = max(left.presum, left.sum + right.presum);
    result.sufsum = max(right.sufsum, right.sum + left.sufsum);
    result.maxsum = max(result.presum,max(result.sufsum,max(left.maxsum,max(right.maxsum,left.sufsum+right.presum))));
                      
    return result; 
} 

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    build(1, n, 0);
//    cout << "\n";
//    cout << seg[15].sum << " " << seg[16].sum << " ";
//    for (int i = 8; i <= 14; i++) cout << seg[i].sum << " ";
//    cout << "\n";
    for (int i=0;i<q;i++){
        char op;
        cin >> op;
        // cout << op << "\n";
        if (op == 'S'){
            int posi, c;
            cin >> posi >> c;
            update(posi,posi,c,0);

          //  for (int i = 7; i <= 14; i++) cout << seg[i].sum << " ";
          //  cout << "\n";
        }
        if (op == 'Q'){
            int l,r;
            cin >> l >> r;
            cout << query(l,r,0).maxsum << "\n";
        }
    }
}