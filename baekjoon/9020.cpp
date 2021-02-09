#include <cstdio>
#include <math.h>
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
  int n; 
  scanf("%d", &n);
  while (n--) {
    int m;
    scanf("%d", &m);
    int a = 0;
    int b = m;
    int len = m / 2;
    for (int i = 2; i <= len; i++) {
      if (isPrime(i) && isPrime(m-i) && m-i-i < b-a) {
        a = i;
        b = m - i;
      }
    }
    printf("%d %d\n", a, b);
  }
}