// Program to show segment tree to demonstrate lazy
// propagation
#include <bits/stdc++.h>
const int MAX = 800010;
typedef long long ll;

using namespace std;

ll tree[MAX]; // To store segment tree
ll lazy[MAX]; // To store pending updates

void rangeUpdate(ll si, ll low, ll high, ll uLow,
                 ll uHigh, ll val, ll mod)
{
    //check for updates
    if (lazy[si] != 0)
    {
        tree[si] += ((high-low+1)*(lazy[si]%mod))%mod;

        //leaf node check
        if (low != high)
        {
            lazy[si*2 + 1] += lazy[si]%mod;
            lazy[si*2 + 1] %= mod;
            lazy[si*2 + 2] += lazy[si]%mod;
            lazy[si*2 + 2] %= mod;
        }
        lazy[si] = 0;
    }

    // no overlap
    if (low>high || low>uHigh || high<uLow)
        return;

    // full overlap
    if (low>=uLow && high<=uHigh)
    {
        // Add the difference to current node
        tree[si] += ((high-low+1)*(val%mod))%mod;

        // leaf node check
        if (low != high)
        {
            //lazy update
            lazy[si*2 + 1] += val%mod;
            lazy[si*2 + 1] %= mod;
            lazy[si*2 + 2] += val%mod;
            lazy[si*2 + 2] %= mod;
        }
        return;
    }

    // partial overlap
    ll mid = (low + high)/2;
    rangeUpdate(si*2+1, low, mid, uLow, uHigh, val,mod);
    rangeUpdate(si*2+2, mid+1, high, uLow, uHigh, val,mod);
    tree[si] = (tree[si*2+1]%mod + tree[si*2+2]%mod)%mod;
}

ll rangeSum(ll si, ll low, ll high, ll qLow, ll qHigh,ll mod)
{
    //check for updates
    if (lazy[si] != 0)
    {
        tree[si] += ((high-low+1)*lazy[si])%mod;

        // leaf node check
        if (high != low)
        {
            lazy[si*2+1] += lazy[si]%mod;
            lazy[si*2+1] %= mod;
            lazy[si*2+2] += lazy[si]%mod;
            lazy[si*2+2] %= mod;
        }

        lazy[si] = 0;
    }

    // no overlap
    if (low>high || low>qHigh || high<qLow)
        return 0;

    // full overlap
    if (low>=qLow && high<=qHigh)
        return tree[si]%mod;

    // partial overlap
    ll mid = (low + high)/2;
    return (rangeSum(2*si+1, low, mid, qLow, qHigh,mod)%mod +
           rangeSum(2*si+2,mid+1, high, qLow, qHigh,mod)%mod)%mod;
}

void buildTree(ll arr[], ll low, ll high, ll si, ll mod)
{
    if (low > high)
        return;
    //at leaf
    if (low == high)
    {
        tree[si] = arr[low];
        return;
    }

    ll mid = (low + high)/2;
    buildTree(arr, low, mid, si*2+1, mod);
    buildTree(arr, mid+1, high, si*2+2, mod);

    tree[si] = (tree[si*2 + 1]%mod + tree[si*2 + 2]%mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    ll m,n,q,op;
    cin >> m >> n >> q;
    ll input[n];
    for (ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        input[i] = a % m;
    }
    buildTree(input, 0, n-1, 0, m);
    for (ll i = 0; i < q; i++){
        cin >> op;
        if (op == 1){
            ll l,r,x;
            cin >> l >> r >> x;
            l--;r--;
            rangeUpdate(0,0,n-1,l,r,x,m);
        }
        if (op == 2){
            ll l,r;
            cin >> l >> r;
            l--;r--;
            cout << rangeSum(0,0,n-1,l,r,m)%m << "\n";
        }
    }
//    cout << endl;
//    for (int i = 0; i < 20; i++){
//        cout << tree[i] << " ";
//    }
//
//    return 0;
}