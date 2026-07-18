#include <bits/stdc++.h>
using namespace std;


int solve(int n, int key, vector<int>& v) {
  // initialize result as not found
  int res = -1;
  int low = 0, high = n-1;
  while(low<=high)
  {
    int mid = low+(high-low)/2;
    if(v[mid] == key)
    {
        res = mid;
        low = mid+1;
    }
    else if(v[mid] > key)
    {
        high = mid-1;
    }
    else low = mid+1;
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
