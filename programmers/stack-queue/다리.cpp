#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weights = 0;
    queue<int> q;
    for (int i = 0; i< bridge_length; i++) {
      q.push(0);
    }
    int nowT = 0;
    int len = truck_weights.size();
    while(1) {
      answer++;
      weights -= q.front();
      q.pop();
      if (nowT == len && weights == 0)
        break;
      if (nowT < len && weights + truck_weights[nowT] <= weight) {
        q.push(truck_weights[nowT]);
        weights += truck_weights[nowT];
        nowT +=1;
      }
      else {
        q.push(0);
      }
    }
    return answer;
}