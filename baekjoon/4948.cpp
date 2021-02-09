#include <cstdio>
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

int main () {
  int n;
  while(1) {
    scanf("%d", &n);
    if (n == 0)
      return 0;
    int m = 2 * n;
    int re = 0;
    for (int i = n+1; i <= m; i++) {
      if (isPrime(i))
        re++; 
    }
    printf("%d\n", re);
  }
}