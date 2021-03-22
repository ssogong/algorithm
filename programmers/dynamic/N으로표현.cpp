#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int > > flags; 
void foo(int N, int number, int p) {
  for (int i = 1; i < p; i++) {
    for (auto& n : flags[i]) {
      for (auto& m : flags[p-i]) {
        flags[p].push_back(n+m);
        flags[p].push_back(n-m);
        flags[p].push_back(n*m);
        if (m != 0)
          flags[p].push_back(n/m);
      }
    }
  }
  int tmp = N;
  int cnt = p;
  while(--cnt) {
    tmp = tmp * 10 + N;
  }
  flags[p].push_back(tmp);
}
int solution(int N, int number) {
    flags.push_back({});
    int p = 1;
    while(p <= 8) {
      vector<int> tmp;
      flags.push_back(tmp);
      foo(N, number, p);
      for (auto& k : flags[p]) {
        if (k == number)
          return p;
      }
      p++;
    }
    return -1;
}
int main() {
  cout << solution(5, 12) << endl;
  return 0;
}