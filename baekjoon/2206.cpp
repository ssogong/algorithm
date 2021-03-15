#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int **Map;
int ***visited;
int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, 1, 0, -1};

void copyArray(int** a, int** b) {
  for (int i = 0; i < N; i++) {
    b[i] = new int[M];
    for (int j = 0; j < M; j++) {
      b[i][j] = a[i][j];
    }
  }
}
bool checkPos(int a, int b) {
  if (a < 0 || a == N || b < 0 || b == M)
    return false;
  return true;
}

void BFS(queue<pair<pair<int, int>, pair<int, int> > >& q, int& ans) {
  while(!q.empty()) {
    pair<pair<int, int>, pair<int, int> > nowNode = q.front();
    q.pop();
    int depth, ifBroke, a, b;
    depth = nowNode.first.first;
    ifBroke = nowNode.first.second;
    a = nowNode.second.first;
    b = nowNode.second.second;
    if (a == N-1 && b == M-1) {
      if (ans == -1)
        ans = depth;
      else if (depth < ans)
        ans = depth;
      return;
    }

    int x, y;
    for (int i = 0; i < 4; i++) {
      x = a + moveX[i];
      y = b + moveY[i];
      if (checkPos(x, y) && !visited[x][y][ifBroke]) {
        visited[x][y][ifBroke] = 1;
        if (Map[x][y] == 0) {
          q.push(make_pair(make_pair(depth+1, ifBroke), make_pair(x, y)));
        }
        else if (Map[x][y] == 1 && !ifBroke) {
          q.push(make_pair(make_pair(depth+1, 1), make_pair(x, y)));
        }
      }
    }
  }
}

int main() {
  scanf("%d%d", &N, &M);
  Map = new int*[N];
  visited = new int**[N];
  for (int i = 0; i < N; i++) {
    Map[i] = new int[M]();
    visited[i] = new int*[M];
    char* s = new char[M+1];
    scanf("%s", s);
    for (int j = 0; j < M; j++) {
      visited[i][j] = new int[2]();
      if (s[j] == '1')
        Map[i][j] = 1;
    }
    delete[] s;
  }

  queue<pair<pair<int, int>, pair<int, int> > > q;
  q.push(make_pair(make_pair(1, 0), make_pair(0, 0)));
  int ans = -1;
  visited[0][0][0] = 1;
  BFS(q, ans);
  printf("%d\n", ans);
  return 0;
}