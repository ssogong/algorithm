#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int n = 5;
    while(n-- > 0) {
        int score;
        cin >> score;
        sum += score > 40 ? score : 40;
    }
    cout << sum / 5;
    return 0;
}
