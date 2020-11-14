#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> m1;
    unordered_map<string, vector<pair<int, int>>> m2;
    int len = genres.size();
    for (int i = 0; i < len; i++) {
        m1[genres[i]] += plays[i];
        m2[genres[i]].push_back(make_pair(i, plays[i]));
    }
    map<int, string, greater<int>> tmp_map;
    // play 총 회수 정렬 heap
    for (auto& m : m1) {
        tmp_map.insert(make_pair(m.second, m.first));
    }
    for (auto& m : tmp_map) {
        sort(m2[m.second].begin(), m2[m.second].end(), cmp);
        for (int i = 0; i < 2 && i < m2[m.second].size(); i++) {
            answer.push_back(m2[m.second][i].first);
        }
    }
    return answer;
}
