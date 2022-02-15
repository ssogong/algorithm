#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int map[110][110];
int dr[4] = { 0, 1, 0, -1 };	// 우, 하, 좌, 상
int dc[4] = { 1, 0, -1, 0 };

void init_map(int& r, int& c) {
    int tmp = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            map[i][j] = tmp++;
        }
    }
}

int rotate(int r1, int c1, int r2, int c2) {
    int Min = 99999999;
    int step_r = r2 - r1;
    int step_c = c2 - c1;
    int before = map[r1][c1];
    int now_r = r1;
    int now_c = c1;
    int now_step;
    for (int i = 0; i < 4; i++) {
        now_step = i % 2 == 0 ? step_c : step_r;
        for (int j = 0; j < now_step; j++) {
            Min = min(Min, before);
            now_r += dr[i];
            now_c += dc[i];
            int tmp = map[now_r][now_c];
            map[now_r][now_c] = before;
            before = tmp;
        }
    }
    return Min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init_map(rows, columns);
    for (auto& q : queries) {
        answer.push_back(rotate(q[0], q[1], q[2], q[3]));
    }
    return answer;
}