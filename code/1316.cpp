#include <iostream>
#include <string>
int main() {
    int n, r = 0;
    char tmp;
    std::string s;
    std::cin >> n;
    while(n--) {
        int a[26] = {0};
        tmp = 0;
        std::cin >> s;
        for (auto c : s) {
            if (c == tmp)
                continue;
            else if (a[c-97]) {
                r--;
                break;
            }
            else {
                a[c-97]++;
                tmp = c;
            }
        }
        r++;
    }
    printf("%d", r);
}