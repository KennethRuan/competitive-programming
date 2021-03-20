//Headers
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int mxn = 2e5+5;
const ll P_M = 1e11+3;

string n, h;
int f_n[26], f_h[26], cnt = 0;
map<ll, bool> incl;

bool isPerm(const int *f_o, const int *f_t){
    for (int i = 0; i < 26; i++){
        if (f_o[i] != f_t[i])
            return false;
    }
    return true;
}

ll mHash(string s){
    ll r = 0;
    for (int i = 0; i < s.length(); i++){
        r = (r*26 + (s[i]-'a'+1)) % P_M;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(f_n, 0, sizeof(f_n));
    memset(f_h, 0, sizeof(f_h));
    cin >> n >> h;

    string h_sub = h.substr(0, n.length());
    ll h_hash = mHash(h_sub);

    for (char i : n){
        f_n[i-'a']++;
    }
    for (char i : h_sub){
        f_h[i-'a']++;
    }

    if (isPerm(f_n, f_h) && !incl[h_hash]){
        incl[h_hash] = true;
        cnt++;
    }

    ll p = 1;
    for (int j = 0; j < n.length()-1; j++)
        p = (p*26) % P_M;

    for (int i = 1; i < h.length() - n.length() + 1; i++){
        char rem = h[i-1], add = h[i+n.length()-1];
        f_h[rem-'a']--; f_h[add-'a']++;

        //rolling hash
        h_hash = (26 * (h_hash - (rem-'a'+1) * p) + (add-'a'+1)) % P_M;
        if (h_hash < 0)
            h_hash += P_M;

        if (isPerm(f_n, f_h) && !incl[h_hash]){
            incl[h_hash] = true;
            cnt++;
        }
    }
    cout << cnt;
}