#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt = 0;
    int match_cnt = 0;
    for (auto& l : lottos) {
        if (l == 0) {
        	zero_cnt++;
            continue;
        }
        for (auto& w : win_nums) {
            if (l == w)
                match_cnt++;
        }
    }
    int max = match_cnt + zero_cnt == 0 ? 6 : 7 - (match_cnt + zero_cnt);
    int min = match_cnt == 0 ? 6 : 7 - match_cnt;
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}