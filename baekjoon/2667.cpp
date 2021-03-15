#include <cstdio>
#include <vector>
#include <algorithm>
int **Map;
int **visited;
int N;
void DFS(int a, int b, int& cnt) {
  if (a < 0 || a == N || b < 0 || b == N || visited[a][b] || !Map[a][b])
    return;
  visited[a][b] = 1;
  cnt++;
  DFS(a-1, b, cnt);
  DFS(a+1, b, cnt);
  DFS(a, b-1, cnt);
  DFS(a, b+1, cnt);
}

int main() {
  scanf("%d", &N);
  Map = new int*[N];
  visited = new int*[N];
  for (int i = 0; i < N; i++) {
    Map[i] = new int[N]();
    visited[i] = new int[N]();
    char* s = new char[N+1];
    scanf("%s", s);
    for (int j = 0; j < N; j++) {
      if (s[j] == '1')
        Map[i][j] = 1;
    }
    delete[] s;
  }

  std::vector<int> answer;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (Map[i][j] && !visited[i][j]) {
        int cnt = 0;
        DFS(i, j, cnt);
        answer.push_back(cnt);
      }
    }
  }
  printf("%lu\n", answer.size());
  sort(answer.begin(), answer.end());
  for (auto& n : answer) {
    printf("%d\n", n);
  }
  return 0;
}