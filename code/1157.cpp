#include <iostream>
#include <string>
using namespace std;
int main() {
    int a[26] = {0};
    int max = -1, index = -1;
    bool flag = false;
    string str;
    cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++) {
        if(str[i] < 'a')
            str[i] += 32;
        a[str[i]-97]++;
        if(a[str[i]-97] == max)
            flag = true;
        if(a[str[i]-97] > max) {
            max = a[str[i]-97];
            index = str[i]-97;
            flag = false;
        }
    }
    if(flag)
        cout << '?';
    else
        printf("%c", 'A'+index);
}