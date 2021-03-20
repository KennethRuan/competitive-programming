#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a > 0){
            count++;
        }
    }
    cout << count;
}