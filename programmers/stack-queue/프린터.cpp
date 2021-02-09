/** 
 * 리뷰
 * 백터 구간에서 최대값을 구할 때
 * #include <algorithm>
 * *max_element(priorities.begin(), priorities.end());
 * 이렇게 할 수 있다.
 */
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    while(location >= 0) {
      int now = priorities.front();
      priorities.erase(priorities.begin());
      int i;
      for (i = 0; i < priorities.size(); i++) {
        if (priorities[i] > now) 
          break;
      }
      if (i != priorities.size()){
        priorities.push_back(now);
        if (location == 0) {
          location = priorities.size() - 1;
        } else {
          location--;
        }
      }
      else {
        answer++;
        location--;
      }
    }
    return answer;
}