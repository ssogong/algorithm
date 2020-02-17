#include <iostream>
#include <list>
#include <map>
using namespace std;
int main() {
    int n, a, b,  r=0;
    map<int, list<int> > desk;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        desk[b].push_back(a);
    }
    for(auto itr = desk.begin(); itr != desk.end(); itr++) {
        if(itr->second.size() == 1) continue;
        itr->second.sort();
        auto iter = itr->second.begin();
        a = -99999;
        while(1) {
            b = *iter;
            a = b - a;
            if(++iter == itr->second.end()) {
                r += a;
                break;
            }    
            r += *iter-b < a ? *iter-b : a;
            a = b;
        }
    }
    cout << r;
}