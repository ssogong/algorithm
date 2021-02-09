#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  queue<int> tmp;
  int len = progresses.size();
  for (int i = 0; i < len; i++) {
    // ceil
   tmp.push((100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] != 0));
  }
  while (!tmp.empty()) {
    int cnt = 1;
    int now = tmp.front();
    tmp.pop();
    while(!tmp.empty() && now >= tmp.front()) {
      cnt++;
      tmp.pop();
    }
    answer.push_back(cnt);
  }
  return answer;
}