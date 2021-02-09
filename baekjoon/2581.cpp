#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n) {
  int maxN = (int) sqrt((double)n);
  if(n == 1) return false;
  for(int i = 2; i <= maxN; i++) {
    if(n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int m, n;
  cin >> m >> n;
  int sum = 0;
  int min = n;
  for(int i = m; i <= n; i++) {
    if(isPrime(i)) {
      sum += i;
      min = i < min ? i : min;
    }
  }
  if(sum == 0) {
    cout << -1;
  } else {
    cout << sum << endl << min;
  }
}