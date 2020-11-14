#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> m;
    for (auto& str : phone_book) {
        m.insert(make_pair(str, true));
    }
    for (auto& str : phone_book) {
        string tmp = "";
        int lengh = str.length();
        for (int i = 0; i < lengh-1; i++) {
            tmp += str[i];
            if (m.find(tmp) != m.end()) {
                return false;
            }
        }
    }
    return answer;
}
