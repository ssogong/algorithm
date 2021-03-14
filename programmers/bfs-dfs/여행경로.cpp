#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Swap(pair<int, string>& p1, pair<int, string>& p2) {
  return p1.second < p2.second;     // 알파벳순서
}

vector<pair<int, string>> findDest(string& str, vector<vector<string>>& tickets, int* visited) {
  vector<pair<int, string>> destList;
  for (int i = 0; i < tickets.size(); i++) {
    if (!visited[i] && tickets[i][0] == str)
      destList.push_back(make_pair(i, tickets[i][1]));
  }
  return destList;
}

bool DFS (vector<string>& answer, int N, string nowPos, vector<vector<string>>& tickets, int* visited) {
  vector<pair<int, string>> destList = findDest(nowPos, tickets, visited);
  if (destList.size() == 0) {
    if (N == tickets.size())
      return true;
    else 
      return false;
  }
  sort(destList.begin(), destList.end(), Swap);
  for (auto& dest : destList) {
    visited[dest.first] = 1;
    answer.push_back(dest.second);
    if (DFS(answer, N+1, dest.second, tickets, visited))
      return true;
    else {
      visited[dest.first] = 0;
      answer.pop_back();
    }
  }
  return false;
}

vector<string> solution(vector<vector<string>> tickets) {
  vector<string> answer;
  int *visited = new int[tickets.size()]();
  string nowPos = "ICN";
  answer.push_back(nowPos);
  DFS(answer, 0, nowPos, tickets, visited);
  return answer;
}

int main() {
  vector<vector<string>> list = {{"ICN","B"},{"B","ICN"},{"ICN","A"},{"A","D"},{"D","A"}};
  vector<string> ans = solution(list);
  for (auto& s : ans) {
    cout << s << " " << endl;
  }
  return 0;
}