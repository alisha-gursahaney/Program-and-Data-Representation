#include <iostream>
using namespace std;

int exponent (int x, int n) {
  if (n == 0) {
    return 1;
  }
  else if (n == 1) {
      return x;
  }
  return x * exponent(x, n-1);
}

int main () {
  int x, n, z;
  cin >> x;
  cin >> n;
  z = exponent (x, n);
  cout << z;
  return 0;
}
