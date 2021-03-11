#include <string>
#include <vector>
#include <iostream>
using namespace std;
void dfs(vector<int>& numbers, int target, int idx, int sum, int& answer) {
  if (idx == numbers.size()) {
    if (sum == target)
      answer++;
    return;
  }
  int sum1 = sum + numbers[idx];
  int sum2 = sum - numbers[idx];
  idx++;
  dfs(numbers, target, idx, sum1, answer);
  dfs(numbers, target, idx, sum2, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}

int main() {
  vector<int> numbers = {1, 1, 1, 1, 1};
  int target = 3;
  int ans = solution(numbers, target);
  cout << ans << endl;
  return 0;
}