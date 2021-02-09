#include <iostream>
using namespace std;

int main() {
    int menu;
    int n = 3;
    int a = 5000;
    int b = 5000;
    while(n-- > 0) {
        cin >> menu;
        a = menu < a ? menu : a;
    }
    n = 2;
    while(n-- > 0) {
        cin >> menu;
        b = menu < b ? menu : b;
    }
    cout << a+b-50;
}
