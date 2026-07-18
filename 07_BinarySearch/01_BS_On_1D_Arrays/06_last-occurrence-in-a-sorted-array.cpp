#include <bits/stdc++.h>
using namespace std;

// find last index of key by scanning from right
int solve(int n, int key, vector<int>& v) {
  // initialize result as not found
  int res = -1;
  // scan from the end toward the start
  for (int i = n - 1; i >= 0; i--) {
    // update and stop when match found
    if (v[i] == key) {
      res = i;
      break;
    }
  }
  // return index or -1
  return res;
}

// program entry
int main() {
  // set size
  int n = 7;
  // set key to search
  int key = 13;
  // define input array
  vector<int> v = {3, 4, 13, 13, 13, 20, 40};
  // print last occurrence index (or -1)
  cout << solve(n, key, v) << "\n";
  // exit
  return 0;
}
