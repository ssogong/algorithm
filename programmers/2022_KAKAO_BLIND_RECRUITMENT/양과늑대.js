function solution(info, edges) {
    var answer = 0;
    let map = {};
    let visited = [];
    for (let i = 0; i < info.length; i++) {
        map[i] = [];
        visited.push(0);
	}
    for (let e of edges) {
        map[e[0]].push(e[1]);
        map[e[1]].push(e[0]);
    }
    let q = [];
    q.push({now: 0, cnt: [1, 0]});
    visited[0]++;
    while(q.length !== 0) {
        let front = q[0];
        q.shift();
        let from = front.now;
        let c = front.cnt;
        if (c[0] - c[1] > answer)
            answer = c[0] - c[1];
        for (let dest of map[from]) {
            if (visited[dest] >= 4)
                continue;
            if (info[dest] === 1 && c[0] === c[1] + 1)
                continue;
            if (info[dest] === 0) {
                if (visited[dest])
                    q.push({now: dest, cnt: [c[0], c[1]]});
                else
                    q.push({now: dest, cnt: [c[0]+1, c[1]]});
            }
            else {
                if (visited[dest])
                    q.push({now: dest, cnt: [c[0], c[1]]});
                else
                    q.push({now: dest, cnt: [c[0], c[1]+1]});
            }
            visited[dest]++;
        }
    }
    return answer;
}

console.log(solution([0,0,1,1,1,0,1,0,1,0,1,1], [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))