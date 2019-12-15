#include <iostream>
using namespace std;
int main() {
    int arr[9];
    int max = -1;
    int index;
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        if(arr[i] > max) {
            max = arr[i];
            index = i+1;
        }
    }
    cout << max << '\n' << index;
    return 0;
}