#include <cstdio>
int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1){
    return 1;
  }
  return fib(n-2) + fib(n-1);
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", fib(n));
  return 0;
}