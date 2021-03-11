#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
int checkDiff(string& s1, string& s2) {
    int len = s1.size();
    int n = 0;
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i])
            n++;
    }
    return n;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<int, string>> que;
    que.push(make_pair(0, begin));    // N, V
    queue<map<string, int>> flagQue;
    map<string, int> tmp;
    flagQue.push(tmp);
    while(!que.empty()) {
        pair<int, string> nowP = que.front();
        que.pop();
        map<string, int> flags = flagQue.front();
        flagQue.pop();

        if (nowP.second == target) {
            answer = nowP.first;
            break;
        }
        map<string, int>::iterator iter;
        for (int i = 0; i < words.size(); i++) {
            iter = flags.find(nowP.second);
            if (iter == flags.end() && checkDiff(nowP.second, words[i]) == 1) {
                que.push(make_pair(nowP.first+1, words[i]));
                map<string, int> newFlag = flags;
                newFlag[nowP.second] = 1;
                flagQue.push(newFlag);
            }
        }
    }
    return answer;
}

int main() {
    vector<string> list = {"hot", "dot", "dog", "lot", "log"};
    string begin = "hit";
    string target = "cog";
    int ans = solution(begin, target, list);
    cout << ans << endl;
    return 0;
}