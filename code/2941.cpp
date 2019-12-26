#include <iostream>
#include <string>
using namespace std;
int main() {
    string c[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string a;
    cin >> a;
    int r = a.size();
    for(auto i : c) {
        int flag = 0;
        while((flag = a.find(i, flag)) != -1) {
            if(i == "z=" && a[flag-1] == 'd') {
                flag++;
                continue;
            }
            r -= i.size() - 1;
            flag ++;
        }
    }
    cout << r;
}