#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int> > nodes; 
int *visited;

void DFS(int node) {
  printf("%d ", node);
  visited[node] = 1;
  for (auto& dest : nodes[node]) {
    if (!visited[dest]) {
      DFS(dest);
    }
  }
}
void BFS(int node) {
  queue<int> q;
  q.push(node);
  visited[node] = 1;
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    printf("%d ", now);
    for (auto& dest : nodes[now]) {
      if (!visited[dest]) {
        visited[dest] = 1;
        q.push(dest);
      }
    }
  }
}

int main() {
  int N, M, V;
  scanf("%d%d%d", &N, &M, &V);
  for (int i = 0; i <= N; i++) {
    vector<int> tmp;
    nodes.push_back(tmp);
  }
  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }
  for (auto& vec : nodes) {
    sort(vec.begin(), vec.end());
  }
  visited = new int[N+1]();
  DFS(V);
  printf("\n");
  visited = new int[N+1]();
  BFS(V);
  return 0;
}