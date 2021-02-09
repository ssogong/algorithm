/**
 * 리뷰
 *    1. 임시 스택에 저장 할 때 굳이 페어로 만들 필요는 없고
 *    인덱스만 저장 하고 값이 필요 할 때에는 prices[인덱스] 하면 된다.
 *    2. for문 돌릴 때 맨 empty 체크를 해주기 때문에 
 *    tmp.push_back(make_pair(0, prices[0]));
 *    이건 필요 없다.
 */
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> solution(vector<int> prices) {
  vector<pair<int, int> > tmp;
  int len = prices.size();
  vector<int> answer(len);
  tmp.push_back(make_pair(0, prices[0]));
  for (int i = 1; i < len; i++) {
      int nowP = prices[i];
      while (!tmp.empty() && tmp.back().second > nowP) {
        answer[tmp.back().first] = i - tmp.back().first;
        tmp.pop_back();
      }
      tmp.push_back(make_pair(i, nowP));
  }
  while(!tmp.empty()) {
    answer[tmp.back().first] = len-1 - tmp.back().first;
    tmp.pop_back();
  }
  
  return answer;
}

int main() {
  vector<int> prices = {1, 2, 3, 2, 3};
  vector<int> answer = solution(prices);
  for (auto& a : answer) {
    printf("%d ", a);
  }
  return 0;
}