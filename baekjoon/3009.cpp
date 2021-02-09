#include <iostream>
#include <vector>
using namespace std;
int main () {
  vector<int> x, y;
  int cX[1001] = {0};
  int cY[1001] = {0};
  int tmpX, tmpY;
  for(int i = 0; i < 3; i++) {
    cin >> tmpX >> tmpY;
    x.push_back(tmpX);
    cX[tmpX]++;
    y.push_back(tmpY);
    cY[tmpY]++;
  }
  while(!x.empty()) {
    if(cX[x.back()] == 1)
      cout << x.back() << " ";
    x.pop_back();
  }
  while(!y.empty()) {
    if(cY[y.back()] == 1)
      cout << y.back();
    y.pop_back();
  }
}