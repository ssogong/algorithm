#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    unordered_map<string, int>::iterator iter;
    for (string& str : completion) {
        iter = m.find(str);
        if (iter == m.end()) {
            m.insert(pair<string, int>(str, 0));
        } else {
            iter->second += 1;
        }
    }
    
    for (string& str : participant) {
        iter = m.find(str);
        if(iter == m.end()) {
            answer = str;
            break;
        } else if (iter->second > 0) {
            iter->second -= 1;
        } else {
            m.erase(iter);
        }
    }
    
    return answer;
}
