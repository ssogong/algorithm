#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool DFS(vector<vector<int>>& computers, int& n, int *flag, int idx) {
  if (flag[idx])
    return false;
  flag[idx] = 1;
  for (int i = 0; i < n; i++) {
    if (computers[idx][i]) {
      DFS(computers, n, flag, i);
    }
  }
  return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int *flag = new int[n]();
    for (int i = 0; i < n; i++) {
      if (DFS(computers, n, flag, i)) {
        answer++;
      }
    }
    return answer;
}

int main() {
  vector<vector<int>> list = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  int n = 3;
  int ans = solution(n, list);
  std::cout << ans << endl;
  return 0;
}