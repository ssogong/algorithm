#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int *answer = &triangle[0][0];
    int len = triangle.size();
    for (int i = len-1; i > 0; i--) {
      for (int j = 0; j < triangle[i].size()-1; j++) {
        triangle[i-1][j] += max(triangle[i][j], triangle[i][j+1]);
      }
    }
    return *answer;
}

int main() {
  cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;
  return 0;
}