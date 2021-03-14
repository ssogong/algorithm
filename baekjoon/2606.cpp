#include <cstdio>
#include <vector>
using namespace std;
int *visited;
vector<vector<int > > nodes;
void DFS(int node, int& cnt) {
  if (visited[node])
    return;
  visited[node] = 1;
  cnt++;
  for (auto& dest : nodes[node]) {
    DFS(dest, cnt);
  }
}
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  visited = new int[N+1]();
  while(N--) {
    vector<int> tmp;
    nodes.push_back(tmp);
  }
  int a, b;
  while(M--) {
    scanf("%d%d", &a, &b);
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }
  int cnt = 0;
  DFS(1, cnt);
  printf("%d", cnt-1);
  return 0;
}