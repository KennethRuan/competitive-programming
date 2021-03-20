#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int num[a+1];
  for (int i = 0; i < a+1; i++){
    num[i] = i+1;
  }
  string s;
  cin >> s;
  int count = 0;
  for (int i = a-1; i > -1; i--){
    if (s[i] == '>'){
      count++;
    }
    if (count > 0 && s[i] == '<'){
      reverse(num+i+1,num+i+count+2);
      count = 0;
    }
    if (i == 0){
      reverse(num,num+count+1);
      count = 0;
    }
  }
  for (int i = 0; i < a+1; i++){
    cout << num[i] << " ";
  }
}